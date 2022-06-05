#include <iostream>
#include <string>
#include "Rational.h"
#include "Integer.h"


using namespace cosc326;
using namespace std;


int main(void) {
    // Testing constructors

    Rational defal = Rational();

    Rational stringCon = Rational("1/2");
    Rational stringCon2 = Rational("1/2.5");
    Rational stringCon3 = Rational("2.5");

    cout << "default = " << defal << "\n";
    cout << "String 1/2 = " << stringCon << "\n";
    cout << "String 1/2.5 = " << stringCon2 << "\n";
    cout << "String 2.5 = " << stringCon3 << "\n";



}