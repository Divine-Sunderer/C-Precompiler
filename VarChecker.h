#ifndef VARCHECKER_H
#define VARCHECKER_H
#include <stdio.h>
const char *parole_riservate[] = {
    "break", "case", "continue", "default", "do",
    "else", "for", "goto", "if", "inline", "restrict",
    "return", "sizeof", "switch", "while",
  };

#define len_res (sizeof(parole_riservate)/sizeof(parole_riservate[0]))

int isValidName(char *var);
char* eliminaSpaziIniziali(char str[]);
char* extendedTrim(char *str);
char* charCleaner(char *str);
int varChecker(FILE *principale,char *nome_input);

#endif //VARCHECKER_H
