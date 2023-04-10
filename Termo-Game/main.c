#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h> 
#include <string.h>
#include "Termo.h"

int main() {
char TERMO[18289][5];
char Palavra[5];
char PalavraOculta[5];
char Palpite[5];
int Tentativas=6;
int i;
int AcertouLetra=0;
char PalpiteMaiusculo[5];
char PalavraSorteada[5];
char PalavraSortMaiuscula[5];
char LetrasQueJaForamMasNaoTem[100];
int ModoDeJogo;
char ArmazenaPalavraSorteada[5];
char LetrasQueJaForamEAindaPodemTer[100];
int Vez;
char NomePrimeiroJogador[20];
char NomeSegundoJogador[20];
char Palpite1[6], Palpite2[6], Palpite3[6], Palpite4[6], Palpite5[6], Palpite6[6];

  
//Start
  
//Abre o arquivo de palavras
AbreArquivoPalavras(TERMO);
c_textcolor(RED);
//Printa a tela inicial, pedindo o nome do jogador
PrintaPrimeiraTela();

//Recebe o nome do jogador e copia para a string
strcpy(NomePrimeiroJogador,RecebeNomeJogador(NomePrimeiroJogador));

tPalavras *P;

FILE *fJ;
FILE *fPS;

//Printa a tela que pede para o jogador escolher o modo de jogo
PrintaMenuDeModos(NomePrimeiroJogador);
  
while (ModoDeJogo!=1||ModoDeJogo!=2||ModoDeJogo!=8||ModoDeJogo!=9) {  
  //Escolhe o modo de jogo
  ModoDeJogo=EscolheModo();

  if (ModoDeJogo==1) {
    LimpaTerminal();
    break;
  }
  
  //Caso o modo de jogo seja de dois jogadores, executa as seguintes funções
  else if (ModoDeJogo==2) {
    //Printa a tela que pede o nome do segundo jogador
    PrintaRecebeNomeDoSegundoJogador();
    //Recebe o nome do segundo jogador e copia para a string
    strcpy(NomeSegundoJogador, RecebeNomeJogador(NomeSegundoJogador));
    LimpaTerminal();
    //Sorteia qual jogador irá começar
    Vez=SorteiaVezDoisJogadores();
    break;
  }

  //Confere se o jogador realmente deseja sair do jogo
  //Caso queira, finaliza o jogo
  else if (ModoDeJogo==0) {
    int Decide;
    PrintaMsgDeConfirmacaoSairDoJogo();
    Decide=DecideSeQuerContinuarOuNao();
    LimpaTerminal();
    if (Decide==1) {
      printf ("\n");
      PrintaMenuDeModos(NomePrimeiroJogador);
      continue;
    }
    else if (Decide==2) {
      PrintaMsgJogadorSaindoDoJogo();
      exit(1);
    }  
    else {
      PrintaEscolheUmaOpcaoValida();
    }
  }

    else if (ModoDeJogo==8) {
      int Escolhe;
      PrintaRanking();
      Escolhe=RecebeEscolha();
      LimpaTerminal();
      if (Escolhe==0) {
        printf ("Até a próxima!");
        exit(1);
      }
      else if (Escolhe==5) {
        PrintaMenuDeModos(NomePrimeiroJogador);
        continue;
      }
      
    }
    else if (ModoDeJogo==9) {
      int Escolhe;
      PrintaEstatisticas();
      Escolhe=RecebeEscolha();
      LimpaTerminal();
      if (Escolhe==0) {
        printf ("Até a próxima!");
        exit(1);
      }
      else if (Escolhe==5) {
        PrintaMenuDeModos(NomePrimeiroJogador);
        continue;
      }
    }
    
  else {
      PrintaEscolheUmaOpcaoValida();
  }
    
}  

  printf ("\n");

  // Sorteia Palavra e copia para a string Palavra
  srand(time(NULL));
  CopiaString(Palavra, RecebePalavra(Palavra, TERMO));
  ViraMaiuscula(Palavra, PalavraSortMaiuscula);

  //Inicia um loop com 
    while (Tentativas!=0) {  
      CopiaString(ArmazenaPalavraSorteada, PalavraSortMaiuscula);
      PrintaInterfaceDeJogo(NomePrimeiroJogador, Palpite1, PalavraSortMaiuscula, Tentativas, LetrasQueJaForamMasNaoTem, ArmazenaPalavraSorteada, ModoDeJogo, NomePrimeiroJogador, NomeSegundoJogador, Palpite2, Palpite3, Palpite4, Palpite5, Palpite6);

        CopiaString (Palpite, JogaModoTermo(Palpite, ModoDeJogo, Vez, NomePrimeiroJogador, NomeSegundoJogador));
        ViraMaiuscula(Palpite, PalpiteMaiusculo);
      //

      
      //Inicializa a primeira posição das letras que ja foram mas nao tem pra evitar erros
      LetrasQueJaForamMasNaoTem[0]='.';
      
      //Salva as letras que ainda podem ter e copia para a string
      strcpy(LetrasQueJaForamEAindaPodemTer, SalvaLetraQueAindaPodemTer(LetrasQueJaForamEAindaPodemTer, PalpiteMaiusculo, PalavraSortMaiuscula));
      //Salva as letras que se sabe que nao pode mais ter e copia para a string
      strcpy(LetrasQueJaForamMasNaoTem, SalvaLetrasQueNaoPodemMaisTer(LetrasQueJaForamMasNaoTem, PalpiteMaiusculo, PalavraSortMaiuscula, LetrasQueJaForamEAindaPodemTer));
      
      //Verifica se o palpite está correto
      //Se estiver correto, printa uma mensagem de parabéns e finaliza
      if (VerificaPalpite(PalavraSortMaiuscula, PalpiteMaiusculo)==CERTO) {
        PrintaMensagemDeVitoria(PalavraSortMaiuscula, ModoDeJogo, Vez, NomePrimeiroJogador, NomeSegundoJogador);
        break;
      }

      if (Tentativas==6) {
        CopiaString(Palpite1, PalpiteMaiusculo);
      }
      //
      if (Tentativas==5) {
        CopiaString(Palpite2, PalpiteMaiusculo);
      }
      //
      if (Tentativas==4) {
        CopiaString(Palpite3, PalpiteMaiusculo);
      }
      //
      if (Tentativas==3) {
        CopiaString(Palpite4, PalpiteMaiusculo);
      }
      //
      if (Tentativas==2) {
        CopiaString(Palpite5, PalpiteMaiusculo);
      }
      //
      if (Tentativas==1) {
        CopiaString(Palpite6, PalpiteMaiusculo);
      }
      //
      //Diminui o valor do int Tentativas para seguir contando a quantidade de tentativas restantes
      Tentativas--;
      if (Tentativas>0) {
        LimpaTerminal();
      }
      //Verifica se acabaram as tentativas
      //Se acabaram as tentativas, então o jogador perdeu. Em seguida printa uma mensagem
      if (Tentativas==0) {
        PrintaMensagemDeDerrota(PalavraSortMaiuscula, ModoDeJogo, Vez);
        break;
      }

      //Laço de if e else if para fazer a alternância de vez dos jogadores
      if (Vez==2) {
        Vez--;
      }
      else if (Vez==1) {
        Vez++;
      }
    }

  
  return 0;
}

