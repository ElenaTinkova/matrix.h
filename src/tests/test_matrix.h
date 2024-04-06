#ifndef TEST_MATRIX_H_
#define TEST_MATRIX_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"

void srunner_add_test_create(SRunner *sr);
void srunner_add_test_comparison(SRunner *sr);
void srunner_add_test_arithmetic(SRunner *sr);
void srunner_add_test_other(SRunner *sr);

#endif
