#include "../my_matrix_test.h"

START_TEST(my_determinant_test_1) {
  matrix_t A = {0};
  double determinant = 0;
  int res = my_determinant(&A, &determinant);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_determinant_test_2) {
  matrix_t A = {0};
  int res = my_determinant(&A, NULL);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_determinant_test_3) {
  matrix_t A = {0};
  int rows = 2;
  int columns = 0;
  double determinant = 0;

  my_create_matrix(rows, columns, &A);
  int res = my_determinant(&A, &determinant);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_determinant_test_4) {
  matrix_t A = {0};
  int size = 2;
  double determinant = 0;

  my_create_matrix(size, size + 1, &A);
  int res = my_determinant(&A, &determinant);

  ck_assert_int_eq(res, CALCULATION_ERROR);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_determinant_test_5) {
  matrix_t A = {0};
  int rows = 2;

  my_create_matrix(rows, rows, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = -5;

  int res = my_determinant(&A, NULL);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_determinant_test_6) {
  matrix_t A = {0};
  int rows = 1;
  double determinant = 0;

  my_create_matrix(rows, rows, &A);
  A.matrix[0][0] = -7;

  int res = my_determinant(&A, &determinant);

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq(determinant, -7);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_determinant_test_7) {
  matrix_t A = {0};
  int rows = 2;
  double determinant = 0;

  my_create_matrix(rows, rows, &A);
  A.matrix[0][0] = 7;
  A.matrix[0][1] = 0.5;
  A.matrix[1][0] = 12;
  A.matrix[1][1] = 1.2;

  int res = my_determinant(&A, &determinant);

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(determinant, 2.4, 1e-06);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_determinant_test_8) {
  matrix_t A = {0};
  int rows = 3;
  double determinant = 0;

  my_create_matrix(rows, rows, &A);
  A.matrix[0][0] = 7;
  A.matrix[0][1] = 0.5;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 12;
  A.matrix[1][1] = 1.2;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = -1;

  int res = my_determinant(&A, &determinant);

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(determinant, 1.9, 1e-06);
  my_remove_matrix(&A);
}
END_TEST

Suite *my_determinant_suite(void) {
  TCase *tc_case = tcase_create("determinant");
  Suite *s = suite_create("my_determinant_test");

  tcase_add_test(tc_case, my_determinant_test_1);
  tcase_add_test(tc_case, my_determinant_test_2);
  tcase_add_test(tc_case, my_determinant_test_3);
  tcase_add_test(tc_case, my_determinant_test_4);
  tcase_add_test(tc_case, my_determinant_test_5);
  tcase_add_test(tc_case, my_determinant_test_6);
  tcase_add_test(tc_case, my_determinant_test_7);
  tcase_add_test(tc_case, my_determinant_test_8);

  suite_add_tcase(s, tc_case);

  return s;
}