#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!s21_is_correct(A)) {
    result->matrix = NULL;
    return INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    result->matrix = NULL;
    return CALCULATION_ERROR;
  }

  double detA = 0;
  s21_determinant(A, &detA);
  if (!detA) {
    result->matrix = NULL;
    return CALCULATION_ERROR;
  } else {
    int flag = s21_create_matrix(A->rows, A->columns, result);
    if (flag != OK)
      return INCORRECT_MATRIX;
    else if (A->rows == 1) {
      result->matrix[0][0] = 1 / A->matrix[0][0];
    } else {
      matrix_t temp_c = {0}, trans_c = {0};
      flag = s21_calc_complements(A, &temp_c);
      if (flag == OK) {
        flag = s21_transpose(&temp_c, &trans_c);
        s21_remove_matrix(&temp_c);
      }
      if (flag == OK) {
        s21_remove_matrix(result);
        s21_mult_number(&trans_c, 1.0 / detA, result);
        s21_remove_matrix(&trans_c);
      }
    }
  }
  return OK;
}
