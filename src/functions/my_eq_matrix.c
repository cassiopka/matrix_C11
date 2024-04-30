#include "../my_matrix.h"

int my_eq_matrix(matrix_t *A, matrix_t *B) {
  int response = TRUE;
  if (A == NULL || A->matrix == NULL || B == NULL || B->matrix == NULL ||
      A->rows < 1 || A->columns < 1 || B->rows < 1 || B->columns < 1) {
    response = INCORRECT_MATRIX;
  } else {
    if (A->rows == B->rows && A->columns == B->columns) {
      response = my_are_equal(A, B);
    } else {
      response = FALSE;
    }
  }
  return response;
}