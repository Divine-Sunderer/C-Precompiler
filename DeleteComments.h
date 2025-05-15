#ifndef DELETECOMMENTS_H
#define DELETECOMMENTS_H
#include <stdio.h>
#include <stdbool.h>

bool checkFile(FILE *prova);
int deleteComments(FILE *input, FILE *output, char* nome_input, char* nome_output);

#endif //DELETECOMMENTS_H
