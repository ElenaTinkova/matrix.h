#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_is_correct(A) || !s21_is_correct(B)) {
    result->matrix = NULL;
    return INCORRECT_MATRIX;
  }

  if (!s21_size_check(A, B)) {
    result->matrix = NULL;
    return CALCULATION_ERROR;
  }

  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++)
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
  }

  return OK;
}
