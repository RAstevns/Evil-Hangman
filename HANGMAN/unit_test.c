#include <stdio.h>
#include <string.h>
#include "unit_test.h"

int main(int argc, char* argv[])
{
 Status (*tests[])(char*, int) =
 {
 test_init_default_returns_nonNULL,
 test_get_size_on_init_default_returns_0,
 rstevens_test_on_init_is_empty,
 rstevens_test_my_string_concat, 
 rstevens_test_my_string_at, 
 rstevens_test_my_string_pop_back, 
 rstevens_test_my_string_push_back, 
 rstevens_test_my_string_insertion, 
 rstevens_test_my_string_compare_equal, 
 rstevens_test_my_string_compare_different, 
 rstevens_test_my_string_extraction_empty, 
 rstevens_test_my_string_extraction, 
 rstevens_test_my_string_at_empty, 
 rstevens_test_my_string_compare_empty, 
 rstevens_test_my_string_pop_empty, 
 rstevens_test_my_string_concat_empty, 
 rstevens_test_my_string_at_OOB, 
 rstevens_test_my_string_at_OOB_negative, 
 rstevens_test_my_string_c_str_empty, 
 rstevens_test_my_string_c_str, 
 rstevens_test_my_string_init_c_string, 
 rstevens_test_my_string_push_back_full, 
 rstevens_test_my_string_init_c_string_NULLchar, 
 rstevens_test_my_string_get_capacity, 
 rstevens_test_my_string_get_size
 };
 
 int number_of_functions = sizeof(tests) / sizeof(tests[0]);
 int i;
 char buffer[500];
 int success_count = 0;
 int failure_count = 0;
 for(i=0; i<number_of_functions; i++)
 {
 if(tests[i](buffer, 500) == FAILURE)
 {
 printf("FAILED: Test %d failed miserably\n", i);
 printf("\t%s\n", buffer);
 failure_count++;
 }
 else
 {
// printf("PASS: Test %d passed\n", i);
// printf("\t%s\n", buffer);
 success_count++;
 }
 }
 printf("Total number of tests: %d\n", number_of_functions);
 printf("%d/%d Pass, %d/%d Failure\n", success_count,
 number_of_functions, failure_count, number_of_functions);
 return 0;
}

Status test_init_default_returns_nonNULL(char* buffer, int length)
{
 MY_STRING hString = NULL;
 hString = my_string_init_default();
 if(hString == NULL)
 {
 strncpy(buffer, "test_init_default_returns_nonNULL\n"
 "my_string_init_default returns NULL", length);
 return FAILURE;
 }
 else
 {
 my_string_destroy(&hString);
 strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
 return SUCCESS;
 }
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
 MY_STRING hString = NULL;
 Status status;
 hString = my_string_init_default();
 if(my_string_get_size(hString) != 0)
 {
 status = FAILURE;
 printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
 strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
 "Did not receive 0 from get_size after init_default\n", length);
 }
 else
 {
 status = SUCCESS;
 strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
 , length);
 }
 my_string_destroy(&hString);
 return status;
}
Status rstevens_test_on_init_is_empty(char* buffer, int length){
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
 if(my_string_empty(hString) != 0)
 {
 status = FAILURE;
 printf("Expected an empty string\n");
 strncpy(buffer, "test_on_init_is_empty\n"
 "Did not receive an empty string after init_default\n", length);
 }
 else
 {
 status = SUCCESS;
 strncpy(buffer, "test_on_init_is_empty\n"
 , length);
 }
 my_string_destroy(&hString);
 return status;
}

Status rstevens_test_my_string_concat(char* buffer, int length){
MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
 if(1)
 {
 status = FAILURE;
 printf("Expected a \n");
 strncpy(buffer, "test_\n"
	 "Did not receive what was expected\n", length);
 }
 else
 {
 status = SUCCESS;
 strncpy(buffer, "test_on_init_is_empty\n", length);
 }

 my_string_destroy(&hString);
 return status;
}

  
Status rstevens_test_my_string_at(char* buffer, int length){return SUCCESS;}
Status rstevens_test_my_string_pop_back(char* buffer, int length){return SUCCESS;}
Status rstevens_test_my_string_push_back(char* buffer, int length){return SUCCESS;}
Status rstevens_test_my_string_insertion(char* buffer, int length){return SUCCESS;}
Status rstevens_test_my_string_compare_equal(char* buffer, int length){return SUCCESS;}
Status rstevens_test_my_string_compare_different(char* buffer, int length){return SUCCESS;}
Status rstevens_test_my_string_extraction_empty(char* buffer, int length){return SUCCESS;}
Status rstevens_test_my_string_extraction(char* buffer, int length){return SUCCESS;}
Status rstevens_test_my_string_at_empty(char* buffer, int length){return SUCCESS;}
Status rstevens_test_my_string_compare_empty(char* buffer, int length){return SUCCESS;}
Status rstevens_test_my_string_pop_empty(char* buffer, int length){return SUCCESS;}
Status rstevens_test_my_string_concat_empty(char* buffer, int length){return SUCCESS;}
Status rstevens_test_my_string_at_OOB(char* buffer, int length){return SUCCESS;}
Status rstevens_test_my_string_at_OOB_negative(char* buffer, int length){return SUCCESS;}
Status rstevens_test_my_string_c_str_empty(char* buffer, int length){return SUCCESS;}
Status rstevens_test_my_string_c_str(char* buffer, int length){return SUCCESS;}
Status rstevens_test_my_string_init_c_string(char* buffer, int length){return SUCCESS;}
Status rstevens_test_my_string_push_back_full(char* buffer, int length){return SUCCESS;}
Status rstevens_test_my_string_init_c_string_NULLchar(char* buffer, int length){return SUCCESS;}
Status rstevens_test_my_string_get_capacity(char* buffer, int length){return SUCCESS;}
Status rstevens_test_my_string_get_size(char* buffer, int length){return SUCCESS;}


/*
{
MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
 if(1)
 {
 status = FAILURE;
 printf("Expected a \n");
 strncpy(buffer, "test_\n"
 "Did not receive what was expected\n");
 }
 else
 {
 status = SUCCESS;
 strncpy(buffer, "test_on_init_is_empty\n", length);
 }

 my_string_destroy(&hString);
 return status;
}
 */
