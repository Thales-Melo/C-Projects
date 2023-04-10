#include "tMusica.h"

struct tMusica {

  char id[23];
  char *nome;
  int popularidade;
  int duracao_ms;
  int explicita; // 0 ou 1

  char **artistas;    //"artistas" e "id_artistas" podem conter um ou mais
  int quant_artistas; // valores, neste caso separados por um pipeline '|'.

  char **id_artistas;
  char data_de_lancamento[11];

  float danceability;
  float energy;
  float key;
  float loudness;
  float mode; // 0 ou 1
  float speechiness;
  float acousticness;
  float instrumentalness;
  float liveness;
  float valence;
  float tempo;
  float time_signature;

  int indice;
};

struct tSongData {
  tMusica **lista_musicas;
  int QuantMusicas;
};

//----------------------------------------------------------------------------//

tSongData *AbreLeArquivoMusicas(tSongData *TSD) {

  int total_musicas = 0;
  // Abre arquivo
  FILE *tracks = fopen("tracks_full.csv", "r");
  if (tracks == NULL) {
    printf("\nErro na abertura do arquivo tracks\n");
    exit(1);
  }

  int cont = 0;
  int flag = 0;
  char nome_aux[1000];
  char artista_aux[1000];
  char id_artista_aux[1000];

  TSD = (tSongData *)malloc(sizeof(tSongData) * 1);
  TSD->lista_musicas = (tMusica **)malloc(sizeof(tMusica *) * 1);
  
  int qtd_alocados_total = 1;
  
  // Começa loop pra passagem das informações para as structs alocadas
  // até o final do arquivo
  while (!feof(tracks)) {

    if (flag == 1){
      
      if(qtd_alocados_total == total_musicas){

        qtd_alocados_total *= 2;
        TSD->lista_musicas = (tMusica **)realloc(TSD->lista_musicas, sizeof(tMusica *) * qtd_alocados_total);
      }
    }

    TSD->lista_musicas[cont] = (tMusica *)malloc(sizeof(tMusica) * 1);

    fscanf(tracks, "%[^;];", TSD->lista_musicas[cont]->id);

    fscanf(tracks, "%[^;];", nome_aux);
    TSD->lista_musicas[cont]->nome = strdup(nome_aux);

    fscanf(tracks, "%d;", &TSD->lista_musicas[cont]->popularidade);
    fscanf(tracks, "%d;", &TSD->lista_musicas[cont]->duracao_ms);
    fscanf(tracks, "%d;", &TSD->lista_musicas[cont]->explicita);

    /*/
    No caso do artistas e id_artistas, como há a possibilidade de mais de
    um objeto, é feita uma checagem(loop) que a verifica, realocando memória
    para cada novo objeto
    /*/
    fscanf(tracks, "%[^;];", artista_aux);
    TSD->lista_musicas[cont]->artistas = (char **)malloc(sizeof(char *) * 1);
    TSD->lista_musicas[cont]->artistas[0] = strdup(strtok(artista_aux, "|"));

    char *substr = NULL;
    int qtd_artistas = 1;
    int qtd_alocados = 1;

    while (1) {
      substr = strtok(NULL, "|");

      if (substr == NULL)
        break;

      if (qtd_alocados == qtd_artistas) {
        qtd_alocados *= 2;

        TSD->lista_musicas[cont]->artistas =
            (char **)realloc(TSD->lista_musicas[cont]->artistas,
                             sizeof(char *) * (qtd_alocados));
      }

      TSD->lista_musicas[cont]->artistas[qtd_artistas] = strdup(substr);

      qtd_artistas += 1;
    }

    TSD->lista_musicas[cont]->quant_artistas = qtd_artistas;

    fscanf(tracks, "%[^;];", id_artista_aux);
    TSD->lista_musicas[cont]->id_artistas = (char **)malloc(sizeof(char *) * 1);
    TSD->lista_musicas[cont]->id_artistas[0] =
        strdup(strtok(id_artista_aux, "|"));

    int qtd_id_artistas = 1;
    qtd_alocados = 1;

    while (1) {
      substr = strtok(NULL, "|");

      if (substr == NULL)
        break;

      if (qtd_alocados == qtd_id_artistas) {
        qtd_alocados *= 2;

        TSD->lista_musicas[cont]->id_artistas =
            (char **)realloc(TSD->lista_musicas[cont]->id_artistas,
                             sizeof(char *) * (qtd_alocados));
      }

      TSD->lista_musicas[cont]->id_artistas[qtd_id_artistas] = strdup(substr);

      qtd_id_artistas += 1;
    }

    // um ou mais artistas com o mesmo id
    if (qtd_artistas != qtd_id_artistas) {
      int a = qtd_artistas - qtd_id_artistas;
      for (int i = 0; i < a; i++) {
        if (qtd_alocados == qtd_id_artistas) {
          qtd_alocados *= 2;

          TSD->lista_musicas[cont]->id_artistas =
              (char **)realloc(TSD->lista_musicas[cont]->id_artistas,
                               sizeof(char *) * (qtd_alocados));
        }
        
        TSD->lista_musicas[cont]->id_artistas[qtd_id_artistas] = strdup(TSD->lista_musicas[cont]->id_artistas[qtd_id_artistas - 1]);
        qtd_id_artistas += 1;
      }
    }


    fscanf(tracks, "%[^;];", TSD->lista_musicas[cont]->data_de_lancamento);

    fscanf(tracks, "%f;", &TSD->lista_musicas[cont]->danceability);
    fscanf(tracks, "%f;", &TSD->lista_musicas[cont]->energy);
    fscanf(tracks, "%f;", &TSD->lista_musicas[cont]->key);
    fscanf(tracks, "%f;", &TSD->lista_musicas[cont]->loudness);
    fscanf(tracks, "%f;", &TSD->lista_musicas[cont]->mode);
    fscanf(tracks, "%f;", &TSD->lista_musicas[cont]->speechiness);
    fscanf(tracks, "%f;", &TSD->lista_musicas[cont]->acousticness);
    fscanf(tracks, "%f;", &TSD->lista_musicas[cont]->instrumentalness);
    fscanf(tracks, "%f;", &TSD->lista_musicas[cont]->liveness);
    fscanf(tracks, "%f;", &TSD->lista_musicas[cont]->valence);
    fscanf(tracks, "%f;", &TSD->lista_musicas[cont]->tempo);
    fscanf(tracks, "%f\n", &TSD->lista_musicas[cont]->time_signature);

    TSD->lista_musicas[cont]->indice = (cont + 1);
    total_musicas++;

    flag = 1;
    cont++;
  }

  TSD->QuantMusicas = total_musicas;

  fclose(tracks);

  return TSD;
}

//----------------------------------------------------------------------------//
void LiberaMusicas(tSongData *TSD) {

  for (int i = 0; i < TSD->QuantMusicas; i++) {

    for (int j = 0; j < TSD->lista_musicas[i]->quant_artistas; j++) {

      if (TSD->lista_musicas[i]->artistas[j] != NULL) {
        free(TSD->lista_musicas[i]->artistas[j]);
        TSD->lista_musicas[i]->artistas[j] = NULL;
      }

      if (TSD->lista_musicas[i]->id_artistas[j] != NULL) {
        free(TSD->lista_musicas[i]->id_artistas[j]);
        TSD->lista_musicas[i]->id_artistas[j] = NULL;
      }

    }

    if (TSD->lista_musicas[i]->artistas != NULL) {
      free(TSD->lista_musicas[i]->artistas);
      TSD->lista_musicas[i]->artistas = NULL;
    }

    if (TSD->lista_musicas[i]->id_artistas != NULL) {
      free(TSD->lista_musicas[i]->id_artistas);
      TSD->lista_musicas[i]->id_artistas = NULL;
    }

    if (TSD->lista_musicas[i]->nome != NULL) {
      free(TSD->lista_musicas[i]->nome);
      TSD->lista_musicas[i]->nome = NULL;
    }

    if (TSD->lista_musicas[i] != NULL) {
      free(TSD->lista_musicas[i]);
      TSD->lista_musicas[i] = NULL;
    }
  }

  if (TSD->lista_musicas != NULL) {
    free(TSD->lista_musicas);
    TSD->lista_musicas = NULL;
  }

  if (TSD != NULL) {
    free(TSD);
    TSD = NULL;
  }
}

//----------------------------------------------------------------------------//

void ListarMusica(tSongData *TSD, tArtistaData *TAD) {
  int QuantArtistas = GetQuantArtistas(TAD);
  int indice = 0;
  int escolha = 0;

  while (escolha != 2) {

    while (indice != -1) {
      // system("clear");
      escolha = 0;
      Negrito(1);
      printf("\nDigite o índice da música: ");
      Negrito(0);
      scanf("%d", &indice);

      // Loop até receber um índice válido
      while (!(indice > 0 && indice <= TSD->QuantMusicas)) {
        printf("\nDigite um índice válido ou 0 para sair: ");
        scanf("%d", &indice);
        printf("\n\n");
        if (indice == 0) {
          break;
        }
      }
      if (indice == 0) {
        break;
      }

      indice -= 1;

      // Aqui começa a printar as informações
      printf("\n");
      Negrito(1);
      printf("Nome: ");
      Negrito(0);
      printf("%s\n", TSD->lista_musicas[indice]->nome);

      Negrito(1);
      printf("ID: ");
      Negrito(0);
      printf("%s\n", TSD->lista_musicas[indice]->id);

      Negrito(1);
      printf("Popularidade: ");
      Negrito(0);
      printf("%d\n", TSD->lista_musicas[indice]->popularidade);

      Negrito(1);
      printf("Duração: ");
      Negrito(0);
      printf("%d ms\n", TSD->lista_musicas[indice]->duracao_ms);
      // float duracao_min=TSD->lista_musicas[indice]->duracao_ms;
      // duracao_min/=60000;
      // Negrito(1); printf("Duração: ");
      // Negrito(0); printf("%.2f min\n", duracao_min);

      Negrito(1);
      printf("Explícita: ");
      if (TSD->lista_musicas[indice]->explicita == 0)
        Negrito(0);
      printf("Não\n");
      if (TSD->lista_musicas[indice]->explicita == 1)
        Negrito(0);
      printf("Sim\n");

      Negrito(1);
      printf("Data do lançamento: ");
      Negrito(0);
      printf("%s\n", TSD->lista_musicas[indice]->data_de_lancamento);

      Negrito(1);
      printf("Artistas:\n");

      for (int j = 0; j < TSD->lista_musicas[indice]->quant_artistas; j++) {
        Negrito(1);
        printf("  Nome: ");
        Negrito(0);
        printf("%s\n", TSD->lista_musicas[indice]->artistas[j]);

        Negrito(1);
        printf("  ID: ");
        Negrito(0);
        printf("%s\n", TSD->lista_musicas[indice]->id_artistas[j]);

        int conf_dados = 0;

        for (int k = 1; k < (QuantArtistas + 1); k++) {
          char *nome_artista;
          nome_artista = GetNome(TAD, k);

          if (strcmp(TSD->lista_musicas[indice]->artistas[j], nome_artista) ==
              0) {
            float seguidores = GetSeguidores(TAD, k);
            Negrito(1);
            printf("  Seguidores: ");
            Negrito(0);
            printf("%.2f\n", seguidores);

            char **generos = GetGeneros(TAD, k);
            int quant_generos = GetQuantGeneros(TAD, k);
            Negrito(1);
            printf("  Gêneros: ");
            ;
            Negrito(0);

            for (int l = 0; l < quant_generos; l++) {
              if (quant_generos == 1)
                printf(" %s", generos[l]);

              else if (quant_generos == 0)
                printf(" - ");

              else if (l >= 1 && l != quant_generos)
                printf(" %s |", generos[l]);
              else
                printf(" %s", generos[l]);
            }

            float popularidade = GetPopularidade(TAD, k);
            Negrito(1);
            printf("\n  Popularidade: ");
            Negrito(0);
            printf("%.2f\n\n", popularidade);

            conf_dados = 0;
          }

          if (strcmp(TSD->lista_musicas[indice]->artistas[j], nome_artista) !=
              0) {
            conf_dados++;
          }

          if (conf_dados == QuantArtistas) {
            printf("  (Não há mais dados do artista)\n\n");
            conf_dados = 0;
          }
        }
      }

      Negrito(1);
      printf("\nDeseja executar a música?\n\n");
      Negrito(2);
      printf("1-Executar\n2-Não\n\n--> ");
      Negrito(0);

      int opcao = 0;
      while (opcao != 1 && opcao != 2) {
        scanf("%d", &opcao);
        if (opcao == 1) {
          Negrito(1);
          printf("\nhttps://open.spotify.com/track/%s\n\n",
                 TSD->lista_musicas[indice]->id);
          break;
// executa a música
#ifdef __unix__
          char openspotify[71];
          sprintf(openspotify,
                  "xdg-open firefox https://open.spotify.com/track/%s",
                  TSD->lista_musicas[indice]->id);
                  system(openspotify);
#elif defined(_WIN32) || defined(WIN32)
          char openspotify[71];
          sprintf(openspotify,
                  "start firefox https://open.spotify.com/track/%s",
                  TSD->lista_musicas[indice]->id);
                  system(openspotify);
#elif defined(_WIN64) || defined(WIN64)
          char openspotify[71];
          sprintf(openspotify,
                  "start firefox https://open.spotify.com/track/%s",
                  TSD->lista_musicas[indice]->id);
                  system(openspotify);
#endif

        } else if (opcao == 2) {
          printf("\n");
          break;
        } else {
          printf("\nDigite uma opção válida: ");
        }
      }

      Negrito(1);
      printf("Deseja listar outra música?\n\n");
      Negrito(1);
      printf("1-Sim\n2-Não\n\n--> ");

      while (escolha != 1 && escolha != 2) {
        scanf("%d", &escolha);
        printf("\n");
        if (escolha == 1 || escolha == 2) {
          break;
        } else {
          printf("\nDigite uma opção válida: ");
        }
      }
      if (escolha == 2) {
        break;
      }
    }

    if (indice == 0) {
      break;
    }

    if (escolha == 1) {
      break;
    }

    else if (escolha == 2) {

      // EnterPraContinuar();
      // MenuPrincipal();
      break;
    }
  }
  char Lixo;
  scanf("%c", &Lixo);
}

//----------------------------------------------------------------------------//

void ProcuraMusica(tSongData *TSD) {
  int opcao = 0;
  while (opcao != 2) {
    // system("clear");

    char *pesquisa;
    pesquisa = PesquisarMusica();
    int j = 0;
    int tampesquisa = strlen(pesquisa);
    // int tampesquisa = strlen(pesquisa)+1 //--> +1 pro ''\0'
    char musicanome_aux[tampesquisa];

    // int *encontrados=(int*)malloc(sizeof(int)*2);
    int encontrados[50000];
    int indice = 0;
    int posicao_na_string = 0;
    int num_encontrados = 0;

    while (indice < TSD->QuantMusicas) {
      // Cria uma string de tamanho igual a busca do usuário
      // A string é criada a partir da letra na posição atual do nome da música
      // no loop
      CriaMusicaAux(posicao_na_string, TSD->lista_musicas[indice]->nome,
                    tampesquisa, musicanome_aux);
      // Vira maíscula para garantir que qualquer busca (minúscula ou maiuscula)
      // possa ser válida
      StrMaiuscula(pesquisa);

      // Compara a string auxiliar da música com a busca do usuário
      // Se resultar em igual, printa as informações
      if (strcmp(musicanome_aux, pesquisa) == 0) {
        /*if (num_encontrados>0) {
          encontrados=(int*)realloc(encontrados, sizeof(int)*2);
        }*/
        encontrados[num_encontrados] = indice;
        indice++;
        posicao_na_string = 0;
        num_encontrados++;

      }

      // Verifica se estorou o tamanho da string e, se preciso, pula para a
      // próxima leitura com indice++
      else if (posicao_na_string ==
               (strlen(TSD->lista_musicas[indice]->nome))) {
        posicao_na_string = 0;
        indice++;
      }

      // Entra aqui caso ainda esteja procurando um trecho válido dentro da
      // string de música
      else {
        posicao_na_string++;
      }
    }

    // Verifica se encontrou alguma música
    if (num_encontrados == 0) {
      printf("Não foi possível encontrar\n");
    }

    else {
      for (int count = 0; count < num_encontrados; count++) {

        Negrito(1);
        printf("\nNome: ");
        Negrito(0);
        printf("%s\n", TSD->lista_musicas[encontrados[count]]->nome);

        Negrito(1);
        printf("Índice: ");
        Negrito(0);
        printf("%d\n", encontrados[count] + 1);

        Negrito(1);
        printf("ID: ");
        Negrito(0);
        printf("%s\n", TSD->lista_musicas[encontrados[count]]->id);

        Negrito(1);
        printf("Artistas:\n");

        for (int j = 0;
             j < TSD->lista_musicas[encontrados[count]]->quant_artistas; j++) {
          Negrito(1);
          printf("  Nome: ");
          Negrito(0);
          printf("%s\n", TSD->lista_musicas[encontrados[count]]->artistas[j]);

          Negrito(1);
          printf("  ID: ");
          Negrito(0);
          printf("%s\n\n",
                 TSD->lista_musicas[encontrados[count]]->id_artistas[j]);
        }

        if (num_encontrados > 10) {
          if (count % 10 == 0 && count != 0) {
            int escolhe = 0;

            Negrito(1);
            printf("Mostrar mais resultados?\n\n");
            // scanf("%*c");
            while (escolhe != 1 || escolhe != 2) {

              Negrito(1);
              printf("1- Sim\n2- Não\n\n--> ");
              Negrito(0);
              scanf("%d", &escolhe);

              if (escolhe == 1) {
                break;
              }
              if (escolhe == 2) {
                break;
              } else {
                printf("Escolha uma opção válida\n\n");
              }
            }

            if (escolhe == 1) {
              continue;
            }
            if (escolhe == 2) {
              break;
            }
          }
        }
      }
    }

    // Liberar alocados
    if (pesquisa != NULL) {
      free(pesquisa);
      pesquisa = NULL;
    }

    Negrito(1);
    printf("Deseja realizar outra pesquisa?\n\n1-Sim\n2-Não\n\n--> ");
    while (opcao != 1 || opcao != 2) {
      scanf("%d", &opcao);
      if (opcao == 1) {
        break;
      }
      if (opcao == 2) {
        break;
      }
    }

    if (opcao == 2) {
      break;
    }
  }

  // EnterPraContinuar();
  // MenuPrincipal();
  char Lixo;
  scanf("%c", &Lixo);
}

//----------------------------------------------------------------------------//

// Função que recebe a entrada de busca do usuário e retorna a mesma
char *PesquisarMusica() {
  char *nome = (char *)malloc(sizeof(char) * 200);

  Negrito(1);
  printf("\nO que você quer ouvir?\n\n--> ");
  Negrito(0);
  scanf("%s", nome);

  return nome;
}

//----------------------------------------------------------------------------//
// Ta dando um 1 erro aqui (invalid read of size 1)
char *CriaMusicaAux(int posicao_na_string, char *nomemus, int tamnome,
                    char str[]) {
  int j = 0;

  while (j < tamnome) {
    str[j] = toupper(nomemus[posicao_na_string]);
    posicao_na_string++;
    j++;

    if (j == tamnome) {
      str[j] = '\0';
    }
  }

  return str;
}

//----------------------------------------------------------------------------//

// Função que recebe uma string transforma todos os caracteres em maiusculo a
// fim de facilitar as comparações
void StrMaiuscula(char *s1) {
  int i = 0;
  while (s1[i] != '\0') {
    s1[i] = toupper(s1[i]);
    i++;
  }
  s1[i] = '\0';
}

//----------------------------------------------------------------------------//

// Função que recebe um tSongData e retorna o título da música
char *GetTitulo(tSongData *TSD, int indice) {

  return TSD->lista_musicas[indice]->nome;
}

//----------------------------------------------------------------------------//

float GetCaracteristicas(tSongData *TSD, int indice, int Caracteristicas) {

  switch (Caracteristicas) {
  case 0:
    return TSD->lista_musicas[indice]->danceability;
    break;

  case 1:
    return TSD->lista_musicas[indice]->energy;
    break;

  case 2:
    return TSD->lista_musicas[indice]->mode;
    break;

  case 3:
    return TSD->lista_musicas[indice]->speechiness;
    break;

  case 4:
    return TSD->lista_musicas[indice]->acousticness;
    break;

  case 5:
    return TSD->lista_musicas[indice]->instrumentalness;
    break;

  case 6:
    return TSD->lista_musicas[indice]->liveness;
    break;

  case 7:
    return TSD->lista_musicas[indice]->valence;
    break;
  }

  return -1;
}

int GetQuantMusicas(tSongData *TSD) { return TSD->QuantMusicas; }

char *GetNomeMusica(tSongData *TSD, int indice) {
  return TSD->lista_musicas[indice]->nome;
}