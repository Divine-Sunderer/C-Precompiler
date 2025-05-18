#include "DeleteComments.h"

bool checkFile(FILE *prova)
{
    if( prova )
    {
        return true;
    }
    return false;
}

int deleteComments(FILE *input, FILE *output, FILE *statistiche, char* nome_input, char* nome_output, bool checkFinale) {
  bool delete = false;
  char riga[256];
  int i, righe_del = 0;

  if(!output) output = fopen(nome_output, "w+");

  //statistiche = fopen("statistiche.txt", "r+");

  // Cicla le righe
  while(fgets(riga, sizeof(riga), input) != NULL) {

    if (strstr(riga, "/*") && strstr(riga, "*/")) {
      for (int y = 0; y < (int)strlen(riga); y++) {
        if (riga[y] == '/' && riga[y+1] == '*') {
          while (!(riga[y] == '*' && riga[y+1] == '/') && y < (int)strlen(riga) - 1) {
            riga[y] = ' ';
            y++;
          }
          // cancella anche */
          riga[y] = ' ';
          riga[y+1] = ' ';
          righe_del++;
          break;
        }
      }
    }

    else if (strstr(riga, "/*") != NULL) {
      for ( i = 0 ; i < (int)strlen(riga) -1 ; i++ ) {
        if ( riga[i] == '/' && riga[i+1] == '*' ) {
          delete = true;
          riga[i] = ' ';
          riga[i+1] = ' ';
          righe_del++;
          break;
        }
      }

      while(delete == true && fgets(riga, sizeof(riga)-1, input) != NULL) {
        for (i=0; i < strlen(riga); i++) {
          if (riga[i] == '*' && riga[i+1] == '/') {
            delete = false;
            riga[i] = ' ';
            riga[i+1] = ' ';
            righe_del++;
            break;
          }
          else {
            riga[i] = ' ';
          }
        }
        righe_del++;
        i = 0; //ricominciamo dall'inizio della riga successiva
      }
    }

    else if (strstr(riga, "//") != NULL) {
      char *comment_start = strstr(riga, "//");
      if (comment_start != NULL) {
        *comment_start = '\0';
        righe_del++;
      }
    }
    // Scrive la riga pulita nel file temporaneo
    if (strlen(riga) > 0) {
      // Se la riga non finisce con \n, lo aggiungiamo noi
      size_t len = strlen(riga);
      if (riga[len - 1] != '\n') {
        fprintf(output, "%s\n", riga);
      } else {
        fprintf(output, "%s", riga);
      }
    }
  }

  rewind(input);
  rewind(output);
  // Altrimenti non vengono riportati i puntatori all'inizio
  fclose(input);
  fclose(output);

  remove(nome_input);
  rename(nome_output, nome_input);

  printf("Righe di commento cancellate: %d\n",righe_del);
  if (statistiche) {
    fprintf(statistiche, "Righe di commento cancellate: %d\n",righe_del);
  }

  if (checkFinale) checkFileSize(input, statistiche, nome_input);
  printf("File sovrascritto con i commenti rimossi.\n");
  return 0;
}