
// Most compilers understand the once pragma, but just in case...
#ifndef INTEGER_H_INCLUDED
#define INTEGER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


namespace cosc326 {

	class Integer {

	public:

		Integer();                             // Integer i;
		Integer(const Integer& i);             // Integer j(i);
		Integer(const std::string& s);         // Integer k("123");

		~Integer();

		Integer& operator=(const Integer& i);  // j = i;

		// Unary operators
		Integer operator-() const;                   // -j;
		Integer operator+() const;                   // +j;

		// Arithmetic assignment operators
		Integer& operator+=(const Integer& i); // j += i;
		Integer& operator-=(const Integer& i); // j -= i;
		Integer& operator*=(const Integer& i); // j *= i;
		Integer& operator/=(const Integer& i); // j /= i;
		Integer& operator%=(const Integer& i); // j %= i;

		// lhs < rhs -- a 'friend' means operator isn't a member, but can access the private parts of the class.
		// You may need to make some other functions friends, but do so sparingly.
		friend bool operator<(const Integer& lhs, const Integer& rhs);
		bool isPositive();
		std::vector<unsigned int> value;
		std::string toString();
		void addLeadingZeros(int);
		std::vector<unsigned int> length;
		void makePositiveIfZero();
		void removeLeadingZeros();
		int getLength();
		void readString(std::string);
		bool mutable positive;
		bool absLesser(Integer &);
		bool absGreater(Integer &);
		void trim();
	private:
		// Can add internal storage or methods here
        //std::vector<int> value;	
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

	// Binary operators
	Integer operator+(const Integer& lhs, const Integer& rhs); // lhs + rhs;
	Integer operator-(const Integer& lhs, const Integer& rhs); // lhs - rhs;
	Integer operator*(const Integer& lhs, const Integer& rhs); // lhs * rhs;
	Integer operator/(const Integer& lhs, const Integer& rhs); // lhs / rhs;
	Integer operator%(const Integer& lhs, const Integer& rhs); // lhs % rhs;

	std::ostream& operator<<(std::ostream& os, const Integer& i);  // std::cout << i << std::endl;
	std::istream& operator>>(std::istream& is, Integer& i);        // std::cin >> i;

	bool operator> (const Integer& lhs, const Integer& rhs); // lhs > rhs
	bool operator<=(const Integer& lhs, const Integer& rhs); // lhs <= rhs
	bool operator>=(const Integer& lhs, const Integer& rhs); // lhs >= rhs
	bool operator==(const Integer& lhs, const Integer& rhs); // lhs == rhs
	bool operator!=(const Integer& lhs, const Integer& rhs); // lhs != rhs

	Integer gcd(const Integer& a, const Integer& b);  // i = gcd(a, b);
}

#endif
