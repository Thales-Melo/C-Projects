#ifndef T_EXECUCAO_
#define T_EXECUCAO_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "tAuxiliar.h"
#include "tJogador.h"
#include "tInterface.h"

#define PALAVRAS_SORTEADAS "palavrassorteadas.txt"

#define JA_TENTOU_MAS_NAO_TEM 9
#define PODE_TER_AINDA 8
#define TRUE 1
#define FALSE 0

 #define VALIDO 1
#define INVALIDO 0
#define TEM_LETRA_INVALIDA 3
#define STRING_MAIOR_QUE_O_PERMITIDO 4
#define CERTO 1
#define ERRADO 0
#define CERTO_E_LUGAR_CERTO 1
#define CERTO_MAS_LUGAR_ERRADO -1
#define NAO_CONTEM_A_LETRA 0
typedef struct tPalavras tPalavras;


void SalvarPalavraSorteada(char Ps[], FILE *f);
void AbreArquivoPalavras(char entry1[18289][5]);
int SorteiaPalavra();
char * RecebePalavra (char Palavra[], char TERMO[18289][5]);
void OcultaPalavra(char Palavra[5], char PalavraOculta[5]);
int VerificaRepeticao (char ArmazenaPalavraSorteada[], char Letra);
int VerificaPalpite (char PalavraSort[], char Palpite[]);
int VerificaSePalpiteValido (char Palpite[]);
int SituacaoDaLetra (char Palpite[], char PalavraSorteada[], int i, char ArmazenaPalavraSorteada[]);
void LiberaPalpite (char Palpite[]);
char * JogaModoTermo (char Palpite[], int ModoDeJogo, int Vez, char NomeUm[], char NomeDois[]);
int VerificaLetraProTeclado(char Teclado[], char PalavraSort[], int i, char LetrasQueJaForamMasNaoTem[], char Palpite[]);
char * SalvaLetrasQueNaoPodemMaisTer(char LetrasQueJaForamMasNaoTem[], char Palpite[], char PalavraSort[], char LetrasQueJaForamEAindaPodemTer[]);
int VerificaSeLetraNaoSeRepeteDepois(char Palpite[], int i);
int VerificaSeLetraJaFoiNoPalpite(char Palpite[], int i);
void ApagaLetraDoArmazenaPalavra (char String[], char Letra);
int VerificaLetrasCertas (char Palpite[], char PalavraSort[]);
char * SalvaLetraQueAindaPodemTer (char LetrasQueJaForamEAindaPodemTer[], char Palpite[], char PalavraSort[]);
int SorteiaVezDoisJogadores();
int EscolheModo();
int DecideSeQuerContinuarOuNao();
int RecebeEscolha ();

#endif
