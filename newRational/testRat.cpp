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

    Rational rat5 = Rational("1/4");

    Rational ratAddition = stringCon + rat5;

    Rational ratAddition2 = stringCon4 + stringCon3;

    cout << "String 1/2 = " << stringCon << "\n";
    cout << "String 5/10 = " << stringCon2 << "\n";
    cout << "String 2.1/2 = " << stringCon3 << "\n";
    cout << "String 2.5/10 = " << stringCon4 << "\n";

    cout << "1/2 + 1/4 = " << ratAddition << "\n";
    cout << "2.5/10 + 2.1/2 = " << ratAddition2 << "\n";

}