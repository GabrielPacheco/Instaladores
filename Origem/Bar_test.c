#include <stdio.h>
#include <stdlib.h>
#include "Struct.c"
#include "Bar_test.h"

int tests_run = 0;

/*!Conta quantas cartas existem em determinado baralho.
 *@param B - Baralho a ser feita a contagem.
 */
int tamanho_baralho(Baralho B){
    int tamanho = 0;
    while (B != NULL){
        B = B->prox;
        tamanho++;
    }
    return tamanho;
}

/*!Testa a função de embaralhar.*/
static char * test_embaralhar() {

    Baralho B = Embaralha(0);
    Baralho aux = B;
    int cartas[10];
    char naipes [10];
    int i, cont=0;

    mu_assert("FUNCAO embaralhar - Erro ao embaralhar. O baralho ficou nulo.", B != NULL);
    mu_assert("FUNCAO embaralhar - Erro ao embaralhar. O baralho nao contem 52 cartas.", tamanho_baralho(B) == 52);

    for (i=0; i<5; i++){

        cartas[i]=aux->carta;
        naipes[i]=aux->naipe;

        aux=aux->prox;
    }

    B = Embaralha(B);

    mu_assert("FUNCAO embaralhar - Erro ao embaralhar. Depois de outra embaralhada o baralho nao ficou com 52 cartas", tamanho_baralho(B) == 52);

    aux=B;

    for (i=0; i<10; i++){

        if ((cartas[i]==aux->carta) && (naipes[i]==aux->naipe)){

            cont++;
        }
        aux=aux->prox;
    }

    mu_assert("FUNCAO embaralhar - Erro ao embaralhar. As cartas nao foram embaralhadas corretamente", cont<7);

    return 0;
}



/*!Aqui são chamados os testes*/
static char * testes() {

    mu_run_test(test_embaralhar);

    return 0;
}

int main() {

    char *result = testes();

    if (result != 0) {
        printf("%s\n", result);
    }

    else {
        printf("\nTODOS OS TESTES FORAM APROVADOS\n");
    }
    printf("Testes: %d\n", tests_run);

    return result != 0;
}
