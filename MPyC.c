#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menuprin(){
	char opc=' ';
	int band=1;
	while(band==1){
		fflush(stdin);
		printf("\nSelecciona una opcion: \n1.-Entrar\n2.-Registrar\n3.-Salir\n");
		scanf("%c",&opc);
		fflush(stdin);
		if(opc=='1'){
			int main(); //Aqui va el inicio de sesion de Carter
		}
		else if(opc=='2'){
			printf("Te estamos esperando, Carter...");
		}
		else if(opc=='3'){
			exit(0);
		}
	}
}

void creditos(){
	char c=' ';
	printf("SERPIENTES Y ESCALERAS DELUXE EDITION SEASON PASS");
	printf("\nCreado por:\nJorge Goytia\nAndres Lucatero\nDiego Mendez\nCassiel Ortega\nGabriel Villanueva");
	printf("\n\n\n\n2017(c)\nPresiona enter para continuar");
	while(c==' '){
		scanf("%c",&c);
	}
	menuprin();
}

int main()
{
		creditos();
		return 0;
}
