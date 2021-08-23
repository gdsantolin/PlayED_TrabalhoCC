#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "../include/listaPlaylist.h"


typedef struct celula_playlist CelPlaylist;

struct celula_playlist{
    Playlist* playlist;
    CelPlaylist* prox;
};

struct lista_playlist{
    CelPlaylist* prim;
    CelPlaylist* ult;
    int cont_playlist;
};

ListaPlaylist* iniciaListaPlaylist(){
    ListaPlaylist* lista = (ListaPlaylist*)malloc(sizeof(ListaPlaylist));
    lista->prim = NULL;
    lista->ult = NULL;
    lista->cont_playlist = 0;

    return lista;
}

Playlist* buscaPlaylist(ListaPlaylist* lista, char* chave){
    CelPlaylist* cel_aux;
    for(cel_aux = lista->prim; cel_aux != NULL; cel_aux = cel_aux->prox){
        if(strcmp(getNomePlaylist(cel_aux->playlist), chave) == 0) return cel_aux->playlist;
    }
    return NULL;
}

void insereListaPlaylist(ListaPlaylist* lista, Playlist* playlist){
    CelPlaylist* cel_nova = (CelPlaylist*)malloc(sizeof(CelPlaylist));

    cel_nova->playlist = playlist;
    cel_nova->prox = NULL;
    lista->cont_playlist++;

    if(lista->prim == NULL){
        lista->prim = cel_nova;
        lista->ult = cel_nova;
    }
    else{
        lista->ult->prox = cel_nova; 
        lista->ult = cel_nova;
    }
}

void preencheListaPlaylist(ListaPessoa* lista_pessoa){
    FILE* arq = fopen("data/Entrada/playlists.txt", "r");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(0);
    }

    char linha[100], nome_pessoa[50], nome_playlist[50], nome_arquivo[50], quebra;
    int qtd_playlist, w;
    
    while(fscanf(arq, "%99[^;];%d;", nome_pessoa, &qtd_playlist) == 2){ //cada loop preenche as playlists de uma pessoa
        Pessoa* p = buscaPessoa(lista_pessoa, nome_pessoa);
        //printf("%s %d ", nome_pessoa, qtd_playlist);
        for(int i = 0; i < qtd_playlist; i++){
            w = fscanf(arq, "%99[^;^\n]%c", nome_playlist, &quebra);
            Playlist* playlist = preenchePlaylist(nome_playlist);
            insereListaPlaylist(getListaPlaylistPessoa(p), playlist);
        }
    }
    fclose(arq);
}

void refatoraListaPlaylist(Pessoa* pessoa){
    CelPlaylist* cel_aux;
    ListaPlaylist* lista = getListaPlaylistPessoa(pessoa);
    ListaPlaylist* lista_refatorada = iniciaListaPlaylist();

    for(cel_aux = lista->prim; cel_aux != NULL; cel_aux = cel_aux->prox){ //para cada playlist de uma pessoa
        refatoraPlaylist(cel_aux->playlist, lista_refatorada);
    }

    destroiListaPlaylist(lista);
    setListaPlaylistPessoa(pessoa, lista_refatorada);
}

void imprimeListaPlaylistArq(char* nome_pessoa, ListaPlaylist* lista){
    CelPlaylist* cel_aux;

    char caminho[100] = "data/Saida/", caminho_aux[100];
    strcat(caminho, nome_pessoa);
    strcat(caminho, "/");
    mkdir(caminho, 0777);

    strcpy(caminho_aux, caminho);

    for(cel_aux = lista->prim; cel_aux != NULL; cel_aux = cel_aux->prox){ //para cada playlist da lista
        strcpy(caminho, caminho_aux); //reseta caminho para "data/pessoa/"
        strcat(caminho, getNomePlaylist(cel_aux->playlist)); //caminho = data/pessoa/banda.txt

        FILE* arq = fopen(caminho, "w");
        if(arq == NULL){
            printf("Erro ao abrir o arquivo\n");
            exit(0);
        }
        
        imprimePlaylistArq(cel_aux->playlist, arq);
        fclose(arq);
    }
}

void imprimeListaPlaylistPlayedRefatorada(ListaPlaylist* lista, FILE* arq){
    CelPlaylist* cel_aux;
    
    fprintf(arq, "%d;", lista->cont_playlist);

    for(cel_aux = lista->prim; cel_aux != NULL; cel_aux = cel_aux->prox){
        fprintf(arq, "%s", getNomePlaylist(cel_aux->playlist));

        if(cel_aux->prox != NULL) fprintf(arq, ";");
        else fprintf(arq, "\n");
    }
}

int comparaListaPlaylistAmigo(ListaPlaylist* lista1, ListaPlaylist* lista2){
    CelPlaylist* cel_aux;
    int similaridade = 0;
    for(cel_aux = lista1->prim; cel_aux != NULL; cel_aux = cel_aux->prox){ //pra cada playlist
        Playlist* p = buscaPlaylist(lista2, getNomePlaylist(cel_aux->playlist));
        if(p != NULL){
            similaridade += comparaPlaylistAmigo(cel_aux->playlist, p);
        }
    }
    return similaridade;
}

void destroiListaPlaylist(ListaPlaylist* lista){
    CelPlaylist* cel_atual = lista->prim;
    CelPlaylist* cel_prox;

    while(cel_atual != NULL){
        cel_prox = cel_atual->prox;

        destroiPlaylist(cel_atual->playlist);
        free(cel_atual);

        cel_atual = cel_prox;
    }
    free(lista);
}