#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Usuarios.c"

int j=0, p1=0, p2=0, p3=0, p4=0;
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
	printf("\nCuantos jugadores son?\n1.-Solo Mode (Testeo)\n2.-Dos jugadores\n3.-Tres jugadores\n4.-Cuatro jugadores\n");
	scanf("%d",&opc);
		if(opc==1){
			rellenar();
			while(p1<100){
				j1();rellenar();
			}
				printf("j1 es el ganador\nY tambien el perdedor :(");
		}
		else if(opc==2){
			rellenar();
			while(p1<100 && p2<100){
				j1();j2();rellenar();
			}
			if (p1>=100)
				printf("j1 es el ganador");
	
			if (p2>=100)
				printf("j2 es el ganador");			
		}
		else if(opc==3){
			rellenar();
			while(p1<100 && p2<100 && p3<100){
				j1();j2();j3();rellenar();
			}
			if (p1>=100)
				printf("j1 es el ganador");
	
			if (p2>=100)
				printf("j2 es el ganador");			
			
			if (p3>=100)
				printf("j3 es el ganador");
		}
		else if(opc==4){
			rellenar();
			while(p1<100 && p2<100 && p3<100 && p4<100){
				j1();j2();j3();j4();rellenar();
			}
			if (p1>=100)
				printf("j1 es el ganador");
	
			if (p2>=100)
				printf("j2 es el ganador");			
			
			if (p3>=100)
				printf("j3 es el ganador");
			
			if (p4>=100)
				printf("j4 es el ganador");
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
	//system("clear");
}

void j1(){
	printf("\nJugador 1:\n");
	p1=posicion(p1);
	imprimir(p1);
	
}

void j2(){
	printf("\nJugador 2:\n");
	p2=posicion(p2);
	imprimir(p2);	
}

void j3(){
	printf("\nJugador 3:\n");
	p3=posicion(p3);
	imprimir(p3);	
}
 
void j4(){
	printf("\nJugador 4:\n");
	p4=posicion(p4);
	imprimir(p4);	
}
    
int posicion(int x){
	int dad=dados();
	printf("\nPosicion original: %d",x);
	printf("\nDado: %d",dad);
	printf("\nAhora estas en: %d\n",x+dad);
	x+=dad;
	x=serp(x);
	x=esc(x);
	return x;
}

void imprimir(int x){
	bool band=true;
	int i, j, n;
	for(i=0;i<j;i++){
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
	}
	system("pause");
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
