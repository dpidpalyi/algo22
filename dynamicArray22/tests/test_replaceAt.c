#include "test_dynamicArray22.h"

START_TEST(test_ReplaceAt_0) {
  int err = ReplaceAt(NULL, 2, 10);

  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(test_ReplaceAt_1) {
  DynamicArray22 *da = NewDynamicArray22(1);
  int err = ReplaceAt(da, 2, 10);

  ck_assert_int_eq(err, 1);

  DestroyDynamicArray22(da);
  free(da);
}
END_TEST

START_TEST(test_ReplaceAt_2) {
  DynamicArray22 *da = NewDynamicArray22(1);
  Put(da, 10);
  int err = ReplaceAt(da, 0, 20);

  ck_assert_int_eq(err, 0);
  ck_assert_int_eq(da->size, 1);
  ck_assert_int_eq(da->capacity, 1);
  ck_assert_int_eq(da->arr[0], 20);

  DestroyDynamicArray22(da);
  free(da);
}
END_TEST

START_TEST(test_ReplaceAt_3) {
  DynamicArray22 *da = NewDynamicArray22(3);
  Put(da, 10);
  Put(da, 20);
  Put(da, 30);
  int err = ReplaceAt(da, 1, 50);

  ck_assert_int_eq(err, 0);
  ck_assert_int_eq(da->size, 3);
  ck_assert_int_eq(da->capacity, 3);
  ck_assert_int_eq(da->arr[0], 10);
  ck_assert_int_eq(da->arr[1], 50);
  ck_assert_int_eq(da->arr[2], 30);

  DestroyDynamicArray22(da);
  free(da);
}
END_TEST

START_TEST(test_ReplaceAt_4) {
  DynamicArray22 *da = NewDynamicArray22(3);
  Put(da, 10);
  Put(da, 20);
  Put(da, 30);
  int err = ReplaceAt(da, 2, 60);

  ck_assert_int_eq(err, 0);
  ck_assert_int_eq(da->size, 3);
  ck_assert_int_eq(da->capacity, 3);
  ck_assert_int_eq(da->arr[0], 10);
  ck_assert_int_eq(da->arr[1], 20);
  ck_assert_int_eq(da->arr[2], 60);

  DestroyDynamicArray22(da);
  free(da);
}
END_TEST

Suite *test_ReplaceAt(void) {
  Suite *s = suite_create("===== ReplaceAt =====");
  TCase *tc = tcase_create("ReplaceAt");

  tcase_add_test(tc, test_ReplaceAt_0);
  tcase_add_test(tc, test_ReplaceAt_1);
  tcase_add_test(tc, test_ReplaceAt_2);
  tcase_add_test(tc, test_ReplaceAt_3);
  tcase_add_test(tc, test_ReplaceAt_4);
  suite_add_tcase(s, tc);

  return s;
}
