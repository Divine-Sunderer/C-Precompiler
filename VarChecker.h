#ifndef VARCHECKER_H
#define VARCHECKER_H
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

extern const char *parole_ris[];

#define len_res (sizeof(parole_ris)/sizeof(parole_ris[0]))

int isValidName(char *var);
char* eliminaSpaziIniziali(char str[]);
char* extendedTrim(char *str);
char* charCleaner(char *str);
int varChecker(FILE *principale,char *nome_input, FILE *statistiche);

#endif //VARCHECKER_H