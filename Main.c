#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Usuarios.c"

int j=0, p1=0, p2=0, p3=0, p4=0;
char n1[256],n2[256],n3[256],n4[256];
void menuprin();
void menujug();
void creditos();
void rellenar();
void imprimir();
int dados();
char tablero[10][10];
int posicion(int x);
void imprimir(int x);
void j1(); void j2(); void j3(); void j4();
int serp(int x);
int esc(int x);
void mostrar();
void ganadorN(char g[256]);
void perdedorN(char j[256]);

int main()
{
	srand(time(NULL));
	creditos();
	menuprin();
	return 0;
}

int dados(){
    int d=rand()%6+1;
    return d;
}

void menuprin(){
	char opc=' ';
	int band=1;
	while(band==1)
	{
		//system("cls"); //windows
		system("clear"); //unix
		fflush(stdin);
		printf("\nSelecciona una opcion: \n1.-Jugar\n2.-Log in\n3.-Lista de Usuarios\n4.-Salir\n");
		scanf("%c",&opc);
		fflush(stdin);
		if(opc=='1')
		{
			menujug();
		}

		else if(opc=='2')
			agregar();
		else if(opc=='3')
		{
			find();
			getchar();
		}
		else if(opc=='4')
			exit(0);
	}
}

void menujug(){
	int opc;
	printf("\nCuantos jugadores son?\n1.-Solo Mode\n2.-Dos jugadores\n3.-Tres jugadores\n4.-Cuatro jugadores\n");
	scanf("%d",&opc);
		if(opc==1)
		{
			printf("Nombre del jugador 1? ");
			getchar();
			fgets(n1,256,stdin);
			n1[strcspn(n1, "\n")]=0; //quita el enter del fgets
			rellenar();
			p1=0;
			while(p1<100)
			{
				j1();
				rellenar();
			}
			printf("%s es el ganador! Y tambien el perdedor :,(",n1);
			ganadorN(n1);
		}
		else if(opc==2){
			printf("Nombre del jugador 1? ");
			getchar();
			fgets(n1,256,stdin);
			n1[strcspn(n1, "\n")]=0;
			printf("\nNombre del jugador 2? ");
			fgets(n2,256,stdin);
			n2[strcspn(n2, "\n")]=0;
			rellenar();
			p1=0;
			p2=0;
			while(p1<100 && p2<100)
			{
				rellenar();
				j1();
				j2();
				
			}
			if (p1>=100){
				printf("%s es el ganador",n1);
				ganadorN(n1);
				perdedorN(n2);
			}
				

			if (p2>=100){
				printf("%s es el ganador",n2);
				ganadorN(n2);
				perdedorN(n1);
			}
		}
		else if(opc==3){
			printf("Nombre del jugador 1? ");
			getchar();
			fgets(n1,256,stdin);
			n1[strcspn(n1, "\n")]=0;
			printf("\nNombre del jugador 2? ");
			fgets(n2,256,stdin);
			n2[strcspn(n2, "\n")]=0;
			printf("\nNombre del jugador 3? ");
			fgets(n3,256,stdin);
			n3[strcspn(n3, "\n")]=0;
			rellenar();
			p1=0;
			p2=0;
			p3=0;
			while(p1<100 && p2<100 && p3<100)
			{
				rellenar();
				j1();
				j2();
				j3();
			}
			if (p1>=100){
				printf("%s es el ganador",n1);
				ganadorN(n1);
				perdedorN(n2);
				perdedorN(n3);
			}
				

			if (p2>=100){
				printf("%s es el ganador",n2);
				ganadorN(n2);
				perdedorN(n1);
				perdedorN(n3);
			}
				

			if (p3>=100){
				printf("%s es el ganador",n3);
				ganadorN(n3);
				perdedorN(n1);
				perdedorN(n2);
			}
		}
		else if(opc==4){
			printf("Nombre del jugador 1? ");
			getchar();
			fgets(n1,256,stdin);
			n1[strcspn(n1, "\n")]=0;
			printf("\nNombre del jugador 2? ");
			fgets(n2,256,stdin);
			n2[strcspn(n2, "\n")]=0;
			printf("\nNombre del jugador 3? ");
			fgets(n3,256,stdin);
			n3[strcspn(n3, "\n")]=0;
			printf("\nNombre del jugador 4? ");
			fgets(n4,256,stdin);
			n4[strcspn(n4, "\n")]=0;
			rellenar();
			p1=0;
			p2=0;
			p3=0;
			p4=0;
			while(p1<100 && p2<100 && p3<100 && p4<100)
			{
				rellenar();
				j1();
				j2();
				j3();
				j4();
			}
			if (p1>=100){
				printf("%s es el ganador",n1);
				ganadorN(n1);
				perdedorN(n2);
				perdedorN(n3);
				perdedorN(n4);				
			}
			
			if (p2>=100){
				printf("%s es el ganador",n2);
				ganadorN(n2);
				perdedorN(n1);
				perdedorN(n3);
				perdedorN(n4);	
			}
				
			if (p3>=100){
				printf("%s es el ganador",n3);
				ganadorN(n3);
				perdedorN(n2);
				perdedorN(n1);
				perdedorN(n4);	
			}
				

			if (p4>=100){
				printf("%s es el ganador",n4);
				ganadorN(n4);
				perdedorN(n2);
				perdedorN(n3);
				perdedorN(n1);	
			}
		}
}

void creditos(){
	char c=' ';
	printf("SERPIENTES Y ESCALERAS DELUXE EDITION SEASON PASS");
	printf("\n\tCreado por:\n\tJorge Goytia\n\tAndres Lucatero\n\tDiego Mendez\n\tCassiel Ortega\n\tGabriel Villanueva");
	printf("\n\n\t2017(c)\nPresiona enter para continuar... ");
	while(c==' ')
		scanf("%c",&c);
}

void rellenar(){
	int i, j;
	for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            tablero[i][j]=(9-i)*10+j+1;
        }
    }
	//system("cls");
	system("clear");
}

void j1(){
	printf("\n%s: \n",n1);
	p1=posicion(p1);
	imprimir(p1);

}

void j2(){
	printf("\n%s: \n",n2);
	p2=posicion(p2);
	imprimir(p2);
}

void j3(){
	printf("\n%s: \n",n3);
	p3=posicion(p3);
	imprimir(p3);
}

void j4(){
	printf("\n%s: \n",n4);
	printf("\nJugador 4:\n");
	p4=posicion(p4);
	imprimir(p4);
}
int posicion(int x){
	int dad=dados();
	printf("\nPosicion original: %d",x);
	printf("\nDado: %d",dad);
	if(x+dad>=100){
		printf("\nAhora estas en: %d\n",100);
		x=100;
		return x;
	}
	else{
		printf("\nAhora estas en: %d\n",x+dad);
		x+=dad;
		x=serp(x);
		x=esc(x);
		return x;		
	}
}

void imprimir(int x){
	int i, j, n;
		n=x;
        int m=0;
        while(n>10){
            n-=10;
            m++;
        }
        if(n==0){
            n=9;m++;
        }
	    tablero[9-m][n-1]=1;
		for(i=0;i<10;i++){
	    	for(j=0;j<10;j++){
	    		if(i==9-m && j==n-1)
						printf("\x1b[31m%c\x1b[0m\t",77);
				else
        		printf("%d\t",tablero[i][j]);
	        }
		printf("\n");
		}

	getchar();
}

int serp(int x){
	if(x==18 || x==22 ||x==36||x==62||x==75||x==78||x==83||x==93||x==96)
		printf("\nMala suerte, caíste en una serpiente\n");

	if (x==18){
		printf("\nAhora estás en 6\n");
		return 6;
	}

	else if (x==22){
		printf("\nAhora estás en 2\n");
		return 2;
	}
	else if (x==36){
		printf("\nAhora estás en 20\n");
		return 20;
	}

	else if (x==62){
		printf("\nAhora estás en 14\n");
		return 14;
	}

	else if (x==75){
		printf("\nAhora estás en 30\n");
		return 30;
	}


	else if (x==78){
		printf("\nAhora estás en 49\n");
		return 49;
	}

	else if (x==83){
		printf("\nAhora estás en 8\n");
		return 8;
	}

	else if (x==93){
		printf("\nAhora estás en 40\n");
		return 40;
	}
	else if (x==96){
		printf("\nAhora estás en 69 UwU\n");
		return 69;
	}

	else
		return x;

}

int esc(int x){
	if(x==11 || x==17 ||x==19||x==21||x==26||x==43||x==52||x==70||x==74)
		printf("\nBuena suerte, subiste por una escalera\n");

	if (x==11){
		printf("\nAhora estás en 39\n");
		return 39;
	}

	else if (x==17){
		printf("\nAhora estás en 67\n");
		return 67;
	}
	else if (x==19){
		printf("\nAhora estás en 45\n");
		return 45;
	}

	else if (x==21){
		printf("\nAhora estás en 56\n");
		return 56;
	}

	else if (x==26){
		printf("\nAhora estás en 50\n");
		return 50;
	}


	else if (x==43){
		printf("\nAhora estás en 84\n");
		return 84;
	}


	else if (x==52){
		printf("\nAhora estás en 76\n");
		return 76;
	}

	else if (x==70){
		printf("\nAhora estás en 92\n");
		return 92;
	}

	else if (x==74){
		printf("\nAhora estás en 100\n");
		return 100;
	}

	else
		return x;
}

void ganadorN(char g[256]){
  	int b=0;
  	FILE *ap;
	ap=fopen("usuarios.txt","w+");
    while(!feof(ap))
    {
      fscanf(ap,"%s",&Us.nom);
      if(strcmp(g,Us.nom)==0)
      {
        fscanf(ap,"%d",&Us.JJ);
        fscanf(ap,"%d",&Us.JG);
        fscanf(ap,"%d",&Us.JP);
        fprintf(ap,"%s %d %d %d\n",g,Us.JJ+1,Us.JG+1,Us.JP);
        b=1;
	      break;
	    }
    }
    if(b==0){
    	fprintf(ap,"%s %d %d %d\n",g,1,1,0);
	}
  	fclose(ap);
}
  
void perdedorN(char j[256]){
    int b=0;
  	FILE *ap;
	ap=fopen("usuarios.txt","w+");
    while(!feof(ap))
    {
      fscanf(ap,"%s",&Us.nom);
      if(strcmp(j,Us.nom)==0)
      {
        fscanf(ap,"%d",&Us.JJ);
        fscanf(ap,"%d",&Us.JG);
        fscanf(ap,"%d",&Us.JP);
        fprintf(ap,"%s %d %d %d\n",j,Us.JJ+1,Us.JG,Us.JP+1);
        b=1;
	      break;
	    }
    }
    if (b==0){
    	fprintf(ap,"%s %d %d %d\n",j,1,0,1);
	}
  	fclose(ap);
}
