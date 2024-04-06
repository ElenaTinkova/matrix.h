#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (!s21_is_correct(A)) {
    result->matrix = NULL;
    return INCORRECT_MATRIX;
  }

  int flag = s21_create_matrix(A->columns, A->rows, result);
  if (flag != OK)
    return INCORRECT_MATRIX;
  else {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++)
        result->matrix[i][j] = A->matrix[j][i];
    }
  }
  return OK;
}
