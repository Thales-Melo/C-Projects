#ifndef T_JOGADOR_
#define T_JOGADOR_

#define NOMES "nomes.bin"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "tAuxiliar.h"

#define JOGADOR_1 1
#define JOGADOR_2 2

typedef struct tJogador tJogador;

char * RecebeNomeJogador (char Nome[]);
//void AbreDadosJogadores(char entry1[20]);
void SalvarNomeJogadores(char Nome[], FILE *f);
void LiberaJogador (tJogador *J);


// FUNÇÕES DE ARQUIVO (PARTE SEPARADA) //

/*
typedef struct jogadores tJogador;
tJogador* RecebeNomeJogador(tJogador *jogador);
tJogador* RecebeNomeJogador_2(tJogador *jogador);
void LiberaJogador(tJogador* jogador);
void LiberaTodosJogadores(tJogador** todos_jogadores, int cont_jd);
int RegistraDadosJogadores(tJogador* jogador, tJogador** todos_jogadores);
tJogador** LeJogadoresBin();
//GetJogadorTimestamp
*/

#endif