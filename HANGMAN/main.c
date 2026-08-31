#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_string.h"

#define SIZE 127142

int main(int argc, char* argv[])
{
  char c = '\0';
  int i = 0;
  MY_STRING* testVals = (MY_STRING*) malloc(sizeof(MY_STRING) * 4);
  testVals[0] = my_string_init_c_string("The");
  testVals[1] = my_string_init_c_string("Truck");
  testVals[2] = my_string_init_c_string("happy");
  testVals[3] = my_string_init_c_string("awesome");
  
  MY_STRING* testKeys = (MY_STRING*) malloc(sizeof(MY_STRING) * 4);
  testKeys[0] = my_string_init_c_string("---");
  testKeys[1] = my_string_init_c_string("-----");
  testKeys[2] = my_string_init_c_string("--ppy");
  testKeys[3] = my_string_init_c_string("--e---e");
  MY_STRING new_key = my_string_init_c_string("test");
  printf("Enter test Guesses\n");
  scanf("%c", &c);
  printf("Old key, Word, Guess, New Key\n");
  
  for(i=0; i<4; i++){
  get_word_key_value(testKeys[i], new_key, testVals[i], c);
  printf("%s, %s, %c, ", my_string_c_str(testKeys[i]), my_string_c_str(testVals[i]), c);
  printf("%s\n", my_string_c_str(new_key));
  scanf("%c", &c);
  }
  
  my_string_destroy(&testVals[0]);  
  my_string_destroy(&testVals[1]); 
  my_string_destroy(&testVals[2]);  
  my_string_destroy(&testVals[3]);

  
  my_string_destroy(&testKeys[0]);
  my_string_destroy(&testKeys[1]);
  my_string_destroy(&testKeys[2]);
  my_string_destroy(&testKeys[3]);

  my_string_destroy(&new_key);
  
  free(testKeys);
  free(testVals);


  
  /*MY_STRING* dictionary = (MY_STRING*) malloc(sizeof(MY_STRING) * SIZE);
  MY_STRING* dictionary = (MY_STRING*) malloc(sizeof(MY_STRING) * SIZE);
  int i=0;
  int j[] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  MY_STRING currentStr = my_string_init_default();
  MY_STRING blank = my_string_init_default();
  FILE* fp;
  
  fp = fopen("dictionary.txt", "r");
  while(my_string_extraction(currentStr, fp)){
    
    dictionary[i] = my_string_init_c_string(my_string_c_str(currentStr));
  
  if(fgetc(fp)== ' ')
  {
  printf("Found a space after the string\n");
  }
  i++;
  my_string_assignment(currentStr, blank);//currentStr = my_string_init_default();
  }
  for(i=0;i<SIZE;i++){
    if(!(my_string_get_size(dictionary[i])>29)){
      j[my_string_get_size(dictionary[i])]++;
    }
  }
  for(i=1;i<29;i++){
    printf("there are %d words that are %d length\n", j[i],i);
  }



  
  my_string_destroy(&currentStr);
  my_string_destroy(&blank);
  for(i=0;i<SIZE;i++){
    
    my_string_destroy(&(dictionary[i]));

  }
  free(dictionary);
  fclose(fp);*/
  return 0;
}
