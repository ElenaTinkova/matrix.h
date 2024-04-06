#include "test_matrix.h"

START_TEST(create_1) {
  matrix_t A = {0};
  int check = s21_create_matrix(3, 4, &A);
  int check_origin = 0;
  s21_remove_matrix(&A);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(create_2) {
  matrix_t A = {0};
  int check = s21_create_matrix(-3, 4, &A);
  int check_origin = 1;
  s21_remove_matrix(&A);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(create_3) {
  matrix_t A = {0};
  int check = s21_create_matrix(3, -4, &A);
  int check_origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(create_4) {
  matrix_t A = {0};
  int check = s21_create_matrix(0, 19, &A);
  int check_origin = 1;
  s21_remove_matrix(&A);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(create_5) {
  matrix_t A = {0};
  int check = s21_create_matrix(1, 1, &A);
  int check_origin = 0;
  s21_remove_matrix(&A);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(create_6) {
  matrix_t res = {0};
  ck_assert_int_eq(s21_create_matrix(7, 7, &res), 0);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(create_7) {
  matrix_t res;
  ck_assert_int_eq(s21_create_matrix(10, 15, &res), 0);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(create_8) {
  matrix_t res = {0};
  ck_assert_int_eq(s21_create_matrix(1, 0, &res), 1);
}
END_TEST

START_TEST(remove_1) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 75301501;
  s21_remove_matrix(&A);
  int check = (A.rows == 3) ? 0 : 1;
  int check_origin = 1;
  ck_assert_uint_eq(check, check_origin);
}
END_TEST

void srunner_add_test_create(SRunner *sr) {
  Suite *suit_1 = suite_create("create");
  TCase *tc1_1 = tcase_create("create");
  suite_add_tcase(suit_1, tc1_1);

  tcase_add_test(tc1_1, create_1);
  tcase_add_test(tc1_1, create_2);
  tcase_add_test(tc1_1, create_3);
  tcase_add_test(tc1_1, create_4);
  tcase_add_test(tc1_1, create_5);
  tcase_add_test(tc1_1, create_6);
  tcase_add_test(tc1_1, create_7);
  tcase_add_test(tc1_1, create_8);
  tcase_add_test(tc1_1, remove_1);

  srunner_add_suite(sr, suit_1);
}
