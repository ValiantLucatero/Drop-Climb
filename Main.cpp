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
int serp(int x);
int esc(int x);

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
        int dad=dados();
		printf("\nPosicion original: %d",pos);
		printf("\nDado: %d\n",dad);
		pos+=dad;
        if(pos>=100){
            band=false;
            printf("\n�Ganaste!\n");
        } 
        
        else{
			printf("Est�s es %d\n",pos);
			pos=serp(pos);
			pos=esc(pos);
			
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

int serp(int x){
	if(x==18 || x==22 ||x==36||x==62||x==75||x==78||x==83||x==93||x==96)	
		printf("\nMala suerte, ca�ste en una serpiente\n");
	
	if (x==18){
		printf("\nAhora est�s en 6\n");
		return 6;
	}
		
	else if (x==22){
		printf("\nAhora est�s en 2\n");
		return 2;
	}
	else if (x==36){
		printf("\nAhora est�s en 20\n");
		return 20;
	}
		
	else if (x==62){
		printf("\nAhora est�s en 14\n");
		return 14;
	}
		
	else if (x==75){
		printf("\nAhora est�s en 30\n");	
		return 30;
	}
		
	
	else if (x==78){
		printf("\nAhora est�s en 49\n");
		return 49;
	}
		
	else if (x==83){
		printf("\nAhora est�s en 8\n");
		return 8;
	}
		
	else if (x==93){
		printf("\nAhora est�s en 40\n");
		return 40;
	}
	else if (x==93){
		printf("\nAhora est�s en 69 UwU\n");
		return 40;
	}
		
	else
		return x;
		
}

int esc(int x){
	if(x==11 || x==17 ||x==19||x==21||x==26||x==43||x==52||x==70||x==74)	
		printf("\nBuena suerte, subiste por una escalera\n");
	
	if (x==11){
		printf("\nAhora est�s en 39\n");
		return 39;
	}
		
	else if (x==17){
		printf("\nAhora est�s en 67\n");
		return 67;
	}
	else if (x==19){
		printf("\nAhora est�s en 45\n");
		return 45;
	}
		
	else if (x==21){
		printf("\nAhora est�s en 56\n");
		return 56;
	}
		
	else if (x==26){
		printf("\nAhora est�s en 50\n");	
		return 50;
	}
		
	
	else if (x==43){
		printf("\nAhora est�s en 84\n");
		return 84;
	}
		
		
	else if (x==52){
		printf("\nAhora est�s en 76\n");
		return 76;
	}
	
	else if (x==70){
		printf("\nAhora est�s en 92\n");
		return 92;
	}
	
	else if (x==74){
		printf("\nAhora est�s en 100\n");
		return 100;
	}
		
	else
		return x;
		
}
