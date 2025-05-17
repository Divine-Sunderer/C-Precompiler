// Per controllare numero righe e grandeza file ( in byte )
#include <stdio.h>

void checkFileLenght(FILE *input, FILE *statistiche, char *nome_input) {
  rewind(input);
  int count = 0;

  statistiche = fopen("statistiche.txt", "r");

  for(char c = getc(input); c != EOF; c = getc(input)) {
    if(c == '\n') count++;
  }
  printf("Il numero delle righe del file: %d\n", count);
  fprintf(statistiche, "Il numero delle righe del file %s è di: %d\n",nome_input, count);
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
  printf("La dimensione del file %s è: %ld\n",nome_input,dim);

  checkFileLenght(input, statistiche);

  rewind(input);
  fclose(input);
  return;
}