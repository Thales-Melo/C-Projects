#include "tLivro.h"

typedef struct livro {

    char *title;
    char *author;
    char *edit;
    int num_Pages;

} tLivro;

typedef struct Biblioteca {

    tLivro **Books;
    int num_Books;

} tBib;


tLivro* init_Books (int num_Books) {
  
    tLivro *L;
    L=(tLivro*)malloc(sizeof(tLivro));
    L->title=(char*)malloc(sizeof(char)*MAX_STRING);
    L->author=(char*)malloc(sizeof(char)*MAX_STRING);
    L->edit=(char*)malloc(sizeof(char)*MAX_STRING);
  
  return L;    
}

tBib* init_Bib () {
  
    tBib *B;

    B=(tBib*)malloc(sizeof(tBib));
    B->num_Books = read_Num_Books(BIBLIOTECA, B);
    B->Books=(tLivro**)malloc(sizeof(tLivro*)*B->num_Books+1);

    for (int i=0; i<B->num_Books; i++) {
      B->Books[i]=init_Books(B->num_Books);
    }

  return B;
}

int read_Num_Books (char *file, tBib *B) {

  FILE *F = fopen(file, "r");
  
  if (F==NULL) {
    fclose(F);
    F = fopen(file, "w");
    fprintf (F, "0"); 
    fclose(F);
  }

  F = fopen (file, "r");

  fscanf (F, "%d", &B->num_Books);

  fclose (F);
  
  return B->num_Books;

}


void read_Bib_File(char *file, tBib *B) {
  FILE *F = fopen(file, "r");
  if (F == NULL) {
    printf("Erro ao abrir o arquivo %s\n", file);
    return;
  }

  int i = 0;
  while (!feof(F)) {

    char *line = strdup(getLine(F, i));
    store_Bib_Data(B, line, i);
    free(line);
    i++;
  }
  
  fclose(F);
}

void store_Bib_Data (tBib *B, char *line, int i) {
  
      char *title, *author, *edit, *num_Pages;
      char delim[3]=" | ";
      title=strtok(line, delim);
      author=strtok(NULL, delim);
      edit=strtok(NULL, delim);
      num_Pages=strtok(NULL, delim);
  
      B->Books[i]->title=title;
      B->Books[i]->author=author;
      B->Books[i]->edit=edit;
      B->Books[i]->num_Pages=atoi(num_Pages);
  
    
}

void preenche_Livros (tBib *B) {

  B->Books=(tLivro**)realloc(B->Books, sizeof(tLivro*)*B->num_Books+1);
  int lastEmpty = B->num_Books;
  B->Books[lastEmpty]=init_Books(B->num_Books);
  B->num_Books++;

    printf ("\nCATALOGUE!!!\n\n");
    printf ("Título --> ");

    //limpa o buffer
    scanf ("%*c");

    fgets (B->Books[lastEmpty]->title, 100, stdin);

    printf ("Autor --> ");
    fgets (B->Books[lastEmpty]->author, 100, stdin);

    printf ("Edição --> ");
    scanf ("%s", B->Books[lastEmpty]->edit);

    printf ("Número de paginas --> ");
    int num_pags;
    scanf ("%d", &num_pags);
    B->Books[lastEmpty]->num_Pages=num_pags;

    printf ("\n\nLivro cadastrado com sucesso!\n\n");

}

void print_Livros (tBib *B) {

    printf ("\n\nQual livro você quer mostrar na tela (1 a %d) --> ", B->num_Books);
    int choose;
    scanf ("%d", &choose);

    printf ("\nLivro[%d]\n\n", choose);
    printf ("Título --> %s\n", B->Books[choose-1]->title);
    printf ("Autor --> %s\n", B->Books[choose-1]->author);
    printf ("Edição --> %s\n", B->Books[choose-1]->edit);
    printf ("Número de páginas --> %d", B->Books[choose-1]->num_Pages);

}

void free_Book (tLivro *L) {

  if (L->title != NULL) {
    free(L->title);
    L->title = NULL;
  }

  if (L->author != NULL) {
    free(L->author);
    L->author = NULL;
  }

  if (L != NULL) {
    free(L);
    L=NULL;
  }

}

void free_Bib (tBib *B) {
  
    for (int i=0; i < B->num_Books; i++) {
      if (B->Books[i] != NULL) {
        free_Book(B->Books[i]);
      }
    }
  
  if (B->Books != NULL) {
    free(B->Books);
    B->Books = NULL;
  }

  if (B != NULL) {
    free (B);
    B = NULL;
  }
  
}


// IA fez
char *getLine(FILE *F, int line_number) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int current_line_number = 0;

    // Percorre o arquivo linha por linha até encontrar a linha desejada
    while ((read = getline(&line, &len, F)) != -1) {
        current_line_number++;
        if (current_line_number == line_number) {
            // Copia a linha encontrada para uma nova string
            char *result = malloc((strlen(line) + 1) * sizeof(char));
            strcpy(result, line);
            free(line);
            return result;
        }
    }

    // Caso não encontre a linha desejada, retorna NULL
    free(line);
    return NULL;
}


