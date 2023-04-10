#ifndef TARTISTA_H
#define TARTISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
  
typedef struct tArtista tArtista;
typedef struct tArtistaData tArtistaData;

tArtistaData* AbreLeArquivoArtistas(tArtistaData *TAD);
void LiberaArtistas (tArtistaData *TAD);
int GetPopularidade(tArtistaData *TAD, int indice);
float GetSeguidores(tArtistaData *TAD, int indice);
char** GetGeneros(tArtistaData *TAD, int indice);
int GetQuantGeneros(tArtistaData *TAD, int indice);
int GetQuantArtistas(tArtistaData *TAD);
char* GetNome (tArtistaData *TAD, int indice);

#endif