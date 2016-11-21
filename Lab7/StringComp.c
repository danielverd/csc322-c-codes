#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 1000
typedef char String[STRING_SIZE];
//------------------------------------------------------------                                                                                                                                 
void  compare(String s1, String s2){

  int i, j;

  for(i = 0; i <= (strlen(s1)-1); i++){
    for(j = 0; j <= (strlen(s2)-1); j++){
      if(s1[i] == s2[j]){
        s1[i] = ' ';
      }
    }
  }

}

int main(void){

  String firstString;
  String secondString;
  String editedString;
  int i;
  int n = 0;

  printf("Enter the first string : ");
  fgets(firstString, STRING_SIZE, stdin);
  firstString[strlen(firstString) - 1] = '\0';

  printf("Enter the second string : ");
  fgets(secondString, STRING_SIZE, stdin);
  secondString[strlen(secondString) - 1] = '\0';

  compare(firstString, secondString);

  for(i = 0; i <= strlen(firstString); i++){
    if(firstString[i] != ' '){
      editedString[n] = firstString[i];
      n++;
    }
  }

  printf("The edited string is %s\n", editedString);

  return(EXIT_SUCCESS);

}
