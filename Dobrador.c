#include <stdio.h>
#include <stdlib.h>

char K[1030];
FILE *On;
FILE *Off;

int main (){ //Listas simplesmente encadeadas
  int i;
  Off=fopen("OUT.txt","w");
  On=fopen("IN.txt","r");
  while (!feof(On)){
    fgets (K, 1024, On);
    i=0;
    while (K[i]!='\n'){
      if (K[i]=='\\'){
        fprintf(Off, "\\\\");
      } else if (K[i]=='%'){
        fprintf(Off, "%%%%");
      } else {
        fprintf(Off, "%c", K[i]);
      }
      /*else if (K[i]=='\"'){
        fprintf(Off, "\\\"");
      } else if (K[i]=='\''){
        fprintf(Off, "\\\'");
      } */
      i++;
    }
    fprintf(Off, "\n");
  }
  return 0;
}
