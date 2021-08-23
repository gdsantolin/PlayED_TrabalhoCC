#ifndef PESSOA_H
#define PESSOA_H

typedef struct pessoa Pessoa;

#include "listaPlaylist.h"
#include "listaAmigo.h"

/*  Aloca e preenche uma pessoa com seu nome e inicializa suas listas de playlist e amigos
    input: String com o nome da pessoa a ser preenchida
    output: Ponteiro para struct pessoa
    pré-condição: Nome não é nulo
    pós-condição: Pessoa foi alocada e criada com as listas inicializadas
*/
Pessoa* criaPessoa(char* nome);

/*  Retorna o nome de uma pessoa
    input: A pessoa
    output: String com o nome da pessoa
    pré-condição: Pessoa existe
    pós-condição: Nome da pessoa foi retornado
*/
char* getNomePessoa(Pessoa* p);

/*  Retorna a lista de amigos de uma pessoa
    input: A pessoa
    output: Ponteiro para a lista de amigos
    pré-condição: Pessoa existe
    pós-condição: Ponteiro para a lista de amigos da pessoa foi retornado
*/
ListaAmigo* getListaAmigoPessoa(Pessoa* p);

/*  Retorna a lista de playlists de uma pessoa
    input: A pessoa
    output: Ponteiro para a lista de playlists
    pré-condição: Pessoa existe
    pós-condição: Ponteiro para a lista de playlists da pessoa foi retornado
*/
ListaPlaylist* getListaPlaylistPessoa(Pessoa* p);

/*  Define uma nova lista de playlists para uma pessoa
    input: A pessoa, a nova lista de playlists
    output: Nenhum
    pré-condição: Pessoa existe, lista de playlists está inicializada
    pós-condição: Nova lista de playlists foi definida para a pessoa
*/
void setListaPlaylistPessoa(Pessoa* p, ListaPlaylist* lista);

/*  Preenche os arquivos de saída de playlists de uma pessoa e o arquivo played_refatorada (linha referente à pessoa passada)
    input: A pessoa, o arquivo
    output: Nenhum
    pré-condição: Pessoa e arquivo existem
    pós-condição: Arquivos played_refatorada e saídas das playlists foram preenchidos de acordo com a pessoa
*/
void imprimePlayedRefatorada(Pessoa* p, FILE* arq);

/*  Libera toda a memória alocada para uma pessoa
    input: A pessoa 
    output: Nenhum
    pré-condição: Pessoa existe
    pós-condição: A memória alocada para a pessoa foi liberada
*/
void destroiPessoa(Pessoa* p);

#endif