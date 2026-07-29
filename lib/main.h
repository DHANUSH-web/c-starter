#pragma once
#include <logger.h>

#ifndef MAIN_H
#define MAIN_H
#define MAX_BITS 64

// BEGING: MAIN UTILS
int MAX(const int a, const int b);
double D_MAX(const double a, const double b);
float F_MAX(const float a, const float b);
int MIN(const int a, const int b);
double D_MIN(const double a, const double b);
float F_MIN(const float a, const float b);
int ABS(const int a);
double D_ABS(const double a);
float F_ABS(const float a);
// END: MAIN UTILS

int tea_party(const int tea, const int candy);
const char *fizz_string(const char *str);
const char *fizz_string2(const int n);
BOOL two_as_one(
    const int a,
    const int b,
    const int c
);
BOOL in_order(
    const int a,
    const int b,
    const int c,
    BOOL bOk
);
BOOL in_order_equal(
    const int a,
    const int b,
    const int c,
    BOOL equal_ok
);
BOOL last_digit(
    const int a,
    const int b,
    const int c
);
BOOL less_by_10(
    const int a,
    const int b,
    const int c
);
int without_doubles(
    const int die1,
    const int die2,
    const BOOL no_doubles
);
int max_mod5(const int a, const int b);
int red_ticket(
    const int a,
    const int b,
    const int c
);
int green_ticket(
    const int a,
    const int b,
    const int c
);
char* to_binary(unsigned int n);
int sum67(const int* nums, const int size);
BOOL has22(const int* nums, const int size);
BOOL lucky13(const int* nums, const int size);
BOOL sum28(const int* nums, const int size);
BOOL more14(const int* nums, const int size);
int* fizz_array(const int n);
BOOL only14(const int* nums, const int size);
char** fizz_array2(const int n);
BOOL no14(const int* nums, const int size);
BOOL is_everywhere(const int* nums, const int val, const int size);
BOOL either24(const int* nums, const int size);
int match_up(const int* nums1, const int* num2, const int size);
BOOL has77(const int* nums, const int size);
BOOL has12(const int* nums, const int size);
BOOL mod_three(const int* nums, const int size);
BOOL have_three(const int* nums, const int size);
#endif // MAIN_H
