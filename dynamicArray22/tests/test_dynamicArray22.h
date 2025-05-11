#ifndef TEST_DYNAMIC_ARRAY22_H
#define TEST_DYNAMIC_ARRAY22_H

#include <check.h>
#include <stdio.h>

#include "../dynamicArray22.h"

Suite *test_NewDynamicArray22(void);
Suite *test_DestroyDynamicArray22(void);
Suite *test_AllocAndCopy(void);
Suite *test_Put(void);
Suite *test_PutAt(void);
Suite *test_RemoveLast(void);
Suite *test_RemoveAt(void);
Suite *test_ReplaceAt(void);

#endif
