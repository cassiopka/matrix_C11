#ifndef MY_MATRIX_TEST
#define MY_MATRIX_TEST

#include <check.h>
#include <stdlib.h>

#include "my_matrix.h"

Suite *my_create_matrix_suite(void);
Suite *my_remove_matrix_suite(void);
Suite *my_eq_matrix_suite(void);
Suite *my_sum_matrix_suite(void);
Suite *my_sub_matrix_suite(void);
Suite *my_mult_number_suite(void);
Suite *my_mult_matrix_suite(void);
Suite *my_transpose_suite(void);
Suite *my_calc_complements_suite(void);
Suite *my_determinant_suite(void);
Suite *my_inverse_matrix_suite(void);
#endif