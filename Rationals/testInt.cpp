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
    printf("%s\n", j_print.c_str());

    std::string k_print = k.toString();
    printf("%s\n", k_print.c_str());


}