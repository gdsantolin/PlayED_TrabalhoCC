#ifndef MUSICA_H
#define MUSICA_H

typedef struct musica Musica;

char* getNomeMusica(Musica* msc);

char* getBandaMusica(Musica* msc);

void destroiMusica(Musica* msc);

#endif