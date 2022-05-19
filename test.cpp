#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Integer.cpp"

using namespace cosc326;

int main()
{
    Integer first("12345");
    cout << "The number of digits"
         << " in first big integer = "
         << Length(first) << '\n';
    Integer second(12345);
    if (first == second)
    {
        cout << "first and second are equal!\n";
    }
    else
        cout << "Not equal!\n";
    Integer third("10000");
    Integer fourth("100000");
    if (third < fourth)
    {
        cout << "third is smaller than fourth!\n";
    }
    Integer fifth("10000000");
    if (fifth > fourth)
    {
        cout << "fifth is larger than fourth!\n";
    }

    // Printing all the numbers
    cout << "first = " << first << '\n';
    cout << "second = " << second << '\n';
    cout << "third = " << third << '\n';
    cout << "fourth = " << fourth << '\n';
    cout << "fifth = " << fifth << '\n';

    // Incrementing the value of first
    first++;
    cout << "After incrementing the"
         << " value of first is : ";
    cout << first << '\n';
    Integer sum;
    sum = (fourth + fifth);
    cout << "Sum of fourth and fifth = "
         << sum << '\n';
    Integer product;
    product = second * third;
    cout << "Product of second and third = "
         << product << '\n';
}