#include "../my_matrix_test.h"

START_TEST(my_transpose_test_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  int res = my_transpose(&A, &B);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_transpose_test_2) {
  matrix_t A = {0};
  int res = my_transpose(&A, NULL);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_transpose_test_3) {
  matrix_t A = {0};
  int rows = 2;
  int columns = 0;
  matrix_t B = {0};

  my_create_matrix(rows, columns, &A);
  int res = my_transpose(&A, &B);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_transpose_test_4) {
  matrix_t A = {0};
  int rows = 1;
  int columns = 1;
  matrix_t B = {0};

  my_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 5;
  int res = my_transpose(&A, &B);
  int eq = my_eq_matrix(&A, &B);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(eq, TRUE);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_transpose_test_5) {
  matrix_t A = {0};
  int rows = 3;
  int columns = 3;
  matrix_t B = {0};

  my_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 0.2;
  A.matrix[1][1] = 4;
  A.matrix[2][0] = 0.05;
  A.matrix[2][1] = 3;
  int res = my_transpose(&A, &B);

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq(B.matrix[0][0], 5);
  ck_assert_double_eq(B.matrix[0][1], 0.2);
  ck_assert_double_eq(B.matrix[0][2], 0.05);
  ck_assert_double_eq(B.matrix[1][0], 1);
  ck_assert_double_eq(B.matrix[1][1], 4);
  ck_assert_double_eq(B.matrix[1][2], 3);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

Suite *my_transpose_suite(void) {
  TCase *tc_case = tcase_create("transpose");
  Suite *s = suite_create("my_transpose_test");

  tcase_add_test(tc_case, my_transpose_test_1);
  tcase_add_test(tc_case, my_transpose_test_2);
  tcase_add_test(tc_case, my_transpose_test_3);
  tcase_add_test(tc_case, my_transpose_test_4);
  tcase_add_test(tc_case, my_transpose_test_5);

  suite_add_tcase(s, tc_case);

  return s;
}