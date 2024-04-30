#include "../my_matrix_test.h"

START_TEST(my_eq_matrix_test_1) {
  int rows = 3;
  int columns = 3;
  matrix_t A = {0};
  matrix_t B = {0};

  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows - 1, columns - 1, &B);

  int res = my_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FALSE);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_eq_matrix_test_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  int result = my_eq_matrix(&A, &B);
  ck_assert_int_eq(FALSE, result);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_eq_matrix_test_3) {
  int rows = 3;
  int columns = 3;
  matrix_t A = {0};

  my_create_matrix(rows, columns, &A);

  int res = my_eq_matrix(&A, NULL);
  ck_assert_int_eq(res, FALSE);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_eq_matrix_test_4) {
  int rows = 3;
  int columns = 3;
  matrix_t A = {0};

  my_create_matrix(rows, columns, &A);

  int res = my_eq_matrix(NULL, &A);
  ck_assert_int_eq(res, FALSE);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_eq_matrix_test_5) {
  int rows = 3;
  int columns = 3;
  matrix_t A = {0};

  my_create_matrix(rows, columns, &A);
  A.rows = -1;

  int res = my_eq_matrix(&A, &A);
  ck_assert_int_eq(res, FALSE);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_eq_matrix_test_6) {
  int rows = 3;
  int columns = 3;
  matrix_t A = {0};

  my_create_matrix(rows, columns, &A);

  int res = my_eq_matrix(&A, &A);
  ck_assert_int_eq(res, TRUE);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_eq_matrix_test_7) {
  int rows = 1;
  int columns = 1;
  matrix_t A = {0};
  matrix_t B = {0};

  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows, columns, &B);
  A.matrix[0][0] = 12.0;
  B.matrix[0][0] = 12.00000009;

  int res = my_eq_matrix(&A, &B);
  ck_assert_int_eq(res, TRUE);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_eq_matrix_test_8) {
  int rows = 1;
  int columns = 1;
  matrix_t A = {0};
  matrix_t B = {0};

  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows, columns, &B);
  A.matrix[0][0] = 12.0;
  B.matrix[0][0] = -55.2;

  int res = my_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FALSE);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_eq_matrix_test_9) {
  int rows = 3;
  int columns = 3;
  matrix_t A = {0};

  my_create_matrix(rows, columns, &A);
  A.columns = -1;

  int res = my_eq_matrix(&A, &A);
  ck_assert_int_eq(res, FALSE);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_eq_matrix_test_10) {
  int rows = 2;
  int columns = 3;
  matrix_t A = {0};
  matrix_t B = {0};

  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows, columns + 1, &B);
  A.matrix[0][0] = 1.0;
  B.matrix[0][0] = 1.0;

  int res = my_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FALSE);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_eq_matrix_test_11) {
  int rows = 2;
  int columns = 2;
  matrix_t A = {0};
  matrix_t B = {0};

  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows, columns, &B);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 3.0;

  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 4.0;  // Difference here
  B.matrix[1][0] = 3.0;

  int res = my_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_eq_matrix_test_12) {
  int rows = 2;
  int columns = 2;
  matrix_t A = {0};
  matrix_t B = {0};

  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows, columns, &B);
  A.matrix[0][0] = 1.0;
  B.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  B.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  B.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  B.matrix[1][1] = 4.0;

  int res = my_eq_matrix(&A, &B);
  ck_assert_int_eq(res, TRUE);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_eq_matrix_test_13) {
  int rows = 2;
  int columns = 2;
  matrix_t A = {0};
  matrix_t B = {0};

  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows, columns, &B);
  A.matrix[0][0] = 1.0;
  B.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  B.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  B.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.000001;  // Difference here

  int res = my_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FALSE);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_eq_matrix_test_14) {
  int rows = 2;
  int columns = 2;
  matrix_t A = {0};
  matrix_t B = {0};

  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows, columns, &B);
  A.matrix[0][0] = 1.0;
  B.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  B.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  B.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0000005;
  B.matrix[1][1] = 3.0;

  int res = my_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FALSE);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

Suite *my_eq_matrix_suite(void) {
  TCase *tc_case = tcase_create("eq_matrix");
  Suite *s = suite_create("my_eq_matrix_test");

  tcase_add_test(tc_case, my_eq_matrix_test_1);
  tcase_add_test(tc_case, my_eq_matrix_test_2);
  tcase_add_test(tc_case, my_eq_matrix_test_3);
  tcase_add_test(tc_case, my_eq_matrix_test_4);
  tcase_add_test(tc_case, my_eq_matrix_test_5);
  tcase_add_test(tc_case, my_eq_matrix_test_6);
  tcase_add_test(tc_case, my_eq_matrix_test_7);
  tcase_add_test(tc_case, my_eq_matrix_test_8);
  tcase_add_test(tc_case, my_eq_matrix_test_9);
  tcase_add_test(tc_case, my_eq_matrix_test_10);
  tcase_add_test(tc_case, my_eq_matrix_test_11);
  tcase_add_test(tc_case, my_eq_matrix_test_12);
  tcase_add_test(tc_case, my_eq_matrix_test_13);
  tcase_add_test(tc_case, my_eq_matrix_test_14);

  suite_add_tcase(s, tc_case);

  return s;
}