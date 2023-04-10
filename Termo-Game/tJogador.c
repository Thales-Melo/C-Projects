#include "tJogador.h"

//Função que recebe o nome do jogador e o retorna
char * RecebeNomeJogador (char Nome[]) {
    scanf ("%s", Nome);
    printf ("\n");
    printf("\33[H\33[2J");
    return Nome;
}

//Função que salva o nome dos jogadores num arquivo .bin
void SalvarNomeJogadores(char Nome[], FILE *f) {
  f = fopen(NOMES,"a+");

  if (f == NULL)
  {
    printf("Erro abertura do arquivo!");
    exit(EXIT_FAILURE);
  }
  fwrite(Nome,sizeof(char *),5, f);
  
  fclose(f);
}


// FUNÇÕES DE ARQUIVO (PARTE SEPARADA) //

/*
  struct jogadores{
  char nome[20];
  int n_jogos, n_vitorias;
  int vitorias_dia, timestamp;
  float p_vitoria;
  int streak_check, current_streak, max_streak;
  int v_1;
  int v_2;
  int v_3;
  int v_4;
  int v_5;
  int v_6;
  int dead;
};



//Função que aloca jogador e recebe nome
tJogador* RecebeNomeJogador(tJogador *jogador){
  jogador = (tJogador*) malloc(sizeof (*jogador));
  
  if(jogador == NULL){
    exit(EXIT_FAILURE);
  }

  int dummy=0;
  dummy = scanf("%s", jogador->nome);

  return jogador;
}



void LiberaJogador(tJogador *jogador){
  free(jogador);
  jogador = NULL;
}



//Função que registra no arquivo jogadores.bin as informações dos jogadores
int RegistraDadosJogadores(tJogador *jogador, tJogador **todos_jogadores){

  
  FILE *f_jogadores;
  f_jogadores = fopen("jogadores.bin", "rb");

  tJogador jogador_aux;
  int cont_jd = 0;
  int dummy = 0;

  //loop que confere quantidade de jogadores (descobre cont_jd de novo)
  while(!feof(f_jogadores)){    
    cont_jd += fread(&jogador_aux, sizeof(tJogador), 1, f_jogadores);    
  }

  fclose(f_jogadores);
  
  //agora sim registra
  f_jogadores = fopen("jogadores.bin", "wb");
  
  if(f_jogadores == NULL){
    printf("\nErro na abertura do arquivo.\n");
    exit(1);
  }

  int flag=0;
  int result=2;
  
  for(int i=0; i<cont_jd; i++){
    result = strcmp(todos_jogadores[i]->nome, jogador->nome);
    if(result == 0){
      todos_jogadores[i] = jogador;
      flag=1;
      break;
    }
  }
  
  for(int i=0; i<cont_jd; i++){
    result = fwrite(todos_jogadores[i], sizeof(*jogador), 1, f_jogadores);
  }
  
  if(flag == 0){
    fwrite(jogador, sizeof(*jogador), 1, f_jogadores);
  }

  fclose(f_jogadores);

  return cont_jd;
}



//Função que acha o jogador procurado, se houver, lendo o arquivo binário. Caso não tenha, cria um.
tJogador** LeJogadoresBin(tJogador* jogador){
  FILE *f_jogadores;
  f_jogadores = fopen("jogadores.bin", "rb");

  tJogador jogador_aux;
  int cont_jd = 0;
  int dummy = 0;

  //loop que confere quantidade de jogadores
  while(!feof(f_jogadores)){    
    cont_jd += fread(&jogador_aux, sizeof(tJogador), 1, f_jogadores);    
  }

  //volta o arquivo pro começo
  rewind(f_jogadores);

  //passa todos os jogadores registrados no arquivo pro ponteiro
  tJogador **todos_jogadores;
  todos_jogadores = (tJogador**) malloc(sizeof(tJogador*) * cont_jd);
  for(int i=0; i<cont_jd; i++){
    todos_jogadores[i] = (tJogador*) malloc(sizeof(tJogador));
    dummy = fread(todos_jogadores[i], sizeof(tJogador), 1, f_jogadores);
  }

  int result=2;
  //compara o nome recebido com o de todos os jogadores até achar o próprio e passa suas informações
  for(int i=0; i<cont_jd; i++){
    result = strcmp(todos_jogadores[i]->nome, jogador->nome);
    if(result == 0){
      jogador = todos_jogadores[i];
      break;
    }
  }

  //inicializa jogador se for novo
  if(result != 0){
    jogador->n_jogos = 0;
    jogador->n_vitorias = 0;
    jogador->vitorias_dia = 0;
    jogador->timestamp = time(NULL) / 86400;
    jogador->p_vitoria = 0;
    jogador->streak_check = 0;
    jogador->current_streak = 0;
    jogador->max_streak = 0;
    jogador->v_1 = 0;
    jogador->v_2 = 0;
    jogador->v_3 = 0;
    jogador->v_4 = 0;
    jogador->v_5 = 0;
    jogador->v_6 = 0;
    jogador->dead = 0;
  }
  
  fclose(f_jogadores);

  return todos_jogadores;
}



void LiberaTodosJogadores(tJogador** todos_jogadores, int cont_jd){
  for(int i=0; i<cont_jd; i++){
    free(todos_jogadores[i]);
  }
  free(todos_jogadores);
}

*/