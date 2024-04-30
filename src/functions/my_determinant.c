#include "../my_matrix.h"

int my_determinant(matrix_t *A, double *result) {
  int response = OK;
  if (A == NULL || A->matrix == NULL || result == NULL || A->rows < 1 ||
      A->columns < 1) {
    response = INCORRECT_MATRIX;
  } else {
    if (A->rows == A->columns) {
      if (A->rows == 1) {
        *result = A->matrix[0][0];
      } else if (A->rows == 2) {
        *result = A->matrix[0][0] * A->matrix[1][1] -
                  A->matrix[0][1] * A->matrix[1][0];
      } else if (A->rows >= 3) {
        *result = 0.;
        my_calc_det_for_matrix_3x3_n_large(A, result);
      }
    } else {
      response = CALCULATION_ERROR;
    }
  }
  return response;
}
