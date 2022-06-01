#ifndef COSC326_RATIONAL_H_
#define COSC326_RATIONAL_H_

#include <vector>
#include <iostream>
#include <map>
#include <bits/stdc++.h>

using namespace std;

namespace cosc326
{
class Rational{
	public:
		Rational();
		Rational(string);
		Rational(int);
		Rational(long long);
		Rational operator + (Rational);
		Rational operator += (Rational);
		Rational & operator ++();
		Rational operator ++(int);
		Rational operator - (Rational);
		Rational operator -= (Rational);
		Rational & operator --();
		Rational operator --(int);
		Rational operator * (Rational);
		Rational operator *= (Rational);
		Rational operator / (Rational);
		Rational operator /= (Rational);
		Rational operator % (Rational);
		Rational operator %= (Rational);
		unsigned int & operator[](int);
		void operator = (Rational);
		bool operator == (Rational);
		bool operator != (Rational);
		bool operator < (Rational);
		bool operator <= (Rational);
		bool operator > (Rational);
		bool operator >= (Rational);
};
}

#endif