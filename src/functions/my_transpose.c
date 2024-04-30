#include "../my_matrix.h"

int my_transpose(matrix_t *A, matrix_t *result) {  // ?
  int response = OK;
  if (A != NULL && A->matrix != NULL && A->rows > 0 && A->columns > 0 &&
      result != NULL) {
    my_find_transpose(A, result);
  } else {
    response = INCORRECT_MATRIX;
  }
  return response;
}