#ifndef DELETECOMMENTS_H
#define DELETECOMMENTS_H
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "checkFileSize.h"

bool checkFile(FILE *prova);
int deleteComments(FILE *input, FILE *output, FILE *statistiche, char* nome_input, char* nome_output, bool checkFinale);

#endif //DELETECOMMENTS_H
