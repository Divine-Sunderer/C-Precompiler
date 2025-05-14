#include <stdio.h>
#include "CheckDirettive.h"
#include "DeleteComments.h"
#include "VarChecker.h"

/*
_Statistiche di elaborazione_
numero di variabili controllate
numero di errori rilevati
per ogni errore rilevato, nome del file in cui e' stato rilevato e numero di riga nel file.
numero di righe di commento eliminate
numero di file inclusi
per il file di input la dimensione in byte ed il numero di righe (pre processamento)
per ogni file incluso dimensione in byte e numero di righe (pre processamento)
numero di righe e dimensione dell'output

L'output sopra riportato deve poter essere abilitato/disabilitato mediante l'opzione -v, --verbose.


creiamo un file, esso verrà aperto da ognuna delle nostre funzioni e ognuna di essere scriverà
qualcosa senza sovrascrivere quello che già c'è;

il nostro file si chiamerà 'statistiche'

il problema su come stamparlo su terminale è un problema del noi del futuro
 */

//argc -> contatore degli argomenti passati
//argv -> array di stringhe simil Java
//Sono essenziali per i parametri da passare
int main(int argc, char *argv[]) {
  FILE *statistiche;
  FILE *test;

  statistiche = fopen("statistiche.txt", "w+"); //creiamo il file per le statistiche
  test = fopen("test1.c", "r"); //apriamo il file di test

  //verifichiamo che i file si aprano correttamente
  if (!statistiche || !test) {
    perror("errore nell'apertura del file");
    return 1;
  }

  checkInclude(test, statistiche);
  //comment_remover(test, statistiche);
  //var_checker(test, statistiche);
// FERMIAMOCI QUI PLS, devo capire alcune cose ( devo fare il punto della situazione e capire come muovermi per continuare il corpo della funzione )
// Domani ( oppure io stasera se c'ho voglia ) creiamo uno schemetto per il funzionamento del main (devo committare)
  fclose(statistiche);
  return 0;








  return 0;
}