#include "Integer.h"

namespace cosc326 {

	Integer::Integer() {
		number = {};
	}

	Integer::Integer(const Integer& i) {
		number = i.number;
		negative = i.negative;
	}

	Integer::Integer(const std::string& s) {
		initialize(s);
	}


	Integer::~Integer() {
	
	}

	unsigned int Integer::size() const {
		return number.size();
	}

	void Integer::initialize(std::string source) {
		number.resize(source.size());
		for (unsigned int i = 0; i < source.size(); i++) {
			number.at(i) = source.at(i) - '0';
		}

		if (source == "0") {
			number = {};
		}
		return;
	}

	std::string Integer::toString() {
		std::string result;
		for (int i : this->number) {
			result += std::to_string(i);
		}
		return result;
	}

	Integer& Integer::operator=(const Integer& i) {
		number = i.number;
		return *this;
	}

	Integer Integer::operator-() const {
		return Integer(*this);
	}

	Integer Integer::operator+() const {
		return Integer(*this);
	}

	Integer& Integer::operator+=(const Integer& i) {
		Integer top = i;
		int min = this->size();

		if (top.size() > min) {
			min = top.size();
		}

		int max = this->size();
		if (top.size() > max) {
			max = top.size();
		}

		std::reverse(this->number.begin(), this->number.end());
		std::reverse(top.number.begin(), top.number.end());

		if (top.size() < max) {
			while (top.size() < max) {
				top.number.push_back(0);
			}
		} else if (this->size() < max) {
			while (this->size() < max) {
				this->number.push_back(0);
			}
		}

		Integer sum;
		sum.number = std::vector<int>(max+1, 0);

		for (int index = 0; index < max; index++) {
			sum.number.at(index) = top.number.at(index) + this->number.at(index);
		}

		for (int index = 0; index < max; index++) {
			if (sum.number.at(index) > 9) {
				sum.number.at(index) -= 10;
				sum.number.at(index + 1) += 1;
			}
		}

		for (int index = max; index >= 0; index--) {
			if (sum.number.at(index) != 0) {
				break;
			} else {
				sum.number.pop_back();
			}
		}

		std::reverse(sum.number.begin(), sum.number.end());
		this->number = sum.number;
		return *this;
	}

	Integer& Integer::operator-=(const Integer& i) {
		Integer result;

    	// sets the upper bar to the larger number
    	Integer upper = *this;
    	Integer lower = i;

    	if (lower > upper) {
        	result.negative = true;
        	upper = i;
        	lower = *this;
    	}

    	// reverse the upper and lower bars, so we can iterate left to right
    	std::reverse( upper.number.begin(), upper.number.end() );
    	std::reverse( lower.number.begin(), lower.number.end() );

    	// goes through each digit, subtraction (may get negative digits here, like {4, 3, -2, -5, 4})
    	for (int index = 0; index < lower.size(); index++) {
        	result.number.push_back(upper.number.at(index) - lower.number.at(index));
    	}

    	// adds any extra digits
    	for (int index = lower.size(); index < upper.size(); index++) {
        	result.number.push_back(upper.number.at(index));
    	}

    	// deals with negatives by subtracting from the digit over
    	for (int index = 0; index < result.size(); index++) {
        	if (result.number.at(index) < 0) {
            	result.number.at(index+1) -= 1;
            	result.number.at(index) += 10;
        	}
    	}

    	// removes any extra zeros
    	while (result.size() != 0 && result.number.at(result.size()-1) == 0) {
        	result.number.pop_back();
    	}

    	// if the result is zero, ensure the number is empty
    	if (result.size() == 0) {
        	result.number = {};
    	}

    	// reverse back to normal
    	std::reverse( result.number.begin(), result.number.end() );

    	this->number = result.number;  // set this number to the result number
    	return *this;
	}

	Integer& Integer::operator*=(const Integer& i) {
		return *this;
	}

	Integer& Integer::operator/=(const Integer& i) {
		return *this;
	}

	Integer& Integer::operator%=(const Integer& i) {
		return *this;
	}

	Integer operator+(const Integer& lhs, const Integer& rhs) {
		Integer lhsTemp = lhs;
		Integer rhsTemp = rhs;
		lhsTemp += rhsTemp;
		return lhsTemp;
	}

	Integer operator-(const Integer& lhs, const Integer& rhs) {
		Integer lhsTemp = lhs;
		Integer rhsTemp = rhs;

		lhsTemp -= rhsTemp;
		return lhsTemp;
	}

	Integer operator*(const Integer& lhs, const Integer& rhs) {
		return lhs;
	}

	Integer operator/(const Integer& lhs, const Integer& rhs) {
		return lhs;
	}

	Integer operator%(const Integer& lhs, const Integer& rhs) {
		return lhs;
	}


	std::ostream& operator<<(std::ostream& os, const Integer& i) {
		return os;
	}

	std::istream& operator>>(std::istream& is, Integer& i) {
		return is;
	}

	bool operator<(const Integer& lhs, const Integer& rhs) {
		return true;
	}

	bool operator> (const Integer& lhs, const Integer& rhs) {
		return true;
	}

	bool operator<=(const Integer& lhs, const Integer& rhs) {
		return true;
	}

	bool operator>=(const Integer& lhs, const Integer& rhs) {
		return true;
	}

	bool operator==(const Integer& lhs, const Integer& rhs) {
		return true;
	}

	bool operator!=(const Integer& lhs, const Integer& rhs) {
		return true;
	}


	Integer gcd(const Integer& a, const Integer& b) {
		return a;
	}

}
