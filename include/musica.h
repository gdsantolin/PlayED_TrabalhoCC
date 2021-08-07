#ifndef MUSICA_H
#define MUSICA_H

typedef struct musica Musica;

#include "listaMusica.h"

/*  Retorna o nome de uma música
    input: 
    output:
    pré-condição:
    pós-condição:
*/
char* getNomeMusica(Musica* msc);

/*  Retorna o nome da banda de uma música
    input:
    output:
    pré-condição:
    pós-condição:
*/
char* getBandaMusica(Musica* msc);

/*  Aloca e preenche uma música 
    input:
    output:
    pré-condição:
    pós-condição:
*/
Musica* preencheMusica(char* nome_banda, char* nome_musica);

/*  Escreve os dados de uma música em um arquivo
    input:
    output:
    pré-condição:
    pós-condição:
*/
void imprimeMusicaArq(Musica* msc, FILE* arq);


void imprimeMusica(Musica* msc); //não precisa


/*  Libera a memória alocada para uma música
    input:
    output:
    pré-condição:
    pós-condição:
*/
void destroiMusica(Musica* msc);

#endif