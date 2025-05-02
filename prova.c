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

void main() {
      char *variabili[50];                                        // <- Un vettore di stringhe
      int index = 0;
      char stringa[] = "int string char madicoio = 3;";
      char *tipo[10] = {"string","bool","char","signed","unsigned","short","int","long","float","double"};


      char *token = strtok(stringa, " ,;=");                // <- Spezza la stringa una prima volta
      while(token != NULL) {
        variabili[index++] = token;
        token = strtok(NULL, " ,;=");                         // <- Continua a spezzarla fino a quando non è più possibile
      }
      for (int i = 0; i < index; i++) {
        for (int j = 0; j < 10; j++) {
          if (strcmp(variabili[i], tipo[j]) == 0) {
            printf("E' un tipo\n");
            i++;
            j = - 1;
            //In questo modo saltiamo alla parola successiva, cosi facendo risparmiamo un pò di tempo
          }
          if (j==9) {

            if (isDigit(variabili[i])) continue;            //Se la stringa è un singolo numero allora salta il controllo successivo

            //Se inizia per numero allora la variabile è ERRATA
            if (startWithNum(variabili[i]) == 0 && containsBadChar(variabili[i]) == 0) {
              printf("( %s ): E' una variabile corretta\n",variabili[i]);
            }else {
              printf("( %s ): E' una variabile ERRATA\n",variabili[i]);
            }
          }
        }
        //printf("%s\n", variabili[i]);
      }
  }



// Qui sto facendo dei test per vedere come agire con strtok