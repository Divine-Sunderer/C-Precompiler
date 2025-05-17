// Per controllare numero righe e grandeza file ( in byte )
#include <stdio.h>

void checkFileLenght(FILE *input) {
  rewind(input);
  int count = 0;
  for(char c = getc(input); c != EOF; c = getc(input)) {
    if(c == '\n') count++;
  }
  printf("Il numero delle righe del file: %d\n", count);
}

void checkFileSize(FILE *input) {
  long dim;

  if(!input) {
    perror("Errore nell'apertura del file input\n");
    return;
  }

  // Vado a fine file
  fseek(input, 0, SEEK_END);

  dim = ftell(input);
  printf("La dimensione del file è: %ld\n",dim);

  checkFileLenght(input);

  rewind(input);
  fclose(input);
  return;
}