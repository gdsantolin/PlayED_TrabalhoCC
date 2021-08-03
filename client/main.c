#include <stdio.h>
#include <stdlib.h>
#include "../include/pessoa.h"
#include "../include/listaPessoa.h"

int main(){
    ListaPessoa* pessoas = iniciaListaPessoa();

    preencheListaPessoa(pessoas);
    preencheListaPlaylist(pessoas);

    imprimeListaPessoa(pessoas);
    
    destroiListaPessoa(pessoas);
}