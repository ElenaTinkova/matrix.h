#include "test_matrix.h"

START_TEST(comparison_1) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 3.33333356;
  A.matrix[0][1] = -5;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = -3;
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 3.33333356;
  B.matrix[0][1] = -5;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = -3;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(comparison_2) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 3.33333357;
  A.matrix[0][1] = -5;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = -3;
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 3.33333356;
  B.matrix[0][1] = -5;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = -3;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(comparison_3) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 3.0;
  A.matrix[0][1] = -5;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = -3;
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 2.0;
  B.matrix[0][1] = -5;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = -3;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(comparison_4) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 3.3333333;
  A.matrix[0][1] = -5;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3.3333334;
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 3.3333333;
  B.matrix[0][1] = -5;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = 3.3333335;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(comparison_5) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;
  matrix_t B;
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 1;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(comparison_6) {
  matrix_t A;
  s21_create_matrix(-1, 1, &A);
  matrix_t B;
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 1;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(comparison_7) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  matrix_t B;
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 1;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

void srunner_add_test_comparison(SRunner *sr) {
  Suite *suit_2 = suite_create("comparison");
  TCase *tc2_2 = tcase_create("comparison");
  suite_add_tcase(suit_2, tc2_2);

  tcase_add_test(tc2_2, comparison_1);
  tcase_add_test(tc2_2, comparison_2);
  tcase_add_test(tc2_2, comparison_3);
  tcase_add_test(tc2_2, comparison_4);
  tcase_add_test(tc2_2, comparison_5);
  tcase_add_test(tc2_2, comparison_6);
  tcase_add_test(tc2_2, comparison_7);

  srunner_add_suite(sr, suit_2);
}