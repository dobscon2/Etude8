#include <iostream>
#include <string>
#include "Rational.h"
#include "Integer.h"


using namespace cosc326;
using namespace std;


int main(void) {
    // Testing constructors

    Rational defal = Rational();
    cout << "default = " << defal << "\n";



    Rational stringCon = Rational("1/2");
    Rational stringCon2 = Rational("5/10");
    Rational stringCon3 = Rational("2.1/2");
    Rational stringCon4 = Rational("2.5/10");

    cout << "String 1/2 = " << stringCon << "\n";
    cout << "String 5/10 = " << stringCon2 << "\n";
    cout << "String 2.1/2 = " << stringCon3 << "\n";
    cout << "String 2.5/10 = " << stringCon4 << "\n";




}