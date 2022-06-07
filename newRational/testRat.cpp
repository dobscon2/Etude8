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
    Rational stringCon4 = Rational("2.2/4");
    Rational stringCon5 = Rational("2.10/5");
    Rational stringCon6 = Rational("2.10/10");
    Rational stringCon7 = Rational("10/10");
    Rational stringCon8 = Rational("-3.1/2");
    Rational stringCon9 = Rational("0.1/3");
    Rational stringCon10 = Rational("-3.2/4");
    Rational stringCon11 = Rational("4/3");
    Rational stringCon12 = Rational("+15.32/2");
    Rational stringCon13 = Rational("100/2");
    Rational stringCon14 = Rational("99/2");
    Rational stringCon15 = Rational("249/2");
    Rational stringCon16 = Rational("200/2");
    Rational stringCon17 = Rational("201/2");
    Rational stringCon18 = Rational("0/2");
    Rational stringCon19 = Rational("-2.1/3");
    Rational stringCon20 = Rational("-8/3");

    

    //cout << "String 1/2 = " << stringCon << "\n";
    //cout << "String 5/10 = " << stringCon2 << "\n";
    //cout << "String 2.1/2 = " << stringCon3 << "\n";
    //cout << "String 2.2/4 = " << stringCon4 << "\n";
    //cout << "String 2.10/5 = " << stringCon5 << "\n";
    //cout << "String 2.10/10 = " << stringCon6 << "\n";
    //cout << "String 10/10 = " << stringCon7 << "\n";
    //cout << "String -3.1/2 = " << stringCon8 << "\n";
    //cout << "String 0.1/3 = " << stringCon9 << "\n";
    //cout << "String -3.2/4 = " << stringCon10 << "\n";
    //cout << "String 4/3 = " << stringCon11 << "\n";
    //cout << "String +15.32/2 = " << stringCon12 << "\n";
    cout << "String 100/2 = " << stringCon13 << "\n";
    cout << "String 99/2 = " << stringCon14 << "\n";
    cout << "String 249/2 = " << stringCon15 << "\n";
    cout << "String 200/2 = " << stringCon16 << "\n";
    cout << "String 201/2 = " << stringCon17 << "\n";
    cout << "String 0/2 = " << stringCon18 << "\n";
    cout << "String -2.1/3 = " << stringCon19 << "\n";
    cout << "String -8/3= " << stringCon20 << "\n";


    // Testing addition
    Rational rat5 = Rational("-1/4");

    Rational ratAddition = stringCon + rat5;
    cout << "1/2 + -1/4 = " << ratAddition << "\n";

    Rational add2 = Rational("-1.1/2") + Rational("2.1/2");
    cout << "Add -1.1/2 + 2.1/2 = " << add2 << "\n";


    Rational ratAddition2 = stringCon4 + stringCon3;
    cout << "2.2/4 + 2.1/2 = " << ratAddition2 << "\n";

    Rational add1 = Rational("1/2") + Rational("1/2");
    cout << "Add 1/2 + 1/2 = " << add1 << "\n";


    // Testing Subtraction
    cout << "Subtract\n";
    Rational sub1 = Rational("-1/2") - Rational("1/2");
    cout << "Subtract -1/2 - 1/2 = " << sub1 << "\n";

    Rational sub2 = Rational("3/4") - Rational("-1/4");
    cout << "Subtract 3/4 - -1/4 = " << sub2 << "\n";

    Rational sub3 = Rational("-3/4") - Rational("1/2");
    cout << "Subtract -3/4 - 1/2 = " << sub3 << "\n";

    Rational sub30 = Rational("3/4") - Rational("1/2");
    cout << "Subtract 3/4 - 1/2 = " << sub30 << "\n";

    Rational sub4 = Rational("-2.1/2") - Rational("1.1/2");
    cout << "Subtract -2.1/2 - 1.1/2 = " << sub4 << "\n";

    Rational sub5 = Rational("2.3/4") - Rational("-1.1/4");
    cout << "Subtract 2.3/4 - -1.1/4 = " << sub5 << "\n";

    Rational sub6 = Rational("1.3/4") - Rational("1.1/4");
    cout << "Subtract 1.3/4 - 1.1/4 = " << sub6 << "\n";

    Rational sub7 = Rational("3.3/4") - Rational("1.1/2");
    cout << "Subtract 3.3/4 - 1.1/2 = " << sub7 << "\n";

    // Testing multiplication
    cout << "Multyply\n";
    Rational mult1 = Rational("-1/2") * Rational("1/2");
    cout << "Multyply -1/2 * 1/2 = " << mult1 << "\n";

    Rational mult2 = Rational("3/4") * Rational("-1/4");
    cout << "Multyply 3/4 * -1/4 = " << mult2 << "\n";

    Rational mult3 = Rational("3/4") * Rational("1/2");
    cout << "Multyply 3/4 * 1/2 = " << mult3 << "\n";

    Rational mult4 = Rational("3/4") * Rational("1/2");
    cout << "Multyply 3/4 * 1/2 = " << mult4 << "\n";

    Rational mult5 = Rational("-2.1/2") * Rational("1.1/2");
    cout << "Multyply -2.1/2 * 1.1/2 = " << mult5 << "\n";

    Rational mult6 = Rational("2.3/4") * Rational("-1.1/4");
    cout << "Multyply 2.3/4 * -1.1/4 = " << mult6 << "\n";

    Rational mult7 = Rational("1.3/4") * Rational("1.1/4");
    cout << "Multyply 1.3/4 * 1.1/4 = " << mult7 << "\n";

    Rational mult8 = Rational("3.3/4") * Rational("1.1/2");
    cout << "Multyply 3.3/4 * 1.1/2 = " << mult8 << "\n";

    // Testing Division
    cout << "Dividing\n";
    Rational divid1 = Rational("1/2") / Rational("1/2");
    cout << "Dividing 1/2 / 1/2 = " << divid1 << "\n";

    Rational divid2 = Rational("3/4") / Rational("1/4");
    cout << "Dividing 3/4 / 1/4 = " << divid2 << "\n";

    Rational divid3 = Rational("3/4") / Rational("-1/2");
    cout << "Dividing 3/4 / -1/2 = " << divid3 << "\n";

    Rational divid4 = Rational("3/4") / Rational("1/2");
    cout << "Dividing 3/4 / 1/2 = " << divid4 << "\n";

    Rational divid5 = Rational("2.1/2") / Rational("1.1/2");
    cout << "Dividing 2.1/2 / 1.1/2 = " << divid5 << "\n";

    Rational divid6 = Rational("2.3/4") / Rational("-1.1/4"); // not working
    cout << "Dividing 2.3/4 / -1.1/4 = " << divid6 << "\n";

    Rational divid7 = Rational("-1.3/4") / Rational("1.1/4");
    cout << "Dividing -1.3/4 / 1.1/4 = " << divid7 << "\n";

    Rational divid8 = Rational("3.3/4") / Rational("1.1/2");
    cout << "Dividing 3.3/4 / 1.1/2 = " << divid8 << "\n";

    cout << Rational("-11/5");

/*

    //Comparisons
    if (Rational("3.1/4") > Rational("1/2")) {
        cout << "True - correct\n";
    } else {
        cout << "False - in\n";
    }

    cout << "if (Rational(1/2) < Rational(1/2)){\n";
    if (Rational("1/2") < Rational("1/2")){
        cout << "True - incorrect\n";
    } else {
        cout << "False - correct\n";
    }

    cout << "if (Rational(1/2) > Rational(1/2)){\n";
    if (Rational("1/2") > Rational("1/2")){
        cout << "True - incorrect\n";
    } else {
        cout << "False - correct\n";
    }

    cout << "if (Rational(3/4) > Rational(1/2)){\n";
    if (Rational("3/4") > Rational("1/2")){
        cout << "True - correct\n";
    } else {
        cout << "False - incorrect\n";
    }

    cout << "if (Rational(2.1/2) > Rational(1.1/2)){\n";
    if (Rational("2.1/2") > Rational("1.1/2")){
        cout << "True - correct\n";
    } else {
        cout << "False - incorrect\n";
    }

    cout << "if (Rational(\"2.1/2\") < Rational(\"1.3/4\")){\n";  // Is not working
    if (Rational("2.1/2") < Rational("1.3/4")){
        cout << "True - incorrect\n";
    } else {
        cout << "False - correct\n";
    }

    


    // Testing <= && >=
    cout << "if (Rational(1/2) <= Rational(1/2)){\n";
    if (Rational("1/2") <= Rational("1/2")){
        cout << "True - correct\n";
    } else {
        cout << "False - incorrect\n";
    }

    cout << "if (Rational(\"1/2\") <= Rational(\"3/4\")){\n";
    if (Rational("1/2") <= Rational("3/4")){
        cout << "True - correct\n";
    } else {
        cout << "False - incorrect\n";
    }

    cout << "if (Rational(\"2.1/2\") <= Rational(\"1.3/4\")){\n";  // Is not working
    if (Rational("2.1/2") <= Rational("1.3/4")){
        cout << "True - incorrect\n";
    } else {
        cout << "False - correct\n";
    }

    cout << "if (Rational(\"2.1/2\") <= Rational(\"2.3/4\")){\n";
    if (Rational("2.1/2") <= Rational("2.3/4")){
        cout << "True - correct\n";
    } else {
        cout << "False - incorrect\n";
    }

    cout << "if (Rational(\"2.1/2\") <= Rational(\"5/2\")){\n";
    if (Rational("2.1/2") <= Rational("5/2")){
        cout << "True - correct\n";
    } else {
        cout << "False - incorrect\n";
    }


    cout << "if (Rational(3.1/4) == Rational(1/2)) {\n";
    if (Rational("3.1/4") == Rational("1/2")) {
        cout << "Incorrect - incorrect\n";
    } else {
        cout << "True - correct\n";
    }

    Rational compare3 = Rational("1/4");

    cout << "if (Rational(1/4) < Rational(3.1/4)) {\n";
    if (Rational("1/4") < Rational("3.1/4")) {
        cout << "1 - correct\n";
    } else {
        cout << "0 - incorrect\n";
    }

    Rational divide = Rational("1/4") / Rational("1/2");

    cout << "Divide: " << divide << "\n";

    cout << "if (Rational(1/2) == Rational(1/4)) {\n";
    if (Rational("1/2") == Rational("1/4")) {
        cout << "Yes - incorrect\n";
    } else {
        cout << "No - correct\n";
    }

    cout << "if (Rational(1/2) == Rational(50/100)) {\n";
    if (Rational("1/2") == Rational("50/100")) {
        cout << "Yes - correct\n";
    } else {
        cout << "No - incorrect\n";
    }

    cout << "if (Rational(-1/2) == Rational(50/100)) {\n";
    if (Rational("-1/2") == Rational("50/100")) {
        cout << "Yes - incorrect\n";
    } else {
        cout << "No - correct\n";
    }
    */
}