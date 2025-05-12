#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

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

int main() {
  int index = 0;
  bool trovato = false;
  FILE *principale;

  char *variabili[20];                                                                                                  // Andra' a contenere le variabili spezzate
  int index_variabili = 0;
  //char stringa[] = "int char canzon,edimerda rrrr = 3;";
  //char stringa[] = "int pippo, paperino = 3;";
  //char stringa[] = "int ciao;";
  char stringa[256];
/*
  const char* tipo[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "unsigned", "sizeof", "static",
    "struct", "switch", "typedef", "union", "signed", "void", "volatile", "while"
};*/

  const char *tipo[] = {
    "int","char","float","double","void","short","long","unsigned","signed","auto",
    "register","static","extern","const","volatile","struct","union","enum","typedef"
};

  const int tipo_lenght = sizeof(tipo) / sizeof(tipo[0]);
  principale = fopen("test1_no_comment.c", "r+");
  if (!principale) return 1;

  while (fgets(stringa, sizeof(stringa), principale)) {
    trovato = false;

    for (int i = 0; i < tipo_lenght; i++) {
      if (strstr(stringa, tipo[i])) {
        trovato = true;
        break;
      }
    }
    if (!trovato) continue;

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

  if (strchr(finale, '=')) {
    for (int i = strlen(finale); finale[i] != '=' ; i--) {
      finale[i] = ' ';
      index = i;
  }
    finale[index-1] = '\0';
  }else{
    index = strlen(finale);
    finale[index-1] = '\0';
  }

  //printf("%s\nLunghezza -> %d\n", finale,strlen(finale));                                                         // Qui abbiamo il nome della/delle variabili senza ne tipi ne uguale
  //-----------------------------------------------------------------

  char *token = strtok(finale, ",");                                                                              // Spezza la stringa una prima volta
  while (token != NULL) {
    variabili[index_variabili++] = token;
    token = strtok(NULL, ",");
    // Continua a spezzarla fino a quando non e' piu' possibile
  }

     /*for (int i = 0; i<index_variabili; i++) {
      printf("%s\n",variabili[i]);
    } */

  for (int i = 0; i < index_variabili; i++) {
    variabili[i] = eliminaSpaziIniziali(variabili[i]);
    if (isValidName(variabili[i])) {
      printf("%s VALIDA\n", variabili[i]);
    }else {
      printf("%s NON-VALIDA\n", variabili[i]);
    }
  }
  }
  fclose(principale);
  return 0;
}