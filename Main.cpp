#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Usuarios.cpp"

void menuprin();
void creditos();
void rellenar();
void imprimir();
int dados();
char tablero[10][10];

main()
{
	srand(time(NULL));
	creditos();
	menuprin();
}

int dados(){
    int d=rand()%6+1;
    return d;
}

void menuprin(){
	char opc=' ';
	int band=1;
	system("cls");
	while(band==1)
	{
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
			find();
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
	system("cls");	
}

    

void imprimir(){
	bool band=true;
	int i, j, n, pos=0;
	while(band==true){
        pos+=dados();
        if(pos>=100){
            band=false;
            printf("\n¡Ganaste!\n");
        } 
        
        else{
			printf("Estás es %d\n",pos);
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
	system("pause");
    rellenar();
	}
}

