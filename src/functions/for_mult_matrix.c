#include "../my_matrix.h"

void my_find_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  my_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < B->columns; ++j) {
      result->matrix[i][j] = 0;
      for (int k = 0; k < A->columns; ++k) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
}