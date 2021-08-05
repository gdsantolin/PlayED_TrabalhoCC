#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/listaPessoa.h"

typedef struct celula_pessoa CelPessoa;

struct celula_pessoa{
    Pessoa* pessoa;
    CelPessoa* prox;
};

struct lista_pessoa{
    CelPessoa* prim;
    CelPessoa* ult;
};

ListaPessoa* iniciaListaPessoa(){
    ListaPessoa* lista = (ListaPessoa*)malloc(sizeof(ListaPessoa));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void insereListaPessoa(ListaPessoa* lista, Pessoa* p){
    CelPessoa* cel_nova = (CelPessoa*)malloc(sizeof(CelPessoa));

    cel_nova->pessoa = p;
    cel_nova->prox = NULL;
    if(lista->prim == NULL){
        lista->prim = cel_nova;
        lista->ult = cel_nova;
    }
    else{
        lista->ult->prox = cel_nova; 
        lista->ult = cel_nova;
    }
}

void imprimeListaPessoa(ListaPessoa* lista){
    CelPessoa* cel_aux = lista->prim;
    for(cel_aux = lista->prim; cel_aux != NULL; cel_aux = cel_aux->prox){
        imprimePessoa(cel_aux->pessoa);
        imprimeListaPlaylist(getListaPlaylistPessoa(cel_aux->pessoa));
    }
}

void refatoraListaPlaylistPessoa(ListaPessoa* lista_p){
    CelPessoa* cel_aux;
    FILE* arq = fopen("data/played_refatorada.txt", "w");

    for(cel_aux = lista_p->prim; cel_aux != NULL; cel_aux = cel_aux->prox){ //para cada pessoa
        refatoraListaPlaylist(cel_aux->pessoa); //faz a refatoração da lista de playlists, encadeando a nova lista e destruindo a antiga
        imprimePlayedRefatorada(cel_aux->pessoa, arq); //cria e escreve no arquivo played_refatorada.txt
        
    }
    fclose(arq);
}

Pessoa* buscaPessoa(ListaPessoa* lista, char* chave){
    CelPessoa* cel_aux;
    for(cel_aux = lista->prim; cel_aux != NULL; cel_aux = cel_aux->prox){
        if(strcmp(getNomePessoa(cel_aux->pessoa), chave) == 0) return cel_aux->pessoa;
    }
    return NULL;
}

void preencheListaPessoa(ListaPessoa* lista){
    FILE* arqAmigos = fopen("data/Entrada/amizade.txt", "r");
    char linha[100], nome_aux[100], quebra;
    Pessoa* pessoa; 
    
    while(fscanf(arqAmigos, "%99[^;^\n]%c", nome_aux, &quebra) == 2){
        pessoa = criaPessoa(nome_aux);
        insereListaPessoa(lista, pessoa);
        if(quebra == '\n') break;
    }  

    preencheListaAmigo(arqAmigos, lista);

    fclose(arqAmigos);
}

void destroiListaPessoa(ListaPessoa* lista){
    CelPessoa* cel_atual = lista->prim;
    CelPessoa* cel_prox;

    while(cel_atual != NULL){
        cel_prox = cel_atual->prox;

        destroiPessoa(cel_atual->pessoa);
        free(cel_atual);

        cel_atual = cel_prox;
    }
    free(lista);
}

