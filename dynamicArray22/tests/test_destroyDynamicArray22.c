#include "test_dynamicArray22.h"

START_TEST(test_DestroyDynamicArray22_0) {
  int err = DestroyDynamicArray22(NULL);

  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(test_DestroyDynamicArray22_1) {
  DynamicArray22 *da = NewDynamicArray22(2);

  int err = DestroyDynamicArray22(da);

  ck_assert_int_eq(err, 0);
  free(da);
}
END_TEST

Suite *test_DestroyDynamicArray22(void) {
  Suite *s = suite_create("===== DestroyDynamicArray22 =====");
  TCase *tc = tcase_create("DestroyDynamicArray22");

  tcase_add_test(tc, test_DestroyDynamicArray22_0);
  tcase_add_test(tc, test_DestroyDynamicArray22_1);
  suite_add_tcase(s, tc);

  return s;
}
