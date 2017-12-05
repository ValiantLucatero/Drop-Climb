#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Usuarios.c"
void mostrar();
main (){
  mostrar();
}
void mostrar(){
  int c;
  FILE *ap;
  ap=fopen("usuarios.txt","rt");

  if(ap==NULL){
    printf(" No se puede mostar el archivo\n");

  }
  while((c=fgetc(ap))!=EOF){
    if(c=='\n'){
      printf("\n");
    }
    else {
      putchar(c);
    }
  }
}
