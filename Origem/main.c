#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "Bibli.h"
#include "Struct.c"

int main(){ 
    Baralho B = cria();
    Baralho C = cria();
    Baralho D = cria();
    lista Ci;
    lista Cf;
    lista R;
    int i, qtd, corte;
    printf("\nBaralho:\n");
    B = Embaralha(B);
    imprime(B); 

        printf("\n\nInforme a posicao do Primeiro Corte: ");
        scanf("%d", &corte);    
        C = cortar(B, corte);
        printf("\nBaralho depois de cortado em %d\n", corte);
        imprime(C);
        
        printf("\n\nInforme a posicao do Segundo Corte: ");
        scanf("%d", &corte);
        C = cortar(C, corte);
        printf("\n\nBaralho depois de cortado em %d\n", corte);
        imprime(C);
   
    fflush(stdin);
    getchar();   
}
