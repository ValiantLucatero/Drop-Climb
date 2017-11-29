#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>


void menuprin();
void creditos();

main(){
	creditos();
	
}

void creditos(){
	char c=' ';
	printf("SERPIENTES Y ESCALERAS DELUXE EDITION SEASON PASS");
	printf("\nCreado por:\nJorge Goytia\nAndres Lucatero\nDiego Mendez\nCassiel Ortega\nGabriel Villanueva");
	printf("\n\n\n\n2017(c)\nPresiona cualquier tecla para continuar");
	while(c==' '){
		scanf("%c",&c);		
	}
	menuprin();
}



void menuprin(){
	char opc=' ';
	bool band=true;
	while(band==true){
		fflush(stdin);
		printf("\nSelecciona una opcion: \n1.-Jugar\n2.-Estadisticas\n3.-Salir\n");
		scanf("%c",&opc);
		fflush(stdin);
		if(opc=='1'){
			main();
		}
		else if(opc=='2'){
			printf("Te estamos esperando, Carter...");
		}
		else if(opc=='3'){
			exit(0);
		}			
	}
}
