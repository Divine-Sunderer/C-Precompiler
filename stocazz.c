#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* strsep(char** stringp, const char* delim) {
    if (*stringp == NULL) return NULL;

    char* start = *stringp;
    char* end = strpbrk(start, delim);

    if (end) {
        *end = '\0';
        *stringp = end + 1;
    } else {
        *stringp = NULL;
    }

    return start;
}


int isValidType(const char* token) {
    const char* types[] = {
        "int", "char", "float", "double", "long", "short",
        "signed", "unsigned", "bool", "string"
    };
    for (int i = 0; i < 10; i++) {
        if (strcmp(token, types[i]) == 0)
            return 1;
    }
    return 0;
}

int isValidVarName(const char* var) {
    if (!isalpha(var[0]) && var[0] != '_')
        return 0;
    for (int i = 1; var[i]; i++) {
        if (!isalnum(var[i]) && var[i] != '_')
            return 0;
    }
    return 1;
}

void checkVariableDeclarations(const char* line) {
    char buffer[256];
    strncpy(buffer, line, sizeof(buffer));
    buffer[sizeof(buffer) - 1] = '\0';

    //Esempio: se la riga è "int a, b;", "firstToken" diventa "int".
    char* rest = buffer;
    char* firstToken = strtok_r(rest, " \t", &rest);

    if (!firstToken || !isValidType(firstToken)) return;

    // Ora parsiamo le variabili
    char* varPart = rest;
    char* semi = strchr(varPart, ';');
    if (semi) *semi = '\0';
    //Adesso "varPart" contiene solo la parte con le variabili

    char* token;
    while ((token = strsep(&varPart, ",")) != NULL) {
        while (isspace(*token)) token++;  // salta spazi iniziali

        // gestisci inizializzazione (es: "a = 4")
        char* equal = strchr(token, '=');
        if (equal) *equal = '\0';

        // pulizia spazi
        while (isspace(token[strlen(token)-1]))
            token[strlen(token)-1] = '\0';

        if (strlen(token) == 0) continue;

        if (isValidVarName(token))
            printf("( %s ): Variabile OK\n", token);
        else
            printf("( %s ): Nome variabile NON valido\n", token);
    }
}


int main() {
    printf("Test 1:\n");
    checkVariableDeclarations("int a, b=4, _ok, 2bad;");

    printf("\nTest 2:\n");
    checkVariableDeclarations("char nome,   cognome= 'X';");

    printf("\nTest 3:\n");
    checkVariableDeclarations("float  wrong name = 3.2;");

    printf("\nTest 4:\n");
    checkVariableDeclarations("unsigned long very_long_var, anotherOne = 10;");

    printf("\nTest 4.5:\n");
    checkVariableDeclarations("char canzonedimerda = 3;");

    printf("\nTest 5 (non dichiarazione):\n");
    checkVariableDeclarations("printf(\"Hello world\");");

    printf("\nTest 6 (tipo non riconosciuto):\n");
    checkVariableDeclarations("custom_type foo, bar;");

    return 0;
}
