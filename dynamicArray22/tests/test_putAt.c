#include "test_dynamicArray22.h"

START_TEST(test_PutAt_0) {
  int err = PutAt(NULL, 0, 10);

  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(test_PutAt_1) {
  DynamicArray22 *da = NewDynamicArray22(1);
  int err = PutAt(da, 5, 10);

  ck_assert_int_eq(err, 1);

  DestroyDynamicArray22(da);
  free(da);
}
END_TEST

START_TEST(test_PutAt_2) {
  DynamicArray22 *da = NewDynamicArray22(1);
  int err = PutAt(da, 0, 10);

  ck_assert_int_eq(err, 0);
  ck_assert_int_eq(da->size, 1);
  ck_assert_int_eq(da->capacity, 1);
  ck_assert_int_eq(da->arr[0], 10);

  DestroyDynamicArray22(da);
  free(da);
}
END_TEST

START_TEST(test_PutAt_3) {
  DynamicArray22 *da = NewDynamicArray22(2);
  Put(da, 1);
  Put(da, 3);

  int err = PutAt(da, 1, 2);

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

Suite *test_PutAt(void) {
  Suite *s = suite_create("===== PutAt =====");
  TCase *tc = tcase_create("PutAt");

  tcase_add_test(tc, test_PutAt_0);
  tcase_add_test(tc, test_PutAt_1);
  tcase_add_test(tc, test_PutAt_2);
  tcase_add_test(tc, test_PutAt_3);
  suite_add_tcase(s, tc);

  return s;
}
