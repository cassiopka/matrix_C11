#include "../my_matrix_test.h"

START_TEST(my_sum_matrix_test_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  int res = my_sum_matrix(&A, &B, &C);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_sum_matrix_test_2) {
  int rows = 2;
  int columns = 2;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  my_create_matrix(rows, columns, &A);
  int res = my_sum_matrix(&A, &B, &C);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_sum_matrix_test_3) {
  int rows = 2;
  int columns = 2;
  matrix_t A = {0};
  matrix_t B = {0};
  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows, columns, &B);
  int res = my_sum_matrix(&A, &B, NULL);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_sum_matrix_test_4) {
  int rows = 2;
  int columns = 2;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows - 1, columns, &B);
  int res = my_sum_matrix(&A, &B, &C);

  ck_assert_int_eq(res, CALCULATION_ERROR);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_sum_matrix_test_5) {
  int rows = 2;
  int columns = 2;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows, columns + 1, &B);
  int res = my_sum_matrix(&A, &B, &C);

  ck_assert_int_eq(res, CALCULATION_ERROR);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_sum_matrix_test_6) {
  int rows = 2;
  int columns = 2;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows, columns, &B);

  A.matrix[0][0] = 0.0;
  A.matrix[0][1] = 0.1;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 1.1;

  B.matrix[0][0] = 0.0;
  B.matrix[0][1] = 0.1;
  B.matrix[1][0] = 1.0;
  B.matrix[1][1] = 1.1;

  int res = my_sum_matrix(&A, &B, &C);

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq(C.matrix[0][0], 0.0);
  ck_assert_double_eq(C.matrix[0][1], 0.2);
  ck_assert_double_eq(C.matrix[1][0], 2.0);
  ck_assert_double_eq(C.matrix[1][1], 2.2);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
  my_remove_matrix(&C);
}
END_TEST

Suite *my_sum_matrix_suite(void) {
  TCase *tc_case = tcase_create("sum_matrix");
  Suite *s = suite_create("my_sum_matrix_test");

  tcase_add_test(tc_case, my_sum_matrix_test_1);
  tcase_add_test(tc_case, my_sum_matrix_test_2);
  tcase_add_test(tc_case, my_sum_matrix_test_3);
  tcase_add_test(tc_case, my_sum_matrix_test_4);
  tcase_add_test(tc_case, my_sum_matrix_test_5);
  tcase_add_test(tc_case, my_sum_matrix_test_6);

  suite_add_tcase(s, tc_case);

  return s;
}