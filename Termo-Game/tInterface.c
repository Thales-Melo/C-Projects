#include "tInterface.h"

struct tJogador {
  char NomeJogador[20];
  char NomeSegundoJogador[20];
  int Chances;
};

struct tPalavras {
  char PalavraSorteada[5];
  char LetrasQueNaoTem[52];   //52 = dobro da quant do alfabeto
  char Palpite[5];
  char PalavraSorteadaMaiuscula[5];
  char PalpiteMaiusculo[5];
  char LetrasQueJaForamMasNaoTem[30];
};

void InterfaceTentativasPraBaixo (char NomeJogador[], char Palpite[], char PalavraSort[], int Contador, char LetrasQueJaForamMasNaoTem[], char ArmazenaPalavraSorteada[], int ModoDeJogo, char NomeUm[], char NomeDois[]) {
      if (ModoDeJogo==1) { 
          printf ("Tentativas restantes: %d\n", Contador);
          PrintaTeclado (Palpite, PalavraSort, LetrasQueJaForamMasNaoTem);
          printf ("\n\n");
          printf ("Jogador %s digite uma palavra a sua escolha: ", NomeUm);
      }

      else if (ModoDeJogo==2) {
        if (Contador==6) {
          printf (" |   |   |   |   |   |\t\t\t\n\n\n");
          printf ("Tentativas restantes: 6\n");
          printf ("\t\t\t\t\t\t\tQ W E R T Y U I O P\n\t\t\t\t\t\t\t A S D F G H J K L\n\t\t\t\t\t\t\t   Z X C V B N M\n\n");
      }
        else {
          printf ("Tentativas restantes: %d\n", Contador);
          PrintaTeclado (Palpite, PalavraSort, LetrasQueJaForamMasNaoTem);
          printf ("\n\n");
        }
      }
}
// - Função para printar a primeira interface do programa
void PrintaPrimeiraTela () {
  printf ("Informe o nome do jogador\nNome: ");
}

// - Função que printa o menu de escolha de modos
void PrintaMenuDeModos (char NomeJogador[]) {

printf ("Jogador %s escolha o modo de jogo:\n", NomeJogador);
printf ("1- Termo\n");
printf ("2- 2-Player\n");
printf ("8- Ranking\n");
printf ("9- Estatisticas\n");
printf ("0- Sair do Jogo\n\n");
}

// - Função que printa a interface durante o jogo
// - A primeira interface possui os espaços de palpite vazios pois ainda não foi inserido nenhum palpite
// - A partir da segunda interface, substitui-se o espaço do palpite por uma função PrintaEspacoDoPalpite que retorna a impressão com os respectivos caracteres e suas situações em jogo (CERTO_E_LUGAR_CERTO, CERTO_MAS_LUGAR_ERRADO, NAO_CONTEM_A_LETRA)
void PrintaInterfaceDeJogo (char NomeJogador[], char Palpite[], char PalavraSort[], int Contador, char LetrasQueJaForamMasNaoTem[], char ArmazenaPalavraSorteada[], int ModoDeJogo, char NomeUm[], char NomeDois[], char Palpite2[], char Palpite3[], char Palpite4[], char Palpite5[], char Palpite6[]) {

  if (ModoDeJogo==1) {
    if (Contador==6) {
      printf ("################### TERMO ###################\n\n");
      printf (" |   |   |   |   |   |\t\t\t\n\n\n");
      printf ("Tentativas restantes: 6\n");
      printf ("\t\t\t\t\t\t\tQ W E R T Y U I O P\n\t\t\t\t\t\t\t A S D F G H J K L\n\t\t\t\t\t\t\t   Z X C V B N M\n\n");
      printf ("Jogador %s digite uma palavra a sua escolha: ", NomeJogador);   
    }
        
    else {
      LimpaTerminal();
      printf ("\n\n\n\n\n################### TERMO ###################\n\n");
      if (Contador==5) {
        PrintaEspacoDoPalpite(Palpite, PalavraSort, ArmazenaPalavraSorteada);
        InterfaceTentativasPraBaixo(NomeUm, Palpite, PalavraSort, Contador, LetrasQueJaForamMasNaoTem, ArmazenaPalavraSorteada, ModoDeJogo, NomeUm,NomeDois);
      }
      if (Contador==4) {
        PrintaEspacoDoPalpite(Palpite, PalavraSort, ArmazenaPalavraSorteada);
          CopiaString(ArmazenaPalavraSorteada, PalavraSort);
        PrintaEspacoDoPalpite(Palpite2, PalavraSort, ArmazenaPalavraSorteada);
        InterfaceTentativasPraBaixo(NomeUm, Palpite2, PalavraSort, Contador, LetrasQueJaForamMasNaoTem, ArmazenaPalavraSorteada, ModoDeJogo, NomeUm,NomeDois);
      }
      if (Contador==3) {
        PrintaEspacoDoPalpite(Palpite, PalavraSort, ArmazenaPalavraSorteada);
          CopiaString(ArmazenaPalavraSorteada, PalavraSort);
        PrintaEspacoDoPalpite(Palpite2, PalavraSort, ArmazenaPalavraSorteada);
          CopiaString(ArmazenaPalavraSorteada, PalavraSort);
        PrintaEspacoDoPalpite(Palpite3, PalavraSort, ArmazenaPalavraSorteada);
        InterfaceTentativasPraBaixo(NomeUm, Palpite3, PalavraSort, Contador, LetrasQueJaForamMasNaoTem, ArmazenaPalavraSorteada, ModoDeJogo, NomeUm,NomeDois);
      }
      if (Contador==2) {
        PrintaEspacoDoPalpite(Palpite, PalavraSort, ArmazenaPalavraSorteada);
          CopiaString(ArmazenaPalavraSorteada, PalavraSort);
        PrintaEspacoDoPalpite(Palpite2, PalavraSort, ArmazenaPalavraSorteada);
          CopiaString(ArmazenaPalavraSorteada, PalavraSort);
        PrintaEspacoDoPalpite(Palpite3, PalavraSort, ArmazenaPalavraSorteada);
          CopiaString(ArmazenaPalavraSorteada, PalavraSort);
        PrintaEspacoDoPalpite(Palpite4, PalavraSort, ArmazenaPalavraSorteada);
        InterfaceTentativasPraBaixo(NomeUm, Palpite4, PalavraSort, Contador, LetrasQueJaForamMasNaoTem, ArmazenaPalavraSorteada, ModoDeJogo, NomeUm,NomeDois);
      }
      if (Contador==1) {
        PrintaEspacoDoPalpite(Palpite, PalavraSort, ArmazenaPalavraSorteada);
          CopiaString(ArmazenaPalavraSorteada, PalavraSort);
        PrintaEspacoDoPalpite(Palpite2, PalavraSort, ArmazenaPalavraSorteada);
          CopiaString(ArmazenaPalavraSorteada, PalavraSort);
        PrintaEspacoDoPalpite(Palpite3, PalavraSort, ArmazenaPalavraSorteada);
          CopiaString(ArmazenaPalavraSorteada, PalavraSort);
        PrintaEspacoDoPalpite(Palpite4, PalavraSort, ArmazenaPalavraSorteada);
          CopiaString(ArmazenaPalavraSorteada, PalavraSort);
        PrintaEspacoDoPalpite(Palpite5, PalavraSort, ArmazenaPalavraSorteada);
        InterfaceTentativasPraBaixo(NomeUm, Palpite5, PalavraSort, Contador, LetrasQueJaForamMasNaoTem, ArmazenaPalavraSorteada, ModoDeJogo, NomeUm,NomeDois);
      }
    } 
  }    

  else if (ModoDeJogo==2) {
    if (Contador==6) {
      printf ("######################## TERMO ########################\n\n");
      printf ("  %s  vs  %s\n\n", NomeUm, NomeDois);
      printf (" |   |   |   |   |   |\t\t\t\n\n\n");
      printf ("Tentativas restantes: 6\n");
      printf ("\t\t\t\t\t\t\tQ W E R T Y U I O P\n\t\t\t\t\t\t\t A S D F G H J K L\n\t\t\t\t\t\t\t   Z X C V B N M\n\n");
  }
    else {
      LimpaTerminal();
      printf ("\n\n\n\n\n################### TERMO ###################\n\n");
      printf ("  %s  vs  %s\n\n", NomeUm, NomeDois);
      if (Contador==5) {
        PrintaEspacoDoPalpite(Palpite, PalavraSort, ArmazenaPalavraSorteada);
        InterfaceTentativasPraBaixo(NomeUm, Palpite, PalavraSort, Contador, LetrasQueJaForamMasNaoTem, ArmazenaPalavraSorteada, ModoDeJogo, NomeUm,NomeDois);
      }
      if (Contador==4) {
        PrintaEspacoDoPalpite(Palpite, PalavraSort, ArmazenaPalavraSorteada);
          CopiaString(ArmazenaPalavraSorteada, PalavraSort);
        PrintaEspacoDoPalpite(Palpite2, PalavraSort, ArmazenaPalavraSorteada);
        InterfaceTentativasPraBaixo(NomeUm, Palpite2, PalavraSort, Contador, LetrasQueJaForamMasNaoTem, ArmazenaPalavraSorteada, ModoDeJogo, NomeUm,NomeDois);
      }
      if (Contador==3) {
        PrintaEspacoDoPalpite(Palpite, PalavraSort, ArmazenaPalavraSorteada);
          CopiaString(ArmazenaPalavraSorteada, PalavraSort);
        PrintaEspacoDoPalpite(Palpite2, PalavraSort, ArmazenaPalavraSorteada);
          CopiaString(ArmazenaPalavraSorteada, PalavraSort);
        PrintaEspacoDoPalpite(Palpite3, PalavraSort, ArmazenaPalavraSorteada);
        InterfaceTentativasPraBaixo(NomeUm, Palpite3, PalavraSort, Contador, LetrasQueJaForamMasNaoTem, ArmazenaPalavraSorteada, ModoDeJogo, NomeUm,NomeDois);
      }
      if (Contador==2) {
        PrintaEspacoDoPalpite(Palpite, PalavraSort, ArmazenaPalavraSorteada);
          CopiaString(ArmazenaPalavraSorteada, PalavraSort);
        PrintaEspacoDoPalpite(Palpite2, PalavraSort, ArmazenaPalavraSorteada);
          CopiaString(ArmazenaPalavraSorteada, PalavraSort);
        PrintaEspacoDoPalpite(Palpite3, PalavraSort, ArmazenaPalavraSorteada);
          CopiaString(ArmazenaPalavraSorteada, PalavraSort);
        PrintaEspacoDoPalpite(Palpite4, PalavraSort, ArmazenaPalavraSorteada);
        InterfaceTentativasPraBaixo(NomeUm, Palpite4, PalavraSort, Contador, LetrasQueJaForamMasNaoTem, ArmazenaPalavraSorteada, ModoDeJogo, NomeUm,NomeDois);
      }
      if (Contador==1) {
        PrintaEspacoDoPalpite(Palpite, PalavraSort, ArmazenaPalavraSorteada);
          CopiaString(ArmazenaPalavraSorteada, PalavraSort);
        PrintaEspacoDoPalpite(Palpite2, PalavraSort, ArmazenaPalavraSorteada);
          CopiaString(ArmazenaPalavraSorteada, PalavraSort);
        PrintaEspacoDoPalpite(Palpite3, PalavraSort, ArmazenaPalavraSorteada);
          CopiaString(ArmazenaPalavraSorteada, PalavraSort);
        PrintaEspacoDoPalpite(Palpite4, PalavraSort, ArmazenaPalavraSorteada);
          CopiaString(ArmazenaPalavraSorteada, PalavraSort);
        PrintaEspacoDoPalpite(Palpite5, PalavraSort, ArmazenaPalavraSorteada);
        InterfaceTentativasPraBaixo(NomeUm, Palpite5, PalavraSort, Contador, LetrasQueJaForamMasNaoTem, ArmazenaPalavraSorteada, ModoDeJogo, NomeUm,NomeDois);
      }
    }
  }
}

// - Função feita para printar o espaço do palpite na interface
// - Considera as respectivas situações das letras para impressão em cores, indicando um caminho para acertar a palavra.
void PrintaEspacoDoPalpite (char Palpite[], char PalavraSort[], char ArmazenaPalavraSorteada[]) {
int i;
int j;
int SituLetra;
  //Loop para analisar letra a letra do Palpite
  for (i=0; i<5; i++) {
    
    //Retorna a cor vermelha
    c_textcolor(RED);
    printf ("| ");
    //Verifica a situação da letra e atribui o retorno a um int SituLetra
    //Utiliza-se desse int para evitar de chamar a função várias vezes e dar erro
    SituLetra=SituacaoDaLetra(Palpite, PalavraSort, i, ArmazenaPalavraSorteada);
    
    //Printa em verde se estiver certo e no lugar certo
    if (SituLetra==CERTO_E_LUGAR_CERTO) {
      c_textcolor(GREEN);
      printf ("%c ", toupper(Palpite[i]));
    }
    //Printa em amarelo se existir na palavra mas não está no lugar correto
    else if (SituLetra==CERTO_MAS_LUGAR_ERRADO) {
      c_textcolor(YELLOW);
      printf ("%c ", toupper(Palpite[i]));
    }
    //Caso nenhuma das duas outras condições sejam válidas, significa que a letra não existe na palavra, então printa em cinza (camufla)
    else {
      c_textcolor(LIGHTGRAY);
      printf ("%c ", toupper(Palpite[i]));
    }
  }
  //Retorna a cor vermelha
  c_textcolor(RED);
  printf("|");
  printf ("\n\n\n");
}

// - Função feita para printar o termo corretamente ao final do jogo
void PrintaTermoQuandoAcaba (char PalavraSort[]) {
int i;
char TermoMaiusculo[5];

  ViraMaiuscula(PalavraSort, TermoMaiusculo);
  for (i=0; i<5; i++) {
    c_textcolor(RED);
    printf ("| ");
    c_textcolor(GREEN);
    printf ("%c ", PalavraSort[i]);  
  }
  c_textcolor(RED);
  printf("|");
  printf ("\n\n\n");
}

// - Função feita para printar uma mensagem de parabéns caso o jogador acerte o Termo
void PrintaMensagemDeVitoria(char PalavraSort[], int ModoDeJogo, int Vez, char NomeUm[], char NomeDois[]) {
  c_textbackground(BLACK);

  if (ModoDeJogo==1) {
    printf ("\n\nParabéns você acertou o termo! :)\n\nTermo: ");
    PrintaTermoQuandoAcaba(PalavraSort);
    printf ("\n\n");
  } 

  else if (ModoDeJogo==2) {
    if (Vez==1) {
      printf ("\n\nParabéns! %s acertou o termo! :)\n\nTermo: ", NomeUm);
      PrintaTermoQuandoAcaba(PalavraSort);
      printf ("\n\n");
    }
    else if (Vez==2) {
      printf ("\n\nParabéns! %s acertou o termo! :)\n\nTermo: ", NomeDois);
      PrintaTermoQuandoAcaba(PalavraSort);
      printf ("\n\n");
    }
  }
}
// - Função feita para printar uma mensagem específica caso o jogador não acerte o Termo antes que terminem suas tentativas
void PrintaMensagemDeDerrota(char PalavraSort[], int ModoDeJogo, int Vez) {
  c_textbackground(BLACK);

  if (ModoDeJogo==1) {
    printf ("\n\nPo mano, tava tão difícil assim? Fica pra próxima :(\n\nTermo: ");
    PrintaTermoQuandoAcaba(PalavraSort);
    printf ("\n\n");
  }

  if (ModoDeJogo==2) {
    printf ("\n\nCaraca rapaziada, nem com duas cabeças pensando vocês conseguiram?? Aiai, fica pra proxima :(\n\n");
    PrintaTermoQuandoAcaba(PalavraSort);
    printf ("\n\n");
  }
}

// - Função feita para printar o teclado com suas respectivas manipulações de acordo com a situação de cada letra no jogo
void PrintaTeclado (char Palpite[], char PalavraSort[], char LetrasQueJaForamMasNaoTem[]) {
  int i;
  int j;
  int LetraAindaPode=0;
  char Teclado [27]="QWERTYUIOPASDFGHJKLZXCVBNM";
tPalavras *P;
  
  for (i=0; i<27; i++) {
    //Verifica a situação da letra para impressão no teclado e atribui a um int LetraAindaPode
    //Utiliza-se desse int para evitar de chamar a função várias vezes e dar erro
  LetraAindaPode=VerificaLetraProTeclado(Teclado, PalavraSort, i, LetrasQueJaForamMasNaoTem, Palpite);
    
    //Se a letra ainda pode ter na palavra, ela continua printada com a cor padrão
    //Caso seja alguns caracteres especificamente, printa algumas correções de interface para que pule linha, ou dê mais espaço entre as letras. Isso garante que a interface fique visualmente mais agradável

  if (LetraAindaPode==PODE_TER_AINDA) {
    c_textcolor(RED);
        if (Teclado[i]=='Q') {
          printf ("\t\t\t\t\t\t\t");
        }
        if (Teclado[i]=='A') {
          printf (" ");
        }
        if (Teclado[i]=='Z') {
          printf ("   ");
        }
      
      printf ("%c ", Teclado[i]);
      
        if (Teclado[i]=='P') {
          printf ("\n\t\t\t\t\t\t\t");
        }
        if (Teclado[i]=='L') {
          printf ("\n\t\t\t\t\t\t\t");
        }
        if (Teclado[i]=='M') {
          printf ("\n\n");
        }    
  }  
    
    //Caso contrário, não tem mais chance de existir a letra na palavra, então ela é impressa em cinza (camuflada)
    else {
      c_textcolor(LIGHTGRAY);
        if (Teclado[i]=='Q') {
          printf ("\t\t\t\t\t\t\t");
        }
        if (Teclado[i]=='A') {
          printf (" ");
        }
        if (Teclado[i]=='Z') {
          printf ("   ");
        }

      printf ("%c ", Teclado[i]);
      
        if (Teclado[i]=='P') {
          printf ("\n\t\t\t\t\t\t\t");
        }
        if (Teclado[i]=='L') {
          printf ("\n\t\t\t\t\t\t\t");
        }
        if (Teclado[i]=='M') {
          printf ("\n\n");
        }
    }
  }
}

// - Função feita para printar o pedido de nome do segundo jogador
void PrintaRecebeNomeDoSegundoJogador() {
  printf ("\nInforme o nome do jogador 2\n");
  printf ("Nome: ");
}

// - Função feita para printar uma mensagem caso o jogador escolha uma opção inválida
void PrintaEscolheUmaOpcaoValida() {
  printf ("Escolha uma opção válida\n\n");
}

// - Função feita para printar uma mensagem caso o jogador decida sair do jogo
void PrintaMsgJogadorSaindoDoJogo() {
  printf ("Até a próxima!\n\n\n");
}

// - Função feita para printar uma mensagem para pedir que o jogador confirme se ele realmente deseja sair do jogo
void PrintaMsgDeConfirmacaoSairDoJogo() {
  printf ("Você ainda não jogou nenhum modo, se sair agora terá seu current_streak zerado, deseja continuar?\n\n");
  printf ("1-Continuar\n");
  printf ("2-Sair do Jogo\n\n");
}

void PrintaEstatisticas() {
  LimpaTerminal();
  printf ("\nEstatísticas: \n\n");
  printf ("Ainda não implementada.\n\n");
  printf ("5 - Escolher Novamente \n0 - Sair do Jogo\n\n--> ");
}

void PrintaRanking () {
  LimpaTerminal();
  printf ("\nRanking: \n\n");
  printf ("Ainda não implementado.\n\n");
  printf ("5 - Escolher Novamente \n0 - Sair do Jogo\n\n--> ");
}

void LimpaTerminal() {
  printf("\33[H\33[2J");
}

