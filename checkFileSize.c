// Per controllare numero righe e grandezza file (in byte)
#include "checkFileSize.h"

void checkFileLenght(FILE *input, FILE *statistiche, char *nome_input) {
  rewind(input);
  int count = 0;

  //statistiche = fopen("statistiche.txt", "r+");

  for(char c = getc(input); c != EOF; c = getc(input)) {
    if(c == '\n') count++;
  }
  //printf("Il numero delle righe del file: %d\n", count);
  if (statistiche) {
    fprintf(statistiche, "Il numero delle righe del file %s è di: %d\n\n",nome_input, count);
  }
}



  void checkFileSize(FILE *input, FILE *statistiche, char *nome_input) {
    long dim;

    if(!input) {
      perror("Errore nell'apertura del file input\n");
      return;
    }

    // Vado a fine file
    fseek(input, 0, SEEK_END);

    dim = ftell(input);
    if (statistiche) {
      fprintf(statistiche,"La dimensione del file %s è: %ld\n",nome_input,dim);
    }

    checkFileLenght(input, statistiche, nome_input);

    printf("funzione checkFileSize eseguita con successo\n");


    rewind(input);
    //fclose(input);
  }