#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/amigo.h"
#include "../include/listaAmigo.h"
#include "../include/pessoa.h"

struct celula_amigo{
    Pessoa* pessoa;
    CelAmigo* prox;
};

struct lista_amigo{
    CelAmigo* prim;
    CelAmigo* ult;
};