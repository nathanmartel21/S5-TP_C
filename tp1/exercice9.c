#include <stdio.h>

// macro CHANGE
#define CHANGE(i, pos, val) ???

// macro PUT
#define PUT(a, index, valeur) ???

// macro GET
#define GET(a, index) ((a >> (index * 6)) & 0x3F)

int main(){

	int a = 0;

	//PUT(a, 0, 8);
	//PUT(a, 1, 37);
	//
	//printf(" %d\n", GET(a,0)); 
	//printf(" %d\n", GET(a,1));


}
