#include<stdio.h>
#include<stdlib.h>
#include <string.h>



struct U{
  char nom[30];
  int JG;
  int JP;
  int JJ;};
  struct U Us[100];

  void agregar();
  void find();
  char nomb[30],con[30];
  int b;
  int i;


main () {
  do{
  system("cls");
  printf("¿Que deseas hacer?\n");
  printf("1. Agregar usuario nuevo\n");
  printf("2. Ver Lista de Usuarios\n");
  printf("3.Salir\n");
  int op;
  printf("Escoge una opcion: ");
  scanf("%d",&op );
  switch (op) {
    case 1: agregar();
            break;
    case 2: find();
      break;
    case 3:
          system("cls");

          printf("Adios");
          break;
    default:
          system("cls");
          printf("Opcion no valida");
        }
    printf("¿Quieres Salir? 1=SI/0=NO \n");
    scanf("%d", &i);
  }while (i==0);
    }

void agregar(){
  system("cls");
  FILE *ap;
  ap=fopen("usuarios.txt","at");
  printf("Dame un nombre para el registro : ");
  fflush(stdin);
  for (int i=0; i<1;i++){
  gets(Us[i].nom);
  fputs(Us[i].nom,ap);
  Us[i].JJ=0; Us[i].JG=0;  Us[i].JP=0;
  fprintf(ap," %d %d %d\n",Us[i].JJ, Us[i].JG,  Us[i].JP );
  fclose(ap);}

  printf("\nUsuario Generado con exito!\n");
  system("pause");
  system("cls");
}

void find(){

  system("cls");
  FILE *ap;
  ap=fopen("usuarios.txt","r");
  printf("A quien buscas :  ");
  fflush(stdin);
  gets(nomb);

    while(feof(ap)==NULL){
    for (int i=0;i<feof(ap);i++){
    fscanf(ap,"%s",Us[i].nom);
    if(strcmp(Us[i].nom,nomb)==0){
      fscanf(ap,"%i",Us[i].JJ);
      fscanf(ap,"%i",Us[i].JG);
      fscanf(ap,"%i",Us[i].JP);}}
    }

    printf("Hola %s , Tinenes Juegos jugados %i, ganados %i, perdidos %i  \n",Us[i].nom,Us[i].JJ,Us[i].JG,Us[i].JP);
}
