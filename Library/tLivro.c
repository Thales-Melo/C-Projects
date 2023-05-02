#include "tLivro.h"

typedef struct livro {

    char *title;
    char *author;
    int edit;
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

  return L;    
}

tBib* init_Bib () {
  
    tBib *B;

    B=(tBib*)malloc(sizeof(tBib));
    B->num_Books = read_Num_Books(BIBLIOTECA, B);
    B->Books=(tLivro**)malloc(sizeof(tLivro*)*B->num_Books+1);

    for (int i=0; i<B->num_Books; i++) {
      B->Books[i]=Init_Books();
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

  fscanf (F, "%d", B->num_Books);

  fclose (F);
  
  return B->num_Books;

}


void read_Bib_File (char *file, tBib *B) {
  FILE *F = fopen(file, "r");

  fscanf (F, "%d", B->num_Books);
  int i=0;
  while (!FEOF) {

    fscanf (F, "%s | %s | %d | %d", B->Books[i]->title, B->Books[i]->author, B->Books[i]->edit, B->Books[i]->num_Pages);
    i++;
  }

}


void preenche_Livros (tBib *B) {

    printf ("Existem %d espaços disponíveis para catalogar!\nEscolha um número de 1 a %d\n\n--> ", B->num_Books, B->num_Books);
    
    int choose;
    scanf ("%d", &choose);
  
    printf ("\nCATALOGUE!!!\n\n");
    printf ("Título --> ");

    scanf ("%*c");
  
    fgets (B->Books[choose-1]->title, 100, stdin);

    printf ("Autor --> ");
    fgets (B->Books[choose-1]->author, 100, stdin);

    printf ("Edição --> ");
    int edit;
    scanf ("%d", &edit);
    B->Books[choose-1]->edit=edit;

    printf ("Número de paginas --> ");
    int num_pags;
    scanf ("%d", &num_pags);
    B->Books[choose-1]->num_Pages=num_pags;

}

void print_Livros (tBib *B) {

    printf ("\n\nQual livro você quer mostrar na tela (1 a %d) --> ", B->num_Books);
    int choose;
    scanf ("%d", &choose);

    printf ("\nLivro[%d]\n\n", choose);
    printf ("Título --> %s\n", B->Books[choose-1]->title);
    printf ("Autor --> %s\n", B->Books[choose-1]->author);
    printf ("Edição --> %d\n", B->Books[choose-1]->edit);
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