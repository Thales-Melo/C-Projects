#include "tLivro.h"

int main() {

  tBib *B = init_Bib();

  preenche_Livros(B);
  
  print_Livros(B);

  free_Bib(B);

  return 0;
  
}