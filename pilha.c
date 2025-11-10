#include <stdlib.h>
#include "pilha.h"

/*
 * Implementacao das funcoes da TAD pilha
 * Autor:
 *    Jean Pablo Lopes Teixeira
 *
 * Versao 1.0.0 de 25/09/2023
*/

struct pilha *pilha_cria ()
{
	struct pilha *p = malloc(sizeof(struct pilha));

    /* Testa se o malloc deu certo */ 
    if (p == NULL) 
        return NULL;

    /* Inicializa o topo e tamanho da pilha para poder retorna-la */
    p->topo = NULL;
    p->tamanho = 0;
    
    return p;
}

void pilha_destroi (struct pilha **pilha)
{
	/* Verifica se a pilha ja foi criada */
    if (*pilha == NULL) 
        return;

    /* Ponteiro para receber o dado do topo da pilha e ir desalocando
    sua memoria no 'For' ate 'atual' ser NULL */
    struct nodo *atual;
    
    for (atual = (*pilha)->topo; atual != NULL; atual = (*pilha)->topo) 
    {
        (*pilha)->topo = atual->prox;
        free(atual);
    }
    
    /* Libera a memoria da pilha em si e depois recebe NULL para aterra-la */
    free(*pilha);
    *pilha = NULL;
}

int push (struct pilha *pilha, int dado)
{
	/* Ponteiro para assumir o dado */
    struct nodo *novoNodo = malloc(sizeof(struct nodo));

    /* Testa se o malloc deu certo */ 
    if (novoNodo == NULL)  
        return 0;

	/* Insercao do novo dado no topo e aumento do tamanho da pilha */
    novoNodo->chave = dado;
    novoNodo->prox = pilha->topo;
    pilha->topo = novoNodo;
    pilha->tamanho++;

    return 1;
}

int pop (struct pilha *pilha, int *dado)
{
	/* Ponteiro para o assumir o topo atual da pilha */
    struct nodo *topo = pilha->topo;

    /* Verfica se a pilha tem topo */
    if (topo == NULL) 
        return 0;

	/* Parametro dado assumindo o valor da chave e remocao da chave da pilha */
    *dado = topo->chave;
    pilha->topo = topo->prox;
    pilha->tamanho--;
    free(topo);

    return 1;
}

int pilha_topo (struct pilha *pilha, int *dado)
{
	/* Verfica se a pilha tem topo */
    if (pilha->topo == NULL) 
        return 0;

    *dado = pilha->topo->chave;

    return 1;
}
 

int pilha_tamanho (struct pilha *pilha)
{
	return pilha->tamanho;
}

int pilha_vazia (struct pilha *pilha)
{
	if (pilha->tamanho == 0)
		return 1;
	
	return 0;
}
