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

void controllo_variabili(char *riga[],char *tipo[]) {
    int punta_carattere = 0;
    char nome_var[50];

      if(strstr(*riga,*tipo) != NULL)
        {
          for(int i = 0; i < strlen(*riga); i++)
          {
              if(*riga[i] == ' ')
                  continue;

              if(*riga[i] == 'i' && *riga[i+1] == 'n' && *riga[i+2] == 't' && *riga[i+3] == ' ')
                {
                    i = i + 4; // Mando avanti di 4 caratteri ( cosi arrivo al nome della variabile )

                }
          }
        }
  }

int main_controllo_variabili() {
  int conta_errori = 0;
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
      controllo_variabili(riga,"int");
      /*if(strstr(riga,controllo_variabili(riga,"int")) != NULL)
        {
            for(int i = 0; i < strlen(riga); i++)
              {
                  if(riga[i] == ' ')
                    continue;

                  if(
              }
        }*/
    }
  return 0;
  }
}