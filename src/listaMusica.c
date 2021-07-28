#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/musica.h"
#include "../include/listaMusica.h"

struct celula_musica{
    Musica* msc;
    CelMusica* prox;
};

struct lista_musica{
    CelMusica* prim;
    CelMusica* ult;
};