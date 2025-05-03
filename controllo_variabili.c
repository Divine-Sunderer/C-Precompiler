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

// index -> indice del file testuale ( ovvero del file C )
int controllo_variabili(char riga[] , int index_riga) {
        char *variabili[20];
        char *tipo[9] = {"bool","char","signed","unsigned","short","int","long","float","double"};
        int indice_token = 0;

        char *token = strtok(riga, " ,;=");
        while(token != NULL) {
          variabili[indice_token++] = token;
          token = strtok(NULL, " ,;=");
        }
        //Adesso dentro "variabili" abbiamo tutta la riga spezzata , e la cicliamo con indice_token


        for (int i=0; i < strlen(variabili); i++) {
          for (int j=0; j < 10; j++) { //iteriamo sulla lista dei tipi
            if (variabili[i] == tipo[j]) {


              }

            elif(variabili[i] == "=") {




        }
  }

int main_controllo_variabili() {
  int conta_errori = 0;
  int index_file = 1;          // Tiene conto dell'indice della riga del file.c
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
    fclose(input);
  return conta_errori;
  // Perché returniamo gli errori , no ? Il resto viene modificato ed inserito in un file
}

// - IDEE -

// SPLITTARE TUTTA LA STRINGA CON strtok. Una volta fatto otteniamo qualcosa del tipo -> ["unsigned", "int", "variabile", "sbagliata", "4"]
// Cancellare tutte le stringhe che appartengono ai tipi. Una volta fatto riuniamo con strcat ( vedi come funge ) le stringhe rimanenti
// Dovrebbe rimanerci una roba del tipo :

// variabile sbagliata 4 ( anche i numeri dovremmo escluderli )

// Adesso facciamo i dovuti controlli ma A MANO , segnando le singole casistiche

// int variabile=0;

// DIVENTA -> "variabile=0;"