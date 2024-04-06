#include "test_matrix.h"

// transpose

START_TEST(transpose_1) {
  matrix_t m1 = {0};
  matrix_t r = {0};
  matrix_t origin = {0};
  int check_origin = OK;
  int check_1 = s21_create_matrix(3, 2, &m1);
  int check_2 = s21_create_matrix(2, 3, &origin);
  m1.matrix[0][0] = 1;
  m1.matrix[0][1] = 4;
  m1.matrix[1][0] = 2;
  m1.matrix[1][1] = 5;
  m1.matrix[2][0] = 3;
  m1.matrix[2][1] = 6;
  origin.matrix[0][0] = 1;
  origin.matrix[0][1] = 2;
  origin.matrix[0][2] = 3;
  origin.matrix[1][0] = 4;
  origin.matrix[1][1] = 5;
  origin.matrix[1][2] = 6;
  int result = s21_transpose(&m1, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(origin.matrix[i][j], r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&r);
  s21_remove_matrix(&origin);
}
END_TEST

START_TEST(transpose_2) {
  // 1 4 7    1 2 3
  // 2 5 8    4 5 6
  // 3 6 9    7 8 9
  matrix_t m1 = {0};
  matrix_t r = {0};
  matrix_t origin = {0};
  int check_origin = OK;
  int check_1 = s21_create_matrix(3, 3, &m1);
  int check_2 = s21_create_matrix(3, 3, &origin);
  m1.matrix[0][0] = 1;
  m1.matrix[0][1] = 4;
  m1.matrix[0][2] = 7;
  m1.matrix[1][0] = 2;
  m1.matrix[1][1] = 5;
  m1.matrix[1][2] = 8;
  m1.matrix[2][0] = 3;
  m1.matrix[2][1] = 6;
  m1.matrix[2][2] = 9;
  origin.matrix[0][0] = 1;
  origin.matrix[0][1] = 2;
  origin.matrix[0][2] = 3;
  origin.matrix[1][0] = 4;
  origin.matrix[1][1] = 5;
  origin.matrix[1][2] = 6;
  origin.matrix[2][0] = 7;
  origin.matrix[2][1] = 8;
  origin.matrix[2][2] = 9;
  int result = s21_transpose(&m1, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(origin.matrix[i][j], r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&r);
  s21_remove_matrix(&origin);
}
END_TEST

START_TEST(transpose_3) {
  matrix_t m1 = {0};
  matrix_t r = {0};
  matrix_t origin = {0};
  int check_origin = OK;
  int check_1 = s21_create_matrix(1, 1, &m1);
  int check_2 = s21_create_matrix(1, 1, &origin);
  m1.matrix[0][0] = 1.1;
  origin.matrix[0][0] = 1.1;
  int result = s21_transpose(&m1, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(origin.matrix[i][j], r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&r);
  s21_remove_matrix(&origin);
}
END_TEST

START_TEST(transpose_4) {
  matrix_t A, result, result_origin;
  s21_create_matrix(5, 4, &A);
  s21_create_matrix(4, 5, &result_origin);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[0][3] = -4;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[1][3] = 14;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  A.matrix[2][3] = -1;
  A.matrix[3][0] = 10;
  A.matrix[3][1] = 3;
  A.matrix[3][2] = 9;
  A.matrix[3][3] = -3;
  A.matrix[4][0] = -3;
  A.matrix[4][1] = 3;
  A.matrix[4][2] = 1;
  A.matrix[4][3] = 5;
  result_origin.matrix[0][0] = 2;
  result_origin.matrix[0][1] = 6;
  result_origin.matrix[0][2] = 5;
  result_origin.matrix[0][3] = 10;
  result_origin.matrix[0][4] = -3;
  result_origin.matrix[1][0] = 5;
  result_origin.matrix[1][1] = 3;
  result_origin.matrix[1][2] = -2;
  result_origin.matrix[1][3] = 3;
  result_origin.matrix[1][4] = 3;
  result_origin.matrix[2][0] = 7;
  result_origin.matrix[2][1] = 4;
  result_origin.matrix[2][2] = -3;
  result_origin.matrix[2][3] = 9;
  result_origin.matrix[2][4] = 1;
  result_origin.matrix[3][0] = -4;
  result_origin.matrix[3][1] = 14;
  result_origin.matrix[3][2] = -1;
  result_origin.matrix[3][3] = -3;
  result_origin.matrix[3][4] = 5;
  s21_transpose(&A, &result);
  for (int i = 0; i < result_origin.rows; i++) {
    for (int j = 0; j < result_origin.columns; j++) {
      ck_assert_uint_eq(result_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_origin);
}
END_TEST

START_TEST(transpose_5) {
  matrix_t A, result, res_origin;
  s21_create_matrix(4, 7, &A);
  s21_create_matrix(7, 4, &res_origin);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i;
    }
  }
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      res_origin.matrix[i][j] = j;
    }
  }
  s21_transpose(&A, &result);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(transpose_6) {
  matrix_t A, result;
  s21_create_matrix(4, -7, &A);
  int check = s21_transpose(&A, &result);
  int check_origin = INCORRECT_MATRIX;
  ck_assert_uint_eq(check, check_origin);
  s21_remove_matrix(&result);
  s21_remove_matrix(&A);
}
END_TEST

// determinant

START_TEST(determinant_1) {
  matrix_t A = {0};
  double result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = -5;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = 3;
  int check = s21_determinant(&A, &result);
  int check_origin = 0;
  double result_origin = 43;
  ck_assert_uint_eq(check, check_origin);
  ck_assert_uint_eq(result, result_origin);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_2) {
  matrix_t A;
  double result;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 3;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 2;
  A.matrix[1][3] = 2;
  A.matrix[2][0] = -5;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = 3;
  A.matrix[2][3] = 3;
  A.matrix[3][0] = -12.12;
  A.matrix[3][1] = 12.12;
  A.matrix[3][2] = 2.12;
  A.matrix[3][3] = -2.12;
  int check = s21_determinant(&A, &result);
  int check_origin = 0;
  double result_origin = -182.32;
  ck_assert_uint_eq(check, check_origin);
  ck_assert_uint_eq(result, result_origin);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_3) {
  matrix_t A;
  double result;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;
  int check = s21_determinant(&A, &result);
  int check_origin = 0;
  double result_origin = 1;
  ck_assert_uint_eq(check, check_origin);
  ck_assert_uint_eq(result, result_origin);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_4) {
  matrix_t A;
  double result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 55.5;
  A.matrix[0][1] = 14.4;
  A.matrix[1][0] = -0.752;
  A.matrix[1][1] = 156.2;
  int check = s21_determinant(&A, &result);
  int check_origin = 0;
  double result_origin = 8679.9288;
  ck_assert_uint_eq(check, check_origin);
  ck_assert_uint_eq(result, result_origin);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_5) {
  matrix_t A;
  double result;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 11.1;
  A.matrix[0][1] = 2.2;
  A.matrix[0][2] = 3.3;
  A.matrix[0][3] = 4.4;
  A.matrix[1][0] = 8.8;
  A.matrix[1][1] = -9.9;
  A.matrix[1][2] = 10.1;
  A.matrix[1][3] = 11.11;
  A.matrix[2][0] = 15.15;
  A.matrix[2][1] = 16.16;
  A.matrix[2][2] = 17.17;
  A.matrix[2][3] = 18.18;
  A.matrix[3][0] = -22.22;
  A.matrix[3][1] = 23.23;
  A.matrix[3][2] = 24.24;
  A.matrix[3][3] = 25.25;
  int check = s21_determinant(&A, &result);
  int check_origin = 0;
  double result_origin = -11770.2443124;
  ck_assert_uint_eq(check, check_origin);
  ck_assert_double_eq_tol(result, result_origin, 1e-7);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_6) {
  matrix_t A;
  double result;
  s21_create_matrix(4, 4, &A);
  int check = s21_determinant(&A, &result);
  int check_origin = 0;
  double result_origin = 0;
  ck_assert_uint_eq(check, check_origin);
  ck_assert_double_eq_tol(result, result_origin, 1e-7);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_7) {
  matrix_t A;
  double result;
  s21_create_matrix(5, 4, &A);
  int check = s21_determinant(&A, &result);
  int check_origin = 2;
  ck_assert_uint_eq(check, check_origin);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_8) {
  matrix_t A;
  double result;
  s21_create_matrix(-4, 4, &A);
  int check = s21_determinant(&A, &result);
  int check_origin = 1;
  ck_assert_uint_eq(check, check_origin);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_9) {
  matrix_t A;
  double result;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 5;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 0;
  A.matrix[1][3] = 4;
  A.matrix[2][0] = 8;
  A.matrix[2][1] = 6;
  A.matrix[2][2] = 0;
  A.matrix[2][3] = 4;
  A.matrix[3][0] = 6;
  A.matrix[3][1] = 8;
  A.matrix[3][2] = 9;
  A.matrix[3][3] = 4;
  int check = s21_determinant(&A, &result);
  ck_assert_int_eq(check, 0);
  ck_assert_double_eq_tol(result, 438.0, 1e-7);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_10) {
  matrix_t A;
  double result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[1][0] = 0;
  A.matrix[2][0] = 0;
  A.matrix[0][1] = 3;
  A.matrix[1][1] = 5;
  A.matrix[2][1] = 9;
  A.matrix[0][2] = 1;
  A.matrix[1][2] = 56.23456;
  A.matrix[2][2] = 12345432.343;
  int check = s21_determinant(&A, &result);
  ck_assert_int_eq(check, 0);
  ck_assert_double_eq_tol(result, 0.0, 1e-7);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_11) {
  matrix_t A;
  double result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 123.456;
  A.matrix[1][0] = 123.455;
  A.matrix[2][0] = 123.454;
  A.matrix[0][1] = 123.453;
  A.matrix[1][1] = 123.452;
  A.matrix[2][1] = 123.451;
  A.matrix[0][2] = 123.450;
  A.matrix[1][2] = 1113.449;
  A.matrix[2][2] = 15.448;
  int check = s21_determinant(&A, &result);
  ck_assert_int_eq(check, 0);
  ck_assert_double_eq_tol(result, 0.006264, 1e-7 * 10.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_12) {
  matrix_t matrix_1 = {0};
  double result;
  int err = 0;

  s21_create_matrix(3, 3, &matrix_1);

  matrix_1.matrix[0][0] = 2;
  matrix_1.matrix[1][0] = 5;
  matrix_1.matrix[2][0] = 3;
  matrix_1.matrix[0][1] = 1;
  matrix_1.matrix[1][1] = -5;
  matrix_1.matrix[2][1] = 3.3;
  matrix_1.matrix[0][2] = -1;
  matrix_1.matrix[1][2] = 0;
  matrix_1.matrix[2][2] = 0.3;

  err = s21_determinant(&matrix_1, &result);
  ck_assert_int_eq(OK, err);
  ck_assert_int_eq(1, result == -36);
  s21_remove_matrix(&matrix_1);

  matrix_t matrix_2 = {0};
  s21_create_matrix(2, 2, &matrix_2);
  matrix_2.matrix[0][0] = 2;
  matrix_2.matrix[1][0] = 5;
  matrix_2.matrix[0][1] = 3;
  matrix_2.matrix[1][1] = 1;

  err = s21_determinant(&matrix_2, &result);
  ck_assert_int_eq(OK, err);
  ck_assert_int_eq(1, result == -13);
  s21_remove_matrix(&matrix_2);

  matrix_t matrix_3 = {0};
  s21_create_matrix(-1, 2, &matrix_3);
  err = s21_determinant(&matrix_3, &result);
  ck_assert_int_eq(INCORRECT_MATRIX, err);

  s21_remove_matrix(&matrix_3);
}
END_TEST

START_TEST(calc_complements_1) {
  matrix_t A, result, res_origin;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &res_origin);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  res_origin.matrix[0][0] = 0;
  res_origin.matrix[0][1] = 10;
  res_origin.matrix[0][2] = -20;
  res_origin.matrix[1][0] = 4;
  res_origin.matrix[1][1] = -14;
  res_origin.matrix[1][2] = 8;
  res_origin.matrix[2][0] = -8;
  res_origin.matrix[2][1] = -2;
  res_origin.matrix[2][2] = 4;
  s21_calc_complements(&A, &result);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(calc_complements_2) {
  matrix_t A, result, res_origin;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &res_origin);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  res_origin.matrix[0][0] = 3;
  res_origin.matrix[0][1] = -6;
  res_origin.matrix[1][0] = -4;
  res_origin.matrix[1][1] = 2;
  s21_calc_complements(&A, &result);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(calc_complements_3) {
  matrix_t A, result, res_origin;
  s21_create_matrix(-2, 2, &A);
  s21_create_matrix(2, 2, &res_origin);
  int check = s21_calc_complements(&A, &result);
  int check_origin = 1;
  ck_assert_uint_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(calc_complements_4) {
  matrix_t A, result, res_origin;
  s21_create_matrix(2, 4, &A);
  s21_create_matrix(2, 2, &res_origin);
  int check = s21_calc_complements(&A, &result);
  int check_origin = 2;
  ck_assert_uint_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

// inverse

START_TEST(inverse_matrix_1) {
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  C.matrix[0][0] = 1;
  C.matrix[0][1] = -1;
  C.matrix[0][2] = 1;
  C.matrix[1][0] = -38;
  C.matrix[1][1] = 41;
  C.matrix[1][2] = -34;
  C.matrix[2][0] = 27;
  C.matrix[2][1] = -29;
  C.matrix[2][2] = 24;
  s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(s21_eq_matrix(&B, &C), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(inverse_matrix_2) {
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &C);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[1][3] = 1;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  A.matrix[2][3] = 3;
  A.matrix[3][0] = 3;
  A.matrix[3][1] = 7;
  A.matrix[3][2] = 2;
  A.matrix[3][3] = 4;
  s21_inverse_matrix(&A, &B);
  C.matrix[0][0] = -0.125;
  C.matrix[0][1] = 0.19166666;
  C.matrix[0][2] = 0.325;
  C.matrix[0][3] = -0.16666666;
  C.matrix[1][0] = -0.125;
  C.matrix[1][1] = 0.05833333;
  C.matrix[1][2] = -0.075;
  C.matrix[1][3] = 0.16666666;
  C.matrix[2][0] = 0.125;
  C.matrix[2][1] = 0.675;
  C.matrix[2][2] = 0.275;
  C.matrix[2][3] = -0.5;
  C.matrix[3][0] = 0.25;
  C.matrix[3][1] = -0.58333333;
  C.matrix[3][2] = -0.25;
  C.matrix[3][3] = 0.33333333;
  ck_assert_int_eq(s21_eq_matrix(&B, &C), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(inverse_matrix_3) {
  matrix_t A, B;
  s21_create_matrix(3, 4, &A);
  ck_assert_int_eq(s21_inverse_matrix(&A, &B), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_matrix_4) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  int check = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(check, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(inverse_matrix_5) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 5;
  int check = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(check, OK);
  ck_assert_double_eq(0.2, B.matrix[0][0]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(inverse_matrix_6) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(-2, 1, &A);
  int check = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(check, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

void srunner_add_test_other(SRunner *sr) {
  Suite *suit_4 = suite_create("other");
  TCase *tc4_4 = tcase_create("other");
  suite_add_tcase(suit_4, tc4_4);

  tcase_add_test(tc4_4, transpose_1);
  tcase_add_test(tc4_4, transpose_2);
  tcase_add_test(tc4_4, transpose_3);
  tcase_add_test(tc4_4, transpose_4);
  tcase_add_test(tc4_4, transpose_5);
  tcase_add_test(tc4_4, transpose_6);

  tcase_add_test(tc4_4, determinant_1);
  tcase_add_test(tc4_4, determinant_2);
  tcase_add_test(tc4_4, determinant_3);
  tcase_add_test(tc4_4, determinant_4);
  tcase_add_test(tc4_4, determinant_5);
  tcase_add_test(tc4_4, determinant_6);
  tcase_add_test(tc4_4, determinant_7);
  tcase_add_test(tc4_4, determinant_8);
  tcase_add_test(tc4_4, determinant_9);
  tcase_add_test(tc4_4, determinant_10);
  tcase_add_test(tc4_4, determinant_11);
  tcase_add_test(tc4_4, determinant_12);

  tcase_add_test(tc4_4, calc_complements_1);
  tcase_add_test(tc4_4, calc_complements_2);
  tcase_add_test(tc4_4, calc_complements_3);
  tcase_add_test(tc4_4, calc_complements_4);

  tcase_add_test(tc4_4, inverse_matrix_1);
  tcase_add_test(tc4_4, inverse_matrix_2);
  tcase_add_test(tc4_4, inverse_matrix_3);
  tcase_add_test(tc4_4, inverse_matrix_4);
  tcase_add_test(tc4_4, inverse_matrix_5);
  tcase_add_test(tc4_4, inverse_matrix_6);

  srunner_add_suite(sr, suit_4);
}
