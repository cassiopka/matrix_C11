#include "../my_matrix.h"

int my_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int response = OK;
  if (A == NULL || A->matrix == NULL || B == NULL || B->matrix == NULL ||
      A->rows < 1 || A->columns < 1 || B->rows < 1 || B->columns < 1 ||
      result == NULL) {
    response = INCORRECT_MATRIX;
  } else {
    if (A->columns == B->rows) {
      my_find_mult_matrix(A, B, result);
    } else {
      response = CALCULATION_ERROR;
    }
  }
  return response;
}
