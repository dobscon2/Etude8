#include <iostream>
#include <string>
#include "Integer.h"

using namespace cosc326;
using namespace std;

int main(void) {
    Rational2 frist = Rational2();

    std::string frist_print = frist.toString();
    printf("%s\n", frist_print.c_str());

    return 0;
}