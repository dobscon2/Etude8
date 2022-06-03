#include "Integer.h"


namespace cosc326 {


	// Constructors
	Integer::Integer() {
		this->value.push_back(0);
		positive = true;	
	}

	Integer::Integer(const Integer& i) {
		value = i.value;
		this->positive = i.positive;
	}

	Integer::Integer(const std::string& s) {
		readString(s);
	}


	Integer::~Integer() {
		// Keep Empty
	}


	// Operations
	Integer& Integer::operator=(const Integer& i) {
		this->value = i.value;
		this->positive = i.positive;
		return *this;
	}

	Integer Integer::operator-() const {
		this->positive = !this->positive;
		return Integer(*this);
	}

	Integer Integer::operator+() const {
		return Integer(*this);
	}

	Integer& Integer::operator+=(const Integer& i) {
		return *this;
	}

	Integer& Integer::operator-=(const Integer& i) {
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
		return lhs;
		
	}

	Integer operator-(const Integer& lhs, const Integer& rhs) {
		return lhs;
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

	std::string Integer::toString(){
		std::string ret = "";
		for(int i = this->getLength()-1; i>=0; i--){
			ret += this->value[i]+'0';
		}
		if(!isPositive()) ret = "-" + ret;
		return ret;
	}

	//Added method

	void Integer::addLeadingZeros(int zeros){
		value.resize(value.size()+zeros);
	}

	void Integer::removeLeadingZeros(){
		while(value.back() == 0 && value.size() > 1)
			value.pop_back();
	}

	void Integer::makePositiveIfZero(){
		if(this->value.size()> 1) return;
		if(!this->getValueAt(0)) positive = true;
	}

	unsigned int & Integer::getValueAt(int index){
		return value[index];
	}


	int Integer::getLength(){
	return this->value.size();
	}

	bool Integer::isPositive(){
		return this->positive;
	}

	void Integer::readString(std::string str){
		if(str.empty())return;
		value.clear();
		positive = str[0] != '-';
		for(int i = str.length()-1; i>-1+!positive; i--){
			this->value.push_back(str[i]-'0');
		}
		removeLeadingZeros();
		makePositiveIfZero();
	}



}
