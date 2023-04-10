#include "tArtista.h"

struct tArtista {

  char id[23]; // Sempre 22 caracteres (+ /0)

  float seguidores; // Possui apenas uma casa depois da vírgula

  char **generos; // Ler um gênero por vez e gravar na lista
  int quant_generos;

  char *nome;

  int popularidade; // Entre 0 e 100
};

struct tArtistaData {
  tArtista **lista_artistas;
  int QuantArtistas;
};

//----------------------------------------------------------------------------//

tArtistaData* AbreLeArquivoArtistas(tArtistaData *TAD) {
int total_artistas = 0;
  
  FILE *artists = fopen("artists_full.csv", "r");
  if (artists == NULL) {
    printf("\nErro na abertura do arquivo artists\n");
    exit(1);
  }

  int i;
  int cont = 0;
  int flag = 0;
  char nome_aux[500];
  char genero_aux[500];

  // love and tunder
  // &genero_aux[0]
  // &genero_aux[5]
  // &genero_aux[8]
  TAD = (tArtistaData*)malloc(sizeof(tArtistaData) * 1);
  TAD->lista_artistas = (tArtista **)malloc(sizeof(tArtista *) * 1);

  while (!feof(artists)) {

    if (flag == 1)
      TAD->lista_artistas = realloc(TAD->lista_artistas, sizeof(tArtista) * (1 + cont));

    TAD->lista_artistas[cont] = (tArtista *)malloc(sizeof(tArtista) * 1);

    fscanf(artists, "%[^;];", TAD->lista_artistas[cont]->id);
    fscanf(artists, "%f;", &TAD->lista_artistas[cont]->seguidores);

    fscanf(artists, "%[^;];", genero_aux);
    TAD->lista_artistas[cont]->generos = (char **)malloc(sizeof(char *) * 1);
    TAD->lista_artistas[cont]->generos[0] = strdup(strtok(genero_aux, "|"));

    char *substr;

    int qtd_generos = 1;
    int qtd_alocados = 1;

    while (1) {
      substr = strtok(NULL, "|");

      if (substr == NULL)
        break;

      if (qtd_generos == qtd_alocados) {
        qtd_alocados *= 2;

        TAD->lista_artistas[cont]->generos = (char **)realloc(
            TAD->lista_artistas[cont]->generos, sizeof(char *) * (qtd_alocados));
      }

      TAD->lista_artistas[cont]->generos[qtd_generos] = strdup(substr);
      qtd_generos++;
    }

    TAD->lista_artistas[cont]->quant_generos = qtd_generos;

    // debug
    //printf("%s\n", lista_artistas[cont]->generos[0]);

    fscanf(artists, "%[^;];", nome_aux);
    TAD->lista_artistas[cont]->nome = strdup(nome_aux);

    // debug
    //printf("%s\n", lista_artistas[cont]->nome);

    fscanf(artists, "%d\n", &TAD->lista_artistas[cont]->popularidade);

    total_artistas++;
    // debug
    //printf("VAMBORA%d\n\n", cont);

    flag = 1;
    cont++;
    
  }

  TAD->QuantArtistas=total_artistas;
  //debug
  //printf ("%d", TAD->QuantArtistas);
  fclose(artists);

  return TAD;
}

//----------------------------------------------------------------------------//

void LiberaArtistas(tArtistaData *TAD) {

  for (int i = 0; i < TAD->QuantArtistas; i++) {

    for (int j = 0; j < (TAD->lista_artistas[i]->quant_generos); j++) {
      if (TAD->lista_artistas[i]->generos[j] != NULL) {
        free(TAD->lista_artistas[i]->generos[j]);
        TAD->lista_artistas[i]->generos[j] = NULL;
      }
    }

    if (TAD->lista_artistas[i]->generos != NULL) {
      free(TAD->lista_artistas[i]->generos);
      TAD->lista_artistas[i]->generos = NULL;
    }

    if (TAD->lista_artistas[i]->nome != NULL) {
      free(TAD->lista_artistas[i]->nome);
      TAD->lista_artistas[i]->nome = NULL;
    }

    if (TAD->lista_artistas[i] != NULL) {
      free(TAD->lista_artistas[i]);
      TAD->lista_artistas[i] = NULL;
    }
  }

  if (TAD->lista_artistas != NULL) {
    free(TAD->lista_artistas);
    TAD->lista_artistas = NULL;
  }
  if (TAD!=NULL) {
    free(TAD);
    TAD=NULL;
  }
}

//----------------------------------------------------------------------------//

int GetPopularidade(tArtistaData *TAD, int indice) {

  indice -= 1;

  return TAD->lista_artistas[indice]->popularidade;
}

//----------------------------------------------------------------------------//

float GetSeguidores(tArtistaData *TAD, int indice) {

  indice -= 1;

  return TAD->lista_artistas[indice]->seguidores;
}

//----------------------------------------------------------------------------//

char** GetGeneros(tArtistaData *TAD, int indice) {

  indice -= 1;

  return TAD->lista_artistas[indice]->generos;
}

//----------------------------------------------------------------------------//

int GetQuantGeneros(tArtistaData *TAD, int indice) {
  indice-=1;

  return TAD->lista_artistas[indice]->quant_generos;
}

//----------------------------------------------------------------------------//

int GetQuantArtistas(tArtistaData *TAD) {
  return TAD->QuantArtistas;
}

//----------------------------------------------------------------------------//

char* GetNome (tArtistaData *TAD, int indice){

  indice -= 1;

  return TAD->lista_artistas[indice]->nome;
}

//----------------------------------------------------------------------------//