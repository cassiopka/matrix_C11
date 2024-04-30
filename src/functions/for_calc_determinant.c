#include "../my_matrix.h"

void my_fill_minor_for_determinant(matrix_t* A, matrix_t* minor, int x) {
  for (int i = 0; i < A->rows - 1; ++i) {
    for (int j = 0; j < A->columns - 1; ++j) {
      int tmp_j = (j >= x) ? 1 : 0;
      minor->matrix[i][j] = A->matrix[i + 1][j + tmp_j];
    }
  }
}

void my_calc_det_for_matrix_3x3_n_large(matrix_t* A, double* result) {
  matrix_t minor;
  my_create_matrix(A->rows - 1, A->columns - 1, &minor);
  for (int x = 0; x < A->columns; ++x) {
    my_fill_minor_for_determinant(A, &minor, x);
    double minor_det = 0.;
    my_determinant(&minor, &minor_det);
    *result += A->matrix[0][x] * minor_det * (x % 2 == 0 ? 1 : -1);
  }
  my_remove_matrix(&minor);
}