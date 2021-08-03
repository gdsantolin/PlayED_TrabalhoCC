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

void destroiMusica(Musica* msc){
    free(msc->banda);
    free(msc->nome);
}
