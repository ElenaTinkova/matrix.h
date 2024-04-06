#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (!s21_is_correct(A)) return INCORRECT_MATRIX;
  if (A->columns != A->rows) return CALCULATION_ERROR;

  double determinant = 0;
  if (A->rows == 1)
    *result = A->matrix[0][0];

  else if (A->rows == 2) {
    *result = (A->matrix[0][0] * A->matrix[1][1]) -
              (A->matrix[0][1] * A->matrix[1][0]);
  } else {
    int minus = 1;
    matrix_t temp_minor;
    double position_value = 0;
    for (int i = 0; i < A->rows; i++) {
      position_value = A->matrix[0][i];
      temp_minor = minor_matrix(*A, 1, i + 1);  // считаем по первой строке
      *result += s21_determinant(&temp_minor, result);
      *result = *result * position_value * minus;
      determinant += *result;
      minus = -minus;
      s21_remove_matrix(&temp_minor);
    }
    *result = determinant;
  }
  return OK;
}

// разложение определителя по строке:
// det = value11 * алгебраическое дополнение11 + value12 * А12 + ...
// А11 = -1^1+1 * минор
// минор value получаем вычеркиванием строки и столбца value