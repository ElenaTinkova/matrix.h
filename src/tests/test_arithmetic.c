#include "test_matrix.h"

// adding matrices

START_TEST(sum_1) {
  matrix_t m1;
  matrix_t m2;
  matrix_t origin;
  matrix_t r;
  int check_origin = OK;
  int check_1 = s21_create_matrix(3, 3, &m1);
  int check_2 = s21_create_matrix(3, 3, &m2);
  int check_3 = s21_create_matrix(3, 3, &origin);
  m1.matrix[0][0] = 0.1;
  m1.matrix[0][1] = 0.2;
  m1.matrix[0][2] = 0.3;
  m1.matrix[1][0] = 0.4;
  m1.matrix[1][1] = 0.5;
  m1.matrix[1][2] = 0.6;
  m1.matrix[2][0] = 0.7;
  m1.matrix[2][1] = 0.8;
  m1.matrix[2][2] = 0.9;
  m2.matrix[0][0] = 1.0;
  m2.matrix[0][1] = 2.0;
  m2.matrix[0][2] = 3.0;
  m2.matrix[1][0] = 4.0;
  m2.matrix[1][1] = 5.0;
  m2.matrix[1][2] = 6.0;
  m2.matrix[2][0] = 7.0;
  m2.matrix[2][1] = 8.0;
  m2.matrix[2][2] = 9.0;
  origin.matrix[0][0] = 1.1;
  origin.matrix[0][1] = 2.2;
  origin.matrix[0][2] = 3.3;
  origin.matrix[1][0] = 4.4;
  origin.matrix[1][1] = 5.5;
  origin.matrix[1][2] = 6.6;
  origin.matrix[2][0] = 7.7;
  origin.matrix[2][1] = 8.8;
  origin.matrix[2][2] = 9.9;
  int result = s21_sum_matrix(&m1, &m2, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(check_3, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(origin.matrix[i][j], r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&r);
  s21_remove_matrix(&origin);
}
END_TEST

START_TEST(sum_2) {
  matrix_t m1;
  matrix_t m2;
  matrix_t origin;
  matrix_t r;
  int check_origin = OK;
  int check_1 = s21_create_matrix(3, 3, &m1);
  int check_2 = s21_create_matrix(3, 3, &m2);
  int check_3 = s21_create_matrix(3, 3, &origin);
  m1.matrix[0][0] = 0.1;
  m1.matrix[0][1] = 0.2;
  m1.matrix[0][2] = 0.3;
  m1.matrix[1][0] = 0.4;
  m1.matrix[1][1] = 0.5;
  m1.matrix[1][2] = 0.6;
  m1.matrix[2][0] = 0.7;
  m1.matrix[2][1] = 0.8;
  m1.matrix[2][2] = 0.9;
  m2.matrix[0][0] = 0.0;
  m2.matrix[0][1] = 0.0;
  m2.matrix[0][2] = 0.0;
  m2.matrix[1][0] = 0.0;
  m2.matrix[1][1] = 0.0;
  m2.matrix[1][2] = 0.0;
  m2.matrix[2][0] = 0.0;
  m2.matrix[2][1] = 0.0;
  m2.matrix[2][2] = 0.0;
  origin.matrix[0][0] = 0.1;
  origin.matrix[0][1] = 0.2;
  origin.matrix[0][2] = 0.3;
  origin.matrix[1][0] = 0.4;
  origin.matrix[1][1] = 0.5;
  origin.matrix[1][2] = 0.6;
  origin.matrix[2][0] = 0.7;
  origin.matrix[2][1] = 0.8;
  origin.matrix[2][2] = 0.9;
  int result = s21_sum_matrix(&m1, &m2, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(check_3, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(origin.matrix[i][j], r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&r);
  s21_remove_matrix(&origin);
}
END_TEST

START_TEST(sum_3) {
  matrix_t m1;
  matrix_t m2;
  matrix_t origin;
  matrix_t r;
  int check_origin = OK;
  int check_1 = s21_create_matrix(3, 3, &m1);
  int check_2 = s21_create_matrix(3, 3, &m2);
  int check_3 = s21_create_matrix(3, 3, &origin);
  m1.matrix[0][0] = 0.1;
  m1.matrix[0][1] = 0.2;
  m1.matrix[0][2] = 0.3;
  m1.matrix[1][0] = 0.4;
  m1.matrix[1][1] = 0.5;
  m1.matrix[1][2] = 0.6;
  m1.matrix[2][0] = 0.7;
  m1.matrix[2][1] = 0.8;
  m1.matrix[2][2] = 0.9;
  m2.matrix[0][0] = -1.0;
  m2.matrix[0][1] = -2.0;
  m2.matrix[0][2] = -3.0;
  m2.matrix[1][0] = -4.0;
  m2.matrix[1][1] = -5.0;
  m2.matrix[1][2] = -6.0;
  m2.matrix[2][0] = -7.0;
  m2.matrix[2][1] = -8.0;
  m2.matrix[2][2] = -9.0;
  origin.matrix[0][0] = -0.9;
  origin.matrix[0][1] = -1.8;
  origin.matrix[0][2] = -2.7;
  origin.matrix[1][0] = -3.6;
  origin.matrix[1][1] = -4.5;
  origin.matrix[1][2] = -5.4;
  origin.matrix[2][0] = -6.3;
  origin.matrix[2][1] = -7.2;
  origin.matrix[2][2] = -8.1;
  int result = s21_sum_matrix(&m1, &m2, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(check_3, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(origin.matrix[i][j], r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&r);
  s21_remove_matrix(&origin);
}
END_TEST

START_TEST(sum_4) {
  matrix_t result, B, A;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  B.matrix[0][0] = 3;
  B.matrix[0][1] = 3;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 3;
  int check = s21_sum_matrix(&A, &B, &result);
  int check_origin = OK;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      ck_assert_int_eq(result.matrix[i][j], 4);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_5) {
  matrix_t result, B, A;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  B.matrix[0][0] = 0;
  B.matrix[0][1] = 0;
  B.matrix[1][0] = 0;
  B.matrix[1][1] = 0;
  int check = s21_sum_matrix(&A, &B, &result);
  int check_origin = OK;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      ck_assert_int_eq(result.matrix[i][j], 0);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_6) {
  matrix_t result, B, A;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  B.matrix[0][0] = 3;
  B.matrix[0][1] = 3;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 3;
  int check = s21_sum_matrix(&A, &B, &result);
  int check_origin = CALCULATION_ERROR;
  ck_assert_int_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_7) {
  matrix_t result, res_origin, B, A;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  s21_create_matrix(4, 4, &res_origin);
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
  B.matrix[0][0] = 8;
  B.matrix[0][1] = 8;
  B.matrix[0][2] = 3;
  B.matrix[0][3] = 5;
  B.matrix[1][0] = -7;
  B.matrix[1][1] = 7;
  B.matrix[1][2] = 1;
  B.matrix[1][3] = 1;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 3;
  B.matrix[2][2] = 4;
  B.matrix[2][3] = -4;
  B.matrix[3][0] = 10;
  B.matrix[3][1] = 3;
  B.matrix[3][2] = 9;
  B.matrix[3][3] = -3;
  res_origin.matrix[0][0] = 10;
  res_origin.matrix[0][1] = 13;
  res_origin.matrix[0][2] = 10;
  res_origin.matrix[0][3] = 1;
  res_origin.matrix[1][0] = -1;
  res_origin.matrix[1][1] = 10;
  res_origin.matrix[1][2] = 5;
  res_origin.matrix[1][3] = 15;
  res_origin.matrix[2][0] = 12;
  res_origin.matrix[2][1] = 1;
  res_origin.matrix[2][2] = 1;
  res_origin.matrix[2][3] = -5;
  res_origin.matrix[3][0] = 20;
  res_origin.matrix[3][1] = 6;
  res_origin.matrix[3][2] = 18;
  res_origin.matrix[3][3] = -6;
  int check = s21_sum_matrix(&A, &B, &result);
  int check_origin = OK;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(sum_8) {
  matrix_t result, res_origin, B, A;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &res_origin);
  A.matrix[0][0] = 2.987654;
  A.matrix[0][1] = -5.3456;
  A.matrix[1][0] = 6.23;
  A.matrix[1][1] = -3.9292;
  B.matrix[0][0] = 4.838;
  B.matrix[0][1] = 8.0987;
  B.matrix[1][0] = -8;
  B.matrix[1][1] = -0.921;
  res_origin.matrix[0][0] = 7.825654;
  res_origin.matrix[0][1] = 2.7531;
  res_origin.matrix[1][0] = -1.77;
  res_origin.matrix[1][1] = -4.8502;
  int check = s21_sum_matrix(&A, &B, &result);
  int check_origin = OK;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(sum_9) {
  matrix_t result, res_origin, B, A;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &res_origin);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i;
    }
  }
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = i;
    }
  }
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      res_origin.matrix[i][j] = i * 2;
    }
  }
  int check = s21_sum_matrix(&A, &B, &result);
  int check_origin = OK;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(sum_10) {
  matrix_t result, res_origin, B, A;
  s21_create_matrix(5, 4, &A);
  s21_create_matrix(5, 4, &B);
  s21_create_matrix(5, 4, &res_origin);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i;
      res_origin.matrix[i][j] = i;
    }
  }
  int check = s21_sum_matrix(&A, &B, &result);
  int check_origin = OK;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(sum_11) {
  matrix_t result, B, A;
  s21_create_matrix(-5, 5, &A);
  s21_create_matrix(5, 4, &B);
  int check = s21_sum_matrix(&A, &B, &result);
  int check_origin = INCORRECT_MATRIX;
  ck_assert_int_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

// subtracting matrices

START_TEST(sub_1) {
  matrix_t m1;
  matrix_t m2;
  matrix_t origin;
  matrix_t r;
  int check_origin = OK;
  int check_1 = s21_create_matrix(3, 3, &m1);
  int check_2 = s21_create_matrix(3, 3, &m2);
  int check_3 = s21_create_matrix(3, 3, &origin);
  m1.matrix[0][0] = 0.1;
  m1.matrix[0][1] = 0.2;
  m1.matrix[0][2] = 0.3;
  m1.matrix[1][0] = 0.4;
  m1.matrix[1][1] = 0.5;
  m1.matrix[1][2] = 0.6;
  m1.matrix[2][0] = 0.7;
  m1.matrix[2][1] = 0.8;
  m1.matrix[2][2] = 0.9;
  m2.matrix[0][0] = 1.0;
  m2.matrix[0][1] = 2.0;
  m2.matrix[0][2] = 3.0;
  m2.matrix[1][0] = 4.0;
  m2.matrix[1][1] = 5.0;
  m2.matrix[1][2] = 6.0;
  m2.matrix[2][0] = 7.0;
  m2.matrix[2][1] = 8.0;
  m2.matrix[2][2] = 9.0;
  origin.matrix[0][0] = -0.9;
  origin.matrix[0][1] = -1.8;
  origin.matrix[0][2] = -2.7;
  origin.matrix[1][0] = -3.6;
  origin.matrix[1][1] = -4.5;
  origin.matrix[1][2] = -5.4;
  origin.matrix[2][0] = -6.3;
  origin.matrix[2][1] = -7.2;
  origin.matrix[2][2] = -8.1;
  int result = s21_sub_matrix(&m1, &m2, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(check_3, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(origin.matrix[i][j], r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&r);
  s21_remove_matrix(&origin);
}
END_TEST

START_TEST(sub_2) {
  matrix_t m1;
  matrix_t m2;
  matrix_t origin;
  matrix_t r;
  int check_origin = OK;
  int check_1 = s21_create_matrix(3, 3, &m1);
  int check_2 = s21_create_matrix(3, 3, &m2);
  int check_3 = s21_create_matrix(3, 3, &origin);
  m1.matrix[0][0] = 0.1;
  m1.matrix[0][1] = 0.2;
  m1.matrix[0][2] = 0.3;
  m1.matrix[1][0] = 0.4;
  m1.matrix[1][1] = 0.5;
  m1.matrix[1][2] = 0.6;
  m1.matrix[2][0] = 0.7;
  m1.matrix[2][1] = 0.8;
  m1.matrix[2][2] = 0.9;
  m2.matrix[0][0] = 0.0;
  m2.matrix[0][1] = 0.0;
  m2.matrix[0][2] = 0.0;
  m2.matrix[1][0] = 0.0;
  m2.matrix[1][1] = 0.0;
  m2.matrix[1][2] = 0.0;
  m2.matrix[2][0] = 0.0;
  m2.matrix[2][1] = 0.0;
  m2.matrix[2][2] = 0.0;
  origin.matrix[0][0] = 0.1;
  origin.matrix[0][1] = 0.2;
  origin.matrix[0][2] = 0.3;
  origin.matrix[1][0] = 0.4;
  origin.matrix[1][1] = 0.5;
  origin.matrix[1][2] = 0.6;
  origin.matrix[2][0] = 0.7;
  origin.matrix[2][1] = 0.8;
  origin.matrix[2][2] = 0.9;
  int result = s21_sub_matrix(&m1, &m2, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(check_3, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(origin.matrix[i][j], r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&r);
  s21_remove_matrix(&origin);
}
END_TEST

START_TEST(sub_3) {
  matrix_t m1;
  matrix_t m2;
  matrix_t origin;
  matrix_t r;
  int check_origin = OK;
  int check_1 = s21_create_matrix(3, 3, &m1);
  int check_2 = s21_create_matrix(3, 3, &m2);
  int check_3 = s21_create_matrix(3, 3, &origin);
  m1.matrix[0][0] = 0.1;
  m1.matrix[0][1] = 0.2;
  m1.matrix[0][2] = 0.3;
  m1.matrix[1][0] = 0.4;
  m1.matrix[1][1] = 0.5;
  m1.matrix[1][2] = 0.6;
  m1.matrix[2][0] = 0.7;
  m1.matrix[2][1] = 0.8;
  m1.matrix[2][2] = 0.9;
  m2.matrix[0][0] = 1.0;
  m2.matrix[0][1] = 2.0;
  m2.matrix[0][2] = 3.0;
  m2.matrix[1][0] = 4.0;
  m2.matrix[1][1] = 5.0;
  m2.matrix[1][2] = 6.0;
  m2.matrix[2][0] = 7.0;
  m2.matrix[2][1] = 8.0;
  m2.matrix[2][2] = 9.0;
  origin.matrix[0][0] = -0.9;
  origin.matrix[0][1] = -1.8;
  origin.matrix[0][2] = -2.7;
  origin.matrix[1][0] = -3.6;
  origin.matrix[1][1] = -4.5;
  origin.matrix[1][2] = -5.4;
  origin.matrix[2][0] = -6.3;
  origin.matrix[2][1] = -7.2;
  origin.matrix[2][2] = -8.1;
  int result = s21_sub_matrix(&m1, &m2, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(check_3, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(origin.matrix[i][j], r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&r);
  s21_remove_matrix(&origin);
}
END_TEST

START_TEST(sub_4) {
  matrix_t m1;
  matrix_t m2;
  matrix_t origin;
  matrix_t r;
  int check_origin = OK;
  int check_1 = s21_create_matrix(3, 3, &m1);
  int check_2 = s21_create_matrix(3, 3, &m2);
  int check_3 = s21_create_matrix(3, 3, &origin);
  m1.matrix[0][0] = 0.1;
  m1.matrix[0][1] = 0.2;
  m1.matrix[0][2] = 0.3;
  m1.matrix[1][0] = 0.4;
  m1.matrix[1][1] = 0.5;
  m1.matrix[1][2] = 0.6;
  m1.matrix[2][0] = 0.7;
  m1.matrix[2][1] = 0.8;
  m1.matrix[2][2] = 0.9;
  m2.matrix[0][0] = 0.0;
  m2.matrix[0][1] = 0.0;
  m2.matrix[0][2] = 0.0;
  m2.matrix[1][0] = 0.0;
  m2.matrix[1][1] = 0.0;
  m2.matrix[1][2] = 0.0;
  m2.matrix[2][0] = 0.0;
  m2.matrix[2][1] = 0.0;
  m2.matrix[2][2] = 0.0;
  origin.matrix[0][0] = 0.1;
  origin.matrix[0][1] = 0.2;
  origin.matrix[0][2] = 0.3;
  origin.matrix[1][0] = 0.4;
  origin.matrix[1][1] = 0.5;
  origin.matrix[1][2] = 0.6;
  origin.matrix[2][0] = 0.7;
  origin.matrix[2][1] = 0.8;
  origin.matrix[2][2] = 0.9;
  int result = s21_sub_matrix(&m2, &m1, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(check_3, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(-(origin.matrix[i][j]), r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&r);
  s21_remove_matrix(&origin);
}
END_TEST

START_TEST(sub_5) {
  matrix_t result, B, A;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  B.matrix[0][0] = 3;
  B.matrix[0][1] = 3;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 3;
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = OK;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      ck_assert_int_eq(result.matrix[i][j], -2);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_6) {
  matrix_t result, B, A;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  B.matrix[0][0] = 0;
  B.matrix[0][1] = 0;
  B.matrix[1][0] = 0;
  B.matrix[1][1] = 0;
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = OK;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      ck_assert_int_eq(result.matrix[i][j], 0);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_7) {
  matrix_t result, B, A;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  B.matrix[0][0] = 3;
  B.matrix[0][1] = 3;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 3;
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = CALCULATION_ERROR;
  ck_assert_int_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_8) {
  matrix_t result, B, A;
  s21_create_matrix(-2, 2, &A);
  s21_create_matrix(2, 2, &B);
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = INCORRECT_MATRIX;
  ck_assert_int_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_9) {
  matrix_t result, B, A;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(-2, 2, &B);
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = INCORRECT_MATRIX;
  ck_assert_int_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_10) {
  matrix_t result, res_origin, B, A;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  s21_create_matrix(4, 4, &res_origin);
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
  B.matrix[0][0] = 8;
  B.matrix[0][1] = 8;
  B.matrix[0][2] = 3;
  B.matrix[0][3] = 5;
  B.matrix[1][0] = -7;
  B.matrix[1][1] = 7;
  B.matrix[1][2] = 1;
  B.matrix[1][3] = 1;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 3;
  B.matrix[2][2] = 4;
  B.matrix[2][3] = -4;
  B.matrix[3][0] = 10;
  B.matrix[3][1] = 3;
  B.matrix[3][2] = 9;
  B.matrix[3][3] = -3;
  res_origin.matrix[0][0] = -6;
  res_origin.matrix[0][1] = -3;
  res_origin.matrix[0][2] = 4;
  res_origin.matrix[0][3] = -9;
  res_origin.matrix[1][0] = 13;
  res_origin.matrix[1][1] = -4;
  res_origin.matrix[1][2] = 3;
  res_origin.matrix[1][3] = 13;
  res_origin.matrix[2][0] = -2;
  res_origin.matrix[2][1] = -5;
  res_origin.matrix[2][2] = -7;
  res_origin.matrix[2][3] = 3;
  res_origin.matrix[3][0] = 0;
  res_origin.matrix[3][1] = 0;
  res_origin.matrix[3][2] = 0;
  res_origin.matrix[3][3] = 0;
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = OK;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(sub_11) {
  matrix_t result, res_origin, B, A;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &res_origin);
  A.matrix[0][0] = 2.987654;
  A.matrix[0][1] = -5.3456;
  A.matrix[1][0] = 6.23;
  A.matrix[1][1] = -3.9292;
  B.matrix[0][0] = 4.838;
  B.matrix[0][1] = 8.0987;
  B.matrix[1][0] = -8;
  B.matrix[1][1] = -0.921;
  res_origin.matrix[0][0] = -1.850346;
  res_origin.matrix[0][1] = -13.4443;
  res_origin.matrix[1][0] = 14.23;
  res_origin.matrix[1][1] = -3.0082;
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = OK;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(sub_12) {
  matrix_t result, res_origin, B, A;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &res_origin);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 4 * i;
    }
  }
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = 2 * i;
    }
  }
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      res_origin.matrix[i][j] = i * 2;
    }
  }
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = OK;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(sub_13) {
  matrix_t result, res_origin, B, A;
  s21_create_matrix(5, 4, &A);
  s21_create_matrix(5, 4, &B);
  s21_create_matrix(5, 4, &res_origin);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i;
      res_origin.matrix[i][j] = i;
    }
  }
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = OK;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

// multiplication by scalar

START_TEST(mul_num_1) {
  matrix_t m1;
  matrix_t origin;
  matrix_t r;
  double num = 2.0;
  int check_origin = OK;
  int check_1 = s21_create_matrix(3, 3, &m1);
  int check_2 = s21_create_matrix(3, 3, &origin);
  m1.matrix[0][0] = 0.1;
  m1.matrix[0][1] = 0.2;
  m1.matrix[0][2] = 0.3;
  m1.matrix[1][0] = 0.4;
  m1.matrix[1][1] = 0.5;
  m1.matrix[1][2] = 0.6;
  m1.matrix[2][0] = 0.7;
  m1.matrix[2][1] = 0.8;
  m1.matrix[2][2] = 0.9;
  origin.matrix[0][0] = 0.2;
  origin.matrix[0][1] = 0.4;
  origin.matrix[0][2] = 0.6;
  origin.matrix[1][0] = 0.8;
  origin.matrix[1][1] = 1.0;
  origin.matrix[1][2] = 1.2;
  origin.matrix[2][0] = 1.4;
  origin.matrix[2][1] = 1.6;
  origin.matrix[2][2] = 1.8;
  int result = s21_mult_number(&m1, num, &r);
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

START_TEST(mul_num_2) {
  matrix_t m1;
  matrix_t r;
  double num = 0.0;
  int check_origin = OK;
  int check_1 = s21_create_matrix(3, 3, &m1);
  m1.matrix[0][0] = 0.1;
  m1.matrix[0][1] = 0.2;
  m1.matrix[0][2] = 0.3;
  m1.matrix[1][0] = 0.4;
  m1.matrix[1][1] = 0.5;
  m1.matrix[1][2] = 0.6;
  m1.matrix[2][0] = 0.7;
  m1.matrix[2][1] = 0.8;
  m1.matrix[2][2] = 0.9;
  int result = s21_mult_number(&m1, num, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(0.0, r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&r);
}
END_TEST

START_TEST(mul_num_3) {
  matrix_t m1;
  matrix_t r;
  double num = 1.0;
  int check_origin = OK;
  int check_1 = s21_create_matrix(3, 3, &m1);
  m1.matrix[0][0] = 0.1;
  m1.matrix[0][1] = 0.2;
  m1.matrix[0][2] = 0.3;
  m1.matrix[1][0] = 0.4;
  m1.matrix[1][1] = 0.5;
  m1.matrix[1][2] = 0.6;
  m1.matrix[2][0] = 0.7;
  m1.matrix[2][1] = 0.8;
  m1.matrix[2][2] = 0.9;
  int result = s21_mult_number(&m1, num, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(m1.matrix[i][j], r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&r);
}
END_TEST

START_TEST(mul_num_4) {
  matrix_t A, result, res_origin;
  double num = 2.0;
  int check_origin = OK;
  int check_1 = s21_create_matrix(5, 4, &A);
  int check_3 = s21_create_matrix(5, 4, &res_origin);
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
  res_origin.matrix[0][0] = 4;
  res_origin.matrix[0][1] = 10;
  res_origin.matrix[0][2] = 14;
  res_origin.matrix[0][3] = -8;
  res_origin.matrix[1][0] = 12;
  res_origin.matrix[1][1] = 6;
  res_origin.matrix[1][2] = 8;
  res_origin.matrix[1][3] = 28;
  res_origin.matrix[2][0] = 10;
  res_origin.matrix[2][1] = -4;
  res_origin.matrix[2][2] = -6;
  res_origin.matrix[2][3] = -2;
  res_origin.matrix[3][0] = 20;
  res_origin.matrix[3][1] = 6;
  res_origin.matrix[3][2] = 18;
  res_origin.matrix[3][3] = -6;
  res_origin.matrix[4][0] = -6;
  res_origin.matrix[4][1] = 6;
  res_origin.matrix[4][2] = 2;
  res_origin.matrix[4][3] = 10;
  int check = s21_mult_number(&A, num, &result);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_3, check_origin);
  ck_assert_int_eq(check, check_origin);
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

START_TEST(mul_num_5) {
  matrix_t A, result, res_origin;
  double num = 4.25;
  int check_origin = OK;
  int check_1 = s21_create_matrix(5, 4, &A);
  int check_3 = s21_create_matrix(5, 4, &res_origin);
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
  res_origin.matrix[0][0] = 8.5;
  res_origin.matrix[0][1] = 21.25;
  res_origin.matrix[0][2] = 29.75;
  res_origin.matrix[0][3] = -17;
  res_origin.matrix[1][0] = 25.5;
  res_origin.matrix[1][1] = 12.75;
  res_origin.matrix[1][2] = 17;
  res_origin.matrix[1][3] = 59.5;
  res_origin.matrix[2][0] = 21.25;
  res_origin.matrix[2][1] = -8.5;
  res_origin.matrix[2][2] = -12.75;
  res_origin.matrix[2][3] = -4.25;
  res_origin.matrix[3][0] = 42.5;
  res_origin.matrix[3][1] = 12.75;
  res_origin.matrix[3][2] = 38.25;
  res_origin.matrix[3][3] = -12.75;
  res_origin.matrix[4][0] = -12.75;
  res_origin.matrix[4][1] = 12.75;
  res_origin.matrix[4][2] = 4.25;
  res_origin.matrix[4][3] = 21.25;
  int check = s21_mult_number(&A, num, &result);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_3, check_origin);
  ck_assert_int_eq(check, check_origin);
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

START_TEST(mul_num_6) {
  matrix_t A, result, res_origin;
  double num = 4.25;
  int check_origin = INCORRECT_MATRIX;
  s21_create_matrix(-5, 4, &A);
  s21_create_matrix(5, 4, &res_origin);
  int check = s21_mult_number(&A, num, &result);
  ck_assert_int_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

// multiplication of two matrices

START_TEST(mult_matrix_1) {
  matrix_t A, B, result, res_origin;
  int check_origin = OK;
  int check_1 = s21_create_matrix(5, 4, &A);
  int check_2 = s21_create_matrix(4, 4, &B);
  int check_4 = s21_create_matrix(5, 4, &res_origin);
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
  B.matrix[0][0] = 8;
  B.matrix[0][1] = 8;
  B.matrix[0][2] = 3;
  B.matrix[0][3] = 5;
  B.matrix[1][0] = -7;
  B.matrix[1][1] = 7;
  B.matrix[1][2] = 1;
  B.matrix[1][3] = 1;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 3;
  B.matrix[2][2] = 4;
  B.matrix[2][3] = -4;
  B.matrix[3][0] = 10;
  B.matrix[3][1] = 3;
  B.matrix[3][2] = 9;
  B.matrix[3][3] = -3;
  res_origin.matrix[0][0] = -10;
  res_origin.matrix[0][1] = 60;
  res_origin.matrix[0][2] = 3;
  res_origin.matrix[0][3] = -1;
  res_origin.matrix[1][0] = 195;
  res_origin.matrix[1][1] = 123;
  res_origin.matrix[1][2] = 163;
  res_origin.matrix[1][3] = -25;
  res_origin.matrix[2][0] = 23;
  res_origin.matrix[2][1] = 14;
  res_origin.matrix[2][2] = -8;
  res_origin.matrix[2][3] = 38;
  res_origin.matrix[3][0] = 92;
  res_origin.matrix[3][1] = 119;
  res_origin.matrix[3][2] = 42;
  res_origin.matrix[3][3] = 26;
  res_origin.matrix[4][0] = 12;
  res_origin.matrix[4][1] = 15;
  res_origin.matrix[4][2] = 43;
  res_origin.matrix[4][3] = -31;
  int check = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(check_4, check_origin);
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(mult_matrix_2) {
  matrix_t A, B, result, res_origin;
  int check_origin = OK;
  int check_1 = s21_create_matrix(2, 2, &A);
  int check_2 = s21_create_matrix(2, 4, &B);
  int check_4 = s21_create_matrix(2, 4, &res_origin);
  A.matrix[0][0] = 2.987654;
  A.matrix[0][1] = -5.3456;
  A.matrix[1][0] = 6.23;
  A.matrix[1][1] = -3.9292;
  B.matrix[0][0] = 4.838;
  B.matrix[0][1] = 8.0987;
  B.matrix[0][2] = 8.09;
  B.matrix[0][3] = -987;
  B.matrix[1][0] = -8;
  B.matrix[1][1] = -0.921;
  B.matrix[1][2] = -0.91;
  B.matrix[1][3] = 21;
  res_origin.matrix[0][0] = 57.219070052;
  res_origin.matrix[0][1] = 29.1194110498;
  res_origin.matrix[0][2] = 29.03461686;
  res_origin.matrix[0][3] = -3061.072098;
  res_origin.matrix[1][0] = 61.57434;
  res_origin.matrix[1][1] = 54.0736942;
  res_origin.matrix[1][2] = 53.976272;
  res_origin.matrix[1][3] = -6231.5232;
  int check = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(check_4, check_origin);
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(mult_matrix_3) {
  matrix_t A, B, result, res_origin;
  int check_origin = OK;
  int check_1 = s21_create_matrix(3, 3, &A);
  int check_2 = s21_create_matrix(3, 3, &B);
  int check_4 = s21_create_matrix(3, 3, &res_origin);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 9;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 7;
  A.matrix[2][0] = 2;
  A.matrix[2][1] = 7;
  A.matrix[2][2] = 0;
  B.matrix[0][0] = 0;
  B.matrix[0][1] = 9;
  B.matrix[0][2] = 8;
  B.matrix[1][0] = 0;
  B.matrix[1][1] = 9;
  B.matrix[1][2] = 9;
  B.matrix[2][0] = 1;
  B.matrix[2][1] = 9;
  B.matrix[2][2] = 6;
  res_origin.matrix[0][0] = 1;
  res_origin.matrix[0][1] = 90;
  res_origin.matrix[0][2] = 87;
  res_origin.matrix[1][0] = 7;
  res_origin.matrix[1][1] = 99;
  res_origin.matrix[1][2] = 77;
  res_origin.matrix[2][0] = 0;
  res_origin.matrix[2][1] = 81;
  res_origin.matrix[2][2] = 79;
  int check = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(check_4, check_origin);
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(mult_matrix_4) {
  matrix_t A, B, result;
  int check_origin = CALCULATION_ERROR;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(4, 2, &B);
  int check = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_5) {
  matrix_t A, B, result;
  int check_origin = OK;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 12, &B);
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = i + j;
    }
  }
  int check = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_int_eq(result.matrix[i][j], 0.0);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_6) {
  matrix_t A, B, result;
  int check_origin = INCORRECT_MATRIX;
  s21_create_matrix(-12, 3, &A);
  s21_create_matrix(3, 12, &B);
  int check = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(check, check_origin);
  s21_remove_matrix(&B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

void srunner_add_test_arithmetic(SRunner *sr) {
  Suite *suit_3 = suite_create("arithmetic");
  TCase *tc3_3 = tcase_create("arithmetic");
  suite_add_tcase(suit_3, tc3_3);

  tcase_add_test(tc3_3, sum_1);
  tcase_add_test(tc3_3, sum_2);
  tcase_add_test(tc3_3, sum_3);
  tcase_add_test(tc3_3, sum_4);
  tcase_add_test(tc3_3, sum_5);
  tcase_add_test(tc3_3, sum_6);
  tcase_add_test(tc3_3, sum_7);
  tcase_add_test(tc3_3, sum_8);
  tcase_add_test(tc3_3, sum_8);
  tcase_add_test(tc3_3, sum_9);
  tcase_add_test(tc3_3, sum_10);
  tcase_add_test(tc3_3, sum_11);

  tcase_add_test(tc3_3, sub_1);
  tcase_add_test(tc3_3, sub_2);
  tcase_add_test(tc3_3, sub_3);
  tcase_add_test(tc3_3, sub_4);
  tcase_add_test(tc3_3, sub_5);
  tcase_add_test(tc3_3, sub_6);
  tcase_add_test(tc3_3, sub_7);
  tcase_add_test(tc3_3, sub_8);
  tcase_add_test(tc3_3, sub_9);
  tcase_add_test(tc3_3, sub_10);
  tcase_add_test(tc3_3, sub_11);
  tcase_add_test(tc3_3, sub_12);
  tcase_add_test(tc3_3, sub_13);

  tcase_add_test(tc3_3, mul_num_1);
  tcase_add_test(tc3_3, mul_num_2);
  tcase_add_test(tc3_3, mul_num_3);
  tcase_add_test(tc3_3, mul_num_4);
  tcase_add_test(tc3_3, mul_num_5);
  tcase_add_test(tc3_3, mul_num_6);

  tcase_add_test(tc3_3, mult_matrix_1);
  tcase_add_test(tc3_3, mult_matrix_2);
  tcase_add_test(tc3_3, mult_matrix_3);
  tcase_add_test(tc3_3, mult_matrix_4);
  tcase_add_test(tc3_3, mult_matrix_5);
  tcase_add_test(tc3_3, mult_matrix_6);

  srunner_add_suite(sr, suit_3);
}
