#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct U
{
  char nom[30];
  int JG=0;
  int JP=0;
  int JJ=0;
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
  ap=fopen("/usuarios.txt","r");
  if(ap) //si existe...
  {
    printf("Dame un nombre para el registro: ");
    fflush(stdin);
    scanf("%s",nomb);
    getchar();
    while(!feof(ap))
    {
      fscanf(ap,"%s",Us.nom);
      if(strcmp(nomb,Us.nom)==0) //si se repite...
      {
        printf("Nombre ya registrado, selecciona otro\n" );
        fclose(ap);
        getchar();
        break;
      }
    }
    if(strcmp(nomb,Us.nom)==1) //si es unico...
    {
      fclose(ap);
      ap=fopen("/usuarios.txt","a");
      fputs(nomb,ap);
      fprintf(ap," %d %d %d\n",0,0,0);
      fclose(ap);
      printf("\nUsuario Generado con exito! Presiona enter para continuar...");
      getchar();
      //system("cls"); //windows
      system("clear"); //unix
    }
  }
  if(!ap)//si no existe...
  {
    ap=fopen("/usuarios.txt","w");
    printf("Dame un nombre para el nuevo registro: ");
    fflush(stdin);
    scanf("%s",nomb);
    getchar();
    fputs(nomb,ap);
    fprintf(ap," %d %d %d\n",0,0,0);
    fclose(ap);
    printf("\nUsuario Generado con exito! Presiona enter para continuar..");
    getchar();
    //system("cls"); //windows
    system("clear"); //unix
  }
}

void find()
{
  int b=0;
  //system("cls"); //windows
  system("clear"); //unix
  fflush(stdin);
  if(access("/usuarios.txt",F_OK)!=-1)
  {
    FILE *ap;
    ap=fopen("usuarios.txt","r");
    printf("A quien buscas :  ");
    scanf("%s",nomb);
    fflush(stdin);
    while(!feof(ap))
    {
      fscanf(ap,"%s",Us.nom);
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
  else
  {
    printf("No hay ningun usuario registrado :( Presiona enter para continuar...");
  }
  getchar();
  //system("cls"); //windows
  system("clear"); //unix
}
