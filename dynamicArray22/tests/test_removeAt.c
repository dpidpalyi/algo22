#include "test_dynamicArray22.h"

START_TEST(test_RemoveAt_0) {
  int err = RemoveAt(NULL, 2);

  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(test_RemoveAt_1) {
  DynamicArray22 *da = NewDynamicArray22(1);
  int err = RemoveAt(da, 2);

  ck_assert_int_eq(err, 1);

  DestroyDynamicArray22(da);
  free(da);
}
END_TEST

START_TEST(test_RemoveAt_2) {
  DynamicArray22 *da = NewDynamicArray22(1);
  Put(da, 10);
  int err = RemoveAt(da, 0);

  ck_assert_int_eq(err, 0);
  ck_assert_int_eq(da->size, 0);
  ck_assert_int_eq(da->capacity, 1);

  DestroyDynamicArray22(da);
  free(da);
}
END_TEST

START_TEST(test_RemoveAt_3) {
  DynamicArray22 *da = NewDynamicArray22(3);
  Put(da, 10);
  Put(da, 20);
  Put(da, 30);
  int err = RemoveAt(da, 0);

  ck_assert_int_eq(err, 0);
  ck_assert_int_eq(da->size, 2);
  ck_assert_int_eq(da->capacity, 3);
  ck_assert_int_eq(da->arr[0], 20);
  ck_assert_int_eq(da->arr[1], 30);

  DestroyDynamicArray22(da);
  free(da);
}
END_TEST

START_TEST(test_RemoveAt_4) {
  DynamicArray22 *da = NewDynamicArray22(3);
  Put(da, 10);
  Put(da, 20);
  Put(da, 30);
  int err = RemoveAt(da, 1);

  ck_assert_int_eq(err, 0);
  ck_assert_int_eq(da->size, 2);
  ck_assert_int_eq(da->capacity, 3);
  ck_assert_int_eq(da->arr[0], 10);
  ck_assert_int_eq(da->arr[1], 30);

  DestroyDynamicArray22(da);
  free(da);
}
END_TEST

START_TEST(test_RemoveAt_5) {
  DynamicArray22 *da = NewDynamicArray22(3);
  Put(da, 10);
  Put(da, 20);
  Put(da, 30);
  int err = RemoveAt(da, 2);

  ck_assert_int_eq(err, 0);
  ck_assert_int_eq(da->size, 2);
  ck_assert_int_eq(da->capacity, 3);
  ck_assert_int_eq(da->arr[0], 10);
  ck_assert_int_eq(da->arr[1], 20);

  DestroyDynamicArray22(da);
  free(da);
}
END_TEST

Suite *test_RemoveAt(void) {
  Suite *s = suite_create("===== RemoveAt =====");
  TCase *tc = tcase_create("RemoveAt");

  tcase_add_test(tc, test_RemoveAt_0);
  tcase_add_test(tc, test_RemoveAt_1);
  tcase_add_test(tc, test_RemoveAt_2);
  tcase_add_test(tc, test_RemoveAt_3);
  tcase_add_test(tc, test_RemoveAt_4);
  tcase_add_test(tc, test_RemoveAt_5);
  suite_add_tcase(s, tc);

  return s;
}
