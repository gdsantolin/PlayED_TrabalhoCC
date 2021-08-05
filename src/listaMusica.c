#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/listaMusica.h"

typedef struct celula_musica CelMusica;

struct celula_musica{
    Musica* msc;
    CelMusica* prox;
};

struct lista_musica{
    CelMusica* prim;
    CelMusica* ult;
};

ListaMusica* iniciaListaMusica(){
    ListaMusica* lista = (ListaMusica*)malloc(sizeof(ListaMusica));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

Musica* buscaMusica(ListaMusica* lista, char* chave_nome, char* chave_banda){
    CelMusica* cel_aux;
    for(cel_aux = lista->prim; cel_aux != NULL; cel_aux = cel_aux->prox){
        if(strcmp(getNomeMusica(cel_aux->msc), chave_nome) == 0){
            if(strcmp(getBandaMusica(cel_aux->msc), chave_banda) == 0){
                return cel_aux->msc;
            }
        }  
    }
    return NULL;
}

void insereListaMusica(ListaMusica* lista, Musica* msc){
    CelMusica* cel_nova = (CelMusica*)malloc(sizeof(CelMusica));

    cel_nova->msc = msc;
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

void refatoraListaMusica(ListaMusica* lista, char* caminho, ListaPlaylist* lista_refatorada){
    FILE* arq;
    CelMusica* cel_aux;
    char nome_arquivo[100], caminho_aux[100];
    strcpy(caminho_aux, caminho);
    

    for(cel_aux = lista->prim; cel_aux != NULL; cel_aux = cel_aux->prox){
        strcpy(caminho, caminho_aux);
        strcpy(nome_arquivo, getBandaMusica(cel_aux->msc));
        strcat(nome_arquivo, ".txt");
        strcat(caminho, nome_arquivo);

        Playlist* playlist = buscaPlaylist(lista_refatorada, nome_arquivo);

        Musica* msc = preencheMusica(getBandaMusica(cel_aux->msc), getNomeMusica(cel_aux->msc));

        if(playlist == NULL){
            playlist = criaPlaylist(nome_arquivo);
            insereListaPlaylist(lista_refatorada, playlist);
            insereListaMusica(getListaMusicaPlaylist(playlist), msc);
        }
        else{
            if(buscaMusica(getListaMusicaPlaylist(playlist), getNomeMusica(cel_aux->msc), getBandaMusica(cel_aux->msc)) == NULL){
                insereListaMusica(getListaMusicaPlaylist(playlist), msc);
            }
            else destroiMusica(msc);
        }

        
        
        

        arq = fopen(caminho, "a");
        //fprintf(arq, "%s - %s\n", getBandaMusica(cel_aux->msc), getNomeMusica(cel_aux->msc)); //precisa verificar se a musica ja existe no arquivo, senao ele vai escrevendo ela toda vez
        fclose(arq);
    }
}

void imprimeListaMusica(ListaMusica* lista){
    CelMusica* cel_aux;
    for(cel_aux = lista->prim; cel_aux != NULL; cel_aux = cel_aux->prox){
        imprimeMusica(cel_aux->msc);
    }
}

void destroiListaMusica(ListaMusica* lista){
    CelMusica* cel_atual = lista->prim;
    CelMusica* cel_prox;

    while(cel_atual != NULL){
        cel_prox = cel_atual->prox;

        destroiMusica(cel_atual->msc);
        free(cel_atual);

        cel_atual = cel_prox;
    }
    free(lista);
}