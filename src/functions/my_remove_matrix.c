#include "../my_matrix.h"

void my_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    if (A->matrix != NULL) {
      free(A->matrix);
      A->matrix = NULL;
    }
    A->columns = 0;
    A->rows = 0;
  }
}