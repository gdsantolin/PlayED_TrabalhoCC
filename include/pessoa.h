#ifndef PESSOA_H
#define PESSOA_H

typedef struct pessoa Pessoa;

#include "listaPlaylist.h"
#include "listaAmigo.h"

/*  Aloca e preenche uma pessoa com seu nome e inicializa suas listas de playlist e amigos
    input:
    output:
    pré-condição:
    pós-condição:
*/
Pessoa* criaPessoa(char* nome);

/*  Retorna o nome de uma pessoa
    input:
    output:
    pré-condição:
    pós-condição:
*/
char* getNomePessoa(Pessoa* p);

/*  Retorna a lista de amigos de uma pessoa
    input:
    output:
    pré-condição:
    pós-condição:
*/
ListaAmigo* getListaAmigoPessoa(Pessoa* p);

/*  Retorna a lista de playlists de uma pessoa
    input:
    output:
    pré-condição:
    pós-condição:
*/
ListaPlaylist* getListaPlaylistPessoa(Pessoa* p);

/*  Define uma nova lista de playlists para uma pessoa
    input:
    output:
    pré-condição:
    pós-condição:
*/
void setListaPlaylistRefatoradaPessoa(Pessoa* p, ListaPlaylist* lista);

/*  Preenche os arquivos de saída de playlists de uma pessoa e o arquivo played_refatorada (linha referente à pessoa passada)
    input:
    output:
    pré-condição:
    pós-condição:
*/
void imprimePlayedRefatorada(Pessoa* p, FILE* arq);


void imprimePessoa(Pessoa * p); //não precisa


/*  Libera a memória alocada para uma pessoa
    input:
    output:
    pré-condição:
    pós-condição:
*/
void destroiPessoa(Pessoa* p);

#endif