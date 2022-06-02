#ifndef COSC326_INTEGER_H_
#define COSC326_INTEGER_H_

#include <vector>
#include <iostream>
#include <map>
//#include <bits/stdc++.h>

using namespace std;

namespace cosc326
{
class Integer{
	public:
		// Constructors
		Integer();
		Integer(string);
		Integer(int);
		Integer(long long);

		// Destructor
		~Integer();

		Integer operator + (Integer);
		Integer operator += (Integer);
		Integer & operator ++();
		Integer operator ++(int);
		Integer operator - (Integer);
		Integer operator -= (Integer);
		Integer & operator --();
		Integer operator --(int);
		Integer operator * (Integer);
		Integer operator *= (Integer);
		Integer operator / (Integer);
		Integer operator /= (Integer);
		Integer operator % (Integer);
		Integer operator %= (Integer);
		Integer gcd(Integer, Integer);
		unsigned int & operator[](int);
		void operator = (Integer);
		bool operator == (Integer);
		bool operator != (Integer);
		bool operator < (Integer);
		bool operator <= (Integer);
		bool operator > (Integer);
		bool operator >= (Integer);
		void print();
		int length();
		bool isPositive();
		bool absGreater(Integer &);
		bool absLesser(Integer &);
		void readString(string);
		string toString();
		void addToTheBeginning(int val, int cant = 1);
		pair<Integer,Integer> resultAndRemainder(Integer);
		Integer ZERO() const;
		Integer ONE() const;
		vector<unsigned int> value;
	private:
		bool positive;
		void addLeadingZeros(int);
		void removeLeadingZeros();
		void makePositiveIfZero();
		unsigned int & getValueAt(int);
		Integer addition(Integer ,Integer );
		Integer substraction(Integer, Integer &);
		Integer multiplication(Integer, Integer);
		Integer longMultiplication(Integer &, Integer &);
		Integer karatsubaMultiplication(Integer&, Integer&);
		Integer division(Integer &, Integer &);
		Integer longDivision(Integer, Integer &);
		Integer mod(Integer, Integer&);
};
}

#endif