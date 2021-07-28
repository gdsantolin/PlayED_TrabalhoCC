#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/pessoa.h"
#include "../include/listaPessoa.h"
#include "../include/listaAmigo.h"
#include "../include/listaPlaylist.h"

struct pessoa{
    char* nome;
    ListaAmigo* amigos;
    ListaPlaylist* playlists;
};

char* getNomePessoa(Pessoa* p){
    return p->nome;
}