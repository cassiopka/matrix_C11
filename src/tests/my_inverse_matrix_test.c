#include "../my_matrix_test.h"

START_TEST(my_inverse_matrix_test_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  int res = my_inverse_matrix(&A, &B);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_inverse_matrix_test_2) {
  matrix_t A = {0};
  int res = my_inverse_matrix(&A, NULL);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_inverse_matrix_test_3) {
  matrix_t A = {0};
  int rows = 2;
  int columns = 0;
  matrix_t B = {0};

  my_create_matrix(rows, columns, &A);
  int res = my_inverse_matrix(&A, &B);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_inverse_matrix_test_4) {
  matrix_t A = {0};
  int size = 2;
  matrix_t B = {0};

  my_create_matrix(size, size + 1, &A);
  int res = my_inverse_matrix(&A, &B);

  ck_assert_int_eq(res, CALCULATION_ERROR);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_inverse_matrix_test_5) {
  matrix_t A = {0};
  int size = 1;
  matrix_t B = {0};

  my_create_matrix(size, size, &A);
  int res = my_inverse_matrix(&A, &B);

  ck_assert_int_eq(res, CALCULATION_ERROR);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_inverse_matrix_test_6) {
  matrix_t A = {0};
  int size = 1;
  matrix_t B = {0};

  my_create_matrix(size, size, &A);

  A.matrix[0][0] = 4;

  int res = my_inverse_matrix(&A, &B);

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq(B.matrix[0][0], 0.25);

  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_inverse_matrix_test_7) {
  matrix_t A = {0};
  int size = 2;
  matrix_t B = {0};

  my_create_matrix(size, size, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 2;

  int res = my_inverse_matrix(&A, &B);

  ck_assert_int_eq(res, CALCULATION_ERROR);

  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_inverse_matrix_test_8) {
  matrix_t A = {0};
  int size = 2;
  matrix_t B = {0};

  my_create_matrix(size, size, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 3;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = -1;

  int res = my_inverse_matrix(&A, &B);

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(B.matrix[0][0], 0.0625, 1e-06);
  ck_assert_double_eq_tol(B.matrix[0][1], 0.1875, 1e-06);
  ck_assert_double_eq_tol(B.matrix[1][0], 0.3125, 1e-06);
  ck_assert_double_eq_tol(B.matrix[1][1], -0.0625, 1e-06);

  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_inverse_matrix_test_9) {
  matrix_t A = {0};
  int size = 1;
  matrix_t B = {0};
  my_create_matrix(size, size, &A);
  A.matrix[0][0] = 0;
  int res = my_inverse_matrix(&A, &B);

  ck_assert_int_eq(res, CALCULATION_ERROR);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_inverse_matrix_test_10) {
  matrix_t A = {0};
  int size = 3;
  matrix_t B = {0};

  my_create_matrix(size, size, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = 2;

  int res = my_inverse_matrix(&A, &B);

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(B.matrix[0][0], -0.75, 1e-06);
  ck_assert_double_eq_tol(B.matrix[0][1], 0.25, 1e-06);
  ck_assert_double_eq_tol(B.matrix[0][2], 1, 1e-06);
  ck_assert_double_eq_tol(B.matrix[1][0], 1.25, 1e-06);
  ck_assert_double_eq_tol(B.matrix[1][1], 0.25, 1e-06);
  ck_assert_double_eq_tol(B.matrix[1][2], -2, 1e-06);
  ck_assert_double_eq_tol(B.matrix[2][0], -0.25, 1e-06);
  ck_assert_double_eq_tol(B.matrix[2][1], -0.25, 1e-06);
  ck_assert_double_eq_tol(B.matrix[2][2], 1, 1e-06);

  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

Suite *my_inverse_matrix_suite(void) {
  TCase *tc_case = tcase_create("inverse_matrix");
  Suite *s = suite_create("my_inverse_matrix_test");

  tcase_add_test(tc_case, my_inverse_matrix_test_1);
  tcase_add_test(tc_case, my_inverse_matrix_test_2);
  tcase_add_test(tc_case, my_inverse_matrix_test_3);
  tcase_add_test(tc_case, my_inverse_matrix_test_4);
  tcase_add_test(tc_case, my_inverse_matrix_test_5);
  tcase_add_test(tc_case, my_inverse_matrix_test_6);
  tcase_add_test(tc_case, my_inverse_matrix_test_7);
  tcase_add_test(tc_case, my_inverse_matrix_test_8);
  tcase_add_test(tc_case, my_inverse_matrix_test_9);
  tcase_add_test(tc_case, my_inverse_matrix_test_10);

  suite_add_tcase(s, tc_case);

  return s;
}