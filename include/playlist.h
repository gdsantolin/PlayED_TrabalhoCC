#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct playlist Playlist;

#include "listaMusica.h"
#include "listaPlaylist.h"

/*  Aloca e cria uma playlist com seu nome e inicializa sua lista de músicas
    input: String com o nome da playlist
    output: Ponteiro para struct playlist
    pré-condição: Nome não é nulo
    pós-condição: Playlist foi alocada e iniciada com a lista de músicas inicializada
*/
Playlist* criaPlaylist(char* nome);

/*  Retorna o nome de uma playlist
    input: A playlist
    output: String com o nome da playlist
    pré-condição: Playlist existe
    pós-condição: Nome da playlist foi retornado
*/
char* getNomePlaylist(Playlist* p);

/*  Retorna a lista de músicas de uma playlist
    input: A playlist
    output: Ponteiro para a lista de músicas
    pré-condição: Playlist existe
    pós-condição: Ponteiro para a lista de músicas da playlist foi retornado
*/
ListaMusica* getListaMusicaPlaylist(Playlist* p);

/*  Define o nome de uma playlist
    input: A playlist, o nome
    output: Nenhum
    pré-condição: Playlist existe, nome não é nulo
    pós-condição: O nome da playlist foi definido
*/
void setNomePlaylist(Playlist* p, char* nome);

/*  Preenche uma playlist a partir do arquivo de entrada
    input: O nome da playlist
    output: Ponteiro para struct playlist
    pré-condição: Nome não é nulo
    pós-condição: Playlist foi preenchida com as músicas conforme arquivo de entrada
*/
Playlist* preenchePlaylist(char* nome_playlist);

/*  Faz a refatoração de uma playlist
    input: A playlist, a nova lista de playlists 
    output: Nenhum
    pré-condição: Playlist existe, lista de playlists está inicializada
    pós-condição: A playlist foi refatorada (organizada por artista/banda)
*/
void refatoraPlaylist(Playlist* p, ListaPlaylist* lista_refatorada);

/*  Escreve os dados de uma playlist em um arquivo
    input: A playlist, o arquivo
    output: Nenhum
    pré-condição: Playlist e arquivo existem
    pós-condição: A playlist foi escrita no arquivo
*/
void imprimePlaylistArq(Playlist* p, FILE* arq);

/*  Conta e retorna as similaridades entre duas playlists
    input: As duas playlists que serão comparadas
    output: Inteiro com a quantidade de músicas iguais nas duas playlists
    pré-condição:
    pós-condição:
*/
int comparaPlaylistAmigo(Playlist* p1, Playlist* p2);

/*  Libera toda a memória alocada para uma playlist
    input: A playlist 
    output: Nenhum
    pré-condição: Playlist existe
    pós-condição: A memória alocada para a playlist foi liberada
*/
void destroiPlaylist(Playlist* p);

void imprimePlaylist(Playlist* p); //não precisa

#endif