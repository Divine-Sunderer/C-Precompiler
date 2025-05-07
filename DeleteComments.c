//Piccolo programma di prova ( non testato ) per vedere se un file si apre correttamente

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

/*

//commento

*/

bool checkFile(FILE * prova)
{
    if( prova )
    {
        return true;
    }
    return false;
}
/*
char string[] = "stringa //";
controllo anche per '';
controlla intervallo in cui sono le stringhe -> qui 16-27
strchr("//") -> BUT cerca l'index di queste
se index in intervallo 16-27 allora NOT COMMENTO

char stringa[] = "stringa//"; //commento
*/

//Da rivedere
void eliminaMultilinea(int char_pointer , char riga[])
{
  int i = char_pointer;

    while ( riga[i] != '\0' ) {
      if(riga[i] == '*' && riga[i+1] == '/')
        {
            riga[i] = ' ';
            riga[i+1] = ' ';
            break;
        }
        riga[i] = ' ';
        i++;
    }
}

void eliminaSingola(int char_pointer , char riga[]) {
  int i = char_pointer;

  while( riga[i] != '*' && riga[i+1] != '/' ) {
        riga[i] = ' ';
    }
    riga[i] = ' ';
    riga[i+1] = ' ';
}

int main(int argc, char * argv[]) { //argc e argv ci permettono di inserire comandi dal prompt
    int char_pointer;
    bool delete = false;
    char riga[256]; // Vettore di caratteri per contenere una riga
    char carattere;
    FILE *prova;
    char string[] = "/*commento ancora più fasullo*/"; //è una stringa, non un commento;

    prova = fopen("inserire file di test", "w+");
    // w+ apre il file in lettura e scrittura. Anche r+ fa lo stesso , ma senza andarlo a creare se inesistente

    if (checkFile(prova)) {
        printf("File aperto correttamente ");
    } else {
        perror("File inesistente!");
        return 0;
    }

    rewind(prova); // riporta il puntatore all'inizio

    // Cicla le righe
    while (fgets(riga, sizeof(riga), prova) != NULL) {

         if ( delete == true ) {
           for ( int i = 0 ; i < strlen(riga) ; i++ )
            {
                riga[i] = ' ';
            }
            continue;
         }

        if(strstr(riga, "/*") != NULL && strstr(riga,"*/") != NULL)
          {
          for(int i = 0; i < strlen(riga); i++) {
                if(riga[i] == '*' && riga[i+1] == '/')
                  char_pointer = i;

                  eliminaSingola(char_pointer, riga);
            }
        }else if (strstr(riga, "//") != NULL) {
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

                    eliminaMultilinea(char_pointer,riga);
                    delete = true;
                }
            }
        }else if (strstr(riga,"*/") != NULL) {
            for ( int i = 0 ; i < strlen(riga) ; i++ ) {
                if ( riga[i] != '*' && riga[i+1] != '/') {
                    char_pointer = i;

                    eliminaMultilinea(char_pointer,riga);
                    delete = false;
                }
            }
        }
        printf("Letto : %s", riga);
    }
    return 0;
}

// for(int i = 0, j = 1; riga[i] != '*' && riga[j] != '/'; j++, i++)