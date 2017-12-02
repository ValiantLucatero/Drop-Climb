#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct U
{
  char nom[30];
  int JG;
  int JP;
  int JJ;
};
  struct U Us;
  void agregar();
  void find();
  char nomb[30];
  int b;
  int i;


/*int main (){
  do
  {
    int op=0;
    system("cls");
    printf("¿Que deseas hacer?\n");
    printf("1. Agregar usuario nuevo\n");
    printf("2. Ver Lista de Usuarios\n");
    printf("3.Salir\n");
    printf("Escoge una opcion: ");
    scanf("%d",&op );
    switch (op)
    {
      case 1: agregar();
        break;
      case 2: find();
        break;
      case 3:
        system("cls");
        printf("Adios");
        break;
      default:
        //system("cls");
        //printf("Opcion no valida");
        break;
    }
    printf("\n¿Quieres Salir? 1=SI/0=NO \n");
    scanf("%d", &i);
  }while (i==0);
  return 0;
}*/

void agregar()
{
  system("cls");
  FILE *ap;
  ap=fopen("usuarios.txt","at");
  printf("Dame un nombre para el registro : ");
  fflush(stdin);
  for (int i=0; i<1;i++)
  {
  gets(Us.nom);
  fputs(Us.nom,ap);
  Us.JJ=0; Us.JG=0;  Us.JP=0;
  fprintf(ap," %d %d %d\n",Us.JJ, Us.JG,  Us.JP );
  fclose(ap);
  }
  printf("\nUsuario Generado con exito!\n");
  system("pause");
  system("cls");
}

void find()
{
  int b=0;
  system("cls");
  FILE *ap;
  ap=fopen("usuarios.txt","rt");
  printf("A quien buscas :  ");
  fflush(stdin);
  gets(nomb);

  while(!feof(ap))
  {
    fscanf(ap,"%s",&Us.nom);
    if(strcmp(nomb,Us.nom)==0)
    {
      fscanf(ap,"%d",&Us.JJ);
      fscanf(ap,"%d",&Us.JG);
      fscanf(ap,"%d",&Us.JP);
      printf("Hola %s, Tinenes Juegos jugados %i, ganados %i, perdidos %i  \n",Us.nom,Us.JJ,Us.JG,Us.JP);
      b=1;
    }

  }
  if(b==0)
  printf("usuario no registrado \n");
}
