#include <stdio.h>
#include <stdlib.h>

#include <sl_list.h>
#include <sl_iterator.h>

#include <check.h>

#define QTD 10

sl_list_root *list;

/* Test Suite 1 */

START_TEST(test_list_create_destroy) {
	sl_list_root *a = sl_list_create(&free, HEAD);
  ck_assert_ptr_ne(a, NULL);
	sl_list_destroy(&a);
	ck_assert_ptr_eq(a, NULL);
} END_TEST

Suite * make_test_list_create_destroy(void) {
  Suite *s; TCase *tc_core;
  s = suite_create("List Create Destroy Test Suite");
  tc_core = tcase_create("create/destroy");
  tcase_add_test(tc_core, test_list_create_destroy);
  suite_add_tcase(s, tc_core);
  return s;
}

/* -------------------------------------------------------------------------- */
/* Test with Setup/Teardown and InsertMode = HEAD */

void setup(void) {
  list = sl_list_create(&free, HEAD);
}

void teardown(void) {
  sl_list_destroy(&list);
}

START_TEST(test_list_insert_next_el_null) {
  int sample[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int result[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int sz_sample = sizeof(sample)/sizeof(sample[0]);
  int *num;

  for (int i = 0; i < sz_sample; i++) {
		num = (int *) malloc(sizeof(int));
		*num = sample[i];
		sl_list_insert_el_next(list, NULL, num);
	}

  iterator_s *itr = sl_iter_create(list);
  for(int i = 0; i < sz_sample; i++) {
    int el = *((int *) sl_iter_item(itr));
    ck_assert_int_eq(result[i], el);
    sl_iter_next(itr);
  }
  sl_iter_free(&itr);
} END_TEST

START_TEST(test_list_insert_next_el_head) {
  int sample[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int result[10] = {1, 10, 9, 8, 7, 6, 5, 4, 3, 2};
  int sz_sample = sizeof(sample)/sizeof(sample[0]);
  int *num;

  for (int i = 0; i < sz_sample; i++) {
		num = (int *) malloc(sizeof(int));
		*num = sample[i];
		sl_list_insert_el_next(list, list->head, num);
	}

  iterator_s *itr = sl_iter_create(list);
  for(int i = 0; i < sz_sample; i++) {
    int el = *((int *) sl_iter_item(itr));
    ck_assert_int_eq(result[i], el);
    sl_iter_next(itr);
  }
  sl_iter_free(&itr);
} END_TEST

START_TEST(test_list_insert_next_el_tail) {
  int sample[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int result[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int sz_sample = sizeof(sample)/sizeof(sample[0]);
  int *num;

  for (int i = 0; i < sz_sample; i++) {
		num = (int *) malloc(sizeof(int));
		*num = sample[i];
		sl_list_insert_el_next(list, list->tail, num);
	}

  iterator_s *itr = sl_iter_create(list);
  for(int i = 0; i < sz_sample; i++) {
    int el = *((int *) sl_iter_item(itr));
    ck_assert_int_eq(result[i], el);
    sl_iter_next(itr);
  }
  sl_iter_free(&itr);
} END_TEST

Suite * make_test_list_insert(void) {
  Suite *s; TCase *tc_core;
  s = suite_create("List Insertion Test Suite");
  tc_core = tcase_create("List Insertion");
  tcase_add_checked_fixture(tc_core, setup, teardown);
  tcase_add_test(tc_core, test_list_insert_next_el_null);
  tcase_add_test(tc_core, test_list_insert_next_el_head);
  tcase_add_test(tc_core, test_list_insert_next_el_tail);
  suite_add_tcase(s, tc_core);
  return s;
}

/* -------------------------------------------------------------------------- */
/* Main */

int main(void) {
  int number_failed;
  SRunner *sr;

  sr = srunner_create(make_test_list_create_destroy());
  srunner_add_suite (sr, make_test_list_insert());
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_set_log(sr, "test.log");
  srunner_set_xml(sr, "test.xml");
  srunner_run_all(sr, CK_VERBOSE);

  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
