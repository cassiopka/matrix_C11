#include "../my_matrix.h"

int my_inverse_matrix(matrix_t *A, matrix_t *result) {
  int response = OK;
  if (A == NULL || A->matrix == NULL || result == NULL) {
    response = INCORRECT_MATRIX;
  } else {
    double det = 0.;
    response = my_determinant(A, &det);
    if (det == 0) {
      response = CALCULATION_ERROR;
    } else if (A->rows == 1) {
      my_create_matrix(1, 1, result);
      result->matrix[0][0] = 1 / (A->matrix[0][0]);
    } else {
      matrix_t alg_comp = {0};

      my_calc_complements(A, &alg_comp);
      matrix_t transpose_m = {0};
      my_transpose(&alg_comp, &transpose_m);
      my_mult_number(&transpose_m, 1. / det, result);
      my_remove_matrix(&alg_comp);
      my_remove_matrix(&transpose_m);
    }
  }
  return response;
}