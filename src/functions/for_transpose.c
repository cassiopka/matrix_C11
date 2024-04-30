#include "../my_matrix.h"

void my_find_transpose(matrix_t *A, matrix_t *result) {
  my_create_matrix(A->columns, A->rows, result);
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
}