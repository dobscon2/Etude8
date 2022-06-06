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
    Rational stringCon5 = Rational("2.10/5");
    Rational stringCon6 = Rational("2.10/10");
    Rational stringCon7 = Rational("10/10");
    Rational stringCon8 = Rational("-3.1/2");
    Rational stringCon9 = Rational("0.1/3");
    Rational stringCon10 = Rational("-3.2/4");
    Rational stringCon11 = Rational("4/3");
    Rational stringCon12 = Rational("+15.32/2");

    Rational rat5 = Rational("1/4");

    Rational ratAddition = stringCon + rat5;

    Rational ratAddition2 = stringCon4 + stringCon3;

    cout << "String 1/2 = " << stringCon << "\n";
    cout << "String 5/10 = " << stringCon2 << "\n";
    cout << "String 2.1/2 = " << stringCon3 << "\n";
    cout << "String 2.5/10 = " << stringCon4 << "\n";
    cout << "String 2.10/5 = " << stringCon5 << "\n";
    cout << "String 2.10/10 = " << stringCon6 << "\n";
    cout << "String 10/10 = " << stringCon7 << "\n";
    cout << "String -3.1/2 = " << stringCon8 << "\n";
    cout << "String 0.1/3 = " << stringCon9 << "\n";
    cout << "String -3.2/4 = " << stringCon10 << "\n";
    cout << "String 4/3 = " << stringCon11 << "\n";
    cout << "String +15.32/2 = " << stringCon12 << "\n";


    // Testing addition
    Rational add1 = Rational("1/2") + Rational("1/2");
    cout << "Add 1/2 + 1/2 = " << add1 << "\n";




    cout << "1/2 + 1/4 = " << ratAddition << "\n";
    cout << "2.5/10 + 2.1/2 = " << ratAddition2 << "\n";

}