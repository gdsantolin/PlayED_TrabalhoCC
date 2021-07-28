#ifndef LISTA_AMIGO_H
#define LISTA_AMIGO_H

typedef struct lista_amigo ListaAmigo;

ListaAmigo* iniciaListaAmigo();

void insereListaAmigo(ListaAmigo* lista, void* p); //como inserir???

void imprimeListaAmigo(ListaAmigo* lista);

void retiraListaAmigo(ListaAmigo* lista, char* chave); //talvez não precise retirar Amigos da lista

void destroiListaAmigo(ListaAmigo* lista);

#endif