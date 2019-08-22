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


    return res >> ((sizeof(uint)<<3) - (k-nbits));
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

int main(int argc, char **argv) {
  // Parte a
  // int a[]= { 0b100 110 101 011 000, 0b101 101 011, 0b001 010 000 };
  uint a[]= { 046530, 0553, 0120 };
  uint r= comprimir(a, 9);
  if (r!=0530553120) {
    fprintf(stderr, "resultado incorrecto %o\n", r);
    exit(1);
  }
  // Parte b
  char *s1= insercion("perro", "gato");
  if (strcmp(s1, "gatoperro")!=0) {
    fprintf(stderr, "resultado incorrecto %s\n", s1);
    exit(1);
  }
  char *s2= insercion("", "gato");
  if (strcmp(s2, "gato")!=0) {
    fprintf(stderr, "resultado incorrecto %s\n", s2);
    exit(1);
  }
  char *s3= insercion("perro", "");
  if (strcmp(s3, "perro")!=0) {
    fprintf(stderr, "resultado incorrecto %s\n", s3);
    exit(1);
  }
  // Parte c
  char d[80]= "*perro"; // d es un arreglo de 80 bytes con el string "perro"
  d[strlen("*gatoperro")+1]='/';
  insertar(d+1, "gato"); // d es el string "gatoperro"
  if (strcmp(d+1, "gatoperro")!=0) {
    fprintf(stderr, "resultado incorrecto %s\n", d);
    exit(1);
  }
  if (d[0]!='*' || d[strlen("*gatoperro")+1]!='/') {
    fprintf(stderr, "escribio fuera del string de destino\n");
    exit(1);
  }

  printf("Bien, felicitaciones\n");
  return 0;
}
