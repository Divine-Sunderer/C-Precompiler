#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool checkFile(FILE *prova)
{
    if( prova )
    {
        return true;
    }
    return false;
}

int deleteComments(int argc, char * argv[]) {
  bool delete = false;
  char riga[256];
  FILE *prova;
  FILE *temp;
  int i;

  prova = fopen("test/test2.c", "r");
  temp = fopen("test/prova_temp.txt", "w+");

  // w+ apre il file in lettura e scrittura. Anche r+ fa lo stesso , ma senza andarlo a creare se inesistente

  if (checkFile(prova) && checkFile(temp)) {
    printf("File aperti correttamente\n");
  } else {
    perror("ricontrolla!\n");
    return 0;
  }

  // Cicla le righe
  while(fgets(riga, sizeof(riga), prova) != NULL) {

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
          break;
        }
      }

      while(delete == true && fgets(riga, sizeof(riga)-1, prova) != NULL) {
        for (i=0; i < strlen(riga); i++) {
          if (riga[i] == '*' && riga[i+1] == '/') {
            delete = false;
            riga[i] = ' ';
            riga[i+1] = ' ';
            break;
          }
          else {
            riga[i] = ' ';
          }
        }
        i = 0; //ricominciamo dall'inizio della riga successiva
      }
    }

    else if (strstr(riga, "//") != NULL) {
      char *comment_start = strstr(riga, "//");
      if (comment_start != NULL) {
        *comment_start = '\0';
      }
    }
    // Scrive la riga pulita nel file temporaneo
    if (strlen(riga) > 0) {
      // Se la riga non finisce con \n, lo aggiungiamo noi
      size_t len = strlen(riga);
      if (riga[len - 1] != '\n') {
        fprintf(temp, "%s\n", riga);
      } else {
        fprintf(temp, "%s", riga);
      }
    }
  }

  fclose(prova);
  fclose(temp);

  remove("test/prova.txt");
  rename("test/temp.txt", "test/prova.txt");
  printf("File sovrascritto con i commenti rimossi.\n");
  return 0;
}