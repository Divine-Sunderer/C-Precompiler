#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

const char *parole_riservate[] = {
  "break", "case", "continue", "default", "do",
  "else", "for", "goto", "if", "inline", "restrict",
  "return", "sizeof", "switch", "while",
};

#define len_res (sizeof(parole_riservate)/sizeof(parole_riservate[0]))                                                  //Lunghezza array di stringhe

int isValidName(char *var) {
  if (!var || (!isalpha(var[0]) && var[0] != '_')) return 0;

  for (int i = 1; var[i]; i++) {
    if (!isalnum(var[i]) && var[i] != '_') return 0;
  }

  for (int i = 0; i < len_res; i++) {
    if (strstr(var, parole_riservate[i])) return 0;
  }

  return 1;
}

char* eliminaSpaziIniziali(char str[]) {
  int i = 0;
  while (str[i] == ' ') i++;  // salta spazi iniziali
  return &str[i];             // ritorna puntatore alla prima lettera dopo gli spazi
}

//Per "tappare" il bug dei /tab all'inizio del nome delle variabili
char* extendedTrim(char *str) {
  while (*str && (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'))
    str++;

  char *end = str + strlen(str) - 1;
  while (end > str && (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r')) {
    *end = '\0';
    end--;
  }
  return str;
}

char* charCleaner(char *str) {
  if (str[strlen(str) - 1] == ';') str[strlen(str) - 1] = '\0';
  return str;
}

int varChecker(FILE *principale, char* nome_input) {
  int index = 0;
  int indice_riga = 0;
  bool trovato = false;

  int count_valid = 0, count_invalid = 0, tot_var = 0;

  char *variabili[20];                                                                                                  // Andra' a contenere le variabili spezzate
  int index_variabili = 0;
  char stringa[256];
  const char *tipo[] = {
    "int","char","float","double","void","short","long","unsigned","signed","auto",
    "register","static","extern","const","volatile","struct","union","enum","typedef"
  };

  const int tipo_lenght = sizeof(tipo) / sizeof(tipo[0]);
  if (!principale)   principale = fopen(nome_input, "r+");

  while (fgets(stringa, sizeof(stringa), principale)) {
      index_variabili = 0;
      indice_riga++;
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

    char *finale = eliminaSpaziIniziali(stringa);
    //printf("%s\n", finale);

    if (strchr(finale, '=')) {
      for (int i = strlen(finale); finale[i] != '=' ; i--) {
        finale[i] = ' ';
        index = i;
      }
    }else{
      index = strlen(finale);
    }
    finale[index-1] = '\0';
    //Cambiato qui sopra

    char *token = strtok(finale, ",");                                                                              // Spezza la stringa una prima volta
    while (token != NULL) {
      token = extendedTrim(token);
      token = charCleaner(token);                                                                                         // <- Può tornare utile per pulire eventuali ";" dalla fine del nome delle variabili
      variabili[index_variabili++] = token;
      token = strtok(NULL, ",");
      // Continua a spezzarla fino a quando non e' piu' possibile
    }

    for (int i = 0; i < index_variabili; i++) {
      variabili[i] = eliminaSpaziIniziali(variabili[i]);

      if (strchr(variabili[i], '(') || strchr(variabili[i], ')')) continue;

      if (isValidName(variabili[i])) {
        printf("%s -> VALIDA\n----------------------------------------\n", variabili[i]);
        count_valid++;


      }else {
        printf("FILE:%s var:%s -> ERRORE nella riga %d\n----------------------------------------\n", nome_input,variabili[i],indice_riga);
        count_invalid++;
      }
    }
  }
  tot_var = count_valid + count_invalid;
  fclose(principale);
  return 0;
}