#include <stdio.h>
#include <stdlib.h>
#include "../include/pessoa.h"
#include "../include/listaPessoa.h"

int main(){
    ListaPessoa* pessoas = iniciaListaPessoa();

    preencheListaPessoa(pessoas);
    preencheListaPlaylist(pessoas);

    imprimeListaPessoa(pessoas);
    printf("\n\n\n");
    
    refatoraListaPlaylistPessoa(pessoas);
    imprimeListaPessoa(pessoas);
    similaridadePlaylistAmigo(pessoas);

    destroiListaPessoa(pessoas);
    //
}