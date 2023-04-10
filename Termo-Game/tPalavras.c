// FUNÇÕES DE ARQUIVO (PARTE SEPARADA) //

/*
#include "tPalavras.h"
#define N_PALAVRAS 18289

struct PS{
  char** palavras_sorteadas;
  int cont_ps;
  char* sorteada;
};

//Função que passa palavras.txt pra dentro do código
char** AbreArquivoPalavras(char** palavras){
  FILE* f_palavras;

  //abre arquivo
  f_palavras = fopen("palavras.txt", "r");
  
  if(f_palavras == NULL){
    printf("\nErro na abertura do arquivo.\n");
    exit(1);
  }

  palavras = (char**) malloc(sizeof(char*) * N_PALAVRAS);
  
  int dummy;
  
  //loop que passa todas as palavras pra dentro do ponteiro
  for(int i=0; i<N_PALAVRAS; i++){
    
    *(palavras+i) = (char*) malloc(sizeof(char) * 6);
    
    dummy = fscanf(f_palavras, "%s ", palavras[i]); 

    
//    equivaleria:
//
//    result = fgets(palavras[i], 6, f_palavras);
//    dummy = fgetc(f_palavras); //consome o \n ao final de cada palavra
//    
//    if(result == NULL){
//      printf("\nErro na leitura do arquivo.\n");
//    } 
    
    
  }

  //fecha arquivo
  fclose(f_palavras);

  return palavras;
}

//Função que libera cada palavra e o próprio double pointer palavras
void LiberaPalavras(char** palavras){

  for(int i=0; i<N_PALAVRAS; i++){
    free(palavras[i]);
    palavras[i] = NULL;
  }

  free(palavras);
  palavras = NULL;
  
}

//Função que lê o timestamp, quantidade de palavras sorteadas e todas as palavras já sorteadas e inicializa na memória
PS* LePalavrasSorteadas(PS* ps){
  FILE *f_palavras_sorteadas;

  f_palavras_sorteadas = fopen("palavras_sorteadas.txt", "r");
  
  if(f_palavras_sorteadas == NULL){
    printf("\nErro na abertura do arquivo.\n");
    exit(1);
  }

  ps = (PS*) malloc(sizeof (*ps));

  int dummy=0;
  dummy = fscanf(f_palavras_sorteadas, "%d", &ps->cont_ps);
  
  ps->palavras_sorteadas = (char**) malloc(sizeof(char*) * ps->cont_ps);

  for(int i=0; i<ps->cont_ps; i++){
    ps->palavras_sorteadas[i] = malloc(sizeof(char) * 6);
    dummy = fscanf(f_palavras_sorteadas, "%s ", ps->palavras_sorteadas[i]);
  } 

  fclose(f_palavras_sorteadas);

  return ps;
}

void SorteiaPalavra (PS* ps, char** palavras) {
  //permite que a ordem das palavras sorteadas seja a mesma pro dia todo
  int timestamp = time(NULL) / 86400;
  srand(timestamp);
  
  do {
    int num = rand() % 18289;
    ps->sorteada = malloc(sizeof(char)*6);
    ps->sorteada = palavras[num];
  
    for(int i=0; i<ps->cont_ps; i++){
      if(ps->sorteada == ps->palavras_sorteadas[i]) continue;
    }
    
    break;
    
  } while(1);
}

//Função que registra as informações do arquivo palavras_sorteadas atualizadas
void RegistraPalavraSorteada(PS* ps, char** palavras){
  FILE *f_palavras_sorteadas;

  f_palavras_sorteadas = fopen("palavras_sorteadas.txt", "w");
  
  if(f_palavras_sorteadas == NULL){
    printf("\nErro na abertura do arquivo.\n");
    exit(1);
  }

// int flag = 0;
//  // verifica se ainda eh o mesmo dia para o jogador
//  if(jogador->timestamp != time(NULL) / 86400){
//    jogador->timestamp = time(NULL) / 86400;
//    flag = 1;
//  }
  
  fprintf(f_palavras_sorteadas, "%d\n", ps->cont_ps);
  for(int i=0; i<ps->cont_ps; i++){
    fprintf(f_palavras_sorteadas, "%s\n", ps->palavras_sorteadas[i]);
  }
// if(flag == 1)
  fprintf(f_palavras_sorteadas, "%s\n", ps->sorteada);

  fclose(f_palavras_sorteadas);
  
}

void LiberaPalavrasSorteadas(PS* ps){

  for(int i=0; i<ps->cont_ps; i++){
    free(ps->palavras_sorteadas[i]);
    ps->palavras_sorteadas[i] = NULL;
  }

  free(ps->palavras_sorteadas);
  ps->palavras_sorteadas = NULL;

  free(ps->sorteada);
  ps->sorteada = NULL;

  free(ps);
  
}

char* GetPalavraSorteada(PS* ps, int num){
  return ps->palavras_sorteadas[num];
}
*/