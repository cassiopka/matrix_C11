#include "../my_matrix_test.h"

START_TEST(my_remove_matrix_test_1) {
  matrix_t A = {0};

  int res = OK;
  my_remove_matrix(&A);
  if (A.matrix != NULL) res = INCORRECT_MATRIX;

  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(my_remove_matrix_test_2) {
  int rows = 1;
  int columns = 1;
  matrix_t A = {0};
  int res = my_create_matrix(rows, columns, &A);
  my_remove_matrix(&A);
  if (A.matrix == NULL) res = OK;

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

START_TEST(my_remove_matrix_test_3) {
  int rows = 15;
  int columns = 24;
  matrix_t A = {0};

  int res = my_create_matrix(rows, columns, &A);
  my_remove_matrix(&A);
  if (A.matrix == NULL) res = OK;

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

Suite *my_remove_matrix_suite(void) {
  TCase *tc_case = tcase_create("remove_matrix");
  Suite *s = suite_create("my_remove_matrix_test");

  tcase_add_test(tc_case, my_remove_matrix_test_1);
  tcase_add_test(tc_case, my_remove_matrix_test_2);
  tcase_add_test(tc_case, my_remove_matrix_test_3);

  suite_add_tcase(s, tc_case);

  return s;
}