#ifndef T_INTERFACE_
#define T_INTERFACE_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include "conio.h"
#include "tJogador.h"
#include "tAuxiliar.h"
#include "tExecucao.h"


typedef struct tJogador tJogador;
typedef struct tPalavras tPalavras;

void PrintaPrimeiraTela ();
void PrintaMenuDeModos (char NomeJogador[]);
void PrintaEspacoDoPalpite (char Palpite[], char PalavraSort[], char ArmazenaPalavraSorteada[]);
void PrintaTermoQuandoAcaba (char PalavraSort[]);
void PrintaInterfaceDeJogo (char NomeJogador[], char Palpite[], char PalavraSort[], int Contador, char LetrasQueJaForamMasNaoTem[], char ArmazenaPalavraSorteada[], int ModoDeJogo, char NomeUm[], char NomeDois[], char Palpite2[], char Palpite3[], char Palpite4[], char Palpite5[], char Palpite6[]);
void PrintaMensagemDeVitoria(char PalavraSort[], int ModoDeJogo, int Vez, char NomeUm[], char NomeDois[]);
void PrintaMensagemDeDerrota(char PalavraSort[], int ModoDeJogo, int Vez);
void PrintaTeclado (char Palpite[], char PalavraSort[], char LetrasQueJaForamMasNaoTem[]);
void PrintaRecebeNomeDoSegundoJogador();
void PrintaEscolheUmaOpcaoValida();
void PrintaMsgJogadorSaindoDoJogo();
void PrintaMsgDeConfirmacaoSairDoJogo();
void InterfaceTentativasPraBaixo (char NomeJogador[], char Palpite[], char PalavraSort[], int Contador, char LetrasQueJaForamMasNaoTem[], char ArmazenaPalavraSorteada[], int ModoDeJogo, char NomeUm[], char NomeDois[]);
void LimpaTerminal();
void PrintaEstatisticas();
void PrintaRanking ();
#endif
