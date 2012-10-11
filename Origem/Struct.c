#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "Bibli.h"

Baralho cortar(Baralho B, int pos){

        int i;
        Baralho aux = B;
        Baralho aux2 = cria();
        Baralho cortado = cria();

        while(i <= pos){
                insere_aux(&aux2, (aux->carta), (aux->naipe));
                aux = aux->prox;
                i++;
        }

        while(aux != NULL){
                 insere_aux(&cortado, (aux->carta), (aux->naipe));
                 aux = aux->prox;
        }

        while(aux2 != NULL){
                 insere_aux(&cortado, (aux2->carta), (aux2->naipe));
                 aux2 = aux2->prox;
        }

        return cortado;
}

void insere_aux(Baralho *A, int carta, char naipe){

        lista* novo = (lista*) malloc(sizeof(lista));

        novo->carta = carta;
        novo->naipe = naipe;

        novo->prox = NULL;

        if((*A) == NULL)

                (*A) = novo;
        else{

                lista* aux = (*A);

                while(aux->prox != NULL)
                        aux = aux->prox;
                        aux->prox = novo;
        }
}

//DESCARTE
Baralho insereCartaDescarte(Baralho D, int carta, char naipe){

        lista *aux =(lista*) malloc(sizeof (lista));

        aux->carta = carta;
        aux->naipe = naipe;
        aux->prox = D;
        return aux;
}

lista retiraDescarte (Baralho* D, int pos){

    int i = 1;
    lista carta;
    Baralho aux = cria();

   
    while ( i < pos){
        insere_aux(&aux, (*D)->carta, (*D)->naipe);

        (*D)=(*D)->prox;
        i++;
    }

    carta.carta = (*D)->prox->carta;
    carta.naipe = (*D)->prox->naipe;

    insere_aux(&aux, (*D)->carta, (*D)->naipe);

    (*D)=(*D)->prox->prox;

    while ((*D)!=NULL){

        insere_aux(&aux, (*D)->carta, (*D)->naipe);

        (*D)=(*D)->prox;
    }

    (*D)=aux;
    return carta;
}


//EMBARALHA

int verificaCarta(int carta, int naipe, Baralho B){

        Baralho aux = B;

        char n [4] = {'C', 'P', 'O', 'E'};

        while (aux != NULL){

                if ((aux->carta == carta) && (n[naipe] == aux->naipe)){

                        return 0;
                }

                else{

                        aux = aux->prox;
                }
        }

        return 1;
}

Baralho insereCarta(Baralho B, int carta, int naipe){

        char n [4] = {'C', 'P', 'O', 'E'};
        lista *aux =(lista*) malloc(sizeof (lista));

        aux->carta = carta;
        aux->naipe = n[naipe];
        aux->prox = B;

        return aux;
}

void imprime(Baralho B){

        Baralho aux = B;

        while (aux!= NULL){
                if (aux->carta < 10){
                printf("0%d-%c| \t", aux->carta, aux->naipe);
                } else
                 printf("%d-%c| \t", aux->carta, aux->naipe);
                aux = aux->prox;
        }
}

Baralho Embaralha(Baralho B){

        int cont = 0, carta, naipe, verifica;

        free(B);

        B=NULL;

        while (cont<52){

                carta = rand()%(13)+1;
                naipe = rand()%4;

                verifica = verificaCarta(carta, naipe, B);

                if (verifica == 1){

                        B = insereCarta(B, carta, naipe);

                        cont++;
                }
         }

         return B;
}

Baralho cria(void){

    return NULL;
}


//RETIRA

lista retira_inicio (Baralho* B){

        lista compra;

        compra.carta = (*B)->carta;
        compra.naipe = (*B)->naipe;

        (*B) = (*B)->prox;

        return compra;
}

lista retira_final (Baralho *B){

        lista compra;
        Baralho aux = cria();

        while ((*B) != NULL){

                compra.carta = (*B)->carta;
                compra.naipe = (*B)->naipe;

                if (((*B)->prox) == NULL){

                    break;
                }

                insere_aux(&aux, ((*B)->carta), ((*B)->naipe));

                (*B) = ((*B)->prox);
        }

        (*B) = aux;

        return compra;
}

void retiraInicio_insereFim(Baralho *B){

    lista inicio;

    inicio = retira_inicio(&(*B));

    insere_aux(&(*B), inicio.carta, inicio.naipe);
}
