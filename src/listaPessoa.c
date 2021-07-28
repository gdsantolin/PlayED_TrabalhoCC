#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/pessoa.h"
#include "../include/listaPessoa.h"

struct celula_pessoa{
    Pessoa* pessoa;
    CelPessoa* prox;
};

struct lista_pessoa{
    CelPessoa* prim;
    CelPessoa* ult;
};