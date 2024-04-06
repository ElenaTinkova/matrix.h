#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;
  if (!s21_is_correct(A) || !s21_is_correct(B) || !s21_size_check(A, B))
    flag = FAILURE;
  if (flag) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        // если разница между элементами матриц A и B <= 1e-7, то они равны
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
          flag = FAILURE;
          break;
        }
      }
    }
  }
  return flag;
}
