#ifndef MUSICA_H
#define MUSICA_H

typedef struct musica Musica;

#include "listaMusica.h"

/*  Retorna o nome de uma música
    input: A música
    output: String com o nome da música
    pré-condição: Música existe
    pós-condição: Nome da música foi retornado
*/
char* getNomeMusica(Musica* msc);

/*  Retorna o nome da banda de uma música
    input: A música
    output: String com o nome da banda
    pré-condição: Música existe
    pós-condição: Nome da banda foi retornado
*/
char* getBandaMusica(Musica* msc);

/*  Aloca e preenche uma música 
    input: O nome da banda, o nome da música
    output: Ponteiro para struct música
    pré-condição: Nome da banda e nome da música não são nulos
    pós-condição: Música foi alocada e seus dados preenchidos
*/
Musica* preencheMusica(char* nome_banda, char* nome_musica);

/*  Escreve os dados de uma música em um arquivo
    input: A música, o arquivo
    output: Nenhum
    pré-condição: Música e arquivo existem
    pós-condição: A música foi escrita no arquivo
*/
void imprimeMusicaArq(Musica* msc, FILE* arq);

/*  Libera toda a memória alocada para uma música
    input: A música 
    output: Nenhum
    pré-condição: Música existe
    pós-condição: A memória alocada para a música foi liberada
*/
void destroiMusica(Musica* msc);

void imprimeMusica(Musica* msc); //não precisa

#endif