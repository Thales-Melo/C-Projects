#ifndef _LIVRO_H_
#define _LIVRO_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING 100

typedef struct livro tLivro;
typedef struct Biblioteca tBib;

tLivro* Init_Books ();

tBib* init_Bib ();

void preenche_Livros (tBib *B);

void print_Livros (tBib *B);

void free_Book (tLivro *L);

void free_Bib (tBib *B);

#endif