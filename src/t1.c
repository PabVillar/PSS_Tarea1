// Coloque aca los #include que necesite
// Si usa por ejemplo strcpy, ingrese en el shell de comandos:
// $ man 3 strcpy
// En SYNOPSIS le indicara que debe incluir el archivo de encabezados string.h
// Programe aca las 3 funciones pedidas

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#include "t1.h"

//Parte a

typedef unsigned int uint;


uint overwrite(uint res, int nbits, int pos, int val){
	
	uint val_desp;
	
	val_desp = val << ((sizeof(uint)<<3) - nbits - pos);

	return res | val_desp;
}

uint comprimir(uint *a, int nbits){
	//Concatenacion de todos los elementos en a truncados a nbits
	//La cantidad de elementos de a es un k tal que k*nbits <= sizeof(uint)<<3
	uint aux[sizeof(a)];
	
	uint res = 0;
	int k;
	int i = 0;
	for (k = nbits; k <= (sizeof(uint)<<3); k += nbits)
	{
		aux[i] = (a[i] << (sizeof(uint)<<3)-nbits) >> ((sizeof(uint)<<3)-nbits);
		//printf("%d\n", aux[i]);
		res = overwrite(res,nbits,k-nbits,aux[i]);
		i++;	
	}
	
    uint n = sizeof(uint)<<3;
	return res >> (n - (k-nbits));
}

//Parte b
char *insercion(char *d, char *s){
	int totalsize = strlen(d)+strlen(s)+1;
    char *aux = malloc(totalsize);
    aux = strcat(strcpy(aux,s),d);

    return aux;
}


//Parte c
void insertar (char *d, char *s){
	char *aux1;
	  char temp;
	  int i = strlen(d);
	  int k = 1;
	  while (k <= i){
	    aux1 = d + i - 1;
	    temp = *aux1;
	    aux1 = d + i - 1 + strlen(s);
	    *aux1 = temp;
	    i--;
	    
	  }
	  i = strlen(s);
	  while(k<=i){
	    aux1 = s + i -1;
	    temp = *aux1;
	    aux1 = d + i -1;
	    *aux1 = temp;
	    i--;
	  }
}


