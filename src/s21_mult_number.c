#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int flag = OK;
  if (!s21_is_correct(A)) {
    result->matrix = NULL;
    flag = INCORRECT_MATRIX;
  }
  if (flag == OK) {
    flag = s21_create_matrix(A->rows, A->columns, result);
    if (flag == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++)
          result->matrix[i][j] = A->matrix[i][j] * number;
      }
    } else
      flag = INCORRECT_MATRIX;
  }
  return flag;
}
