#ifndef LISTA_PESSOA_H
#define LISTA_PESSOA_H

typedef struct lista_pessoa ListaPessoa;

#include "pessoa.h"

/*  Inicializa uma lista encadeada de pessoas 
    input:
    output:
    pré-condição:
    pós-condição:
*/
ListaPessoa* iniciaListaPessoa();

/*  Busca uma pessoa dentro de uma lista de pessoas
    input: 
    output: A pessoa, se encontrada; NULL, caso contrário.
    pré-condição:
    pós-condição:
*/
Pessoa* buscaPessoa(ListaPessoa* lista, char* chave); 

/*  Insere uma célula pessoa em uma lista encadeada de pessoas
    input:
    output:
    pré-condição:
    pós-condição:
*/
void insereListaPessoa(ListaPessoa* lista, Pessoa* p);

/*  Preenche uma lista de pessoas com todas as pessoas definidas no arquivo de entrada
    input:
    output:
    pré-condição:
    pós-condição:
*/
void preencheListaPessoa(ListaPessoa* lista);

/*  Faz a refatoração da lista de playlists de todas as pessoas em uma lista de pessoas
    input:
    output:
    pré-condição:
    pós-condição:
*/
void refatoraListaPlaylistPessoa(ListaPessoa* lista_p);

/*  Contabiliza as similaridades de músicas entre amigos e gera/preenche o arquivo similaridades.txt
    input:
    output:
    pré-condição:
    pós-condição:
*/
void similaridadePlaylistAmigo(ListaPessoa* lista);


void imprimeListaPessoa(ListaPessoa* lista); //não precisa


/*  Libera toda a memória alocada para uma lista de pessoas
    input:
    output:
    pré-condição:
    pós-condição:
*/
void destroiListaPessoa(ListaPessoa* lista);

/*  Libera a memória alocada para a lista que guarda as pessoas "repetidas"
    input:
    output:
    pré-condição:
    pós-condição:
*/
void destroiListaRepetidos(ListaPessoa* lista);

#endif