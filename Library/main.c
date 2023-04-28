#include "livro.h"

int main() {

  tBib *B = init_Bib();

  preenche_Livros(B);
  
  print_Livros(B);

  free_Bib(B);

  //teste  

  return 0;
}