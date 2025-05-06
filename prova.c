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

char* eliminaSpazi(char str[]) {
  int i = 0;
  char *finale = "";
  while (str[i] == ' ') i++;
  while (str[i] != '\0') finale[i] = str[i++];
  return finale;
}

void main() {
  int index = 0;

  //char stringa[] = "int char canzon,edimerda rrrr = 3;";
  char stringa[] = "int pippo = 3;";
  char finale[] = "";
  const char* tipo[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};
  const int tipo_lenght = sizeof(tipo) / sizeof(tipo[0]);

  for (int i = 0; i < tipo_lenght; i++) {
    char *pos = strstr(stringa, tipo[i]);       //Cerchiamo il tipo come sottostringa

    //Se lo trova allora potrei far fare i-- , cosi che ricontrolli nuovamente per lo stesso tipo se ce ne è un'altra
    if (pos != NULL) {
      index = pos - stringa;          //Calcoliamo l'indice sottraendo i puntatori
      for (int j = 0; j < strlen(tipo[i]); j++) {
        stringa[index++] = ' ';
      }
      i--;
    }
  }
  printf("%s",stringa);
}