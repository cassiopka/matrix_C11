#include "../my_matrix.h"

int my_create_matrix(int rows, int columns, matrix_t *result) {
  int response = OK;
  if (result == NULL || rows < 1 || columns < 1)
    response = INCORRECT_MATRIX;
  else {
    result->matrix = (double **)malloc(rows * sizeof(double *) +
                                       rows * columns * sizeof(double));
    if (result->matrix == NULL) {
      response = INCORRECT_MATRIX;
    } else {
      double *ptr = (double *)(result->matrix + rows);
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = ptr + i * columns;
      }
      result->rows = rows;
      result->columns = columns;
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          result->matrix[i][j] = 0.0;
        }
      }
    }
  }
  return response;
}