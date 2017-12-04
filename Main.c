#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Usuarios.c"

void menuprin();
void creditos();
void rellenar();
void imprimir();
int dados();
char tablero[10][10];

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
		if(opc=='1'){
			rellenar();
			imprimir();
		}

		else if(opc=='2')
			agregar();
		else if(opc=='3')
		{
			b=0;
			find();
			getchar();
			b=1;
		}
		else if(opc=='4')
			exit(0);
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
	//system("cls"); //windows
	system("clear"); //unix
}



void imprimir(){
	int band=1;
	int i, j, n, pos=0;
	while(band==1)
	{
        pos+=dados();
        if(pos>=100){
            band=0;
            printf("\nGanaste!\n");
        }

        else{
			printf("Estas en %d\n",pos);
	        n=pos;
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
            printf("%d\t",tablero[i][j]);
    	}
    	printf("\n");
    	}
		}
		getchar();
    rellenar();
	}
}
