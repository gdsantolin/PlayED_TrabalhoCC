#include <stdio.h>
#include <stdlib.h>
#include "../include/pessoa.h"
#include "../include/listaPessoa.h"

int main(){
    ListaPessoa* pessoas = iniciaListaPessoa();

    //implementação da estrutura inicial
    preencheListaPessoa(pessoas);

    //refatoração e similaridades
    refatoraListaPlaylistPessoa(pessoas);
    similaridadePlaylistAmigo(pessoas);
    
    //liberação da memória
    destroiListaPessoa(pessoas);
}