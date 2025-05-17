#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CheckDirettive.h"
#include "DeleteComments.h"
#include "VarChecker.h"
#include "checkFileSize.h"

//argc -> contatore degli argomenti passati
//argv -> array di stringhe simil Java
//Sono essenziali per i parametri da passare
void checkNextArg(int i, int argc, const char *nomeString) {
  if (i + 1 >= argc) {
    fprintf(stderr, "Errore: nessun argomento dopo %s\n", nomeString);
    exit(4);
  }
}

/* TUTTI I RETURN
* return 0 -> Terminato con successo
* return 1 -> Errore apertura file statistiche
* return 2 -> Errore apertura file input
* return 3 -> Errore apertura file output
* return 4 -> Errore argomento non specificato dopo identificatore (es. -i)
* return 5 -> Errore no file input specificato*/
int main(int argc, char *argv[]) {
  FILE *input, *statistiche, *output;
  char *nome_input, *nome_output;
  bool in = false, out = false, verbose = false;

  for(int i = 0; i < argc; i++) {
    if(strcmp(argv[i], "-i") == 0) {
      checkNextArg(i, argc, "-i");
      input = fopen(argv[i+1], "r+");
      nome_input = argv[i+1];
      in = true;
    }else if(strcmp(argv[i], "-o") == 0) {
      checkNextArg(i, argc, "-o");
      output = fopen(argv[i+1], "w+");
      nome_output = argv[i+1];
      out = true;
    }else if(strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
      statistiche = fopen("statistiche.txt", "w+"); //creiamo il file per le statistiche
      verbose = true;
    }else if(strstr(argv[i], "--in=") != NULL) {
      input = fopen( strchr(argv[i],'=') + 1 , "r+");
      in = true;
    }else if(strstr(argv[i], "--out=") != NULL) {
      output = fopen( strchr(argv[i],'=') + 1 , "w+");
      out = true;
    }
  }

  if(!in) {
    printf("Errore: nessun file input specificato\n");
    return 5;
  }

  //Verifichiamo che i file si aprano correttamente
  if (!statistiche && verbose) {
    perror("Errore nell'apertura del file statistiche\n");
    return 1;
  }
  if(!input) {
    perror("Errore nell'apertura del file input\n");
    return 2;
  }
  if(!output && out) {
    perror("Errore nell'apertura del file output\n");
    return 3;
  }


  deleteComments(input, output, nome_input, nome_output);
  checkInclude(input);
  deleteComments(input, output, nome_input, nome_output);
  varChecker(input, nome_input);


  if(input) fclose(input);
  if(output) fclose(output);
  if(statistiche) fclose(statistiche);
  return 0;
}