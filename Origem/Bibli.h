#ifndef BIBLI_H
#define BIBLI_H

//EMBARALHA

typedef struct nodo {

    int carta;// armazena uma carta (seu respectivo número).
    char naipe;// armazena um nipe.
    struct nodo *prox;// apontador para o próximo nó.

}lista;

typedef lista* Baralho;// Lista que representa um baralho.

extern Baralho cria(void);
extern Baralho Embaralha(Baralho B);
extern int verifica_Carta(Baralho B, int carta, int naipe);
extern Baralho insere_Carta(Baralho B, int carta, int naipe);
extern void imprime(Baralho B);

//RETIRA
extern lista retira_inicio (Baralho* B);
extern lista retira_final (Baralho* B);
extern void retiraInicio_insereFim(Baralho *B);

//DESCARTA
extern Baralho atualizaDescarte (Baralho D);
extern Baralho insereCartaDescarte(Baralho D, int carta, char naipe);

// CORTA
extern Baralho cortar (Baralho B, int pos);
extern void insere_aux(Baralho* A, int carta, char naipe);

#endif
