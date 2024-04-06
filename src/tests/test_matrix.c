#include "test_matrix.h"

int main() {
  Suite *s = suite_create("matrix tests");
  SRunner *sr = srunner_create(s);
  int err;

  srunner_add_test_create(sr);
  srunner_add_test_comparison(sr);
  srunner_add_test_arithmetic(sr);
  srunner_add_test_other(sr);

  srunner_run_all(sr, CK_NORMAL);  // CK_ENV?
  err = srunner_ntests_failed(sr);
  srunner_free(sr);

  return err == 0 ? 0 : 1;
}
