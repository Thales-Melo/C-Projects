#include "tExecucao.h"

struct tPalavras {
  char PalavraSorteada[5];
  char LetrasQueNaoTem[52]; 
  char Palpite[5];
  char PalavraSorteadaMaiuscula[5];
  char PalpiteMaiusculo[5];
  char LetrasQueJaForamMasNaoTem[30];
};

struct tJogador {
  char NomeJogador[20];
  char NomeSegundoJogador[20];
  int Chances;
};

// - Função feita para salvar as palavras sorteadas num arquivo .txt
void SalvarPalavraSorteada(char Ps[], FILE *f) {
  f = fopen(PALAVRAS_SORTEADAS,"a+");

  if (f == NULL)
  {
    printf("Erro abertura do arquivo!");
    exit(EXIT_FAILURE);
  }
  fwrite(Ps,sizeof(*Ps),6, f);
  
  fclose(f);
}

//- Função que abre o arquivo palavras.txt e armazena todas as palavras num array com 18289 palavras
void AbreArquivoPalavras(char entry1[18289][5]) {
  FILE *p = fopen(PALAVRAS, "r");
  if (p == NULL) {
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }
  int i = 0, count = 0;
  while (count < 18289) {
    fscanf(p, "%s", entry1[i]);
    i += 1;
    count++;
  }
  fclose(p);
}

// - Função que recebe como parâmetro uma string de Palavra, e atribui a ela uma palavra sorteada no arquivo de palavras
char * RecebePalavra (char Palavra[], char TERMO[18289][5]) {

  int num = SorteiaPalavra();
  CopiaString(Palavra, TERMO[num]);

  return Palavra;
}

// - Função que sorteia um número correspondente a alguma palavra do arquivo de palavras
// - Retorna um número entre 18289 (NUM PALAVRAS ARQUIVO)
int SorteiaPalavra() {
  int num = 0;
  num = rand() % 18289;
  return num;
}

// - Função que verifica se a letra ainda aparece na palavra sorteada
// - Retorna TRUE se ainda aparece; Retorna FALSE se não aparece mais
int VerificaRepeticao (char ArmazenaPalavraSorteada[], char Letra) {
  int i;
  
  for (i=0; i<5; i++) {
    if (Letra==ArmazenaPalavraSorteada[i]) {
      return TRUE;
    }
  }

  return FALSE;
}

// - Função que verifica a situação da letra em sua determinada posição
// - Retorna CERTO_E_LUGAR_CERTO se a letra pertencer aquela posição; Retorna CERTO_MAS_LUGAR_ERRADO se a letra exisitr na palavra mas estiver na posição errada; Retorna NAO_CONTEM_A_LETRA se não existir a letra na palavra
int SituacaoDaLetra (char Palpite[], char PalavraSorteada[], int i, char ArmazenaPalavraSorteada[]) {
int j;
int z;

  //Verifica como prioridade as letras que estão corretas e no lugar certo na palavra
  //Mas não retorna nada, pois serve apenas para garantir que não será verificada primeiro uma letra que posteriormente estará listada como correta
  //Apenas apaga a letra da string ArmazenaPalavraSorteada
  for (z=0; z<5; z++) {
    if (Palpite[z]==PalavraSorteada[z]) {
      ApagaLetraDoArmazenaPalavra(ArmazenaPalavraSorteada, Palpite[z]);
    }
  }

  //Verifica se a letra na posição i (posição passada como parâmetro da função) está correta e no lugar certo
  //Retorna CERTO_E_LUGAR_CERTO caso a condição seja verdadeira
    if (Palpite[i]==PalavraSorteada[i]) {
      ApagaLetraDoArmazenaPalavra(ArmazenaPalavraSorteada, Palpite[i]);
      return CERTO_E_LUGAR_CERTO;
    } 
  
  //Verifica se a letra na posição i (posição passada como parâmetro da função) está correta mas no lugar errado
  //Retorna CERTO_MAS_LUGAR_ERRADO caso a condição seja verdadeira
  for (j=0; j<5; j++) {
    if (Palpite[i]==PalavraSorteada[j]&&i!=j) {
      if (VerificaRepeticao(ArmazenaPalavraSorteada, Palpite[i])==TRUE) {
        ApagaLetraDoArmazenaPalavra(ArmazenaPalavraSorteada, Palpite[i]); 
        return CERTO_MAS_LUGAR_ERRADO;
      } 
    }
  } 
  
  //Caso nenhuma das condições anteriores se satisfaça, significa que não existe a letra na palavra
  //Retorna NAO_CONTEM_A_LETRA
  return NAO_CONTEM_A_LETRA;
  
}

// - Função que compara o palpite com a palavra sorteada para verificar se está correto
// - Retorna CERTO se a palavra estiver certa e retorna ERRADO se ela estiver errada
int VerificaPalpite (char PalavraSort[], char Palpite[]) {
  int i=0;
  int AcertouLetra=0;
  
  //Loop para comparar cada caractere e verificar se eles são iguais
    for (i=0; i<5; i++) {
      if (Palpite[i]==PalavraSort[i]) {
        AcertouLetra++;        
      }
    }
  
  //Se as cinco letras estiverem corretas, então AcertouLetra deve ser igual a 5, entrando nessa condição, e retornando CERTO para o palpite
    if (AcertouLetra==5) {
      return CERTO;
    }
  //Caso contrário, retorna ERRADO, significando que o palpite não está condizente com a palavra sorteada
    else {
      return ERRADO;
    }

}

// - Função que verifica se o palpite é válido, isto é, ele deve existir no arquivo predefinido de palavras aceitas
// - Compara o palpite com cada palavra do arquivo
// - Retorna VALIDO se ele existir e INVALIDO caso contrário
int VerificaSePalpiteValido (char Palpite[]) {
char TERMO[18289][5];
AbreArquivoPalavras(TERMO);
int i;
int j;

  //loop com função que retorna VALIDO se o palpite for uma palavra que existe no arquivo de palavras do jogo, INVALIDO se não existe
  for (i=0; i<=18289; i++) {
    if (memcmp(Palpite, TERMO[i], 5)==0&&strlen(Palpite)==5) {
      return VALIDO;
      break;
    }
  }

  return INVALIDO;
  
}


// - Função que executa as tentativas do Jogo Termo
// - Recebe um palpite e faz as verificações de validade do palpite
// - Só sai da função quando o usuário inserir um palpite válido
// - Retorna o array Palpite;
// - Possui dois casos: Modo 1 Jogador e Modo 2 Jogadores. Caso seja dois jogadores, alterna entre eles por meio do int Vez que é passado como parâmetro
char * JogaModoTermo (char Palpite[], int ModoDeJogo, int Vez, char NomeUm[], char NomeDois[]) {
  
  int i, j;
  int Valido;
  int Verifica;

  if (ModoDeJogo==1) {
  while (Verifica!=VALIDO) {
    scanf ("%s", Palpite);

    Verifica=VerificaSePalpiteValido(Palpite);
    
    if (Verifica==VALIDO) {
      break;
    }
    else {
      printf ("\nDigite um termo válido de exatamente 5 letras: ");
    }
  }
  return Palpite;
  }

  else if (ModoDeJogo==2) {
    if (Vez==1) {
      printf ("Jogador %s digite uma palavra a sua escolha: ", NomeUm);
      while (Verifica!=VALIDO) {

        scanf ("%s", Palpite);
        Verifica=VerificaSePalpiteValido(Palpite);

        if (Verifica==VALIDO) {
          break;
        }
        else {
          printf ("\nDigite um termo válido de exatamente 5 letras: ");
        }    
      }   
    }
      
    else if (Vez==2) {
      printf ("Jogador %s digite uma palavra a sua escolha: ", NomeDois);
      while (Verifica!=VALIDO) {

        scanf ("%s", Palpite);
        Verifica=VerificaSePalpiteValido(Palpite);
        
        if (Verifica==VALIDO) {
          break;
        }
        else {
          printf ("\nDigite um termo válido de exatamente 5 letras: ");
        }
      }   
    }
  }
  return Palpite;
}

// - Função que faz as verificações da situação de cada letra já tentada
// - k<=30 porque no máximo 30 caracteres podem ser inseridos ao longo do jogo, considerando que são 6 tentativas de 5 letras.
// - Recebe um array Teclado que armazena cada caractere a ser impresso na interface, palavra sorteada, letras que já foram mas não tem na palavra e o palpite
// - Compara a letra do teclado com cada letra que não pode mais ter para retornar JA_TENTOU_MAS_NAO_TEM se a letra deve ser impressa camuflada, ou retorna PODE_TER_AINDA caso ela ainda seja uma possibilidade
int VerificaLetraProTeclado(char Teclado[], char PalavraSort[], int i, char LetrasQueJaForamMasNaoTem[], char Palpite[]) {
  int j, k, l;
  
  //Loop para verificar se a letra a ser printada na interface do teclado ainda pode ter ou não.
  for (k=0; k<=30; k++) {
      if (LetrasQueJaForamMasNaoTem[k]==Teclado[i]&&LetrasQueJaForamMasNaoTem[k]!='\0') {        
          return JA_TENTOU_MAS_NAO_TEM;
      }  
  }
  return PODE_TER_AINDA;
  
}


// - Função que salva num array "LetrasQueJaForamEAindaPodemTer" todas as letras que ainda podem aparecer na palavra
// - Intuito de evitar a dupla verificação (e possível falha) de uma letra que aparece mais de uma vez no palpite
// - Retorna um array "LetrasQueJaForamEAindaPodemTer"
char * SalvaLetraQueAindaPodemTer (char LetrasQueJaForamEAindaPodemTer[], char Palpite[], char PalavraSort[]) {
  int i, j;
  char ArmazenaPalavraSorteada[5];
  int SituLetra;
  
  //Copia a palavra sorteada para um array ArmazenaPalavraSorteada, com o intuito de possuir um array com a palavra sorteadaque possa ser manipulado sem interferir no restante do código
  CopiaString(ArmazenaPalavraSorteada, PalavraSort);

  //Double Loop que verifica a situação da letra para inseri-la no array "LetrasQueJaForamEAindaPodemTer" caso ela tenha sido tentada e verificou-se que ela existe na palavra 
  for (i=0; i<5; i++) {
    SituLetra=SituacaoDaLetra(Palpite, PalavraSort, i, ArmazenaPalavraSorteada);
    
    if (SituLetra==CERTO_E_LUGAR_CERTO||SituLetra==CERTO_MAS_LUGAR_ERRADO) {
      for (j=0; j<=30; j++) {
        if (LetrasQueJaForamEAindaPodemTer[j]=='\0') {
          LetrasQueJaForamEAindaPodemTer[j]=Palpite[i];
          break;
      }
    }
  }
}
  return LetrasQueJaForamEAindaPodemTer;
}

// - Função que salva num array "LetrasQueJaForamMasNaoTem" todas as letras que não tem mais chance de estar na palavra
// - Utiliza-se de um array ArmazenaPalavraSorteada para sua respectiva manipulação e usual comparação dentro da função
// - Retorna um array "LetrasQueJaForamMasNaoTem"
char * SalvaLetrasQueNaoPodemMaisTer(char LetrasQueJaForamMasNaoTem[], char Palpite[], char PalavraSort[], char LetrasQueJaForamEAindaPodemTer[]) {
int i, j, z;
int SituLetra;
int count=0;
char ArmazenaPalavraSorteada[5];

  //Copia a palavra sorteada para um array ArmazenaPalavraSorteada, com o intuito de possuir um array com a palavra sorteadaque possa ser manipulado sem interferir no restante do código
  CopiaString (ArmazenaPalavraSorteada, PalavraSort);
    
  //Loop que verifica letra por letra e compara com o array LetrasQueJaForamEAindaPodemTer para evitar que se adicione erroneamente, em "LetrasQueJaForamMasNaoTem", uma letra que já foi verificada que existe na palavra
  for (i=0; i<5; i++) {
  SituLetra=SituacaoDaLetra(Palpite, PalavraSort, i, ArmazenaPalavraSorteada);

    if (SituLetra==NAO_CONTEM_A_LETRA) {
      for (z=0; z<=30; z++) {
        if (Palpite[i]==LetrasQueJaForamEAindaPodemTer[z]) {
          count++;
        }
      }
      
      if (count==0) {
        for (j=0; j<=30; j++) {
          if (LetrasQueJaForamMasNaoTem[j]=='\0') {
            LetrasQueJaForamMasNaoTem[j]=Palpite[i];
            break;
          }
        }
      }
    }
  }
  return LetrasQueJaForamMasNaoTem;
}

// - Função auxiliar que "apaga" uma letra da string para usuais comparações dentro da função SituaçãoDaLetra
// - Retorna a string com a letra determinada substituida por um caractere de ponto "."
void ApagaLetraDoArmazenaPalavra (char String[], char Letra) {
  int i;
  for (i=0; i<5; i++) {
    if (String[i]==Letra) {
      String[i]='.';
      break;
    }
  }
}

//Função que sorteia um jogador caso o modo de jogo seja 2 players
//Retorna um int Vez com o número do jogador que irá começar
int SorteiaVezDoisJogadores() {
  srand(time(NULL));
  int Vez = 0; 
  Vez = rand() % 2 + 1;
  return Vez;
}

//Função que scanea um int para o jogador escolher o modo de jogo
//Retorna um int Modo
int EscolheModo() {
  int Modo;
  
  scanf ("%d", &Modo);
  
  return Modo;
}

//Função que scanea um int para o jogador decidir se quer continuar ou sair do jogo
//Retorna um int Decide
int DecideSeQuerContinuarOuNao() {
  int Decide;
  scanf ("%d", &Decide);
  return Decide;
}

int RecebeEscolha () {
  int Escolhe;
  while (Escolhe!=5||Escolhe!=0) {
    scanf ("%d", &Escolhe);
    if (Escolhe==5||Escolhe==0) {
      break;
    }
    else {
      printf ("\nDigite uma opção válida: \n\n--> ");
    }
  }  
  return Escolhe;
}