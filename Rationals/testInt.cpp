#include <iostream>
#include <string>
#include "Integer.h"


using namespace cosc326;
using namespace std;


int main(void) {

    // Test default Constructor
    Integer first;

    std::string first_print = first.toString();
    printf("%s\n", first_print.c_str());

    // Test constructor passing in another instance

    Integer second(first);

    std::string second_print = second.toString();
    printf("%s\n", second_print.c_str());


    // Test string constructor
    Integer third("1");

    std::string third_print = third.toString();
    printf("%s\n", third_print.c_str());

    // Test assigment

    third = second;
    third_print = third.toString();
    printf("%s\n", third_print.c_str());


    // Test -
    Integer i("5");
    Integer j = -i;

    Integer k = -j;


    std::string j_print = j.toString();
    printf("j: %s\n", j_print.c_str());

    std::string k_print = k.toString();
    printf("k: %s\n", k_print.c_str());

    // Test addition
    Integer plus = i + third;

    Integer x("10");
    Integer y("2");
    Integer plus2 = x + y;

    std::string plus_print = plus.toString();
    printf("plus: %s\n", plus_print.c_str());

    std::string plus2_print = plus2.toString();
    printf("plus2: %s\n", plus2_print.c_str());

    std::string i_print = i.toString();
    printf("i: %s\n", i_print.c_str());

    // Test subtraction
    Integer subtract = x - y;
    Integer subtract2 = y - x;

    std::string subtract_print = subtract.toString();
    printf("x - y: %s\n", subtract_print.c_str());

    std::string subtract2_print = subtract2.toString();
    printf("y - x: %s\n", subtract2_print.c_str());


    // Testing +=
    x += y;

    std::string plusEquals_print = x.toString();
    printf("x += y: %s\n", plusEquals_print.c_str());

    // Testing -=
    x = Integer("10");

    plusEquals_print = y.toString();
    printf("y: %s\n", plusEquals_print.c_str());

    plusEquals_print = x.toString();
    printf("x: %s\n", plusEquals_print.c_str());

    x -= y;

    plusEquals_print = x.toString();
    printf("x -= y: %s\n", plusEquals_print.c_str());

    //cout << "first = " << first << '\n';


}