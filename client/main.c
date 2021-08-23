#include <stdio.h>
#include <stdlib.h>
#include "../include/pessoa.h"
#include "../include/listaPessoa.h"

int main(){
    ListaPessoa* pessoas = iniciaListaPessoa();

    //leitura dos dados a partir dos arquivos
    preencheListaPessoa(pessoas);
    preencheListaPlaylist(pessoas);

    //refatoração e similaridades
    refatoraListaPlaylistPessoa(pessoas);
    similaridadePlaylistAmigo(pessoas);
    
    //liberação de memória
    destroiListaPessoa(pessoas);
    
}