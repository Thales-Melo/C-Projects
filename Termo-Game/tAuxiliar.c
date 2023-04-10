#include "tAuxiliar.h"

//Função que copia uma string a outra
char CopiaString(char *string2, char *string1) {
  int i;
  for (i = 0; i<5; i++) {
    string2[i] = string1[i];
  }
  string2[i] = '\0';
  return *string2;
}

//Função que copia uma string para outra e a transforma em maiúscula
void ViraMaiuscula(char string1[], char string2[]) {
  int i;
  for (i = 0; string1[i] != '\0'; i++) {
    string2[i] = toupper(string1[i]);
  }
  string2[i] = '\0';
}

