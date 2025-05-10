#include "test_dynamicArray22.h"

int main() {
  int all_tests_failed = 0;
  Suite *test_dynamicArray22[] = {test_NewDynamicArray22(),
                                  test_DestroyDynamicArray22(),
                                  test_AllocAndCopy(),
                                  test_Put(),
                                  test_PutAt(),
                                  NULL};
  for (int i = 0; test_dynamicArray22[i] != NULL; i++) {
    SRunner *runner = srunner_create(test_dynamicArray22[i]);

    srunner_run_all(runner, CK_NORMAL);
    int failed = srunner_ntests_failed(runner);
    all_tests_failed += failed;
    printf("----------------------------------------\n");
    srunner_free(runner);
  }

  if (all_tests_failed) {
    printf("======= NUMBER OF FAILED TESTS: %d =======\n", all_tests_failed);
  } else {
    printf("======= SUCCESS =======\n");
  }

  return all_tests_failed;
}
