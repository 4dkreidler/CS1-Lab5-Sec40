#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
/*
Name: Drake Kreidler
This code takes two messages, one old and one new, and gives back the amount of letters that would need to be purchased if we reuse the old letters.
*/
#define MAX_STRING_LEN 100002

int main(void) {
  //Allocates memory for both messages and declare variables
  char* oldmsg = (char*)calloc(MAX_STRING_LEN, sizeof(char)); 
  char* newmsg = (char*)calloc(MAX_STRING_LEN, sizeof(char)); 
  int freqArray1[26]={0}, freqArray2[26]={0},len1, len2, total=0; 
  
  //Gets user input
  fgets(oldmsg, MAX_STRING_LEN, stdin); 
  fgets(newmsg, MAX_STRING_LEN, stdin); 

  //Gets lengths of the strings
  len1 = strlen(oldmsg); 
  len2 = strlen(newmsg); 

  //Finds frequency of letters for the old message
  for(int i=0; i<len1; i++){
        freqArray1[oldmsg[i]-'A']++;
  }

  //Finds frequencye of letters for the new message
  for(int i=0; i<len2; i++){
        freqArray2[newmsg[i]-'A']++;
  }

  //Subtracts the letters we already have on the old message to the new message
  for(int i=0; i<26; i++){
    if(freqArray2[i]>0 && freqArray1[i]>0)
      freqArray2[i] -= freqArray1[i]; 
  }

  //Adds up the total amount of letters we still need to buy
  for(int i=0; i<26; i++){
    if(freqArray2[i]>0)
      total += freqArray2[i]; 
  }

  //Displays total
  printf("%d", total); 
  
  //Frees allocated memory 
  free(oldmsg); 
  free(newmsg); 
  return 0;
}