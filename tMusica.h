#ifndef TMUSICA_H
#define TMUSICA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tArtista.h"
#include "tInterface.h"

typedef struct tMusica tMusica;
typedef struct tSongData tSongData;

tSongData* AbreLeArquivoMusicas(tSongData *TSD);
void LiberaMusicas(tSongData *TSD);
void ListarMusica(tSongData *TSD, tArtistaData *TAD);
char * PesquisarMusica ();
void ProcuraMusica (tSongData *TSD);
char *CriaMusicaAux(int posicao_na_string, char *nomemus, int tamnome, char str[]);
void StrMaiuscula (char *s1);
char* GetTitulo(tSongData *TSD, int indice);
//
float GetCaracteristicas(tSongData *TSD, int indice, int Caracteristica);
int GetQuantMusicas(tSongData *TSD);
char * GetNomeMusica (tSongData *TSD, int indice);

#endif