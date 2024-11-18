/// Soit deux structures: Voiture et Bateau, ayant chacune une fonction associée permettant d'afficher leurs characteristiques
#include <stdio.h>
#include <stdlib.h>
struct Voiture{
  int puissance;
  int essence_restante;
  float usage_pneus;
};
typedef struct Voiture Voiture;

void affiche_voiture(Voiture* v){
  printf("Voiture de %d chevaux\nCarburant restant: %d\nUsage pneus: %f cm\n", v->puissance, v->essence_restante, v->usage_pneus);
}


struct Bateau{
  int poids;
  int taille_coque;
  int annees;
};
typedef struct Bateau Bateau;

void affiche_bateau(Bateau* b){
  printf("Bateau de %d ans d'un poids de %d pour une taille de %d\n", b->annees, b->poids, b->taille_coque);
}

// si on souhaitait utiliser un seul type regrouppant des bateaux et des voitures on pourrait procéder ainsi

typedef enum VehiculeType {BATEAU, VOITURE} VehiculeType;
typedef union VehiculeInfos{
  Bateau bateau_infos;
  Voiture voitures_infos;
} VehiculeInfos;

typedef struct Vehicule{
  VehiculeType type;
  VehiculeInfos infos;
} Vehicule;

/// Pour parcourir une liste de véhicule en affichant leurs charactéristiques, on pourrait écrire :

void affiche_vehicules(int nombre, Vehicule* vehicules){
  for (int i = 0; i < nombre; i++){
     if (vehicules[i].type == BATEAU){
       affiche_bateau(&vehicules[i].infos.bateau_infos);
     } else if (vehicules[i].type == VOITURE){
       affiche_voiture(&vehicules[i].infos.voitures_infos);
     }
  }
}

// pour créer un véhicule on procède donc ainsi

Vehicule cree_voiture(int puissance, int essence_restante, float usage_pneus){
  Vehicule v;
  v.type = VOITURE;
  v.infos.voitures_infos.essence_restante = essence_restante;
  v.infos.voitures_infos.puissance = puissance;
  v.infos.voitures_infos.usage_pneus = usage_pneus;
  return v;
}


Vehicule cree_bateau(int poids, int annees, int taille_coque){
  Vehicule v;
  v.type = BATEAU;
  v.infos.bateau_infos.annees = annees;
  v.infos.bateau_infos.poids = poids;
  v.infos.bateau_infos.taille_coque = taille_coque;
  return v;
}




/////////////////////////////////////////
// Exercice 6 question 1: Tables virtuelles
/////////////////////////////////////////



// Une autre façon serait d'utiliser une vtable
// Pour cet exemple on imagine la fonction prix d'un vehicule

int prix_voiture(void* ptr){
  Voiture* v = (Voiture*)ptr;
  return v->puissance * (v->essence_restante - v->usage_pneus);
}

int prix_bateau(void* ptr){
  Bateau* b = (Bateau*)ptr;
  return b->taille_coque * (b->poids - b->annees);
}


// la vtable contient des pointeurs vers toutes les fonctions des différents vehicules
// pour cet exemple, seule la fonction prix est utilisée
typedef struct VehiculeVTable{
  int (*prix)(void*);
} VehiculeVTable;

typedef struct Vehicule2{
  void* vehicule_ptr;
  VehiculeVTable vtable;  
} Vehicule2;

// on peut ainsi créer une fonction qui somme les prix d'une collection de vehicules

int prix_collection(int nombre_vehicules, Vehicule2* liste_vehicules){
  int somme = 0;
  for (int i = 0; i < nombre_vehicules; i++){
    somme += liste_vehicules[i].vtable.prix(liste_vehicules[i].vehicule_ptr);
  }
  return somme;
}


// Pour créer un vehicule on s'y prendrait ainsi
// NOTE: puisqu'on ne connait pas la taille de l'objet alloué, on est obligés d'utiliser un pointeur vers le tas
// Cela implique de devoir libérer la mémoire allouée lorsqu'on n'utilise plus un vehicule
Vehicule2 cree_voiture_2(int puissance, int essence_restante, float usage_pneus){
  Vehicule2 vehicule;
  Voiture* voiture = malloc(sizeof(Voiture));
  
  voiture->essence_restante = essence_restante;
  voiture->puissance = puissance;
  voiture->usage_pneus = usage_pneus;

  vehicule.vehicule_ptr = (void*)voiture;
  vehicule.vtable.prix = &prix_voiture;
  return vehicule;
}


Vehicule2 cree_bateau_2(int poids, int annees, int taille_coque){
  Vehicule2 v;
  Bateau* b = malloc(sizeof(Bateau));
  
  b->annees = annees;
  b->poids = poids;
  b->taille_coque = taille_coque;

  v.vehicule_ptr = (void*)b;
  v.vtable.prix = &prix_bateau;
  return v;
}


// Voici aussi un exemple d'usage de ces deux façons d'implémenter un vehicule
// NOTE: pour des raisons de simplicité, la mémoire n'est pas libérée
int main(){

  // comme fait jusqu'a présent dans le cours
  Vehicule collection[3];
  collection[0] = cree_bateau(5, 4, 3);
  collection[1] = cree_voiture(150, 10, 1.2);
  collection[2] = cree_bateau(10, 2, 100);
  affiche_vehicules(3, collection);

  // comme fait dans les langages objets, en utilisant une vtable
  Vehicule2 collection2[3];
  collection2[0] = cree_bateau_2(5, 4, 3);
  collection2[1] = cree_voiture_2(150, 10, 1.2);
  collection2[2] = cree_bateau_2(10, 2, 100);
  printf("le prix de la collection est %d\n", prix_collection(3, collection2));
}
