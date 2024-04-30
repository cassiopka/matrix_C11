#include "../my_matrix.h"

int my_mult_number(matrix_t *A, double number, matrix_t *result) {
  int response = OK;
  if (A != NULL && A->matrix != NULL && A->rows > 0 && A->columns > 0 &&
      result != NULL) {
    my_find_mult_num_matrix(A, number, result);
  } else {
    response = INCORRECT_MATRIX;
  }
  return response;
}