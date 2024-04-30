#include "../my_matrix.h"

void my_fill_minor_for_complement(matrix_t *A, matrix_t *minor, int i, int j) {
  int row = 0;
  for (int k = 0; k < A->rows; ++k) {
    if (k == i) {
      continue;
    }
    int col = 0;
    for (int z = 0; z < A->columns; ++z) {
      if (z == j) {
        continue;
      }
      minor->matrix[row][col] = A->matrix[k][z];
      ++col;
    }
    ++row;
  }
}

void my_find_complements(matrix_t *A, matrix_t *result) {
  matrix_t minor;
  my_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      my_create_matrix(A->rows - 1, A->columns - 1, &minor);
      my_fill_minor_for_complement(A, &minor, i, j);
      double minor_det = 0.;
      my_determinant(&minor, &minor_det);
      int sign = (i + j) % 2 == 0 ? 1 : -1;
      result->matrix[i][j] = sign * minor_det;
      my_remove_matrix(&minor);
    }
  }
}