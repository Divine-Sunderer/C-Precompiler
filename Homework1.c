//Piccolo programma di prova ( non testato ) per vedere se un file si apre correttamente

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool checkFile(FILE * prova)
{
    if( prova )
    {
        return true;
    }
    return false;
}

char eliminaMultilinea(int i, int char_pointer , char riga[])
{
    while ( char_pointer < strlen(riga) || (riga[i] != '*' && riga[i+1] != '/')) {
        riga[char_pointer] = ' ';
        char_pointer++;
    }
    if(riga[i] != '*' && riga[i+1] != '/')
    {
        riga[i] = ' ';
        riga[i+1] = ' ';
    }
  return *riga;
}

int main(int argc, char * argv[]) { //argc e argv ci permettono di inserire comandi dal prompt
    int char_pointer;
    char riga[256]; // Vettore di caratteri per contenere una riga
    char carattere;
    FILE *prova;
    prova = fopen("C:\\Users\\cripo\\Desktop\\sistemi operativi II\\test1\\test1\\test1.c", "w+");
    // w+ apre il file in lettura e scrittura. Anche r+ fa lo stesso , ma senza andarlo a creare se inesistente

    if (checkFile(prova)) {
        printf("File aperto correttamente ");
    } else {
        perror("File inesistente!");
        return 0;
    }

    //fprintf(prova, "paperella gay sei l'uccello che vorrei \n");
    rewind(prova); // riporta il puntatore all'inizio

    // Cicla le righe
    while (fgets(riga, sizeof(riga), prova) != NULL) {

        if (strstr(riga, "//") != NULL) {
            for ( int i = 0 ; i < strlen(riga) ; i++ ) {
                if (riga[i] == '/' && riga[i+1] == '/') {
                    char_pointer = i;

                    while ( char_pointer < strlen(riga) ) {
                        riga[char_pointer] = ' ';
                        char_pointer++;
                    }
                    break;
                }
            }
        }else if (strstr(riga, "/*") != NULL) {
            for ( int i = 0 ; i < strlen(riga) ; i++ ) {
                if ( riga[i] == '/' && riga[i+1] == '*' ) {
                    char_pointer = i;

                    eliminaMultilinea(i,char_pointer,riga);
                }
            }
        }else if (strstr(riga,"*/")) {
            for ( int i = 0 ; i < strlen(riga) ; i++ ) {
                if ( riga[i] != '*' && riga[i+1] != '/') {
                    char_pointer = i;

                    eliminaMultilinea(i,char_pointer,riga);
                }
            }
        }



        printf("Letto : %s", riga);
    }

    return 0;
}