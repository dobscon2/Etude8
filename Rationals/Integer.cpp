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
		Integer temp = *this;
		if(temp.isPositive() == true){
			temp.positive = false;
		} else {
			temp.positive = true;
		}
		
		return Integer(temp);
	}

	Integer Integer::operator+() const {
		return Integer(*this);
	}

	Integer& Integer::operator+=(const Integer& i) {
		*this = (*this + i);
		return *this;
	}

	Integer& Integer::operator-=(const Integer& i) {
		//Integer temp = *this;
		if(this->positive == true){
			this->positive = false;
		} else {
			this->positive = true;
		}
		*this = (*this + i);
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
		if(lhsTemp.isPositive() != rhsTemp.isPositive()){
			if(lhsTemp.value.size() != rhsTemp.value.size()){
				if(lhsTemp.value.size() > rhsTemp.value.size()){
					return (lhsTemp - rhsTemp);
				}else{
					return (rhsTemp - lhsTemp);
				}
			}else{
				for(int i = lhsTemp.value.size()-1; i>=0; i--){
					if(lhsTemp.value[i] == rhsTemp.value[i]) continue;
					if(lhsTemp.value[i] > rhsTemp.value[i]) return (lhsTemp - rhsTemp);
					return (rhsTemp - lhsTemp);
				}
				return Integer();
			}
		}

		if(lhsTemp.value.size() < rhsTemp.value.size()) std::swap(lhsTemp,rhsTemp);
		int i = 0, carry = 0, sum;
		lhsTemp.addLeadingZeros(1);
		for(; i < lhsTemp.getLength(); i++){
			sum = lhsTemp.value[i] + rhsTemp.value[i] + carry;
			carry = sum/10;
			lhsTemp.value[i] = sum%10;
			if(i+1 == rhsTemp.value.size() && ++i) break;
		}
		while(carry)
			sum = lhsTemp.value[i] + carry,
			lhsTemp.value[i++] = sum%10, carry = sum/10;

		lhsTemp.removeLeadingZeros();
		lhsTemp.makePositiveIfZero();
		return lhsTemp;
		
	}

	Integer operator-(const Integer& lhs, const Integer& rhs) {
		Integer lhsTemp = lhs;
		Integer rhsTemp = rhs;
		//if(lhsTemp.value < rhsTemp.value)
        	//throw("UNDERFLOW");
		/*
		lhsTemp.addLeadingZeros(1);
		for(int i = 0; i<lhsTemp.value.size(); i++){
			if(lhsTemp.value[i] < rhsTemp.value[i]){
				for(int j = i+1; j<lhsTemp.value.size(); j++){
					if(lhsTemp.value[j]){
						lhsTemp.value[j] = lhsTemp.value[j] - 1;
						break;
					}else{
						lhsTemp.value[j] = 9;
					}
				}
				int val1 = lhsTemp.value[i]+10, val2 = rhsTemp.value[i];
				lhsTemp.value[i] = val1-val2;
				if(i+1==rhsTemp.value.size()) break;
			}else{
				lhsTemp.value[i] = lhsTemp.value[i] - rhsTemp.value[i];
				if(i+1==rhsTemp.value.size()) break;
			}
		}
		lhsTemp.removeLeadingZeros();
		lhsTemp.makePositiveIfZero();
		return lhsTemp;
		*/
		int n = lhsTemp.value.size(), m = rhsTemp.value.size();
		int i, t = 0, s;
		for (i = 0; i < n;i++){
			if(i < m)
				s = lhsTemp.value[i] - rhsTemp.value[i]+ t;
			else
				s = lhsTemp.value[i]+ t;
			if(s < 0)
				s += 10,
				t = -1;
			else
				t = 0;
			lhsTemp.value[i] = s;
		}
		while(n > 1 && lhsTemp.value[n - 1] == 0)
			lhsTemp.value.pop_back(),
			n--;
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
		Integer temp = i;
		if(!temp.isPositive()) std::cout<<"-";
		for(int y = 0; y < temp.getLength(); y++){
			os<<temp.value[y];
		}
		return os;
	}

	std::istream& operator>>(std::istream& is, Integer& i) {
		Integer temp = i;
		std::string str;
		is>>str;
		temp.readString(str);
		return is;
		}

	bool operator<(const Integer& lhs, const Integer& rhs) {
		Integer tempLhs = lhs;
		Integer tempRhs = rhs;

		int n = tempLhs.getLength(), m = tempRhs.getLength();
    	if(n != m)
        	return n < m;
   		while(n--)
        	if(tempLhs.value[n] != tempRhs.value[n])
            	return tempLhs.value[n] < tempRhs.value[n];
    	return false;
		//return true;
	}

	bool operator> (const Integer& lhs, const Integer& rhs) {
		return rhs < lhs;
	}

	bool operator<=(const Integer& lhs, const Integer& rhs) {
		return !(lhs > rhs);
	}

	bool operator>=(const Integer& lhs, const Integer& rhs) {
		return !(lhs < rhs);
	}

	bool operator==(const Integer& lhs, const Integer& rhs) {
		Integer lhsTemp = lhs;
		Integer rhsTemp = rhs;
		return (lhsTemp.value == rhsTemp.value && lhsTemp.isPositive() == rhsTemp.isPositive());
	}

	bool operator!=(const Integer& lhs, const Integer& rhs) {
		return !(lhs == rhs);
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
