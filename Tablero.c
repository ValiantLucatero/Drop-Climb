#include <stdio.h>
#include <cstdlib>
#include <time.h>

int dados();

main(){
    int pos=0,n;
    bool band=true;
    srand(time(NULL));
    
    char tablero[10][10];
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            tablero[i][j]=0;
        }
    }
    
    
    
    while(band==true){
        pos+=dados();
        if(pos>=100){
            band=false;
            printf("\n¡Ganaste!");
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
        
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                printf("%d\t",tablero[i][j]);
        }
        printf("\n");
    }}
           
}

}


int dados(){
    int d=rand()%6+1;
    return d;
}