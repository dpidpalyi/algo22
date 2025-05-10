#include "test_dynamicArray22.h"

START_TEST(test_Put_0) {
  int err = Put(NULL, 20);

  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(test_Put_1) {
  DynamicArray22 *da = NewDynamicArray22(1);
  int err = Put(da, 20);

  ck_assert_int_eq(err, 0);
  ck_assert_int_eq(da->size, 1);
  ck_assert_int_eq(da->capacity, 1);
  ck_assert_int_eq(da->arr[0], 20);

  DestroyDynamicArray22(da);
  free(da);
}
END_TEST

START_TEST(test_Put_2) {
  DynamicArray22 *da = NewDynamicArray22(2);
  int err = Put(da, 10);
  ck_assert_int_eq(err, 0);
  err = Put(da, 20);
  ck_assert_int_eq(err, 0);

  ck_assert_int_eq(da->size, 2);
  ck_assert_int_eq(da->capacity, 2);
  ck_assert_int_eq(da->arr[0], 10);
  ck_assert_int_eq(da->arr[1], 20);

  DestroyDynamicArray22(da);
  free(da);
}
END_TEST

START_TEST(test_Put_3) {
  DynamicArray22 *da = NewDynamicArray22(2);
  int err = Put(da, 1);
  ck_assert_int_eq(err, 0);
  err = Put(da, 2);
  ck_assert_int_eq(err, 0);
  err = Put(da, 3);
  ck_assert_int_eq(err, 0);

  ck_assert_int_eq(da->size, 3);
  ck_assert_int_eq(da->capacity, 4);
  ck_assert_int_eq(da->arr[0], 1);
  ck_assert_int_eq(da->arr[1], 2);
  ck_assert_int_eq(da->arr[2], 3);

  DestroyDynamicArray22(da);
  free(da);
}
END_TEST

Suite *test_Put(void) {
  Suite *s = suite_create("===== Put =====");
  TCase *tc = tcase_create("Put");

  tcase_add_test(tc, test_Put_0);
  tcase_add_test(tc, test_Put_1);
  tcase_add_test(tc, test_Put_2);
  tcase_add_test(tc, test_Put_3);
  suite_add_tcase(s, tc);

  return s;
}
