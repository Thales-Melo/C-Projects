  #include "tPlaylist.h"

struct tPlaylist {

  char *nome; 

  int *indice_musicas;

  int qtd_musicas;
};

struct tPlaylistData {
  tPlaylist **lista_playlists;
  int QuantPlaylists;
};
  
struct ODE {
  float distancia_euclidiana;
  int indice_musica;
};


tPlaylist** InicializaListaPlaylists(tPlaylistData *TPD){
  TPD->lista_playlists = (tPlaylist**)malloc(sizeof(tPlaylist*) * 1);

  return TPD->lista_playlists;
}

//----------------------------------------------------------------------------//

tPlaylistData* InicializaPlaylistData(tPlaylistData *TPD){
  TPD = (tPlaylistData*)malloc(sizeof(tPlaylistData) * 1);

  return TPD;
}

//----------------------------------------------------------------------------//

tPlaylistData* CriaPlaylist(tPlaylistData *TPD){
  
  printf("\nDigite o nome da playlist (máximo de 30 caracteres): ");

  //debug
  scanf ("\n");
  
  char nome_aux[31];
  fgets(nome_aux, 30, stdin);
  
  
  //mata \n
  int n = strlen(nome_aux);
  nome_aux[n - 1] = '\0';

  TPD->lista_playlists = (tPlaylist**)realloc(TPD->lista_playlists, sizeof(tPlaylist*) * (TPD->QuantPlaylists + 1));
  
  TPD->lista_playlists[TPD->QuantPlaylists] = (tPlaylist*)malloc(sizeof(tPlaylist) * 1);
  
  TPD->lista_playlists[TPD->QuantPlaylists]->nome = strdup(nome_aux);

  
  TPD->lista_playlists[TPD->QuantPlaylists]->qtd_musicas = 0;
  TPD->QuantPlaylists += 1;

  return TPD;
}

//----------------------------------------------------------------------------//

tPlaylistData* CarregaPlaylists(tPlaylistData *TPD){

  TPD = InicializaPlaylistData(TPD);
  TPD->lista_playlists = InicializaListaPlaylists(TPD);
  
  FILE *playlists = fopen("playlists_salvas.bin", "rb");
    if(playlists == NULL){
      printf("\nErro na abertura do arquivo playlists\n");
      exit(1);
    }

  //debug
  /*
  fclose(playlists);
  fopen("playlists_salvas.bin", "wb");
  if(playlists == NULL){
      printf("\nErro na abertura do arquivo playlists\n");
      exit(1);
    }
  int uga=0;
  fwrite(&uga, 4, 1, playlists);
  fclose(playlists);
  exit(2);
  */

  TPD->QuantPlaylists = 0;

  int total_lido = 0;
  
  total_lido = fread(&TPD->QuantPlaylists, sizeof(int), 1, playlists);
    if(total_lido != 1){
      printf("\nErro na leitura do binário\n");
      exit(1);
    }

  
  if(TPD->QuantPlaylists == 0) return TPD;

  if(TPD->QuantPlaylists > 1)
  TPD->lista_playlists = (tPlaylist**)realloc(TPD->lista_playlists, sizeof(tPlaylist*) * TPD->QuantPlaylists);

  
  int tam_nome = 0;

  for(int i=0; i<TPD->QuantPlaylists; i++){

    TPD->lista_playlists[i] = (tPlaylist*)malloc(sizeof(tPlaylist) * 1);
    
    fread(&tam_nome, sizeof(int), 1, playlists);
    fread(&TPD->lista_playlists[i]->qtd_musicas, sizeof(int), 1, playlists);

    
    // strlen não retorna valor contando com \0 >> (tam_nome + 1)
    TPD->lista_playlists[i]->nome = (char*)malloc(sizeof(char) * (tam_nome + 1));
    fread(TPD->lista_playlists[i]->nome, sizeof(char), tam_nome, playlists);
    TPD->lista_playlists[i]->nome[tam_nome] = '\0';
    

    if(TPD->lista_playlists[i]->qtd_musicas > 0){
      
      TPD->lista_playlists[i]->indice_musicas = (int*)malloc(sizeof(int) * TPD->lista_playlists[i]->qtd_musicas);
      
      for(int j=0; j<TPD->lista_playlists[i]->qtd_musicas; j++){
        fread(&TPD->lista_playlists[i]->indice_musicas[j], sizeof(int), 1, playlists);
      }
      
    }

  }

  fclose(playlists);

  return TPD;
}

//----------------------------------------------------------------------------//

void DescarregaPlaylists(tPlaylistData* TPD){

  FILE *playlists = fopen("playlists_salvas.bin", "wb");
    if(playlists == NULL){
      printf("\nErro na abertura do arquivo playlists\n");
      exit(1);
    }

  int total_gravado = 0;
  int qtd_musicas = 0;
  int tam_nome = 0;
  
  fwrite(&TPD->QuantPlaylists, sizeof(int), 1, playlists);

  for(int i=0; i<TPD->QuantPlaylists; i++){
    
    tam_nome = strlen(TPD->lista_playlists[i]->nome);
    total_gravado = fwrite(&tam_nome, sizeof(int), 1, playlists);
    
    qtd_musicas = TPD->lista_playlists[i]->qtd_musicas;
    total_gravado = fwrite(&qtd_musicas, sizeof(int), 1, playlists);

    total_gravado = fwrite(TPD->lista_playlists[i]->nome, sizeof(char), tam_nome, playlists);

    for(int j=0; j<qtd_musicas; j++){
      total_gravado = fwrite(&TPD->lista_playlists[i]->indice_musicas[j], sizeof(int), 1, playlists);
    }
    
  }

  fclose(playlists);
}

//----------------------------------------------------------------------------//

void ListarPlaylists(tPlaylistData *TPD){

  for(int i=0; i<TPD->QuantPlaylists; i++){
    printf("\n");
    printf("Indice[%d]    ", i);
    printf("Nome: %s    ", TPD->lista_playlists[i]->nome);
    printf("Musicas: %d    ", TPD->lista_playlists[i]->qtd_musicas);
    printf("\n\n");
  }
  
  char Lixo;
  scanf ("%c", &Lixo);
}

//----------------------------------------------------------------------------//

void ListarUmaPlaylist(tPlaylistData *TPD, tSongData *TSD){

  printf("\nDigite o índice da playlist: ");

  int indice_playlist = 0;

  //loop pra garantir que vai entrar um número válido
  while (!(indice_playlist>=TPD->QuantPlaylists && indice_playlist < 0)) {
    scanf("%d", &indice_playlist);

    if(indice_playlist >= TPD->QuantPlaylists || indice_playlist < 0){
      printf("\nIndice inválido.\n");
      printf ("\nTente novamente: ");
    }
    else {
      break;
    }
  }
  printf("\n");

  if(TPD->lista_playlists[indice_playlist]->qtd_musicas == 0){
    printf("Playlist %d vazia\n", indice_playlist); 
    char Lixo;
    scanf ("%c", &Lixo);
    return;
  }
  
  printf("Nome: %s\n", TPD->lista_playlists[indice_playlist]->nome);

  printf("Títulos: \n");
  
  for(int i=0; i<TPD->lista_playlists[indice_playlist]->qtd_musicas; i++){
    printf("  %s\n\n", GetTitulo(TSD, TPD->lista_playlists[indice_playlist]->indice_musicas[i]));
  }
  
  printf("\n");

  char Lixo;
  scanf ("%c", &Lixo);
}

//----------------------------------------------------------------------------//

tPlaylistData* AdicionarMusicaPlaylist(tPlaylistData *TPD){

  printf("\nDigite o indice da música: ");

  int indice_musica = 0;
  scanf("%d", &indice_musica);

  //alterado
  indice_musica -= 1;
  
  printf("\nDigite o indice da playlist: ");
  
  int indice_playlist = 0;
  scanf("%d", &indice_playlist);

  int qtd_musicas = TPD->lista_playlists[indice_playlist]->qtd_musicas;

  //guarda os indices das musicas postas na lista de playlists
  if(qtd_musicas == 0){
    TPD->lista_playlists[indice_playlist]->indice_musicas = (int*)malloc(sizeof(int) * 1);
    TPD->lista_playlists[indice_playlist]->indice_musicas[qtd_musicas] = indice_musica;
    TPD->lista_playlists[indice_playlist]->qtd_musicas += 1;
  }
    
  else {
    TPD->lista_playlists[indice_playlist]->indice_musicas = (int*)realloc(TPD->lista_playlists[indice_playlist]->indice_musicas, sizeof(int) * (qtd_musicas + 1));
    TPD->lista_playlists[indice_playlist]->indice_musicas[qtd_musicas] = indice_musica;
    TPD->lista_playlists[indice_playlist]->qtd_musicas += 1;
  }
  
  char Lixo;
  scanf ("%c", &Lixo);
  
  return TPD;
}

//----------------------------------------------------------------------------//

void LiberaPlaylists(tPlaylistData *TPD){

  for(int i=0; i<TPD->QuantPlaylists; i++){

    if(TPD->lista_playlists[i]->nome != NULL){
        free(TPD->lista_playlists[i]->nome);
        TPD->lista_playlists[i]->nome = NULL;
      }
    
    if(TPD->lista_playlists[i]->qtd_musicas > 0){
    
      if(TPD->lista_playlists[i]->indice_musicas != NULL){
        free(TPD->lista_playlists[i]->indice_musicas);
        TPD->lista_playlists[i]->indice_musicas = NULL;
      }

    }

    if(TPD->lista_playlists[i] != NULL){
        free(TPD->lista_playlists[i]);
        TPD->lista_playlists[i] = NULL;
      }
  }
  
  if(TPD->lista_playlists != NULL){
    free(TPD->lista_playlists);
    TPD->lista_playlists = NULL;
    }


  if (TPD!=NULL) {
      free(TPD);
      TPD = NULL;
    }
  
}

//----------------------------------------------------------------------------//

void RecomendaMusica(tSongData *TSD, tPlaylistData *TPD) {

  int indice_playlist;
  printf ("\nDigite o índice da playlist: ");
  scanf ("%d", &indice_playlist);
  
  int k_musicas;
  printf ("\nDigite o número de músicas: ");
  scanf ("%d", &k_musicas);

  float *media_playlist = (float*)calloc(8, sizeof(float));

  
  //soma as caracteristicas de cada musica no vetor media_playlist
  //para depois dividir pela quantidade de musicas, achando a media da playlist
  for(int i=0; i<TPD->lista_playlists[indice_playlist]->qtd_musicas; i++) {
    
    for(int NumCaracteristica=0; NumCaracteristica<8; NumCaracteristica++) {
      
      media_playlist[NumCaracteristica] += GetCaracteristicas(TSD, TPD->lista_playlists[indice_playlist]->indice_musicas[i], NumCaracteristica);
      
    }
  }
  
  for(int NumCaracteristica=0; NumCaracteristica<8; NumCaracteristica++) {
    
    media_playlist[NumCaracteristica] /= TPD->lista_playlists[indice_playlist]->qtd_musicas;
    
  }
  
  int total_mus = GetQuantMusicas(TSD);
  float **lista_caracteristicas_musicas = (float**)malloc(sizeof(float*) * total_mus);

  
  //passa todas as caracteristicas de todas as musicas para essa nova lista
  //a fim de realizar o calculo da distancia euclidiana
  for(int i=0; i<total_mus; i++){

    lista_caracteristicas_musicas[i] = (float*)malloc(sizeof(float) * 8);

    for(int NumCaracteristica=0; NumCaracteristica<8; NumCaracteristica++) {
      
      lista_caracteristicas_musicas[i][NumCaracteristica] = GetCaracteristicas(TSD, i, NumCaracteristica);
      
    }
  }

  
  //ordena por distancia euclidiana
  ODE **lista_musicas_ordenadas = (ODE**)malloc(sizeof(ODE*) * total_mus);
  
  float diferenca_vet;
  
  for(int i=0; i<total_mus; i++){

    diferenca_vet = 0;
    
    for(int NumCaracteristica=0; NumCaracteristica<8; NumCaracteristica++) {
      
       diferenca_vet += pow((lista_caracteristicas_musicas[i][NumCaracteristica] - media_playlist[NumCaracteristica]), 2);
      
    }

    lista_musicas_ordenadas[i] = (ODE*)malloc(sizeof(ODE));
    
    lista_musicas_ordenadas[i]->distancia_euclidiana = sqrt(diferenca_vet);
    lista_musicas_ordenadas[i]->indice_musica = i;
      
  }

  
  //ordena musicas de forma crescente em relação à distancia euclidiana (quick sort)
  QuickSort(lista_musicas_ordenadas, 0, (total_mus - 1));
  
    
  printf ("\nAs %d músicas mais parecidas com a playlist desejada são:\n\n", k_musicas);

  char *nome_musica;
  
  for(int k=1; k <= k_musicas; k++) {

    if(k > 1) free(nome_musica);
    
    nome_musica = strdup(GetNomeMusica(TSD, lista_musicas_ordenadas[k]->indice_musica));
    
    Negrito(1); printf ("%d° mais parecida: ", k);
    Negrito(0); printf ("%s\n", nome_musica);
    Negrito(1); printf ("Índice: ");
    Negrito(0); printf ("%d\n\n", (lista_musicas_ordenadas[k]->indice_musica + 1));
  }

  //acho q n precisa disso
  //char Lixo;
  //scanf ("%c", &Lixo);
  scanf("%*c");

  //libera tudo
  for(int i=0; i<total_mus; i++){
    if(lista_caracteristicas_musicas[i] != NULL){
      free(lista_caracteristicas_musicas[i]);
      lista_caracteristicas_musicas[i] = NULL;
    }
    
    if(lista_musicas_ordenadas[i] != NULL){
      free(lista_musicas_ordenadas[i]);
      lista_musicas_ordenadas[i] = NULL;
    }
  }

  if(lista_caracteristicas_musicas != NULL){
      free(lista_caracteristicas_musicas);
      lista_caracteristicas_musicas = NULL;
    }

  if(lista_musicas_ordenadas != NULL){
      free(lista_musicas_ordenadas);
      lista_musicas_ordenadas = NULL;
    }
  
  if(media_playlist != NULL){
      free(media_playlist);
      media_playlist = NULL;
    }
  
  if(nome_musica != NULL){
      free(nome_musica);
      nome_musica = NULL;
    }

}

//----------------------------------------------------------------------------//

void GerarRelatorio(tPlaylistData *TPD, tSongData *TSD){
/*
  struct ADD{
    int* musicas_add;  // guarda os indices de todas as musicas add em playlists
    int* qtd_mus_add;  // inicia com 0 e sempre tem a mesma quantidade de elementos de musicas_add / quando alguma musica repete, soma +1 no indice do vetor correspondente

    char* artistas_add; //mesma coisa pros artistas, só muda que vão ser guardados por nome / strcmp
    int* qtd_art_add;
  };

  int cont_mus_add = 0;
  int cont_art_add = 0;

  int *musicas_add = (int*)malloc(sizeof(int));
  int *artistas_add = (int*)malloc(sizeof(int));

  int cont_mus_aloc = 1;
  int cont_art_aloc = 1;

  for(int i=0; i < TPD->QuantPlaylists; i++){
 
    for(int j=0; j < TPD->lista_playlists[i]->qtd_musicas; j++) {

      if(cont_mus_aloc == cont_mus_add){
        cont_mus_aloc *= 2;
        musicas_add = (int*)realloc(musicas_add, sizeof(int) * cont_mus_aloc);
      }
      
      musicas_add[cont_mus_add] = TPD->lista_playlists[i]->indice_musicas[j];
      cont_mus_add += 1;
    }
    
  }

  //artistas: -

  
  //ordena musicas
  //ordena artistas

  
  FILE *musicas_relatorio = fopen("musicas_relatorio.txt", "w");
    if(musicas_relatorio == NULL){
      printf("\nErro na abertura do arquivo musicas_relatorio\n");
      exit(1);
    }

  for(int i=0; i < cont_mus_add; i++){
    fprintf(musicas_relatorio, "%d ", musicas_add[i]);
  }

  
  //libera musicas
  //libera artistas

  */
}

//----------------------------------------------------------------------------//

void QuickSort(ODE **vetor, int inicio, int fim){
  
  int pivo;

  if(fim > inicio){
    pivo = Particiona(vetor, inicio, fim);
    QuickSort(vetor, inicio, (pivo - 1));
    QuickSort(vetor, (pivo + 1), fim);
  }
  
}

//----------------------------------------------------------------------------//

int Particiona(ODE **vetor, int inicio, int fim){

  int esq = inicio;
  int dir = fim;
  ODE *pivo = vetor[inicio];
  ODE *aux;

  while(esq < dir){

    while(vetor[esq]->distancia_euclidiana <= pivo->distancia_euclidiana)
      esq++;
      
    while(vetor[dir]->distancia_euclidiana > pivo->distancia_euclidiana)
      dir--;

    if(esq < dir){
      aux = vetor[esq];
      vetor[esq] = vetor[dir];
      vetor[dir] = aux;
    }

  }

    vetor[inicio] = vetor[dir];
    vetor[dir] = pivo;
    
  return dir;
  
}

//----------------------------------------------------------------------------//

/* alg insertion sort
for(int i=1; i<total_mus; i++) {
    
    for (int j=i-1; j>=0; j--) {
      
      if (lista_musicas_ordenadas[j+1]->distancia_euclidiana < lista_musicas_ordenadas[j]->distancia_euclidiana) {
        int aux_dist=lista_musicas_ordenadas[j]->distancia_euclidiana;
        int aux_indice=lista_musicas_ordenadas[j]->indice_musica;
        lista_musicas_ordenadas[j]->distancia_euclidiana=lista_musicas_ordenadas[j+1]->distancia_euclidiana;
        lista_musicas_ordenadas[j]->indice_musica=lista_musicas_ordenadas[j+1]->indice_musica;
        lista_musicas_ordenadas[j+1]->distancia_euclidiana=aux_dist;
        lista_musicas_ordenadas[j+1]->indice_musica=aux_indice;
      }
        
      else {
      
        
        break;
      }
      
    }
    
  }
*/