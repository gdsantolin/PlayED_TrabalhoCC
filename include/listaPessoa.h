#ifndef LISTA_PESSOA_H
#define LISTA_PESSOA_H

typedef struct lista_pessoa ListaPessoa;

#include "pessoa.h"

/*  Inicializa uma lista encadeada de pessoas
    input: Nenhum
    output: Ponteiro para a lista de pessoas
    pré-condição: Nenhuma
    pós-condição: Lista de pessoas simplesmente encadeada com sentinela (vazia)
*/
ListaPessoa* iniciaListaPessoa();

/*  Busca uma pessoa dentro de uma lista de pessoas
    input: A lista de pessoas, o nome da pessoa
    output: A pessoa, se encontrada; NULL, caso contrário.
    pré-condição: Lista de pessoas está inicializada
    pós-condição: A pessoa foi encontrada caso a chave coincida
*/
Pessoa* buscaPessoa(ListaPessoa* lista, char* chave_nome); 

/*  Insere uma célula pessoa em uma lista encadeada de pessoas
    input: A lista de pessoas, a pessoa
    output: Nenhum
    pré-condição: Lista de pessoas está inicializada e pessoa existe
    pós-condição: Célula pessoa inserida na lista de pessoas
*/
void insereListaPessoa(ListaPessoa* lista, Pessoa* p);

/*  Preenche uma lista de pessoas com todas as pessoas definidas no arquivo de entrada
    input: A lista de pessoas
    output: Nenhum
    pré-condição: Lista de pessoas está inicializada
    pós-condição: Lista de pessoas foi preenchida com todas as pessoas descritas no arquivo
*/
void preencheListaPessoa(ListaPessoa* lista_pessoas);

/*  Faz a refatoração da lista de playlists de todas as pessoas em uma lista de pessoas
    input: A lista de pessoas
    output: Nenhum
    pré-condição: Lista de pessoas está inicializada
    pós-condição: Todas as listas de playlists foram refatoradas (organizadas por artista/banda)
*/
void refatoraListaPlaylistPessoa(ListaPessoa* lista_p);

/*  Contabiliza as similaridades de músicas entre amigos e gera/preenche o arquivo similaridades.txt
    input: A lista de pessoas
    output: Nenhum
    pré-condição: Lista de pessoas está inicializada
    pós-condição: Arquivo de similaridades foi preenchido para todas as relações de amizade
*/
void similaridadePlaylistAmigo(ListaPessoa* lista);

/*  Libera toda a memória alocada para uma lista de pessoas
    input: A lista de pessoas 
    output: Nenhum
    pré-condição: Lista de pessoas está inicializada
    pós-condição: A memória alocada para a lista de pessoas foi liberada
*/
void destroiListaPessoa(ListaPessoa* lista);

/*  Libera a memória alocada para a lista que guarda as pessoas "repetidas", sem liberar a memória das pessoas em si
    input: A lista de pessoas
    output: Nenhum
    pré-condição: Lista de pessoas está inicializada
    pós-condição: A memória alocada para a lista de pessoas repetidas foi liberada
*/
void destroiListaRepetidos(ListaPessoa* lista);

#endif
