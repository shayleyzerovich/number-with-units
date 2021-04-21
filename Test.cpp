#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <string>
using namespace ariel;
using namespace std;

ifstream units_file("units.txt");

TEST_CASE(" + and -")
{
    NumberWithUnits::read_units(units_file);

    CHECK_EQ(NumberWithUnits(1, "km") + NumberWithUnits(1, "km"), NumberWithUnits(2, "km"));
    CHECK_EQ(NumberWithUnits(2, "km") + NumberWithUnits(3, "m"), NumberWithUnits(2.003, "km"));
    CHECK_EQ(NumberWithUnits(2, "m") + NumberWithUnits(30, "cm"), NumberWithUnits(2.30, "m"));
    CHECK_EQ(NumberWithUnits(2, "cm") + NumberWithUnits(2, "cm"), NumberWithUnits(4, "cm"));
    CHECK_EQ(NumberWithUnits(3, "kg") + NumberWithUnits(400, "g"), NumberWithUnits(3.4, "kg"));
    CHECK_EQ(NumberWithUnits(3, "ton") + NumberWithUnits(400, "kg"), NumberWithUnits(3.400, "ton"));
    CHECK_EQ(NumberWithUnits(3, "kg") + NumberWithUnits(1, "ton"), NumberWithUnits(1003, "kg"));
    CHECK_EQ(NumberWithUnits(4, "hour") + NumberWithUnits(5, "min"), NumberWithUnits(4.5, "hour"));
    CHECK_EQ(NumberWithUnits(5, "min") + NumberWithUnits(60, "sec"), NumberWithUnits(6, "min"));

    CHECK_EQ(NumberWithUnits(10, "km") - NumberWithUnits(2, "km"), NumberWithUnits(8, "km"));
    CHECK_EQ(NumberWithUnits(9, "km") - NumberWithUnits(500, "m"), NumberWithUnits(8.500, "km"));
    CHECK_EQ(NumberWithUnits(8, "m") - NumberWithUnits(62, "cm"), NumberWithUnits(7.38, "m"));
    CHECK_EQ(NumberWithUnits(7, "m") - NumberWithUnits(1, "m"), NumberWithUnits(6, "m"));
    CHECK_EQ(NumberWithUnits(7, "m") - NumberWithUnits(99, "cm"), NumberWithUnits(6.01, "m"));
    CHECK_EQ(NumberWithUnits(6, "kg") - NumberWithUnits(234, "g"), NumberWithUnits(5.776, "kg"));
    CHECK_EQ(NumberWithUnits(5, "ton") - NumberWithUnits(350, "kg"), NumberWithUnits(4.650, "ton"));
    CHECK_EQ(NumberWithUnits(4, "hour") - NumberWithUnits(15, "min"), NumberWithUnits(3.75, "hour"));

}

TEST_CASE("+=, -=, unary + and -")
{
    NumberWithUnits::read_units(units_file);

    NumberWithUnits test_num1(5, "km");
    NumberWithUnits test_num2(400, "m");
    NumberWithUnits test_num3(5,"km");

    CHECK(test_num3 == test_num1);
    CHECK((test_num1 += test_num2) == NumberWithUnits(5.4, "km"));
    CHECK(test_num1 == NumberWithUnits(5.4, "km"));
    CHECK((test_num2 += test_num1) == NumberWithUnits(5800, "m"));
    CHECK(test_num2 == NumberWithUnits(5800, "m"));
    CHECK((test_num1 -= test_num2) == NumberWithUnits(-0.4, "km"));
    CHECK(test_num1 == NumberWithUnits(-0.4, "km"));
    CHECK((test_num2 -= test_num1) == NumberWithUnits(6200, "m"));
    CHECK(test_num2 == NumberWithUnits(6200, "m"));

    NumberWithUnits test_num4(4, "kg");
    NumberWithUnits test_num5(-13, "m");

    CHECK((+test_num4) == NumberWithUnits(4, "kg"));
    CHECK((-test_num4) == NumberWithUnits(-4, "kg"));
    CHECK((+test_num5) == NumberWithUnits(-13, "m"));
    CHECK((-test_num5) == NumberWithUnits(13, "m"));
}

TEST_CASE(">, >=, <, <=, ==, !=")
{
    NumberWithUnits::read_units(units_file);

    CHECK_GT(NumberWithUnits(10, "min"), NumberWithUnits(8, "min"));
    CHECK_GT(NumberWithUnits(2, "km"), NumberWithUnits(800, "m"));
    CHECK_GE(NumberWithUnits(5, "min"), NumberWithUnits(400, "sec"));
    CHECK_GE(NumberWithUnits(2, "kg"), NumberWithUnits(2000, "g"));
    CHECK_LT(NumberWithUnits(5, "km"), NumberWithUnits(8, "km"));
    CHECK_LT(NumberWithUnits(3, "min"), NumberWithUnits(250, "sec"));
    CHECK_LE(NumberWithUnits(2, "m"), NumberWithUnits(2, "m"));
    CHECK_LE(NumberWithUnits(1, "m"), NumberWithUnits(100, "cm"));
    CHECK_EQ(NumberWithUnits(1, "hour"), NumberWithUnits(60, "min"));
    CHECK_EQ(NumberWithUnits(3, "USD"), NumberWithUnits(9, "ILS"));
    CHECK_NE(NumberWithUnits(30, "min"), NumberWithUnits(30, "sec"));
    CHECK_NE(NumberWithUnits(4, "kg"), NumberWithUnits(2000, "g"));
}

TEST_CASE("before and after ++ and --")
{
    NumberWithUnits::read_units(units_file);

    NumberWithUnits test_num1(6, "km");

    CHECK(test_num1== NumberWithUnits(6, "km"));
    CHECK(++test_num1 == NumberWithUnits(7, "km"));
    CHECK(test_num1 == NumberWithUnits(7, "km"));
    CHECK(test_num1++ == NumberWithUnits(7, "km"));
    CHECK(test_num1 == NumberWithUnits(8, "km"));
    CHECK(test_num1-- == NumberWithUnits(8, "km"));
    CHECK(test_num1 == NumberWithUnits(7, "km"));
    CHECK(--test_num1 == NumberWithUnits(6, "km"));
    CHECK(test_num1 == NumberWithUnits(6, "km"));
}

TEST_CASE("before and after * and *=")
{
    NumberWithUnits::read_units(units_file);

    NumberWithUnits test_num1(4, "USD");
    NumberWithUnits test_num2(10, "m");

    CHECK((test_num1 * 1) == NumberWithUnits(4, "USD"));
    CHECK((test_num1 * 3.5) == NumberWithUnits(14, "USD"));
    CHECK((0.5 * test_num1) == NumberWithUnits(2, "USD"));
    CHECK((10 * test_num1) == NumberWithUnits(40, "USD"));
    
    CHECK((test_num2 *= 1) == NumberWithUnits(10, "m"));
    CHECK((test_num2 *= 2.5) == NumberWithUnits(25, "m"));
    CHECK((test_num2 *= 4) == NumberWithUnits(100, "m"));
    CHECK((test_num2 *= 4) == NumberWithUnits(400, "m"));
    CHECK((test_num2 *= 0.4) == NumberWithUnits(160, "m"));
  
}
