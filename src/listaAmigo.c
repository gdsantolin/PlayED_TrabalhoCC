#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/listaAmigo.h"


typedef struct celula_amigo CelAmigo;

struct celula_amigo{
    Pessoa* amigo;
    CelAmigo* prox;
};

struct lista_amigo{
    CelAmigo* prim;
    CelAmigo* ult;
};

ListaAmigo* iniciaListaAmigo(){
    ListaAmigo* lista = (ListaAmigo*)malloc(sizeof(ListaAmigo));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void insereListaAmigo(ListaAmigo* lista, Pessoa* p){
    CelAmigo* cel_nova = (CelAmigo*)malloc(sizeof(CelAmigo));

    cel_nova->amigo = p;
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

void preencheListaAmigo(FILE* arq, ListaPessoa* lista_pessoa){
    char nome1[50], nome2[50], linha[100];
    Pessoa *p1, *p2;
    ListaAmigo *p1_amigos, *p2_amigos;

    while(fgets(linha, 100, arq)){
        sscanf(linha, "%49[^;];%49[^\n]", nome1, nome2);
        p1 = buscaPessoa(lista_pessoa, nome1);
        p2 = buscaPessoa(lista_pessoa, nome2);

        p1_amigos = getListaAmigoPessoa(p1);
        p2_amigos = getListaAmigoPessoa(p2);

        insereListaAmigo(p1_amigos, p2);
        insereListaAmigo(p2_amigos, p1); //amizade reciproca
    }

}

void imprimeListaAmigo(ListaAmigo* lista){
    CelAmigo* cel_aux;
    for(cel_aux = lista->prim; cel_aux != NULL; cel_aux = cel_aux->prox){
        printf("  %s\n", getNomePessoa(cel_aux->amigo));
    }
}

void destroiListaAmigo(ListaAmigo* lista){
    CelAmigo* cel_atual = lista->prim;
    CelAmigo* cel_prox;

    while(cel_atual != NULL){
        cel_prox = cel_atual->prox;
        free(cel_atual);
        cel_atual = cel_prox;
  }
  free(lista);
}