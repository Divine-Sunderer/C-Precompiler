#include <ctype.h>
#include<stdio.h>
#include<string.h>

int isValidName(char *var) {
  if (!var || (!isalpha(var[0]) && var[0] != '_')) return 0;

  for (int i = 1; var[i]; i++) {
    if (!isalnum(var[i]) && var[i] != '_') return 0;
  }

  return 1;
}

int checkType(char *token, char *tipo[], int tipoSize) {
  for (int i = 0; i < tipoSize; i++) {
    if (strcmp(token, tipo[i]) == 0) return 1;
  }
  return 0;
}

void main() {
  int index = 0;

  char stringa[] = "int string char canzonedimerda = 3;";
  char str_half[50] = "";
  char *variabili[20];
  char *tipo[10] = {"string","bool","char","signed","unsigned","short","int","long","float","double"};

  for(int i = 0; stringa[i] != '\0'; i++) {
    if(stringa[i] != '=' && stringa[i] != ';') {
        str_half[i] = stringa[i];
      }else{
        break;
      }
  }
  // Adesso la stringa è spezzata dalla prima parte dell'uguale
  //printf("%s", str_half);

  // Tokenizziamo per spazi
  char *token = strtok(str_half, " ,\t\n");
  while(token != NULL) {
    if (!checkType(token,tipo,10)) {              // Se il token NON è un tipo allora lo considera VARIABILE e la salva nell'array
      variabili[index++] = token;
    }
    token = strtok(NULL, " ,\t\n");                // Continua a splittare spazi
  }

  for (int i = 0; i < index; i++) {
    printf("-%s\n", variabili[i]);
  }
}