#include <check.h>

#include "calculator.h"

START_TEST(test_add) {
  char str1[256] = "9+8";
  double x = 1;
  double res = 0;
  double reference = 17;
  res = m_proccesing(str1, x);
  ck_assert_double_eq(res, reference);

  char str2[256] = "10+6";
  reference = 16;
  res = m_proccesing(str2, x);
  ck_assert_double_eq(res, reference);

  char str3[256] = "x+4";
  reference = 5;
  res = m_proccesing(str3, x);
  ck_assert_double_eq(res, reference);

  char str4[256] = "x + 4";
  reference = 5;
  res = m_proccesing(str4, x);
  ck_assert_double_eq(res, reference);

  char str5[256] =
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1";
  reference = 128;
  res = m_proccesing(str5, x);
  ck_assert_double_eq(res, reference);
}
END_TEST

START_TEST(test_sub) {
  char str1[256] = "9-8";
  double x = 9;
  double res = 0;
  double reference = 1;
  res = m_proccesing(str1, x);
  ck_assert_double_eq(res, reference);

  char str2[256] = "10-3";
  reference = 7;
  res = m_proccesing(str2, x);
  ck_assert_double_eq(res, reference);

  char str3[256] = "x-4";
  reference = 5;
  res = m_proccesing(str3, x);
  ck_assert_double_eq(res, reference);
}
END_TEST

START_TEST(test_mul) {
  char str1[256] = "18*2";
  double x = 9;
  double res = 0;
  double reference = 36;
  res = m_proccesing(str1, x);
  ck_assert_double_eq(res, reference);

  char str2[256] = "2.5*2";
  reference = 5;
  res = m_proccesing(str2, x);
  ck_assert_double_eq(res, reference);

  char str3[256] = "x*1";
  reference = 9;
  res = m_proccesing(str3, x);
  ck_assert_double_eq(res, reference);
}
END_TEST

START_TEST(test_div) {
  char str1[256] = "18/2";
  double x = 9;
  double res = 0;
  double reference = 9;
  res = m_proccesing(str1, x);
  ck_assert_double_eq(res, reference);

  char str2[256] = "5/5";
  reference = 1;
  res = m_proccesing(str2, x);
  ck_assert_double_eq(res, reference);

  char str3[256] = "x/3";
  reference = 3;
  res = m_proccesing(str3, x);
  ck_assert_double_eq(res, reference);

  char str4[256] = "5/0";
  reference = INFINITY;
  res = m_proccesing(str4, x);
  ck_assert_double_eq(res, reference);
  END_TEST
}

START_TEST(test_fun) {
  char str1[256] = "(cos(2))";
  double x = 9;
  double res = 0;
  double reference = cos(2.0);
  res = m_proccesing(str1, x);
  ck_assert_double_eq(res, reference);

  char str2[256] = "-(cos(2))";
  reference = -cos(2.0);
  res = m_proccesing(str2, x);
  ck_assert_double_eq(res, reference);

  char str3[256] = "(sin(2))";
  reference = sin(2.0);
  res = m_proccesing(str3, x);
  ck_assert_double_eq(res, reference);

  char str4[256] = "-(sin(-2))";
  reference = -sin(-2.0);
  res = m_proccesing(str4, x);
  ck_assert_double_eq(res, reference);

  char str5[256] = "(tan(4))";
  reference = tan(4.0);
  res = m_proccesing(str5, x);
  ck_assert_double_eq(res, reference);

  char str6[256] = "-(tan(4))";
  reference = -tan(4.0);
  res = m_proccesing(str6, x);
  ck_assert_double_eq(res, reference);

  char str7[256] = "(acos(1))";
  reference = acos(1);
  res = m_proccesing(str7, x);
  ck_assert_double_eq(res, reference);

  char str8[256] = "-(acos(1))";
  reference = -acos(1);
  res = m_proccesing(str8, x);
  ck_assert_double_eq(res, reference);

  char str9[256] = "(asin(0))";
  reference = asin(0);
  res = m_proccesing(str9, x);
  ck_assert_double_eq(res, reference);

  char str10[256] = "-(asin(0))";
  reference = -asin(0);
  res = m_proccesing(str10, x);
  ck_assert_double_eq(res, reference);

  char str11[256] = "(atan(0))";
  reference = atan(0);
  res = m_proccesing(str11, x);
  ck_assert_double_eq(res, reference);

  char str12[256] = "-(atan(0))";
  reference = -atan(0);
  res = m_proccesing(str12, x);
  ck_assert_double_eq(res, reference);

  char str13[256] = "(sqrt(4))";
  reference = sqrt(4);
  res = m_proccesing(str13, x);
  ck_assert_double_eq(res, reference);

  char str14[256] = "-(sqrt(9))";
  reference = -sqrt(9);
  res = m_proccesing(str14, x);
  ck_assert_double_eq(res, reference);

  char str15[256] = "(ln(2))";
  reference = log(2);
  res = m_proccesing(str15, x);
  ck_assert_double_eq(res, reference);

  char str16[256] = "-(ln(7))";
  reference = -log(7);
  res = m_proccesing(str16, x);
  ck_assert_double_eq(res, reference);

  char str17[256] = "(log(100))";
  reference = log10(100);
  res = m_proccesing(str17, x);
  ck_assert_double_eq(res, reference);

  char str18[256] = "-(log(1000))";
  reference = -log10(1000);
  res = m_proccesing(str18, x);
  ck_assert_double_eq(res, reference);

  char str19[256] = "12mod10";
  reference = 12 % 10;
  res = m_proccesing(str19, x);
  ck_assert_double_eq(res, reference);

  char str20[256] = "2^2";
  reference = pow(2, 2);
  res = m_proccesing(str20, x);
  ck_assert_double_eq(res, reference);

  char str21[256] = "abc";
  res = m_proccesing(str21, x);
  ck_assert_double_nan(res);

  char str22[256] = "4+()";
  res = m_proccesing(str22, x);
  ck_assert_double_nan(res);

  char str23[256] = "4+(6+5)-5)+5";
  res = m_proccesing(str23, x);
  ck_assert_double_nan(res);

  char str24[256] = "4+(5)5";
  res = m_proccesing(str24, x);
  ck_assert_double_nan(res);

  char str25[256] = "4+";
  res = m_proccesing(str25, x);
  ck_assert_double_nan(res);

  char str26[256] = "*4";
  res = m_proccesing(str26, x);
  ck_assert_double_nan(res);

  char str27[256] = "cos4";
  res = m_proccesing(str27, x);
  ck_assert_double_nan(res);

  char str28[256] = "x4";
  res = m_proccesing(str28, x);
  ck_assert_double_nan(res);

  char str29[256] = "4x";
  res = m_proccesing(str29, x);
  ck_assert_double_nan(res);

  char str30[256] = "4+(5*8";
  res = m_proccesing(str30, x);
  ck_assert_double_nan(res);

  char str31[256] = "4+5.5.5";
  res = m_proccesing(str31, x);
  ck_assert_double_nan(res);

  char str32[256] = "5**4";
  res = m_proccesing(str32, x);
  ck_assert_double_nan(res);

  char str33[256] = "2+(5^(1*2^(2))-4^(2))+5^(2)";
  reference = 636.0;
  res = m_proccesing(str33, x);
  ck_assert_double_eq(res, reference);
}
END_TEST

START_TEST(test_l) {
  char str1[256] = "(cos(2))-(-(cos(2)))-(cos(2))-(-(cos(2)))";
  double x = 9;
  double res = 0;
  double reference = (cos(2)) - (-(cos(2))) - (cos(2)) - (-(cos(2)));
  res = m_proccesing(str1, x);
  ck_assert_double_eq(res, reference);

  char str2[256] = "-x+3";
  reference = -6;
  res = m_proccesing(str2, x);
  ck_assert_double_eq(res, reference);

  char str3[256] = "2*2*2*2";
  reference = 16;
  res = m_proccesing(str3, x);
  ck_assert_double_eq(res, reference);
}
END_TEST

Suite *suit_create(void) {
  Suite *suite = suite_create("Tests of calculator's logic");

  TCase *test_addition = tcase_create("test_addition");
  tcase_add_test(test_addition, test_add);
  suite_add_tcase(suite, test_addition);

  TCase *test_subtraction = tcase_create("test_subtraction");
  tcase_add_test(test_subtraction, test_sub);
  suite_add_tcase(suite, test_subtraction);

  TCase *test_multiplication = tcase_create("test_multiplication");
  tcase_add_test(test_multiplication, test_mul);
  suite_add_tcase(suite, test_multiplication);

  TCase *test_division = tcase_create("test_division");
  tcase_add_test(test_division, test_div);
  suite_add_tcase(suite, test_division);

  TCase *test_functions = tcase_create("test_functions");
  tcase_add_test(test_functions, test_fun);
  suite_add_tcase(suite, test_functions);

  TCase *test_long = tcase_create("test_long");
  tcase_add_test(test_long, test_l);
  suite_add_tcase(suite, test_long);

  return suite;
}

int main(void) {
  Suite *suite = suit_create();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
