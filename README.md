Homework 1 del corso Sistemi Operativi II del corso di laurea in Informatica della Sapienza Università di Roma
di Cristina Porceddu [@crostataa](https://github.com/crostataa) e Antonio Salvati [@Divine-Sunderer](https://github.com/Divine-Sunderer)
Il progetto consiste nella realizzazione in linguaggio C di un programma che simuli la precompilazione di un file C

-+-+-+-+-+-+-+-+-+-+-+-+-+-+
# Traccia del Progetto
Sviluppare un applicazione che, dato un file contenente del codice C, lo elabori come segue
1) risolva le direttive #include, ovvero includa il contenuto dei file argomento della direttiva #include;
2) controlli se sono state dichiarate variabili con nome non valido, ovvero identificatori non validi (ad es. x-ray, two&four, 5brothers)
3) elimini tutti i commenti;
4) produca un file di output contenente il codice modificato, ovvero il file di input estenso con gli include e senza commenti;
5) produca le statistiche di elaborazione riportate nella sezione "Specifiche"

## Assunzioni
Si puo' assumere che:

1) i file inclusi mediante la direttiva #include siano memorizzati nella CWD

2) il file contenente il codice C fornito come input sia costituito dal solo blocco di codice della funzione main e che non ci siano altre funzioni

3) che tutte le variabili locali siano dichiarate all'inizio della funzione main in righe contigue e che le variabili globali siano dichiarate prima del main in righe contigue;

4) i tipi di dato usati nella dichiarazione delle variabili sono corretti;

## Specifiche

1) Input: il programma prevede tre parametri di input

-i, --in (notazione doppio trattino) per specificare il file di input

-o --out (notazione doppio trattino) per specificare il file di output

-v, --verbose (notazione doppio trattino) per produrre o meno come output le statistiche di elaborazione

Il file di input, ovvero il file contenente il codice C da processare, e' un parametro obbligatorio e puo' essere passato come argomento dell'opzione -i o --in. Ad esempio:
myPreCompiler nome_file_input.c

in questo caso il file nome_file_input.c verra' processato dal programma e l'output prodotto su stdout (vedi sezione Output)

```bash
myPreCompiler -i nome_file_input.c 
```
```bash
myPreCompile --in=nome_file_input.c
```
in questo caso il file nome_file_input.c verra' processato dal programma e potra' essere utilizzata l'opzione -o, --out per specificare il file di output (vedi sezione Output).

2) Output: devono essere previste due modalita' di output. 
Nella prima, viene specificato come parametro di input del programma il nome del file di output quale argomento dell'opzione -o, --out.
Nella seconda, se l'opzione -o non viene usata, il risultato del processamento del file di input viene inviato allo stdout.

Esempi di esecuzione
```bash
myPreCompiler -i nome_file_input.c -o nome_file_output
```
al termine del programma, il file nome_file_output conterra' il codice processato.
```bash
myPreCompiler -i nome_file_input.c
```
```bash
myPreCompiler nome_file_input.c
```
prima di terminare il programma invia su stdout il risultato del processamento
```bash
myPreCompiler -i nome_file_input.c > nome_file_output
```
prima di terminare il programma invia sullo stdout il risultato del processamento che viene ridirezionato nel file nome_file_output.

## Statistiche di elaborazione
Il programma myPreCompiler deve altresi' poter restituire come risultato, sullo standard output, le seguenti statistiche di elaborazione:

- numero di variabili controllate
- numero di errori rilevati
-per ogni errore rilevato, nome del file in cui e' stato rilevato e numero di riga nel file. 
- numero di righe di commento eliminate
- numero di file inclusi
- per il file di input la dimensione in byte ed il numero di righe (pre processamento)
- per ogni file incluso dimensione in byte e numero di righe (pre processamento)
- numero di righe e dimensione dell'output

L'output sopra riportato deve poter essere abilitato/disabilitato mediante l'opzione -v, --verbose. Ad esempio
```bash
myPreCompiler -v -c nome_file_input.c -o nome_file_output
```
restituisce sullo standard output le statistiche sopra menzionate, mentre 
```bash
myPreCompiler -c nome_file_input.c -o nome_file_output
```
non produce sullo standard output le statistiche sopra menzionate

(Opzionale: Restituire le statistiche di elaborazione sullo standard error invece che sullo 
standard output in modo da poter ridirezionare il file processato e le statistiche di 
elaborazione su due file diversi quando si seleziona la seconda modalità di output)

## Errori
L'applicazione sviluppata deve gestire i seguenti errori:
- errore nei parametri di input, opzioni e relativi argomenti specificate da linea di comando
- errore di apertura dei file di input o specificati come argomento dell'include
- errore di chiusura file
- errore di lettura da file - ad esempio file vuoto o corrotto
- errore di scrittura su file
  
## Struttura del programma e uso della memoria
Il programma non deve essere monolotico ma composto da un main e varie funzioni che sviluppano le funzinalita' principali e funzionalita' di supporto.
Il programma deve essere organizzato in almeno tre file: un file contenente il main, almeno un file contenente le funzioni, ed almeno un header file.
