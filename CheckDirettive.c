#include "CheckDirettive.h"
// return 1 -> file non aperto correttamente
// ruturn 2 -> errore inerente a malloc
// return 3 -> trovato un include, ripetere scansione

int checkInclude(FILE *principale, FILE *statistiche, char* nome_input, char* nome_output) {
  char riga[256] , raw[256];
  char *str_din , *inizio , *fine;
  bool start = false;
  int count_str = 0, repeat = 0;
  FILE *dir, *nuovo;

  //statistiche = fopen("statistiche.txt", "r+");
  int count_include = 0;
  // Principale -> file su cui lavorare, dir -> file da includere, nuovo -> file "in return" con modifiche

  principale = fopen(nome_input, "r+");
  nuovo = fopen(nome_output, "w+");
  if (!principale) return 1;
  if (!nuovo) return 1;

  while(fgets(riga, sizeof(riga), principale) != NULL){
      //Se trova la sotto-stringa "#include" dentro la stringa
      if(strstr(riga,"#include") && strchr(riga,'\"')){
        repeat = 3;
        for(int i = 0; i < strlen(riga); i++){
          if(riga[i] == '\"' && start == false){                                                                        //Inizia la conta dei caratteri per l'allocazione dinamica
            count_str = 0;                                                                                              //Va azzerato altrimenti allochiamo troppa memoria inutilmente
            start = true;
            inizio = strchr(riga+i, '\"') + 1;
            count_str++;
          }else if(riga[i] == '\"' && start == true){                                                                   //Finisce la conta dei caratteri per l'allocazione dinamica
            start = false;
            fine = strchr(inizio, '\"');
            break;
          }
          if(start){                                                                                                    //Finché start == true ( e non trova nessun'altra virgoletta )  incrementa il conteggio
            count_str++;
          }
        }

        str_din = (char *)malloc((count_str + 1) * sizeof(char));
        if(!str_din){
          perror("Errore con la malloc\n");
          fclose(principale);
          return 2;
        }

        strncpy(str_din, inizio, fine - inizio);
        str_din[fine - inizio] = '\0';              //Altrimenti non avrebbe fine

        dir = fopen(str_din, "r+");
        if (statistiche) {
          fprintf(statistiche, "statistiche del file: %s\n", str_din);
        }
        //righe e dimensione per ogni file incluso, il cui nome è nella variabile dir
        checkFileLenght(dir, statistiche, nome_input);
        checkFileSize(dir, statistiche, nome_input);

        count_include++;

        while(fgets(raw, sizeof(raw), dir) != NULL){
          fprintf(nuovo,"%s", raw);
        }
        fclose(dir);
        free(str_din);
        str_din = NULL;
      }else{
        fprintf(nuovo,"%s",riga);
      }
  }

  if (statistiche) {
    fprintf(statistiche, "Numero di file inclusi: %d\n", count_include);
  }

  //fclose(statistiche);
  rewind(nuovo);
  rewind(principale);
  fclose(nuovo);
  fclose(principale);

  remove(nome_input);
  rename(nome_output, nome_input);
  return repeat;
}