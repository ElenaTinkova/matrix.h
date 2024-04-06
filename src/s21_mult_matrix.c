#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_is_correct(A) || !s21_is_correct(B)) {
    result->matrix = NULL;
    return INCORRECT_MATRIX;
  }

  if (A->columns != B->rows) {
    result->matrix = NULL;
    return CALCULATION_ERROR;
  }

  s21_create_matrix(A->rows, B->columns, result);
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = 0;
      for (int m = 0; m < A->columns; m++) {
        result->matrix[i][j] += A->matrix[i][m] * B->matrix[m][j];
      }
    }
  }
  return OK;
}
