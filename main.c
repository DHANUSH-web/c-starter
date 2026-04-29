#include <string.h>
#include <stdio.h>
#include <logger/logger.h>
#include <math.h>

#define MAX_BITS 64

// BEGIN: MAIN UTILS

int MAX(const int a, const int b)
{
    return a > b ? a : b;
}

double D_MAX(const double a, const double b)
{
    return a > b ? a : b;
}

float F_MAX(const float a, const float b)
{
    return a > b ? a : b;
}

int MIN(const int a, const int b)
{
    return a < b ? a : b;
}

double D_MIN(const double a, const double b)
{
    return a < b ? a : b;
}

float F_MIN(const float a, const float b)
{
    return a < b ? a : b;
}

int ABS(const int a)
{
    return a < 0 ? -a : a;
}

double D_ABS(const double a)
{
    return a < 0 ? -a : a;
}

float F_ABS(const float a)
{
    return a < 0 ? -a : a;
}

// ============ BLACK HOLE ============

// Universal CONSTANTS in SI units
const double G = 6.67430e-11;           // Gravitational constant (m^3 kg^-1 s^-2)
const long int C = 299792458;           // Speed of light (m/s)
const double SOLAR_MASS = 1.98847e30;   // Mass of our sun (kg)

// #define G 6.67430e-11           // Gravitational constant (m^3 kg^-1 s^-2)
// #define C 299792458.0           // Speed of light (m/s)
// #define SOLAR_MASS 1.98847e30   // Mass of our sun (kg)

// convert mass from kg to solar mass
double to_solar_mass(const double mass_kg)
{
    return mass_kg / SOLAR_MASS;
}

// convert mass from solar mass to kg
double to_kg(const double solar_masses)
{
    return solar_masses * SOLAR_MASS;
}

/*
    Logic1: Mass from Orbital Data (Keplerian)
    This is the "Measurement" method. You can calculate the mass if you know how fast a star
    is moving (v) at a certain distance (r)

    v = velocity in ms
    r = radius in `m`

    M = (v^2 * r) / G
*/
double mass_from_orbit(const double r, const double v)
{
    const double mass_kg = ((v * v) * r) / G;
    return mass_kg;
}

/*
    Logic2: Radius from MASS (Schwarzschild)
    If you already have the mass in solar masses, you can calculate the radius of event horizon,
    and you can calculate how much big the black hole actually is

    Rs = (2 * G * M) / C^2
    Rs = schwarzschild radius
    G = gravitational constant
    M = Mass of black hole in kg
    C = speed of light
*/
double get_schwarzschild_radius(const double mass_kg)
{
    const double sr = (2 * G * mass_kg) / (double)(C * C);
    return sr;
}

/*
    Logic3: Time dilation (interstellar effect)
    This method can be used to calculate how much the time got slowed near a certain distance

    t0 = tf * { 1 - (Rs / r) }
*/
double calculate_time_dilation(const double mass_kg, const double distance_r, const double time_seconds)
{
    const double sr = get_schwarzschild_radius(mass_kg);

    if (distance_r <= sr)
    {
        return -1.0;
    }

    const double time_dilation = time_seconds * sqrt( 1 - ( sr / distance_r ) );
    return time_dilation;
}

// ============ BLACK HOLE ============

// END: MAIN_UTILS

const int tea_party(const int tea, const int candy)
{
    return (tea < 5 || candy < 5) ? 0 : (tea >= candy * 2 || candy >= tea * 2) ? 2 : 1;
}

const char *fizz_string(const char *str)
{
    const size_t size = strlen(str);

    if (str[0] == 'f' && str[size - 1] == 'b')
        return "FizzBuzz";
    if (str[0] == 'f')
        return "Fizz";
    if (str[size - 1] == 'b')
        return "Buzz";

    return str;
}

const char *fizz_string2(const int n)
{
    if (n % 3 == 0 && n % 5 == 0)
        return "FizzBuzz!";
    if (n % 3 == 0)
        return "Fizz!";
    if (n % 5 == 0)
        return "Buzz!";

    char *buffer = malloc(20);
    sprintf(buffer, "%d", n);
    strcat(buffer, "!");

    return buffer;
}

const BOOL two_as_one(const int a, const int b, const int c)
{
    return a + b == c || a + c == b || b + c == a;
}

const BOOL in_order(
    const int a,
    const int b,
    const int c,
    BOOL bOk)
{
    return (bOk || b > a) && c > b;
}

const BOOL in_order_equal(
    const int a,
    const int b,
    const int c,
    const BOOL equal_ok)
{
    return (equal_ok && a <= b && b <= c) || (a < b && b < c);
}

const BOOL last_digit(const int a, const int b, const int c)
{
    return a % 10 == b % 10 || b % 10 == c % 10 || a % 10 == c % 10;
}

const BOOL less_by_10(const int a, const int b, const int c)
{
    return abs(a - b) >= 10 || abs(b - c) >= 10 || abs(a - c) >= 10;
}

const int without_doubles(const int die1, const int die2, const BOOL no_doubles)
{
    return no_doubles && die1 == die2 ? (die1 == 6 ? 1 : die1 + 1) + die2 : die1 + die2;
}

const int max_mod5(const int a, const int b)
{
    return a == b ? 0 : a % 5 == b % 5 ? MIN(a, b) : MAX(a, b);
}

const int red_ticket(const int a, const int b, const int c)
{
    return a == 2 && b == 2 && c == 2 ? 10 : a == b && b == c ? 5 : a != b && a != c ? 1 : 0;
}

const int green_ticket(const int a, const int b, const int c)
{
    return a == b && b == c ? 20 : a == b || a == c || b == c ? 10 : 0;
}

const char* to_binary(unsigned int n)
{
    char* bits = malloc(MAX_BITS + 1);

    if (!bits) return NULL;

    bits[MAX_BITS] = '\0';
    int i = MAX_BITS - 1;

    do
    {
        bits[i--] = (char)((n & 1) + '0');
        n >>= 1;
    } while (n);

    memmove(bits, bits + i + 1, MAX_BITS - i + 2);
    return bits;
}

const int sum67(const int* nums, const int size)
{
    int sum = 0;
    BOOL skip = FALSE;

    for (int i = 0; i < size; i++)
    {
        if (nums[i] == 6) skip = TRUE;
        else if (nums[i] == 7 && skip) skip = FALSE;
        else if (!skip) sum += nums[i];
    }

    return sum;
}

const BOOL has22(const int* nums, const int size)
{
    for (int i = 0; i < size; i++)
        if (nums[i] == 2 && nums[i+1] == 2)
            return TRUE;
    return FALSE;
}

const BOOL lucky13(const int* nums, const int size)
{
    for (int i = 0; i < size; i++)
        if (nums[i] == 1 || nums[i] == 3)
            return FALSE;

    return TRUE;
}

const BOOL sum28(const int* nums, const int size)
{
    int sum = 0;
    
    for (int i = 0; i < size; i++)
        if (nums[i] == 2)
            sum += nums[i];
    
    return sum == 8;
}

const BOOL more14(const int* nums, const int size)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (nums[i] == 1) count++;
        if (nums[i] == 4) count--;
    }

    return count > 0;
}

#ifndef UNIT_TEST
int main()
{
    // printf("Run `./build test` to test your logic!!\n");

    // BLACK HOLE SIMULATION

    // printf("Black Hole Simulation\n");

    // const char* BH = "Sagittarius A*";
    // const double mass_kg = mass_from_orbit(1e9, 2e7);
    // const double solar_masses = to_solar_mass(mass_kg);
    // const double sr = get_schwarzschild_radius(mass_kg);

    // printf("Black Hole: %s\n", BH);
    // printf("Mass of Black Hole: %f KG\n", mass_kg);
    // printf("Mass of Black Hole: %f SM\n", solar_masses);
    // printf("Schwarzschild Radius: %f M\n", sr);
    // BLACK HOLE SIMULATION

    printf("Run `mac test` to test your logic!!\n");
    return 0;
}
#endif
