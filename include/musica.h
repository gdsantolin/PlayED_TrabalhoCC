#ifndef MUSICA_H
#define MUSICA_H

typedef struct musica Musica;

#include "listaMusica.h"

char* getNomeMusica(Musica* msc);

char* getBandaMusica(Musica* msc);

Musica* preencheMusica(char* nome_banda, char* nome_musica);

void imprimeMusica(Musica* msc);

void destroiMusica(Musica* msc);

#endif