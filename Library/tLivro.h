#ifndef _T_LIVRO_H_
#define _T_LIVRO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

typedef struct livro tLivro;
typedef struct Biblioteca tBib;

// Initializes a struct type tLivro pointer, which includes book`s contents as:
// Title (STR), Author (STR), Edition (INT) and Number of Pages (INT)
// OBS: It doesnt need any argument and it returns a type tLivro*
tLivro *init_Books(int num_Books);

// Initializes a struct type tBib pointer, which includes library`s contents as:
// Double pointer for a struct type tLivro, which is a book`s catalog, Num of Books
// OBS: It doesnt need any argument and in returns a type tBib*
tBib *init_Bib();

int read_Num_Books (char *file, tBib *B);

// It fills the book`s content
// Void function which requires only one tBib* argument
void preenche_Livros(tBib *B);

// It prints the book`s content
// Void function which requires only one tBib* argument
void print_Livros(tBib *B);

// It frees the content of a book
// Void function which requires only one tLivro* argument
void free_Book(tLivro *L);

// It frees the content of a library
// Void funciont which requires only one tBib* argument
void free_Bib(tBib *B);

char *getLine (FILE *F, int line_number);

#endif
