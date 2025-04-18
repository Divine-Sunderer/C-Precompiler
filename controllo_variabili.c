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

int controllo_variabili(char riga[], char tipo[], int index_file) {
    int punta_char = 0 , conta_errori = 0;
    char nome_var[50];

      if(strstr(riga,tipo) != NULL)
        {
          for(int i = 0; i < strlen(riga); i++)
          {
              if(riga[i] == ' ')
                  continue;

              if( riga[i] == 'i' && riga[i+1] == 'n' && riga[i+2] == 't' && riga[i+3] == ' ' )
                {
                    i = i + 4;                                                                                          // Mando avanti di 4 caratteri ( cosi arrivo al nome della variabile )
                    punta_char = i;
                    while(riga[i] != ';' && riga[i] != '\0')
                      {
                          i++;
                      }
                      strncpy(nome_var , riga + punta_char, (i - punta_char));
                      nome_var[i - punta_char] = '\0';                                                                  //Chiudo la stringa manualmente
                      if( isNum(nome_var[0]) || checkChar(nome_var) )
                        {
                            conta_errori++;
                            printf("Errore nome_var alla riga : %d , non consentito",index_file);
                        }
                }
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
      conta_errori = conta_errori + controllo_variabili(riga,"int",index_file);

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