#include "../my_matrix.h"

int my_calc_complements(matrix_t *A, matrix_t *result) {
  int response = OK;
  if (A == NULL || A->matrix == NULL || result == NULL || A->rows < 1 ||
      A->columns < 1 || A->rows != A->columns) {
    response = INCORRECT_MATRIX;
  } else if (A->rows == 1) {
    response = CALCULATION_ERROR;
  } else {
    double det = 0.;
    response = my_determinant(A, &det);
    if (!response && det != 0) {
      my_find_complements(A, result);
    } else {
      response = CALCULATION_ERROR;
    }
  }
  return response;
}