//Programma esempio che può tornare utile - tocca studiarlo

#include <ctype.h>
#include<stdio.h>
#include<string.h>

//Returna 1 se inizia per numero, altrimenti returna 0
int startWithNum(char variabile[]) {
    if (variabile != NULL && variabile[0] >= '0' && variabile[0] <= '9') {
      return 1;
    }
  return 0;
}

int isDigit(char character[]) {
  return strlen(character) == 1 && startWithNum(character);
}

int containsBadChar(char variabile[]) {
  char str_vietata[] = " !\"#%&'()*+,-./:;<=>?@[\\]^`{|}~$@€£§¶©®™✓°•½¼¾µ¤¿¡¨¸ªº×÷±¬ƒ¬„…‰†‡‹›";
  for(int i = 0; i < strlen(str_vietata); i++) {
    if(strchr(variabile, str_vietata[i])) {
      return 1;   //Dunque nome variabile NON corretto
    }
  }
  return 0;       //Dunque nome variabile corretto
}

//Quando manca una virgola tra due variabili (ed al suo posto c'è uno spazio). *a e *b puntano rispettivamente al primo char della corrispettiva variabile
int missingComma(char *a , char *b) {
  while (a < b) {
    if (*a == ',') return 0;                          //Se troviamo tra a e b una virgola allora tutto apposto ammoh
    if (*a != ' ' && *a != '\t') return 1;            //Se troviamo qualcosa che NON è spazio/tab e NON è virgola ERRORE
    a++;
  }
  return 1;                                           //Se arriviamo alla fine senza trovare virgole ERRORE
}

void main() {
  char *variabili[50];                                        // <- Un vettore di stringhe
  int index = 0;
  char stringa[] = "int string char canzonedimerda = 3;";
  char *tipo[10] = {"string","bool","char","signed","unsigned","short","int","long","float","double"};

  char *token = strtok(stringa, " ");                // <- Spezza la stringa una prima volta
  while(token != NULL) {
    variabili[index++] = token;
    token = strtok(NULL, " ");                         // <- Continua a spezzarla fino a quando non è più possibile
  }
  for (int i = 0; i < index; i++) {
    for (int j = 0; j < 10; j++) {
      if (strcmp(variabili, tipo[j]) == 0) {

      }
    }
    printf("%s", variabili[i]);
  }
}



// Qui sto facendo dei test per vedere come agire con strtok