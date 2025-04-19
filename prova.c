//Programma esempio che può tornare utile - tocca studiarlo

#include<stdio.h>
#include<string.h>

void main() {
      char *variabili[50];                                        // <- Un vettore di stringhe
      int index = 0;
      char stringa[] = "int string char madicoio = 3;";

      char *token = strtok(stringa, " ,;=");                // <- Spezza la stringa una prima volta
      while(token != NULL) {
        variabili[index++] = token;
        token = strtok(NULL, " ,;=");                         // <- Continua a spezzarla fino a quando non è più possibile
      }
      for (int i = 0; i < index; i++) {
        printf("%s\n", variabili[i]);
      }
  }