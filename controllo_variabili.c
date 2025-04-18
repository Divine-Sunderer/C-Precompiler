#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool checkFile(FILE * prova)
{

    if( prova )
    {
        return true;
    }
    return false;
}

bool checkChar(char nome_var[]) {
  char str_vietata[] = " !\"#%&'()*+,-./:;<=>?@[\\]^`{|}~$@€£§¶©®™✓°•½¼¾µ¤¿¡¨¸ªº×÷±¬ƒ¬„…‰†‡‹›";
  for(int i = 0; i < strlen(str_vietata); i++) {
        if(strchr(nome_var, str_vietata[i])) {                                                                          //Check se il singolo carattere si trova nel nome
          return true;
        }
    }
    return false;
  }

bool isNum(char carattere) {
      if(carattere >= '0' && carattere <= '9')
        {
            return true;
        }
        return false;
  }

int contaOccorrenze(char *riga) {
  int cont = 0;
  for(int i = 0; i < strlen(riga); i++) {
    if(riga[i] == '=')
      cont++;
  }
  return cont;
}

int controllo_variabili(char riga[], int index_file) {
    int punta_char = 0 , conta_errori = 0 , n_uguale = contaOccorrenze(riga);
    char nome_var[50];

    for( int i = strlen(riga) - 1; i >= 0; i--)
    {
        if( riga[i] == '=' )
        {
            punta_char = i - 1;
            n_uguale--;
        }
    }


    return conta_errori;
  }

int main_controllo_variabili() {
  int conta_errori = 0;
  int index_file = 1;
  char riga[256];

  FILE *input;
  input = fopen("prova.txt","r"); //Ci basta aprire il file in mod. lettura

  if (checkFile(input)) {
      printf("File aperto correttamente ");
  } else {
      perror("File inesistente!");
      return 0;
    }

    while(fgets(riga, sizeof(riga), input) != NULL) {
      conta_errori = conta_errori + controllo_variabili(riga,index_file);

      index_file++;
    }
  return 0;
}

//IDEE
/*
*  Nella riga 44 ( circa , non lo so ) dovremmo in teoria inserire UNA MAREA di casi diversi
*  Ma inserirli tutti li è brutto visivamente , cosi stavo pensando di creare una funziona secondaria
*  Il problema è che non so se sia fattibile farla con una sfilza di if oppure se uno switch sia possibile
*  inserirlo... Non so , idee ?
*
*  https://en.wikipedia.org/wiki/C_data_types
*
*  Qui sopra ci sono tutti i tipi che vanno inseriti
*/