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

const int tea_party(const int tea, const int candy);
const char *fizz_string(const char *str);
const char *fizz_string2(const int n);
const BOOL two_as_one(
    const int a,
    const int b,
    const int c
);
const BOOL in_order(
    const int a,
    const int b,
    const int c,
    BOOL bOk
);
const BOOL in_order_equal(
    const int a,
    const int b,
    const int c,
    BOOL equal_ok
);
const BOOL last_digit(
    const int a,
    const int b,
    const int c
);
const BOOL less_by_10(
    const int a,
    const int b,
    const int c
);
const int without_doubles(
    const int die1,
    const int die2,
    const BOOL no_doubles
);
const int max_mod5(const int a, const int b);
const int red_ticket(
    const int a,
    const int b,
    const int c
);
const int green_ticket(
    const int a,
    const int b,
    const int c
);
char* to_binary(unsigned int n);
const int sum67(const int* nums, const int size);
const BOOL has22(const int* nums, const int size);
#endif // MAIN_H