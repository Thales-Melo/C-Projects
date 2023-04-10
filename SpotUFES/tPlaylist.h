#ifndef TPLAYLIST_H
#define TPLAYLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tMusica.h"
#include "tArtista.h"

typedef struct tPlaylist tPlaylist;
typedef struct tPlaylistData tPlaylistData;
typedef struct ODE ODE;

tPlaylist** InicializaListaPlaylists(tPlaylistData *TPD);
tPlaylistData* InicializaPlaylistData(tPlaylistData *TPD);
tPlaylistData* CarregaPlaylists(tPlaylistData *TPD);
tPlaylistData* CriaPlaylist(tPlaylistData *TPD);
tPlaylistData* AdicionarMusicaPlaylist(tPlaylistData *TPD);
void ListarPlaylists(tPlaylistData *TPD);
void ListarUmaPlaylist(tPlaylistData *TPD, tSongData *TSD);
void DescarregaPlaylists(tPlaylistData *TPD);
void LiberaPlaylists(tPlaylistData *TPD);
//void GerarRelatorio(tPlaylistData *TPD);
void RecomendaMusica(tSongData *TSD, tPlaylistData *TPD);
void QuickSort(ODE **vetor, int inicio, int fim);
int Particiona(ODE **vetor, int inicio, int fim);
float Diferenca (float Valor, float Parametro);

#endif