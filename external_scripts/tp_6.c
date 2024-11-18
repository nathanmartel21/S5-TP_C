#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char const* argv[])
{
	// On crée la socket, la fonction nous renvoie le numéro du descripteur de fichier correspondant a la socket
  // AF_INET indique qu'on utilise de l'ipv4
  // SOCK_STREAM indique qu'on souhaite un protocole connecté dans lequel les paquets arrivent dans l'ordre
  // Le dernier argument sert à préciser le protocole, on met zéro pour qu'il soit choisi automatiquement
	int numero_socket = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in address; // cette structure sert a configurer les parametres d'écoute de la socket.
	address.sin_family = AF_INET; // on indique le protocole ip (ici ipv4)
	address.sin_addr.s_addr = INADDR_ANY; // On écoute sur toutes les addresses entrantes 
	address.sin_port = htons(7070); // On écoute sur le port 7070
	int addrlen = sizeof(address);

	int un = 1; // on crée une variable contenant 1 car on aura besoin d'un pointeur vers la valeur un a la ligne suivante
	// setsockopt sert à changer les options d'une socket
	// Les options SO_REUSEADDR et SO_REUSEPORT sont utiles dans le cas ou un programme précédent a attaché une socket sur le
	// même couple port/addresss et qu'elle n'a pas été supprimée
	// En précisant REUSE_PORT et REUSE_ADDR nous précisons que nous souhaitons utiliser ce couple "de force"	
	setsockopt(numero_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &un, sizeof(un));

  // On configure la socket en lui passant la structure qui contient l'addresse et le port sur lesquelle écouter.
  bind(numero_socket, (struct sockaddr*)&address, sizeof(address));

  // On écoute sur la socket précédement créée, le numero 3 indique qu'on autorise une queue de maximum 3 requêtes en attente de traitement
  // Ecouter signifie simplement que le noyau va enregistrer les paquets qui arrivent sur cette socket.
	listen(numero_socket, 3);

	// L'appel à la fonction accept met le programme en pause en attendant que le noyau ait réussi un handshake tcp avec un client.
  // Lorsqu'une connection est réussie, on enregistre le numéro de la nouvelle socket qui sera utilisée pour commmuniquer avec le client.
  int socket_nouvelle_connection = accept(numero_socket, (struct sockaddr*)&address, (socklen_t*)&addrlen);

	printf("Connection réussie avec un client\n");

	// On ferme la socket connectée au client
	close(socket_nouvelle_connection);
	// On ferme la socket d'écoute
	close(numero_socket);
	return 0;
}
