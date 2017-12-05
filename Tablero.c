#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dados();

int main(){
    int pos=0,n;
    int band=1;
    srand(time(NULL));

    char tablero[10][10];

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            tablero[i][j]=0;
        }
    }



    while(band==1){
        pos+=dados();
        if(pos>=100){
            band=0;
            printf("\n¡Ganaste!");
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

        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                printf("%d\t",tablero[i][j]);
        }
        printf("\n");
    }}

}
return 0;
}


int dados(){
    int d=rand()%6+1;
    return d;
}
