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

void agregar()
{
  //system("cls"); //windows
  system("clear"); //unix
  FILE *ap;
  ap=fopen("usuarios.txt","at");
  printf("Dame un nombre para el registro : ");
  fflush(stdin);
  for (int i=0;i<1;i++){
	  //gets(Us.nom); //está en desuso
    scanf("%s",Us.nom);
	  fputs(Us.nom,ap);
	  Us.JJ=0; Us.JG=0;  Us.JP=0;
	  fprintf(ap," %d %d %d\n",Us.JJ, Us.JG,  Us.JP );
	  fclose(ap);
  }
  printf("\nUsuario Generado con exito!\n");
  system("pause");
  //system("cls"); //windows
  system("clear"); //unix
}

void find()
{
  int b=0;
  //system("cls"); //windows
  system("clear"); //unix
  FILE *ap;
  ap=fopen("usuarios.txt","rt");
  printf("A quien buscas :  ");
  fflush(stdin);
  //gets(nomb); //está en desuso
  scanf("%s",nomb);
  fflush(stdin);
  while(!feof(ap))
  {
    fscanf(ap,"%s",&Us.nom);
    if(strcmp(nomb,Us.nom)==0)
    {
      fscanf(ap,"%d",&Us.JJ);
      fscanf(ap,"%d",&Us.JG);
      fscanf(ap,"%d",&Us.JP);
      printf("Hola %s, Tienes Juegos jugados %i, ganados %i, perdidos %i  \n",Us.nom,Us.JJ,Us.JG,Us.JP);
      b=1;
	    break;
	  }

  }
  if(b==0)
  printf("Usuario no registrado :(\n");
}
