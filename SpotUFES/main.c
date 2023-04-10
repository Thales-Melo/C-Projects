#include "SpotFES.h"

int main(void) {
  
  system ("clear");

  //SpotFES();
  
  tSongData *TSD;
  TSD = AbreLeArquivoMusicas(TSD);

  tArtistaData *TAD;
  TAD = AbreLeArquivoArtistas(TAD);

  tPlaylistData *TPD;
  TPD = CarregaPlaylists(TPD);
  
  int opcao=0;
  
  while (opcao!=9) {
    MenuPrincipal();
    
    scanf("%d", &opcao);
    
    switch (opcao) {
      
      case 1:
        ProcuraMusica(TSD);
        break;

      case 2:
        ListarMusica(TSD, TAD);
        break;

      case 3:
        CriaPlaylist(TPD);        
        break;
      
      case 4:
        ListarPlaylists(TPD);
        break;
      
      case 5:
        ListarUmaPlaylist(TPD, TSD);
        break;
      
      case 6:
        AdicionarMusicaPlaylist(TPD);
        break;
            
      case 7:
        RecomendaMusica(TSD, TPD);
        break;
            
      case 8:
        //GerarRelatorio(TPD);
        break;
            
      case 9:
        DescarregaPlaylists(TPD);
        LiberaMusicas(TSD);
        LiberaArtistas(TAD);
        LiberaPlaylists(TPD);
        ProgramaFinalizado();
        break;

      default:
        exit(2);
    }
    if (opcao!=9) {
      EnterPraContinuar();
      system("clear");
    }
  }
  
  return 0;
}

 
//gcc -o main main.c tArtista.c tMusica.c tPlaylist.c tInterface.c
//gcc -lm -g -Wno-unused-result -o main main.c tArtista.c tMusica.c tPlaylist.c tInterface.c 
