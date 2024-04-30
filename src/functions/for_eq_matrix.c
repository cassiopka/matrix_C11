#include "../my_matrix.h"

int my_are_equal(matrix_t *A, matrix_t *B) {
  int response = TRUE;
  int diff = 0;
  for (int i = 0; i < A->rows && !diff; ++i) {
    for (int j = 0; j < A->columns && !diff; ++j) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-06) {
        diff = 1;
        response = FALSE;
      }
    }
  }
  return response;
}