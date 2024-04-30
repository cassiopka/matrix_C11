#include "../my_matrix.h"

void my_find_mult_num_matrix(matrix_t *A, double number, matrix_t *result) {
  my_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
}