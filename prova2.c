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

char* eliminaSpaziIniziali(char str[]) {
  int i = 0;
  while (str[i] == ' ') i++;  // salta spazi iniziali
  return &str[i];             // ritorna puntatore alla prima lettera non spazio
}

void main() {
  int index = 0;
  int fine_stringa;

  //char stringa[] = "int char canzon,edimerda rrrr = 3;";
  char stringa[] = "int pippo = 3;";
  const char* tipo[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};
  const int tipo_lenght = sizeof(tipo) / sizeof(tipo[0]);

  for (int i = 0; i < tipo_lenght; i++) {
    char *pos = strstr(stringa, tipo[i]);                                                                     //Cerchiamo il tipo come sottostringa

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
  finale[index-1] = ' ';
  printf("%s\n", finale);                                                                                         // Qui abbiamo il nome della/delle variabili senza ne tipi ne uguale
  //-----------------------------------------------------------------
  for (int i = 0;  i < strlen(finale); i++) {
    if (finale[i] == ' ') {
      fine_stringa = i;
      break;
    }
  }

  char end[fine_stringa+1];
  for (int i = 0; i < fine_stringa; i++) {
    end[i] = finale[i];
  }
  end[fine_stringa] = '\0';                                                                                             // Se non la terminiamo allora si rischia di andare incontro a dei bug fastidiosi

  printf("%s\n", end);
}