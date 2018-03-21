#include <stdio.h>
#include <stdlib.h>

#include <sl_list.h>
#include <sl_iterator.h>

#include <check.h>

#define QTD 100

int sample[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

sl_list_root *list;

void setup(void) {
  list = sl_list_create(&free, HEAD);
}

void teardown(void) {
  sl_list_destroy(&list);
}

START_TEST(test_list_create_destroy) {
	sl_list_root *a = sl_list_create(&free, HEAD);
  ck_assert_ptr_ne(a, NULL);
	sl_list_destroy(&a);
	ck_assert_ptr_eq(a, NULL);
}
END_TEST

Suite * make_test_list_create_destroy(void) {
  Suite *s; TCase *tc_core;
  s = suite_create("Sample Create Destroy Test Suite");
  tc_core = tcase_create("sl_list_create/sl_list_destroy");
  tcase_add_test(tc_core, test_list_create_destroy);
  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  int number_failed;
  SRunner *sr;

  sr = srunner_create(make_test_list_create_destroy());
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_set_log(sr, "test.log");
  srunner_set_xml(sr, "test.xml");
  srunner_run_all(sr, CK_VERBOSE);

  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
