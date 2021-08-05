#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/musica.h"

struct musica{
    char* banda;
    char* nome;
};

char* getNomeMusica(Musica* msc){
    return msc->nome;
}

char* getBandaMusica(Musica* msc){
    return msc->banda;
}

Musica* preencheMusica(char* nome_banda, char* nome_musica){
    Musica* msc = (Musica*)malloc(sizeof(Musica));
    msc->banda = strdup(nome_banda);
    msc->nome = strdup(nome_musica);

    return msc;
}

void imprimeMusicaArq(Musica* msc, FILE* arq){
    fprintf(arq, "%s - %s\n", msc->banda, msc->nome);
}

void imprimeMusica(Musica* msc){
    printf("%s - %s\n", msc->banda, msc->nome);
}

void destroiMusica(Musica* msc){
    free(msc->banda);
    free(msc->nome);
    free(msc);
}
