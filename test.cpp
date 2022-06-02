#include <iostream>
#include <string>
#include "Integer.h"

using namespace cosc326;
using namespace std;

int main(void) {
    Integer first = Integer(5);
    Integer second = Integer(10);
    Integer fifth = Integer(20);
    Integer copy = Integer(fifth);

    std::string fifth_print = fifth.toString();
    printf("%s\n", fifth_print.c_str());

    std::string copy_value = copy.toString();
    printf("%s\n", copy_value.c_str());

    fifth = Integer();
    fifth_print = fifth.toString();
    printf("%s\n", fifth_print.c_str());

    Integer result = first + second;

    Integer result2 = first * second;

    Integer third = Integer("50");
    Integer forth = 25;

    if (third > forth) {
        printf("Correct\n");
    } else {
        printf("Incorrect\n");
    }

    std::string result_print = result.toString();
    printf("%s\n", result_print.c_str());

    Integer divide = third / forth;
    Integer moddy = third % forth;

    std::string divide_string = divide.toString();
    std::string moddy_string = moddy.toString();

    printf("%s\n", divide_string.c_str());
    printf("%s\n", moddy_string.c_str());

    Integer big = 875;
    Integer small = 9;

    Integer mod2 = big % small;

    std::string mod_result = mod2.toString();
    printf("%s\n", mod_result.c_str());

    if (big != small) {
        printf("Doesn't match, good job\n");
    } else {
        printf("Fix this\n");
    }

    if (big == big) {
        printf("Match\n");
    } else {
        printf("Matchmate\n");
    }

    Integer divide1 = 85;
    Integer divide2 = 9;

    Integer divde_result = divide1 / divide2;

    std::string divde_string_result = divde_result.toString();

    printf("%s\n", divde_string_result.c_str());

    Integer negtive_value = -50;
    Integer positive_value = +50;

    Integer sub = negtive_value - positive_value;

    std::string sub_result = sub.toString();

    printf("%s\n", sub_result.c_str());

    std::string print_negative = negtive_value.toString();
    printf("%s\n", print_negative.c_str());

    Integer default_value = Integer();

    std::string default_print = default_value.toString();
    printf("%s\n", default_print.c_str());

    Integer gcd_value = gcd_value.gcd(big, divide2);
    std::string gcd_string = gcd_value.toString();

    printf("%s\n", gcd_string.c_str());
    return 0;
}