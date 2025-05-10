#include "test_dynamicArray22.h"

START_TEST(test_NewDynamicArray22_0) {
  DynamicArray22 *da = NewDynamicArray22(0);

  ck_assert_ptr_null(da);
}
END_TEST

START_TEST(test_NewDynamicArray22_1) {
  DynamicArray22 *da = NewDynamicArray22(-10);

  ck_assert_ptr_null(da);
}
END_TEST

START_TEST(test_NewDynamicArray22_2) {
  DynamicArray22 *da = NewDynamicArray22(1);

  ck_assert_ptr_nonnull(da);
  ck_assert_int_eq(da->capacity, 1);

  DestroyDynamicArray22(da);
  free(da);
}
END_TEST

START_TEST(test_NewDynamicArray22_3) {
  DynamicArray22 *da = NewDynamicArray22(100000);

  ck_assert_ptr_nonnull(da);
  ck_assert_int_eq(da->capacity, 100000);

  DestroyDynamicArray22(da);
  free(da);
}
END_TEST

Suite *test_NewDynamicArray22(void) {
  Suite *s = suite_create("===== NewDynamicArray22 =====");
  TCase *tc = tcase_create("NewDynamicArray22");

  tcase_add_test(tc, test_NewDynamicArray22_0);
  tcase_add_test(tc, test_NewDynamicArray22_1);
  tcase_add_test(tc, test_NewDynamicArray22_2);
  tcase_add_test(tc, test_NewDynamicArray22_3);
  suite_add_tcase(s, tc);

  return s;
}
