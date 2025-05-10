#include "test_dynamicArray22.h"

START_TEST(test_AllocAndCopy_0) {
  int err = AllocAndCopy(NULL);

  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(test_AllocAndCopy_1) {
  DynamicArray22 *da = NewDynamicArray22(1);
  int *old = da->arr;
  Put(da, 10);

  int err = AllocAndCopy(da);

  ck_assert_int_eq(err, 0);
  ck_assert_ptr_ne(old, da->arr);
  ck_assert_int_eq(da->size, 1);
  ck_assert_int_eq(da->capacity, 2);
  ck_assert_int_eq(da->arr[0], 10);

  DestroyDynamicArray22(da);
  free(da);
}
END_TEST

Suite *test_AllocAndCopy(void) {
  Suite *s = suite_create("===== AllocAndCopy =====");
  TCase *tc = tcase_create("AllocAndCopy");

  tcase_add_test(tc, test_AllocAndCopy_0);
  tcase_add_test(tc, test_AllocAndCopy_1);
  suite_add_tcase(s, tc);

  return s;
}
