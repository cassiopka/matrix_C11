#include "my_matrix_test.h"

int main(void) {
  SRunner *runner;

  runner = srunner_create(my_create_matrix_suite());
  srunner_add_suite(runner, my_remove_matrix_suite());
  srunner_add_suite(runner, my_eq_matrix_suite());
  srunner_add_suite(runner, my_sum_matrix_suite());
  srunner_add_suite(runner, my_sub_matrix_suite());
  srunner_add_suite(runner, my_mult_number_suite());
  srunner_add_suite(runner, my_mult_matrix_suite());
  srunner_add_suite(runner, my_transpose_suite());
  srunner_add_suite(runner, my_calc_complements_suite());
  srunner_add_suite(runner, my_determinant_suite());
  srunner_add_suite(runner, my_inverse_matrix_suite());

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}