#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!s21_is_correct(A)) {
    result->matrix = NULL;
    return INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    result->matrix = NULL;
    return CALCULATION_ERROR;
  } else if (s21_create_matrix(A->rows, A->columns, result)) {
    result->matrix = NULL;
    return INCORRECT_MATRIX;
  } else {
    matrix_t temp = {0};
    double det = 0;
    for (int i = 1; i < A->rows + 1; i++) {
      for (int j = 1; j < A->columns + 1; j++) {
        temp = minor_matrix(*A, i, j);
        s21_determinant(&temp, &det);
        result->matrix[i - 1][j - 1] = det;
        // получена матрица миноров
        s21_remove_matrix(&temp);
      }
    }
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] *= pow(-1, i + j);
        // получена матрицу алгебраических дополнений
      }
    }
  }
  return OK;
}