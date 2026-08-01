#include <unity.h>
#include <logger.h>
#include <main.h>
#include <string.h>

void setUp(void) {}

// ********************* UTILS *********************
void test_MAX(void)
{
    TEST_ASSERT_EQUAL(1, MAX(0, 1));
    TEST_ASSERT_EQUAL(5, MAX(1, 5));
    TEST_ASSERT_EQUAL(121, MAX(121, -121));
}

void test_D_MAX(void)
{
    TEST_ASSERT_EQUAL(1.5, D_MAX(0.2, 1.5));
    TEST_ASSERT_EQUAL(5.6, D_MAX(1.7, 5.6));
    TEST_ASSERT_EQUAL(121.1, D_MAX(121.1, -121.1));
}

void test_F_MAX(void)
{
    TEST_ASSERT_EQUAL(1.5f, F_MAX(0.2f, 1.5f));
    TEST_ASSERT_EQUAL(5.6f, F_MAX(1.7f, 5.6f));
    TEST_ASSERT_EQUAL(121.1f, F_MAX(121.1f, -121.1f));
}

void test_MIN(void)
{
    TEST_ASSERT_EQUAL(-1, MIN(-1, 1));
    TEST_ASSERT_EQUAL(2, MIN(26, 2));
    TEST_ASSERT_EQUAL(-29, MIN(0, -29));
}

void test_D_MIN(void)
{
    TEST_ASSERT_EQUAL(-1.6, D_MIN(-1.6, 1.0));
    TEST_ASSERT_EQUAL(26.0, D_MIN(26.0, 26.1));
    TEST_ASSERT_EQUAL(-29.0, D_MIN(29.0, -29.0));
}

void test_F_MIN(void)
{
    TEST_ASSERT_EQUAL(-1.6f, F_MIN(-1.6f, 1.0f));
    TEST_ASSERT_EQUAL(26.0f, F_MIN(26.0f, 26.1f));
    TEST_ASSERT_EQUAL(-29.0f, F_MIN(29.0f, -29.0f));
}

void test_ABS(void)
{
    TEST_ASSERT_EQUAL(1, ABS(1));
    TEST_ASSERT_EQUAL(1, ABS(-1));
    TEST_ASSERT_EQUAL(0, ABS(0));
}

void test_D_ABS(void)
{
    TEST_ASSERT_EQUAL(1.2, D_ABS(1.2));
    TEST_ASSERT_EQUAL(1.6, D_ABS(-1.6));
    TEST_ASSERT_EQUAL(0.0, D_ABS(0.0));
}

void test_F_ABS(void)
{
    TEST_ASSERT_EQUAL(1.2f, F_ABS(1.2f));
    TEST_ASSERT_EQUAL(1.6f, F_ABS(-1.6f));
    TEST_ASSERT_EQUAL(0.0f, F_ABS(0.0f));
}
// ********************* UTILS *********************

// ********************* MAIN *********************
void test_tea_party(void)
{
    TEST_ASSERT_EQUAL(1, tea_party(6, 8));
    TEST_ASSERT_EQUAL(0, tea_party(3, 8));
    TEST_ASSERT_EQUAL(2, tea_party(20, 6));
}

void test_fizz_string(void)
{
    TEST_ASSERT_EQUAL_STRING("Fizz", fizz_string("fig"));
    TEST_ASSERT_EQUAL_STRING("Buzz", fizz_string("dib"));
    TEST_ASSERT_EQUAL_STRING("FizzBuzz", fizz_string("fib"));
    TEST_ASSERT_EQUAL_STRING("hello", fizz_string("hello"));
}

void test_fizz_string2(void)
{
    TEST_ASSERT_FALSE(strcmp("1!", fizz_string2(1)));
    TEST_ASSERT_FALSE(strcmp("2!", fizz_string2(2)));
    TEST_ASSERT_FALSE(strcmp("Fizz!", fizz_string2(3)));
}

void test_two_as_one(void)
{
    TEST_ASSERT_TRUE(two_as_one(1, 2, 3));
    TEST_ASSERT_TRUE(two_as_one(3, 1, 2));
    TEST_ASSERT_FALSE(two_as_one(3, 2, 2));
}

void test_in_order(void)
{
    TEST_ASSERT_TRUE(in_order(1, 2, 4, FALSE));
    TEST_ASSERT_FALSE(in_order(1, 2, 1, FALSE));
    TEST_ASSERT_TRUE(in_order(1, 1, 2, TRUE));
}

void test_in_order_equal(void)
{
    TEST_ASSERT_TRUE(in_order_equal(2, 5, 11, FALSE));
    TEST_ASSERT_FALSE(in_order_equal(5, 7, 6, FALSE));
    TEST_ASSERT_TRUE(in_order_equal(5, 5, 7, TRUE));
}

void test_last_digit(void)
{
    TEST_ASSERT_TRUE(last_digit(25, 75, 30));
    TEST_ASSERT_FALSE(last_digit(45, 23, 30));
    TEST_ASSERT_TRUE(last_digit(25, 25, 30));
}

void test_less_by_10(void)
{
    TEST_ASSERT_TRUE(less_by_10(1, 2, 11));
    TEST_ASSERT_FALSE(less_by_10(1, 2, 3));
    TEST_ASSERT_TRUE(less_by_10(1, 12, 0));
}

void test_without_doubles(void)
{
    TEST_ASSERT_EQUAL(5, without_doubles(2, 3, TRUE));
    TEST_ASSERT_EQUAL(7, without_doubles(3, 3, TRUE));
    TEST_ASSERT_EQUAL(6, without_doubles(3, 3, FALSE));
}

void test_max_mod5(void)
{
    TEST_ASSERT_EQUAL(3, max_mod5(2, 3));
    TEST_ASSERT_EQUAL(6, max_mod5(6, 2));
    TEST_ASSERT_EQUAL(3, max_mod5(3, 2));
}

void test_red_ticket(void)
{
    TEST_ASSERT_EQUAL(10, red_ticket(2, 2, 2));
    TEST_ASSERT_EQUAL(0, red_ticket(2, 2, 1));
    TEST_ASSERT_EQUAL(5, red_ticket(0, 0, 0));
}

void test_green_ticket(void)
{
    TEST_ASSERT_EQUAL(0, green_ticket(1, 2, 3));
    TEST_ASSERT_EQUAL(20, green_ticket(2, 2, 2));
    TEST_ASSERT_EQUAL(10, green_ticket(1, 1, 2));
}

void test_to_binary(void)
{
    char* TEST1 = to_binary(27);
    char* TEST2 = to_binary(1);
    char* TEST3 = to_binary(32);

    TEST_ASSERT_EQUAL_STRING("11011", TEST1);
    TEST_ASSERT_EQUAL_STRING("1", TEST2);
    TEST_ASSERT_EQUAL_STRING("100000", TEST3);

    free(TEST1);
    free(TEST2);
    free(TEST3);
}

void test_sum67(void)
{
    const int TEST_ARR1[] = {1, 2, 2};
    const int TEST_ARR2[] = {1, 2, 2, 6, 99, 99, 7};
    const int TEST_ARR3[] = {1, 1, 6, 7, 2};
    const int TEST_ARR4[] = {6, 7, 2};
    const int TEST_ARR5[] = {1, 6, 7, 6, 7};
    const int TEST_ARR6[] = {1, 6, 7, 2, 6, 99, 7};
    const int TEST_ARR7[] = {1, 6, 99, 7, 7};
    const int TEST_ARR8[] = {6, 7, 7};

    TEST_ASSERT_EQUAL(5, sum67(TEST_ARR1, sizeof(TEST_ARR1) / sizeof(TEST_ARR1[0])));
    TEST_ASSERT_EQUAL(5, sum67(TEST_ARR2, sizeof(TEST_ARR2) / sizeof(TEST_ARR2[0])));
    TEST_ASSERT_EQUAL(4, sum67(TEST_ARR3, sizeof(TEST_ARR3) / sizeof(TEST_ARR3[0])));
    TEST_ASSERT_EQUAL(2, sum67(TEST_ARR4, sizeof(TEST_ARR4) / sizeof(TEST_ARR4[0])));
    TEST_ASSERT_EQUAL(1, sum67(TEST_ARR5, sizeof(TEST_ARR5) / sizeof(TEST_ARR5[0])));
    TEST_ASSERT_EQUAL(3, sum67(TEST_ARR6, sizeof(TEST_ARR6) / sizeof(TEST_ARR6[0])));
    TEST_ASSERT_EQUAL(8, sum67(TEST_ARR7, sizeof(TEST_ARR7) / sizeof(TEST_ARR7[0])));
    TEST_ASSERT_EQUAL(7, sum67(TEST_ARR8, sizeof(TEST_ARR8) / sizeof(TEST_ARR8[0])));
}

void test_has22(void)
{
    const int TEST_ARR1[] = {1, 2, 2};
    const int TEST_ARR2[] = {1, 2, 1, 2, 5, 7};
    const int TEST_ARR3[] = {1, 1, 2};
    
    TEST_ASSERT_TRUE(has22(TEST_ARR1, sizeof(TEST_ARR1) / sizeof(TEST_ARR1[0])));
    TEST_ASSERT_FALSE(has22(TEST_ARR2, sizeof(TEST_ARR2) / sizeof(TEST_ARR2[0])));
    TEST_ASSERT_FALSE(has22(TEST_ARR3, sizeof(TEST_ARR3) / sizeof(TEST_ARR3[0])));
}

void test_lucky13(void)
{
    const int TEST_ARR1[] = {0, 2, 4};
    const int TEST_ARR2[] = {1, 2, 3};
    const int TEST_ARR3[] = {1, 2, 4};

    TEST_ASSERT_TRUE(lucky13(TEST_ARR1, sizeof(TEST_ARR1) / sizeof(TEST_ARR1[0])));
    TEST_ASSERT_FALSE(lucky13(TEST_ARR2, sizeof(TEST_ARR2) / sizeof(TEST_ARR2[0])));
    TEST_ASSERT_FALSE(lucky13(TEST_ARR3, sizeof(TEST_ARR3) / sizeof(TEST_ARR3[0])));
}

void test_sum28(void)
{
    const int TEST_ARR1[] = {2, 3, 2, 2, 4, 2};
    const int TEST_ARR2[] = {2, 3, 2, 2, 4, 2, 2};
    const int TEST_ARR3[] = {1, 2, 3, 4};

    TEST_ASSERT_TRUE(sum28(TEST_ARR1, sizeof(TEST_ARR1) / sizeof(TEST_ARR1[0])));
    TEST_ASSERT_FALSE(sum28(TEST_ARR2, sizeof(TEST_ARR2) / sizeof(TEST_ARR2[0])));
    TEST_ASSERT_FALSE(sum28(TEST_ARR3, sizeof(TEST_ARR3) / sizeof(TEST_ARR3[0])));
}

void test_more14(void)
{
    const int TEST_ARR1[] = {1, 4, 1};
    const int TEST_ARR2[] = {1, 4, 1, 4};
    const int TEST_ARR3[] = {1, 1};

    TEST_ASSERT_TRUE(more14(TEST_ARR1, sizeof(TEST_ARR1) / sizeof(TEST_ARR1[0])));
    TEST_ASSERT_FALSE(more14(TEST_ARR2, sizeof(TEST_ARR2) / sizeof(TEST_ARR2[0])));
    TEST_ASSERT_TRUE(more14(TEST_ARR3, sizeof(TEST_ARR3) / sizeof(TEST_ARR3[0])));
}

void test_fizz_array(void)
{
    int* TEST1 = fizz_array(4);
    int* TEST2 = fizz_array(1);
    int* TEST3 = fizz_array(10);

    const int TEST1_EXPECTED[] = {0, 1, 2, 3};
    const int TEST2_EXPECTED[] = {0};
    const int TEST3_EXPECTED[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // TEST1
    for (int i = 0; i < 4; i++)
        TEST_ASSERT_EQUAL(TEST1_EXPECTED[i], TEST1[i]);

    // TEST2
    TEST_ASSERT_EQUAL(TEST2_EXPECTED[0], TEST2[0]);

    // TEST3
    for (int i = 0; i < 10; i++)
        TEST_ASSERT_EQUAL(TEST3_EXPECTED[i], TEST3[i]);
    
    free(TEST1);
    free(TEST2);
    free(TEST3);
}

void test_only14(void)
{
    const int TEST_ARR1[] = {1, 4, 1, 4};
    const int TEST_ARR2[] = {1, 4, 2, 4};
    const int TEST_ARR3[] = {1, 1};
    
    TEST_ASSERT_TRUE(only14(TEST_ARR1, sizeof(TEST_ARR1) / sizeof(TEST_ARR1[0])));
    TEST_ASSERT_FALSE(only14(TEST_ARR2, sizeof(TEST_ARR2) / sizeof(TEST_ARR2[0])));
    TEST_ASSERT_TRUE(only14(TEST_ARR3, sizeof(TEST_ARR3) / sizeof(TEST_ARR3[0])));
}

void test_fizz_array2(void)
{
    char** TEST1 = fizz_array2(4);
    char** TEST2 = fizz_array2(1);
    char** TEST3 = fizz_array2(10);
    
    const char TEST1_EXPECTED[4][2] = {"0", "1", "2", "3"};
    const char TEST2_EXPECTED[1][2] = {"0"};
    const char TEST3_EXPECTED[10][2] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    
    // TEST1
    for (int i = 0; i < 4; i++)
    {
        TEST_ASSERT_EQUAL(strcmp(TEST1_EXPECTED[i], TEST1[i]), 0);
        free(TEST1[i]);
    }
    
    // TEST2
    TEST_ASSERT_EQUAL(strcmp(TEST2_EXPECTED[0], TEST2[0]), 0);
    free(TEST2[0]);
    
    // TEST3
    for (int i = 0; i < 10; i++)
    {
        TEST_ASSERT_EQUAL(strcmp(TEST3_EXPECTED[i], TEST3[i]), 0);
        free(TEST3[i]);
    }
    
    free(TEST1);
    free(TEST2);
    free(TEST3);
}

void test_no14(void)
{
    const int TEST_ARR1[] = {1, 2, 3};
    const int TEST_ARR2[] = {1, 2, 3, 4};
    const int TEST_ARR3[] = {2, 3, 4};
    
    TEST_ASSERT_TRUE(no14(TEST_ARR1, sizeof(TEST_ARR1) / sizeof(TEST_ARR1[0])));
    TEST_ASSERT_FALSE(no14(TEST_ARR2, sizeof(TEST_ARR2) / sizeof(TEST_ARR2[0])));
    TEST_ASSERT_TRUE(no14(TEST_ARR3, sizeof(TEST_ARR3) / sizeof(TEST_ARR3[0])));
}

void test_is_everywhere(void)
{
    const int TEST_ARR1[] = {1, 2, 1, 3};
    const int TEST_ARR2[] = {1, 2, 1, 3};
    const int TEST_ARR3[] = {1, 2, 1, 3, 4};

    TEST_ASSERT_TRUE(is_everywhere(TEST_ARR1, 1, sizeof(TEST_ARR1) / sizeof(TEST_ARR1[0])));
    TEST_ASSERT_FALSE(is_everywhere(TEST_ARR2, 2, sizeof(TEST_ARR2) / sizeof(TEST_ARR2[0])));
    TEST_ASSERT_FALSE(is_everywhere(TEST_ARR3, 1, sizeof(TEST_ARR3) / sizeof(TEST_ARR3[0])));
}

void test_either24(void)
{
    const int TEST_ARR1[] = {1, 2, 2};
    const int TEST_ARR2[] = {4, 4, 1};
    const int TEST_ARR3[] = {4, 4, 1, 2, 2};

    TEST_ASSERT_TRUE(either24(TEST_ARR1, sizeof(TEST_ARR1) / sizeof(TEST_ARR1[0])));
    TEST_ASSERT_TRUE(either24(TEST_ARR2, sizeof(TEST_ARR2) / sizeof(TEST_ARR2[0])));
    TEST_ASSERT_FALSE(either24(TEST_ARR3, sizeof(TEST_ARR3) / sizeof(TEST_ARR3[0])));
}

void test_match_up(void)
{
    const int TEST_ARR11[] = {1, 2, 3};
    const int TEST_ARR12[] = {2, 3, 10};
    
    const int TEST_ARR21[] = {1, 2, 3};
    const int TEST_ARR22[] = {2, 3, 5};
    
    const int TEST_ARR31[] = {1, 2, 3};
    const int TEST_ARR32[] = {2, 3, 3};
    
    TEST_ASSERT_EQUAL(match_up(TEST_ARR11, TEST_ARR12, sizeof(TEST_ARR11) / sizeof(TEST_ARR11[0])), 2);
    TEST_ASSERT_EQUAL(match_up(TEST_ARR21, TEST_ARR22, sizeof(TEST_ARR21) / sizeof(TEST_ARR21[0])), 3);
    TEST_ASSERT_EQUAL(match_up(TEST_ARR31, TEST_ARR32, sizeof(TEST_ARR31) / sizeof(TEST_ARR31[0])), 2);
}

void test_has77(void)
{
    const int TEST_ARR1[] = {1, 7, 7};
    const int TEST_ARR2[] = {1, 7, 1, 7};
    const int TEST_ARR3[] = {1, 7, 1, 1, 7};

    TEST_ASSERT_TRUE(has77(TEST_ARR1, sizeof(TEST_ARR1) / sizeof(TEST_ARR1[0])));
    TEST_ASSERT_TRUE(has77(TEST_ARR2, sizeof(TEST_ARR2) / sizeof(TEST_ARR2[0])));
    TEST_ASSERT_FALSE(has77(TEST_ARR3, sizeof(TEST_ARR3) / sizeof(TEST_ARR3[0])));
}

void test_has12(void)
{
    const int TEST_ARR1[] = {1, 3, 2};
    const int TEST_ARR2[] = {3, 1, 2};
    const int TEST_ARR3[] = {3, 1, 4, 5, 2};
    const int TEST_ARR4[] = {1};

    TEST_ASSERT_TRUE(has12(TEST_ARR1, sizeof(TEST_ARR1) / sizeof(TEST_ARR1[0])));
    TEST_ASSERT_TRUE(has12(TEST_ARR2, sizeof(TEST_ARR2) / sizeof(TEST_ARR2[0])));
    TEST_ASSERT_TRUE(has12(TEST_ARR3, sizeof(TEST_ARR3) / sizeof(TEST_ARR3[0])));
    TEST_ASSERT_FALSE(has12(TEST_ARR4, sizeof(TEST_ARR4) / sizeof(TEST_ARR4[0])));
}

void test_mod_three(void)
{
    const int TEST_ARR1[] = {2, 1, 3, 5};
    const int TEST_ARR2[] = {2, 1, 2, 5};
    const int TEST_ARR3[] = {2, 4, 2, 5};

    TEST_ASSERT_TRUE(mod_three(TEST_ARR1, sizeof(TEST_ARR1) / sizeof(TEST_ARR1[0])));
    TEST_ASSERT_FALSE(mod_three(TEST_ARR2, sizeof(TEST_ARR2) / sizeof(TEST_ARR2[0])));
    TEST_ASSERT_TRUE(mod_three(TEST_ARR3, sizeof(TEST_ARR3) / sizeof(TEST_ARR3[0])));
}

void test_have_three(void)
{
    const int TEST_ARR1[] = {3, 1, 3, 1, 3};
    const int TEST_ARR2[] = {3, 1, 3, 3};
    const int TEST_ARR3[] = {3, 4, 3, 3, 4};

    TEST_ASSERT_TRUE(have_three(TEST_ARR1, sizeof(TEST_ARR1) / sizeof(TEST_ARR1[0])));
    TEST_ASSERT_FALSE(have_three(TEST_ARR2, sizeof(TEST_ARR2) / sizeof(TEST_ARR2[0])));
    TEST_ASSERT_FALSE(have_three(TEST_ARR3, sizeof(TEST_ARR3) / sizeof(TEST_ARR3[0])));
}

void test_two_two(void)
{
    const int TEST_ARR1[] = {4, 2, 2, 3};
    const int TEST_ARR2[] = {2, 2, 4};
    const int TEST_ARR3[] = {2, 2, 4, 2};

    TEST_ASSERT_TRUE(two_two(TEST_ARR1, sizeof(TEST_ARR1) / sizeof(TEST_ARR1[0])));
    TEST_ASSERT_TRUE(two_two(TEST_ARR2, sizeof(TEST_ARR2) / sizeof(TEST_ARR2[0])));
    TEST_ASSERT_FALSE(two_two(TEST_ARR3, sizeof(TEST_ARR3) / sizeof(TEST_ARR3[0])));
}// ********************* MAIN *********************

void tearDown(void) {}

int main(void)
{
    UNITY_BEGIN();
    
    RUN_TEST(test_MAX);
    RUN_TEST(test_D_MAX);
    RUN_TEST(test_F_MAX);
    RUN_TEST(test_MIN);
    RUN_TEST(test_D_MIN);
    RUN_TEST(test_F_MIN);
    RUN_TEST(test_ABS);
    RUN_TEST(test_D_ABS);
    RUN_TEST(test_F_ABS);
    RUN_TEST(test_tea_party);
    RUN_TEST(test_fizz_string);
    RUN_TEST(test_fizz_string2);
    RUN_TEST(test_two_as_one);
    RUN_TEST(test_in_order);
    RUN_TEST(test_in_order_equal);
    RUN_TEST(test_last_digit);
    RUN_TEST(test_less_by_10);
    RUN_TEST(test_without_doubles);
    RUN_TEST(test_max_mod5);
    RUN_TEST(test_red_ticket);
    RUN_TEST(test_green_ticket);
    RUN_TEST(test_to_binary);
    RUN_TEST(test_sum67);
    RUN_TEST(test_has22);
    RUN_TEST(test_lucky13);
    RUN_TEST(test_sum28);
    RUN_TEST(test_more14);
    RUN_TEST(test_fizz_array);
    RUN_TEST(test_only14);
    RUN_TEST(test_fizz_array2);
    RUN_TEST(test_no14);
    RUN_TEST(test_is_everywhere);
    RUN_TEST(test_either24);
    RUN_TEST(test_match_up);
    RUN_TEST(test_has77);
    RUN_TEST(test_has12);
    RUN_TEST(test_mod_three);
    RUN_TEST(test_have_three);
    RUN_TEST(test_two_two);

    return UNITY_END();
}
