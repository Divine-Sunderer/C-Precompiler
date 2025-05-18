#ifndef MYPRECOMPILER_H
#define MYPRECOMPILER_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CheckDirettive.h"
#include "DeleteComments.h"
#include "VarChecker.h"
#include "checkFileSize.h"

void checkNextArg(int i, int argc, const char *nomeString);
int main(int argc, char *argv[]);

#endif //MYPRECOMPILER_H
