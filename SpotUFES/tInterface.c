#include "tInterface.h"
#include <unistd.h>
#include <stdlib.h>

void Negrito (int status) {
 static const char *seq[] = {"\x1b[0m", "\x1b[1m"};
 printf("%s", seq[!!status]);
}

//----------------------------------------------------------------------------//

void SpotFES () {
int i=0;
char AppLogo[1365]={"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣴⡄\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠿⠿⣿⡇\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⢀⣤⣿⡇\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⠀⠀⣿⣿⣿⠃\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠿⠋⠀⠀⠈⠉⠁⠀⠀\n\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⢿⣿⣿⣿⣿⣿⣿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁⢰⠀⣿⠀⢰⠀⢻⡇⢰⠀⢹⣶⠀⣶⣿⠀⣶⣾⡇⢰⣶⣿⠀⡆⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡘⠻⣿⠀⢸⠀⢸⡇⢸⠀⢸⣿⠀⣿⣿⠀⣛⣿⡇⢘⣻⣿⣄⡙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⣿⠀⢘⣀⣾⡇⢸⠀⢸⣿⠀⣿⣿⠀⣿⣿⡇⢸⣿⣿⣿⡇⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠉⢹⠀⣿⠀⢸⣿⣿⡇⢸⠀⢸⣿⠀⢿⣿⠀⣿⣿⡇⢸⣿⣿⠉⡇⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣶⣿⣶⣾⣿⣿⣷⣦⣶⣿⣿⣶⣾⣿⣶⣿⣿⣷⣶⣶⣿⣶⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"};

  while (i < 1365) {
    usleep(1000);
    printf ("%c", AppLogo[i]);
    i++;  
  }

  char Tecla=' ';
  
  Negrito(1); printf ("\nAperte ENTER para continuar\n");
  Negrito(0);
  while (Tecla!=10){
    scanf ("%c", &Tecla);
  }
  system ("clear");
  
}

//----------------------------------------------------------------------------//

void MenuPrincipal () {
  Negrito(2); printf ("Escolha uma opção:\n\n");
  
  Negrito(1); printf ("1. "); Negrito (0); printf ("Buscar músicas\n");
  Negrito(1); printf ("2. "); Negrito (0); printf ("Listar uma música\n");
  Negrito(1); printf ("3. "); Negrito (0); printf ("Criar uma playlist\n");
  Negrito(1); printf ("4. "); Negrito (0); printf ("Listar playists\n");
  Negrito(1); printf ("5. "); Negrito (0); printf ("Listar uma playlist\n");
  Negrito(1); printf ("6. "); Negrito (0); printf ("Adicionar uma música na playlist\n");
  Negrito(1); printf ("7. "); Negrito (0); printf ("Recomendar músicas parecidas com uma playlist\n");
  Negrito(1); printf ("8. "); Negrito (0); printf ("Gerar relatório\n");
  Negrito(1); printf ("9. "); Negrito (0); printf ("Sair\n");
  
  Negrito(1); printf ("\n--> ");
  Negrito(0);
}

void ProgramaFinalizado() {
  //system("clear");
  printf ("\n\nPrograma Finalizado\n\n");
}

void EnterPraContinuar () {
  char Tecla=' ';
  //char Lixo;
  
  Negrito(1); printf ("\nAperte ENTER para continuar\n");
  Negrito(0);
  //scanf ("%c", &Lixo);
  while (Tecla!=10){
    scanf ("%c", &Tecla);
  }
  //system ("clear");
}