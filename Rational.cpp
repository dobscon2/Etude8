#include "Integer.h"
#include "Rational.h"
#include <iostream>
#include <string>

using namespace std;

namespace cosc326
{

    Rational::Rational()
    {
        this->numerator = 0;
        this->denominator = 0;
    }

    Rational::Rational(Integer a)
    {
        this->numerator = a;
        this->denominator = 0;
    }

    Rational::Rational(Integer a, Integer b)
    {
        this->numerator = a;
        this->denominator = b;
    }

    Rational::Rational(Integer a, Integer b, Integer c)
    {
        // a + b/c
    }

    Rational::Rational(const Rational &i)
    {
        this->numerator = i.numerator;
        this->denominator = i.denominator;
    }

    Rational::Rational(string Value)
    {
        // parse String
    }

    Rational Rational::add(const Rational& a) {
        Rational t;

        t.numerator = a.numerator * denominator + a.denominator * numerator;
        t.denominator = a.denominator * denominator;

        if (denominator != 0) {
            t.reduce();
        }

        return t;
    }

    Rational Rational::subtract(const Rational& s) {
        Rational t;

        t.numerator = s.denominator * numerator - denominator * s.numerator;
        t.denominator = s.denominator * denominator;

        if (denominator != 0) {
            t.reduce();
        }

        return t;
    }

    Rational Rational::multiply(const Rational& m) {
        Rational t;

        t.numerator = m.numerator * numerator;
        t.denominator = m.denominator * denominator;

        if (denominator != 0) {
            t.reduce();
        }

        return t;
    }

    Rational Rational::divide(const Rational& v) {
        Rational t;

        t.numerator = v.denominator * numerator;
        t.denominator = denominator * v.numerator;

        if (denominator != 0) {
            t.reduce();
        }

        return t;
    }

    void Rational::toString() {
        if (denominator == 0) {
            cout << end1 << "Can't divide by zero" << end1;
        } else if (numerator == 0) {
            cout << 0;
        } else {
            cout << numerator << "/" << denominator;
        }
    }

    void Rational::printDecimal() {
        if (denominator == 0) {
            cout << end1 << "Can't divide by zero" << end1;
        } else {
            cout << float(numerator) / float(denominator);
        }
    }

    void Rational::reduce()
    {
        Integer n = numerator < 0 ? -numerator : numerator;
        Integer d = denominator;
        Integer largest = n > d ? n : d;

        Integer gcd = gcd.gcd(n, d);

        if (gcd != 0)
        {
            numerator /= gcd;
            denominator /= gcd;
        }
    }

}