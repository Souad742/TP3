#include <stdint.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>
#include<stdio.h>

#include "queens.c"

static void test_same_diagonal(void **state) {
assert_int_equal(true,check_same_diagonal(0,0,1,1));
assert_int_equal(true,check_same_diagonal(0,2,1,3));
assert_int_equal(true,check_same_diagonal(1,2,2,1));
assert_int_equal(false,check_same_diagonal(1,0,1,1));
}

static void test_check_same_column(void **state) {

   assert_int_equal(false, check_column_ok(2,2, (int []){2}));
   assert_int_equal(true, check_column_ok(0,2, (int []){}));
   assert_int_equal(true, check_column_ok(3,2, (int []){1}));
   assert_int_equal(true, check_column_ok(1,2, (int []){3}));
   
   
}
static void test_check_row_available(void **state) {

  assert_int_equal(1, find_available(0,4, (bool []){false,true,true,true}));
  assert_int_equal(-1, find_available(3,4, (bool []){false}));
  assert_int_equal(-1, find_available(1,4, (bool []){false,false,false}));
  assert_int_equal(1, find_available(1,4, (bool []){false,true,true}));
  assert_int_equal(1, find_available(2,4, (bool []){false,true}));
  assert_int_equal(1, find_available(0,4, (bool []){false,false,true,false}));
  assert_int_equal(-1, find_available(2,4, (bool []){false,false}));
  assert_int_equal(-1, find_available(1,4, (bool []){false,false,false}));

}
static void test_find_solution(void **state) {
assert_int_equal(true, _find_solution(4,1,(int[]){3}, (bool []){true,true,true,false}));
assert_int_equal(true, _find_solution(4,2,(int[]){2}, (bool []){true,true,false,true}));
assert_int_equal(true, _find_solution(4,3,(int[]){3}, (bool []){true,true,true,false}));
assert_int_equal(true, _find_solution(4,0,(int[]){}, (bool []){true,true,true,true}));


}




int main(void) {
  int result = 0;
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_same_diagonal),
      cmocka_unit_test(test_check_same_column), 
      cmocka_unit_test(test_check_row_available),
      cmocka_unit_test(test_find_solution),
  };
  result |= cmocka_run_group_tests_name("queens", tests, NULL, NULL);

  return result;
}
