#include "s21_matrix.h"

int s21_is_correct(matrix_t *A) {
  if (A->matrix == NULL || A->rows < 1 || A->columns < 1) return FAILURE;
  return SUCCESS;
}

int s21_size_check(matrix_t *A, matrix_t *B) {
  if ((A->rows != B->rows) || (A->columns != B->columns)) return FAILURE;
  return SUCCESS;
}

matrix_t minor_matrix(matrix_t A, int x, int y) {
  matrix_t minor_result = {0};
  x--;
  y--;
  int flag = OK;
  if (x < 0 || y < 0 || x >= A.rows || y >= A.columns || A.rows != A.columns) {
    flag = INCORRECT_MATRIX;
  }
  if (flag == OK) {
    s21_create_matrix(A.rows - 1, A.columns - 1, &minor_result);
    for (int i = 0, i_res = 0; i < A.rows; i++) {
      if (i == x) continue;
      for (int j = 0, j_res = 0; j < A.columns; j++) {
        if (j == y) continue;
        minor_result.matrix[i_res][j_res] = A.matrix[i][j];
        j_res++;
      }
      i_res++;
    }
  }
  return minor_result;
}
