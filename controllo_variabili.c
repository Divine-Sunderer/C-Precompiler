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

/*int controllo_variabili(char riga[] , int index_riga) {
        char *variabili[20];
        char *tipo[9] = {"bool","char","signed","unsigned","short","int","long","float","double"};
        int indice_token = 0;
        int numero_tipi = 0;

        char *token = strtok(riga, " ,;=");
        while(token != NULL) {
          variabili[indice_token++] = token;
          token = strtok(NULL, " ,;=");
        }
        //Adesso dentro "variabili" abbiamo tutta la riga spezzata , e la cicliamo con indice_token
        for(int i = 0; i < indice_token; i++) {
              for(int j = 0; j < 9; j++)                                                                                // 9 -> Grandezza vettore di stringhe di tipo[i]
                if(strcmp(variabili[i], tipo[j]) == 0) {
                  //Se un pezzo della stringa è uguale ad un tipo di variabile allora... farò qualcosa , ma non oggi
                  numero_tipi++;
                }
        }
  }*/