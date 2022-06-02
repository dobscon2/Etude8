#ifndef COSC326_RATIONAL_H_
#define COSC326_RATIONAL_H_

#include <vector>
#include <iostream>
#include <map>
#include <bits/stdc++.h>
#include "Integer.h"

using namespace std;

namespace cosc326
{
class Rational{
	public:
		Rational();
		Rational(string);
		Rational(Integer);
		Rational(Integer, Integer);
		Rational(Integer, Integer, Integer);
		Rational(const Rational&);
		Rational add(const Rational&);
		Rational subtract(const Rational&);
		Rational multiply(const Rational&);
		Rational divide(const Rational&);
		void toString();
		void printDecimal();
		void reduce();
		Integer numerator;
		Integer denominator;
}

}

#endif