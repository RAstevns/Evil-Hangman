#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"
Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);
Status rstevens_test_on_init_is_empty(char* buffer, int length);
Status rstevens_test_my_string_concat(char* buffer, int length);
Status rstevens_test_my_string_at(char* buffer, int length);
Status rstevens_test_my_string_pop_back(char* buffer, int length);
Status rstevens_test_my_string_push_back(char* buffer, int length);
Status rstevens_test_my_string_insertion(char* buffer, int length);
Status rstevens_test_my_string_compare_equal(char* buffer, int length);
Status rstevens_test_my_string_compare_different(char* buffer, int length);
Status rstevens_test_my_string_extraction_empty(char* buffer, int length);
Status rstevens_test_my_string_extraction(char* buffer, int length);
Status rstevens_test_my_string_at_empty(char* buffer, int length);
Status rstevens_test_my_string_compare_empty(char* buffer, int length);
Status rstevens_test_my_string_pop_empty(char* buffer, int length);
Status rstevens_test_my_string_concat_empty(char* buffer, int length);
Status rstevens_test_my_string_at_OOB(char* buffer, int length);
Status rstevens_test_my_string_at_OOB_negative(char* buffer, int length);
Status rstevens_test_my_string_c_str_empty(char* buffer, int length);
Status rstevens_test_my_string_c_str(char* buffer, int length);
Status rstevens_test_my_string_init_c_string(char* buffer, int length);
Status rstevens_test_my_string_push_back_full(char* buffer, int length);
Status rstevens_test_my_string_init_c_string_NULLchar(char* buffer, int length);
Status rstevens_test_my_string_get_capacity(char* buffer, int length);
Status rstevens_test_my_string_get_size(char* buffer, int length);

// empty test : Status rstevens_(char* buffer, int length);
#endif
