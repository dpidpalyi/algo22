#include "test_dynamicArray22.h"

START_TEST(test_RemoveLast_0) {
  int err = RemoveLast(NULL);

  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(test_RemoveLast_1) {
  DynamicArray22 *da = NewDynamicArray22(1);
  int err = RemoveLast(da);

  ck_assert_int_eq(err, 1);

  DestroyDynamicArray22(da);
  free(da);
}
END_TEST

START_TEST(test_RemoveLast_2) {
  DynamicArray22 *da = NewDynamicArray22(1);
  Put(da, 10);
  int err = RemoveLast(da);

  ck_assert_int_eq(err, 0);
  ck_assert_int_eq(da->size, 0);
  ck_assert_int_eq(da->capacity, 1);

  DestroyDynamicArray22(da);
  free(da);
}
END_TEST

START_TEST(test_RemoveLast_3) {
  DynamicArray22 *da = NewDynamicArray22(3);
  Put(da, 1);
  Put(da, 2);
  Put(da, 3);

  int err = RemoveLast(da);
  ck_assert_int_eq(err, 0);
  ck_assert_int_eq(da->size, 2);
  ck_assert_int_eq(da->capacity, 3);
  ck_assert_int_eq(da->arr[0], 1);
  ck_assert_int_eq(da->arr[1], 2);

  DestroyDynamicArray22(da);
  free(da);
}
END_TEST

Suite *test_RemoveLast(void) {
  Suite *s = suite_create("===== RemoveLast =====");
  TCase *tc = tcase_create("RemoveLast");

  tcase_add_test(tc, test_RemoveLast_0);
  tcase_add_test(tc, test_RemoveLast_1);
  tcase_add_test(tc, test_RemoveLast_2);
  tcase_add_test(tc, test_RemoveLast_3);
  suite_add_tcase(s, tc);

  return s;
}
