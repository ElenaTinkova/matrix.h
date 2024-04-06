#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (result == NULL || rows < 1 || columns < 1) {
    result->matrix = NULL;
    return INCORRECT_MATRIX;
  }
  result->matrix = (double **)calloc(rows, sizeof(double *));
  if (result->matrix == NULL) {
    free(result->matrix);
    return INCORRECT_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
      if (result->matrix[i] == NULL) {
        s21_remove_matrix(result);
        return INCORRECT_MATRIX;
      }
    }
  }
  return OK;
}
