#include "../my_matrix_test.h"

START_TEST(my_calc_complements_test_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  int res = my_calc_complements(&A, &B);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
  // my_remove_matrix(&A);
  // my_remove_matrix(&B);
}
END_TEST

START_TEST(my_calc_complements_test_2) {
  matrix_t A = {0};
  int res = my_calc_complements(&A, NULL);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
  // my_remove_matrix(&A);
}
END_TEST

START_TEST(my_calc_complements_test_3) {
  matrix_t A = {0};
  int rows = 2;
  int columns = 0;
  matrix_t B = {0};

  my_create_matrix(rows, columns, &A);
  int res = my_calc_complements(&A, &B);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
  // my_remove_matrix(&A);
  // my_remove_matrix(&B);
}
END_TEST

START_TEST(my_calc_complements_test_4) {
  matrix_t A = {0};
  int size = 2;
  matrix_t B = {0};

  my_create_matrix(size, size + 1, &A);
  int res = my_calc_complements(&A, &B);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
  my_remove_matrix(&A);
  // my_remove_matrix(&B);
}
END_TEST

START_TEST(my_calc_complements_test_5) {
  matrix_t A = {0};
  int size = 1;
  matrix_t B = {0};
  my_create_matrix(size, size, &A);
  A.matrix[0][0] = 1;
  int res = my_calc_complements(&A, &B);

  ck_assert_int_eq(res, CALCULATION_ERROR);

  my_remove_matrix(&A);
  // my_remove_matrix(&B);
}
END_TEST

START_TEST(my_calc_complements_test_6) {
  matrix_t A = {0};
  int size = 2;
  matrix_t B = {0};

  my_create_matrix(size, size, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = -5;

  int res = my_calc_complements(&A, &B);

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq(B.matrix[0][0], -5);
  ck_assert_double_eq(B.matrix[0][1], -4);
  ck_assert_double_eq(B.matrix[1][0], -2);
  ck_assert_double_eq(B.matrix[1][1], 1);

  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_calc_complements_test_7) {
  matrix_t A = {0};
  int size = 2;
  my_create_matrix(size, size, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = -5;

  int res = my_calc_complements(&A, NULL);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
  my_remove_matrix(&A);
}
END_TEST

Suite *my_calc_complements_suite(void) {
  TCase *tc_case = tcase_create("calc_complements");
  Suite *s = suite_create("my_calc_complements_test");

  tcase_add_test(tc_case, my_calc_complements_test_1);
  tcase_add_test(tc_case, my_calc_complements_test_2);
  tcase_add_test(tc_case, my_calc_complements_test_3);
  tcase_add_test(tc_case, my_calc_complements_test_4);
  tcase_add_test(tc_case, my_calc_complements_test_5);
  tcase_add_test(tc_case, my_calc_complements_test_6);
  tcase_add_test(tc_case, my_calc_complements_test_7);

  suite_add_tcase(s, tc_case);

  return s;
}