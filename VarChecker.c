#include<ctype.h>
#include<stdio.h>
#include<string.h>

int isValidName(char *var) {
  if (!var || (!isalpha(var[0]) && var[0] != '_')) return 0;

  for (int i = 1; var[i]; i++) {
    if (!isalnum(var[i]) && var[i] != '_') return 0;
  }

  return 1;
}

char* eliminaSpaziIniziali(char str[]) {
  int i = 0;
  while (str[i] == ' ') i++;  // salta spazi iniziali
  return &str[i];             // ritorna puntatore alla prima lettera non spazio
}

void main() {
  int index = 0;

  char *variabili[20];                                                                                                  // Andra' a contenere le variabili spezzate
  int index_variabili = 0;
  char stringa[] = "int char canzon,edimerda rrrr = 3;";
  //char stringa[] = "int pippo, paperino = 3;";
  const char* tipo[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};
  const int tipo_lenght = sizeof(tipo) / sizeof(tipo[0]);

  for (int i = 0; i < tipo_lenght; i++) {
    char *pos = strstr(stringa, tipo[i]);                                                                     //Cerchiamo il tipo come sotto-stringa

    //Se lo trova allora potrei far fare i-- , cosi che ricontrolli nuovamente per lo stesso tipo se ce ne è un'altra
    if (pos != NULL) {
      index = pos - stringa;                                                                                            //Calcoliamo l'indice sottraendo i puntatori
      for (int j = 0; j < strlen(tipo[i]); j++) {
        stringa[index++] = ' ';
      }
      i--;
    }
  }
  //printf("%s\n",stringa);
  char *finale = eliminaSpaziIniziali(stringa);
  //printf("%s\n",finale);

  for (int i = strlen(finale); finale[i] != '=' ; i--) {
    finale[i] = ' ';
    index = i;
  }
  finale[index-2] = '\0';
  //printf("%s\nLunghezza -> %d\n", finale,strlen(finale));                                                         // Qui abbiamo il nome della/delle variabili senza ne tipi ne uguale
  //-----------------------------------------------------------------

  char *token = strtok(finale, ",");                                                                              // Spezza la stringa una prima volta
  while (token != NULL) {
    variabili[index_variabili++] = token;
    token = strtok(NULL, ",");                                                                                    // Continua a spezzarla fino a quando non e' piu' possibile
  }
  for (int i = 0; i < index_variabili; i++) {
    variabili[i] = eliminaSpaziIniziali(variabili[i]);
    if (isValidName(variabili[i])) {
      printf("%s VALIDA\n", variabili[i]);
    }else {
      printf("%s NON-VALIDA\n", variabili[i]);
    }
  }
}



/* FUNZIONI NON USATE MA PROBABILMENTE UTILI
int checkType(char *token, char *tipo[], int tipoSize) {
  for (int i = 0; i < tipoSize; i++) {
    if (strcmp(token, tipo[i]) == 0) return 1;
  }
  return 0;
}
 */