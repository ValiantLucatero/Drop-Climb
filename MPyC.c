#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Usuarios.c>


void menuprin()
{
	char opc=' ';
	int band=1;
	while(band==1)
	{
		fflush(stdin);
		printf("\nSelecciona una opcion: \n1.-Entrar\n2.-Registrar\n3.-Lista de Usuarios\n4.-Salir");
		scanf("%c",&opc);
		fflush(stdin);
		if(opc=='1')
			printf("Aquí va el juego");
		else if(opc=='2')
			agregar();
		else if(opc=='3')
			find();
		else if(opc=='4')
			exit(0);
	}
}

void creditos()
{
	char c=' ';
	printf("SERPIENTES Y ESCALERAS DELUXE EDITION SEASON PASS");
	printf("\nCreado por:\nJorge Goytia\nAndres Lucatero\nDiego Mendez\nCassiel Ortega\nGabriel Villanueva");
	printf("\n\n\n\n2017(c)\nPresiona enter para continuar");
	while(c==' ')
		scanf("%c",&c);
	menuprin();
}

int main()
{
	creditos();
	return 0;
}
