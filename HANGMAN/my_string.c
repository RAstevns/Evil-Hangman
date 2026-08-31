#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_string.h"

MY_STRING my_string_init_default(void){
  
  My_string* pString;
  pString = (My_string*)malloc(sizeof(My_string));
  
  if(pString != NULL){
    
    pString->size =0;
    pString->capacity = 7;
    pString->data = (char*)malloc(sizeof(char)*pString->capacity);
    
  } else {
    
    free(pString);
    pString = NULL;
    
  }
  
  return (MY_STRING)pString;
}

void my_string_destroy(MY_STRING* phMy_string) {
  
  My_string* pMy_string = (My_string*) *phMy_string;
  free(pMy_string->data);
  free(pMy_string);
  *phMy_string = NULL;
  
  return; 
}
MY_STRING my_string_init_c_string(const char* c_string){
  
  My_string* pString;

  int i = 0;
  char c = 'm';

  for(i=0;c!='\0';i++){
    c = c_string[i];
  }

  pString = (My_string*)malloc(sizeof(My_string));
  
  if(pString != NULL){
    
    pString->size = i;
    pString->capacity = i;
    pString->data = (char*)malloc(sizeof(char) *pString->capacity);
    
  }else {
    
    free(pString);
    pString = NULL;
    
  }
  for (i = 0; i < pString->capacity; i++){
    pString->data[i] = c_string[i];
  }
  return (MY_STRING) pString;
}

int my_string_get_capacity(MY_STRING hMy_string){
  My_string* pMy_string = (My_string*) hMy_string;
  return pMy_string->capacity;
}

int my_string_get_size(MY_STRING hMy_string){
  My_string* pMy_string = (My_string*) hMy_string;
  return pMy_string->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string){
  char c = 'm';
  int diff = 0;
  int i =0;
  My_string* pRight_string = (My_string*) hRight_string;
  My_string* pLeft_string = (My_string*) hLeft_string;
  for(i=0;c!='\0';i++){
    c = pLeft_string->data[i];
    diff++;
  }
  c = 'm';
  for(i=0;c!='\0';i++){
    c = pRight_string->data[i];
    diff--;
  }
  return diff;
}
//Precondition: hMy_string is the handle to a valid My_string object.
//Postcondition: hMy_string will be the handle of a string object that contains
// the next string from the file stream fp according to the following rules.
// 1) Leading whitespace will be ignored.
// 2) All characters (after the first non-whitespace character is obtained
// and included) will be added to the string until a stopping condition
// is met. The capacity of the string will continue to grow as needed
// until all characters are stored.
// 3) A stopping condition is met if we read a whitespace character after
// we have read at least one non-whitespace character or if we reach
// the end of the file.
// Function will return SUCCESS if a non-empty string is read successfully.
// and failure otherwise. Remember that the incoming string may aleady
// contain some data and this function should replace the data but not
// necessarily resize the array unless needed.

Status my_string_extraction(MY_STRING hMy_string, FILE* fp){
My_string* pMy_string = (My_string*) hMy_string;
 int i = 0;
 char c = 'd';
 c = fgetc(fp);
 while(isspace(c)){
   c=fgetc(fp);
   if(c==EOF){
     return FAILURE;
   }
 }
 
 pMy_string->size = 0;
 for(i=0;!isspace(c);i++){
   if(pMy_string->capacity > i+1){
   pMy_string->size=i+1;
   pMy_string->data[i]=c;
   } else {
     pMy_string->data = (char*) realloc(pMy_string->data,pMy_string->capacity*2);
     if(pMy_string->data == NULL){
       return FAILURE;
     }
     pMy_string->capacity *= 2;
     pMy_string->size = i+1;
     pMy_string->data[i] = c;

   }
   c=fgetc(fp);
   if(c==EOF){
     return FAILURE;
   }
 }
 ungetc(c, fp);
 return SUCCESS;
}

//Precondition: hMy_string is the handle to a valid My_string object.
//Postcondition: Writes the characters contained in the string object indicated
// by the handle hMy_string to the file stream fp.
// Function will return SUCCESS if it successfully writes the string and
// FAILURE otherwise.

Status my_string_insertion(MY_STRING hMy_string, FILE* fp){
 My_string* pMy_string = (My_string*) hMy_string;
 int i = 0;
 char c = 'l';

 if(pMy_string == NULL){
   return FAILURE;
 } else {

   for(i=0;i<=pMy_string->size;i++){
     c = pMy_string->data[i];
     fprintf(fp,"%c",c);
   }
   return SUCCESS;
 }
  
}

//Precondition: hMy_string is the handle to a valid My_string object.
//Postcondition: If successful, places the character item at the end of the
// string and returns SUCCESS. If the string does not have enough room and
// cannot resize to accomodate the new character then the operation fails
// and FAILURE is returned. The resize operation will attempt to amortize
// the cost of a resize by making the string capacity somewhat larger than
// it was before (up to 2 times bigger).

Status my_string_push_back(MY_STRING hMy_string, char item){
My_string* pMy_string = (My_string*) hMy_string;
 if(pMy_string->capacity>pMy_string->size+1){
   
   pMy_string->size+=1;
   pMy_string->data[pMy_string->size-1]=item;
 }  else {
     pMy_string->data = (char*) realloc(pMy_string->data, pMy_string->capacity*2);
     if(pMy_string->data == NULL){
       return FAILURE;
     }
     pMy_string->capacity *= 2;
     pMy_string->size += 1;
     pMy_string->data[pMy_string->size] = item;

   }
 return SUCCESS;
}

//Precondition: hMy_string is the handle to a valid My_string object.
//Postcondition: Removes the last character of a string in constant time.
// Guaranteed to not cause a resize operation of the internal data. Returns
// SUCCESS on success and FAILURE if the string is empty.

Status my_string_pop_back(MY_STRING hMy_string){
My_string* pMy_string = (My_string*) hMy_string;
 if(pMy_string->size>0){
   pMy_string->size=pMy_string->size-1;
 }else{
   return FAILURE;
 }
 return SUCCESS;
}

//Precondition: hMy_string is the handle to a valid My_string object.
//Postcondition: Returns the address of the character located at the given
// index if the index is in bounds but otherwise returns NULL. This address
// is not usable as a c-string since the data is not NULL terminated and is
// intended to just provide access to the element at that index.

char* my_string_at(MY_STRING hMy_string, int index){
My_string* pMy_string = (My_string*) hMy_string;
 if(my_string_get_size(hMy_string)>index&&index>=0)
   {
   return &pMy_string->data[index];
   } else {
   return NULL;
 }
}

//Precondition: hMy_string is the handle to a valid My_string object.
//Postcondition: Returns the address of the first element of the string object
// for use as a c-string. The resulting c-string is guaranteed to be NULL
// terminated and the memory is still maintained by the string object though
// the NULL is not actually counted as part of the string (in size).

char* my_string_c_str(MY_STRING hMy_string){
 My_string* pMy_string = (My_string*) hMy_string;
 return pMy_string->data;
}

//Precondition: hResult and hAppend are handles to valid My_string objects.
//Postcondition: hResult is the handle of a string that contains the original
// hResult object followed by the hAppend object concatenated together. This
// function should guarantee no change to the hAppend object and return
// SUCCESS if they operation is successful and FAILURE if the hResult object
// is unable to accomodate the characters in the hAppend string perhaps
// because of a failed resize operation. On FAILURE, no change to either
// string should be made.

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend){
 My_string* pResult = (My_string*) hResult;
 My_string* pAppend = (My_string*) hAppend;
 int i =0;
 if(pResult->capacity>pAppend->size+1){
   
   pResult->size+=pAppend->size;
   for(i=0;i<pAppend->size;i++){
     
     pResult->data[pResult->size-1+i]=pAppend->data[i];
     
   }
 }  else {
     pResult->data = (char*) realloc(pResult->data, pResult->capacity+pAppend->capacity);
     if(pResult->data == NULL){
       return FAILURE;
     }
     
     pResult->capacity += pAppend->size;
     pResult->size+=pAppend->size;
     
     for(i=0;i<pAppend->size;i++){
     
     pResult->data[pAppend->size-1+i]=pAppend->data[i];
     
   }

   }
 return SUCCESS;
}

//Precondition: hMy_string is the handle to a valid My_string object.
//Postcondition: Returns an enumerated type with value TRUE if the string
// is empty and FALSE otherwise.

Boolean my_string_empty(MY_STRING hMy_string){
 My_string* pMy_string = (My_string*) hMy_string;
 if(pMy_string->size<=0){
   return TRUE;
 }
 return FALSE;
}

//Precondition: hLeft and hRight contain the handles of valid
// MY_STRING objects.
//Postcondition: On Success hLeft will contain the handle
// to a valid MY_STRING object that is a deep copy of the object indicated
// by hRight. The object indicated by the handle at the address pLeft will
// attempt to resize to hold the data in Right. If the object on the left
// already has enough room to store all of the data on the right then it
// will not resize. hLeft will have the same size as hRight if the call
// succeeds but the capacities may differ. The data in the dynamic arrays
// up to size number of elements will be identical in both objects.
// On failure pLeft will be unchanged and a Status of FAILURE will be
// returned.

Status my_string_assignment(MY_STRING hLeft, MY_STRING hRight){
  My_string* pLeft = (My_string*) hLeft;
  My_string* pRight = (My_string*) hRight;
  int i;
  
  pLeft->size = pRight->size;
  pLeft->capacity =  pRight->capacity;
  free(pLeft->data);
  pLeft->data = malloc(sizeof(char)*pRight->capacity);
  
  if(pLeft->data==NULL){
    return FAILURE;
  }
  for(i=0;i<pRight->size;i++){
    pLeft->data[i] = pRight->data[i];
  }
  
  return SUCCESS;
  
}

//Precondition: hMy_string is the handle to a valid MY_STRING object.
//Postcondition: Will return the handle to a valid MY_STRING object that
//is a deep copy of the object indicated by hMy_string. This means the
//copied object will be a complete and independent copy and not share
//any data with the object we are copying from. On failure the function will
//return NULL.

MY_STRING my_string_init_copy(MY_STRING hMy_string){

  MY_STRING result = my_string_init_c_string(my_string_c_str(hMy_string));
  My_string* pResult = (My_string*) result;
  if(pResult->data != NULL){
    return result;
  }
  
  return NULL;
}

//Precondition: hLeft and hRight are handles to valid MY_STRING objects.
//Postcondition: After the function hLeft will contain the size capacity and
//data of the object indicated by hRight and hRight will contain
//the size capacity and data of the oject indicated by hLeft. This function
//will be much faster than making deep copies of the objects using
//my_string_assignment and attempting to swap them in the traditional way
//calling my_string assignment in place of the '=' below.
//temp = a;
//a = b;
//b = temp;

void my_string_swap(MY_STRING hLeft, MY_STRING hRight){
  My_string* pLeft = (My_string*) hLeft;
  My_string* pRight = (My_string*) hRight;
  int i;
  MY_STRING temp = my_string_init_copy(hLeft);
  
  My_string* pTemp = (My_string*) temp;
  
  pLeft->size = pRight->size;
  pLeft->capacity = pRight->capacity;
  pLeft->data = realloc(pLeft->data, pLeft->capacity*(sizeof(char)));
  
  if(pLeft->data == NULL){
    exit(0);
  }
  
  for(i=0;i<pLeft->size;i++){
      pLeft->data[i] = pRight->data[i];
  }

  
  pRight->size = pTemp->size;
  pRight->capacity = pTemp->capacity;
  pRight->data = realloc(pRight->data, pRight->capacity*(sizeof(char)));
  
  if(pRight->data == NULL){
    exit(0);
  }
  
  for(i=0;i<pRight->size;i++){
      pRight->data[i] = pTemp->data[i];
  }


  
  my_string_destroy(&temp);
}

//Precondition:current_word_family, new_key and word are all handles to valid
// MY_STRING opaque objects. guess is an alphabetical character that can be either
// upper or lower case.
//Postcondition: Returns SUCCESS after replacing the string in new_key with the key
// value formed by considering the current word family, the word and the guess.
// Returns failure in the case of a resizing problem with the new_key string.

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess){    int i;
    while(!my_string_empty(new_key))
        my_string_pop_back(new_key);
    for(i = 0; i < my_string_get_size(word); i++)
        if(!my_string_push_back(new_key, *my_string_at(word, i) == guess ? guess : *my_string_at(current_word_family, i)))
            return FAILURE;
    return SUCCESS;   
}

