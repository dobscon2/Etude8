#include <string>
#include <sstream>
#include <map>
//#include <bits/stdc++.h>
#include "Integer.h"

using namespace std;

namespace cosc326
{

// Constructors

Integer::Integer(){
	this->value.__emplace_back(0);
	positive = true;	
}

Integer::Integer(string stringValue){
	readString(stringValue);
}

Integer::Integer(int integerValue){
	string stringValue = to_string(integerValue);
	readString(stringValue);
}

Integer::Integer(long long LLValue){
	string stringValue = to_string(LLValue);
	readString(stringValue);
}

// Destructor

Integer::~Integer(){
	std::cout<<"\ndestructor execution";
}

// Relational Operators

bool Integer::operator == (Integer bigNumber){
	bigNumber.removeLeadingZeros();
	if(this->positive != bigNumber.positive) return false;
	if(value.size() != bigNumber.length()) return false;
	for(int i = 0; i<bigNumber.length(); i++){
		if(value[i] != bigNumber.value[i]) return false;
	}
	return true;
}

bool Integer::operator != (Integer bigNumber){
	bigNumber.removeLeadingZeros();
	if(this->positive != bigNumber.positive) return true;
	if(value.size() != bigNumber.length()) return true;
	for(int i = 0; i<bigNumber.length(); i++){
		if(value[i] != bigNumber.value[i]) return true;
	}
	return false;
}

bool Integer::operator < (Integer bigNumber){
	bigNumber.removeLeadingZeros();
	if(!this->positive && !bigNumber.positive){
		if(this->value.size() != bigNumber.value.size()){
			if(this->value.size() > bigNumber.value.size()) return true;
			return false;
		}
		for(int i = this->length()-1; i>=0; i--){
			if(this->value[i] == bigNumber.value[i]) continue;
			if(this->value[i] > bigNumber.value[i]) return true;
		}
		return false;
	}
	if(this->positive != bigNumber.positive){
		if(!this->positive) return true;
		return false;
	}
	if(this->value.size() != bigNumber.value.size()){
		return this->value.size() < bigNumber.value.size();
	}
	for(int i = this->value.size()-1; i>=0; i--){
		if(this->value[i] == bigNumber.value[i]) continue;
		if(this->value[i] < bigNumber.value[i]) return true;
		return false;
	}
	return false;
}

bool Integer::operator <= (Integer bigNumber){
	bigNumber.removeLeadingZeros();
	if(!this->positive && !bigNumber.positive){
		if(this->value.size() != bigNumber.value.size()){
			if(this->value.size() > bigNumber.value.size()) return true;
			return false;
		}
		for(int i = this->length()-1; i>=0; i--){
			if(this->value[i] > bigNumber.value[i]) return true;
			if(this->value[i] == bigNumber.value[i]) continue;
			if(this->value[i] < bigNumber.value[i]) return false;
		}
		return true;
	}
	if(this->positive != bigNumber.positive){
		if(!this->positive && bigNumber.positive) return true;
		return false;
	}
	if(this->value.size() != bigNumber.value.size()){
		if(this->length() < bigNumber.value.size()) return true;
		return false;
	}
	for(int i = this->value.size()-1; i>=0; i--){
		if(this->value[i] < bigNumber.value[i]) return true;
		if(this->value[i] == bigNumber.value[i]) continue;
		return false;
	}
	return true;
}

bool Integer::operator > (Integer bigNumber){
	return !(*this <= bigNumber);
}

bool Integer::operator >= (Integer bigNumber){
	return !(*this < bigNumber);
}

// Arithmetic Operators

Integer Integer::operator + (Integer bigNumber){
	return addition(*this,bigNumber);
}

Integer Integer::operator - (Integer bigNumber){
	bigNumber.positive = !bigNumber.positive;
	return addition(*this, bigNumber);
}

Integer Integer::operator * (Integer bigNumber){
	return multiplication(*this,bigNumber);
}

Integer Integer::operator / (Integer bigNumber){
	return division(*this, bigNumber);
}

Integer Integer::operator % (Integer bigNumber){
	return mod(*this,bigNumber);
}

// Increment and Decrement Operators

Integer Integer::operator ++ (int){
	Integer one("1");
	Integer prevCopy = *this;
	*this = addition(*this,one);
	return prevCopy;
}

Integer & Integer::operator ++ (){
	Integer one("1");
	*this = addition(*this,one);
	return *this;
}

Integer & Integer::operator -- (){
	Integer one("1");
	one.positive = false;
	*this = addition(*this,one);
	return *this;
}

Integer Integer::operator --(int){
	Integer one("1");
	one.positive = false;
	Integer prevCopy = *this;
	*this = addition(*this,one);
	return prevCopy;
}

// Assigment Operators

void Integer::operator = (Integer bigNumber){
	this->value = bigNumber.value;
	this->positive = bigNumber.positive;
}
Integer Integer::operator += (Integer bigNumber){
	*this = addition(*this,bigNumber);
	return *this;
}

Integer Integer::operator -= (Integer bigNumber){
	bigNumber.positive = !bigNumber.positive;
	*this = addition(*this,bigNumber);
	return *this;
}

Integer Integer::operator *= (Integer bigNumber){
	*this =  multiplication(*this,bigNumber);
	return *this;
}

Integer Integer::operator /= (Integer bigNumber){
	*this = *this / bigNumber;
	return *this;
}

Integer Integer::operator %= (Integer bigNumber){
	*this = mod(*this, bigNumber);
	return *this;
}

// Stream Operators

ostream & operator << (ostream &out, Integer Integer){
	if(!Integer.isPositive()) cout<<"-";
	for(int i = 0; i < Integer.length(); i++){
		out<<Integer[i];
	}
	return out;
}

istream & operator >> (istream &in,Integer &Integer){
	string str;
	in>>str;
	Integer.readString(str);
	return in;
}

// Indexed operators

unsigned int & Integer::operator[](int index){
	return this->value[this->length()-1-index];
}

// Functions and methods

int Integer::length(){
	return this->value.size();
}

bool Integer::isPositive(){
	return this->positive;
}

bool Integer::absGreater(Integer &bigNumber){
	if(this->value.size() != bigNumber.value.size())
		return this->value.size() > bigNumber.value.size();
	for(int i = this->value.size()-1; i>=0; i--){
		if(this->value[i] == bigNumber.value[i]) continue;
		if(this->value[i] > bigNumber.value[i]) return true;
		return false;
	}
	return false;
}

bool Integer::absLesser(Integer &bigNumber){
	if(this->value.size() != bigNumber.value.size())
		return this->value.size() < bigNumber.value.size();
	for(int i = this->value.size(); i>=0; i--){
		if(this->value[i] == bigNumber.value[i]) continue;
		if(this->value[i] < bigNumber.value[i]) return true;
		return false;
	}
	return false;
}

void Integer::readString(string str){
	if(str.empty())return;
	value.clear();
	positive = str[0] != '-';
	for(int i = str.length()-1; i>-1+!positive; i--){
		this->value.__emplace_back(str[i]-'0');
	}
	removeLeadingZeros();
	makePositiveIfZero();
}

string Integer::toString(){
	string ret = "";
	for(int i = this->length()-1; i>=0; i--){
		ret += this->value[i]+'0';
	}
	if(!isPositive()) ret = "-" + ret;
	return ret;
}

Integer Integer::ZERO() const{
	return Integer();
}

Integer Integer::ONE() const{
	return Integer("1");
}

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

void Integer::addToTheBeginning(int val, int cant){
	if(cant<=0) return;
	value.resize(value.size()+cant,val);
	for(int i = value.size()-1; i>=cant; i--){
		swap(value[i],value[i-cant]);
	}
}

unsigned int & Integer::getValueAt(int index){
	return value[index];
}

Integer Integer::addition(Integer big1, Integer big2){
	if(big1.isPositive() != big2.isPositive()){
		if(big1.value.size() != big2.value.size()){
			if(big1.value.size() > big2.value.size()){
				return substraction(big1,big2);
			}else{
				return substraction(big2,big1);
			}
		}else{
			for(int i = big1.value.size()-1; i>=0; i--){
				if(big1.value[i] == big2.value[i]) continue;
				if(big1.value[i] > big2.value[i]) return substraction(big1,big2);
				return substraction(big2,big1);
			}
			return Integer();
		}
	}

	if(big1.value.size() < big2.value.size()) swap(big1,big2);
	int i = 0, carry = 0, sum;
	big1.addLeadingZeros(1);
	for(; i < big1.length(); i++){
		sum = big1.value[i] + big2.value[i] + carry;
		carry = sum/10;
		big1.value[i] = sum%10;
		if(i+1 == big2.value.size() && ++i) break;
	}
	while(carry)
		sum = big1.value[i] + carry,
		big1.value[i++] = sum%10, carry = sum/10;

	big1.removeLeadingZeros();
	big1.makePositiveIfZero();
	return big1;
}

Integer Integer::substraction(Integer big1, Integer &big2){
	big1.addLeadingZeros(1);
	for(int i = 0; i<big1.value.size(); i++){
		if(big1.value[i] < big2.value[i]){
			for(int j = i+1; j<big1.value.size(); j++){
				if(big1.value[j]){
					--big1.value[j];
					break;
				}else{
					big1.value[j] = 9;
				}
			}
			int val1 = big1.value[i]+10, val2 = big2.value[i];
			big1.value[i] = val1-val2;
			if(i+1==big2.value.size()) break;
		}else{
			big1.value[i] = big1.value[i] - big2.value[i];
			if(i+1==big2.value.size()) break;
		}
	}
	big1.removeLeadingZeros();
	big1.makePositiveIfZero();
	return big1;
}

Integer Integer::multiplication(Integer big1, Integer big2){
	return karatsubaMultiplication(big1, big2);
}

Integer Integer::division(Integer &dividend, Integer &divisor){
	return longDivision(dividend, divisor);
}

Integer Integer::longMultiplication(Integer &big1, Integer &big2){
	Integer result;
	result.value.resize(big1.value.size()+big2.value.size()+1);
	int i,j,carry = 0, product;
	for(i = 0; i<big1.value.size(); i++){
		carry = 0;
		for(j = 0; j<big2.value.size(); j++){
			product = (big2.value[j]*big1.value[i]) + carry + result.value[i+j];
			carry = product/10;
			result.value[i+j] = product%10;
		}
		while(carry)
			product = result.value[i+j] + carry,
			result.value[i+j] = product%10,
			carry = product/10, ++j;
	}
	result.removeLeadingZeros();
	result.positive = big1.positive == big2.positive;
	makePositiveIfZero();
	return result;
}

Integer Integer::karatsubaMultiplication(Integer &big1, Integer &big2){
	if(big1.value.size() * big2.value.size() < 6000){
		return longMultiplication(big1,big2);
	}
	int splitSize = (max(big1.value.size(), big2.value.size())+1)>>1;
	Integer bigNum1H, bigNum1L, bigNum2H, bigNum2L;
	if(((int)big1.value.size()) - splitSize <= 0){
		bigNum1L.value = big1.value;
	}else{
		bigNum1L.value.assign(big1.value.begin(), big1.value.begin()+splitSize);
		bigNum1H.value.assign(big1.value.begin()+splitSize,big1.value.end());
	}
	if(((int)big2.value.size()) - splitSize <= 0){
		bigNum2L.value = big2.value;
	}else{
		bigNum2L.value.assign(big2.value.begin(), big2.value.begin()+splitSize);
		bigNum2H.value.assign(big2.value.begin()+splitSize,big2.value.end());
	}
	Integer sumA = bigNum1H+bigNum1L, sumB = bigNum2H+bigNum2L;
	Integer A = karatsubaMultiplication(bigNum1H, bigNum2H);
	Integer D = karatsubaMultiplication(bigNum1L, bigNum2L);
	Integer E = karatsubaMultiplication(sumA,sumB) - A - D;
	A.addToTheBeginning(0,splitSize<<1);
	E.addToTheBeginning(0,splitSize);
	Integer result =  A + E + D;
	result.positive = big1.positive == big2.positive;
	result.removeLeadingZeros();
	return result;
}

pair<Integer,Integer> Integer::resultAndRemainder(Integer divisor){
	if(divisor == Integer()){
		cout<<"Mod by zero.\n";
		exit(1);
	};
	Integer dividend = *this;
	if(divisor == Integer()) return make_pair(Integer(), Integer("-1"));
	if(divisor.absGreater(dividend)) return make_pair(Integer(),*this);
	bool dividendSign = dividend.positive, divisorSign = divisor.positive;
	dividend.positive = divisor.positive = true;
	Integer result, subNumber, bigRemainder;
	int dividendLength = dividend.value.size();
	result.value.resize(dividendLength,0);
	while(true){
		dividend.removeLeadingZeros();
		if(dividend.value.size() >= divisor.value.size()){
			int pos = dividend.value.size() - divisor.value.size();
			subNumber.value.assign(dividend.value.begin() + pos, dividend.value.end());
			if(subNumber < divisor){
				if(dividend.value.size() > divisor.value.size()){
					subNumber.value.insert(subNumber.value.begin(), dividend.value[dividend.value.size()-(divisor.value.size()+1)]);
				}else{
					bigRemainder = subNumber;
					break;
				}
			}
		}else{
			bigRemainder = dividend;
			break;
		}
		int quotient = 0, splitSize = subNumber.value.size();
		int indexPosition = (dividendLength-(subNumber.value.size()+(dividendLength-dividend.value.size())));
		while(divisor <= subNumber){
			subNumber-=divisor;
			++quotient;
		}
		bigRemainder = subNumber;
		result.value[indexPosition] = quotient; 
		int leadingNumbersToRemove = splitSize-bigRemainder.value.size();
		while(leadingNumbersToRemove--) dividend.value.pop_back();
		for(int i = 0; i<bigRemainder.value.size(); i++){
			dividend.value[dividend.value.size()-i-1] = bigRemainder.value[bigRemainder.value.size()-1-i];
		}
	}
	result.removeLeadingZeros();
	result.positive = dividendSign == divisorSign;
	return make_pair(result,bigRemainder);
}

Integer Integer::longDivision(Integer dividend, Integer &divisor){
	if(divisor == Integer()){
		cout<<"Division by zero.\n";
		exit(1);
	};
	if(divisor.absGreater(dividend)) return Integer();
	bool dividendSign = dividend.positive, divisorSign = divisor.positive;
	dividend.positive = divisor.positive = true;
	Integer result, subNumber, bigRemainder;
	int dividendLength = dividend.value.size();
	result.value.resize(dividendLength,0);
	while(true){
		dividend.removeLeadingZeros();
		if(dividend.value.size() >= divisor.value.size()){
			int pos = dividend.value.size() - divisor.value.size();
			subNumber.value.assign(dividend.value.begin() + pos, dividend.value.end());
			if(subNumber < divisor){
				if(dividend.value.size() > divisor.value.size()){
					subNumber.value.insert(subNumber.value.begin(), dividend.value[dividend.value.size()-(divisor.value.size()+1)]);
				}else{
					bigRemainder = subNumber;
					break;
				}
			}
		}else{
			bigRemainder = dividend;
			break;
		}
		int quotient = 0, splitSize = subNumber.value.size();
		int indexPosition = (dividendLength-(subNumber.value.size()+(dividendLength-dividend.value.size())));
		while(divisor <= subNumber){
			subNumber-=divisor;
			++quotient;
		}
		bigRemainder = subNumber;
		result.value[indexPosition] = quotient; 
		int leadingNumbersToRemove = splitSize-bigRemainder.value.size();
		while(leadingNumbersToRemove--) dividend.value.pop_back();
		for(int i = 0; i<bigRemainder.value.size(); i++){
			dividend.value[dividend.value.size()-i-1] = bigRemainder.value[bigRemainder.value.size()-1-i];
		}
	}
	result.removeLeadingZeros();
	result.positive = dividendSign == divisorSign;
	return result;
}

Integer Integer::gcd(Integer a, Integer b) {
	if (b == a) {
		return a;
	} else {
		return gcd(b, a%b);
	}
}

Integer Integer::mod(Integer dividend, Integer &divisor){
	if(divisor == Integer()){
		cout<<"Module by zero.\n";
		exit(1);
	}
	if(divisor.absGreater(dividend)) return Integer();
	bool dividendSign = dividend.positive, divisorSign = divisor.positive;
	dividend.positive = divisor.positive = true;
	Integer result, subNumber, bigRemainder;
	int dividendLength = dividend.value.size();
	result.value.resize(dividendLength,0);
	while(true){
		dividend.removeLeadingZeros();
		if(dividend.value.size() >= divisor.value.size()){
			int pos = dividend.value.size() - divisor.value.size();
			subNumber.value.assign(dividend.value.begin() + pos, dividend.value.end());
			if(subNumber < divisor){
				if(dividend.value.size() > divisor.value.size()){
					subNumber.value.insert(subNumber.value.begin(), dividend.value[dividend.value.size()-(divisor.value.size()+1)]);
				}else{
					bigRemainder = subNumber;
					break;
				}
			}
		}else{
			bigRemainder = dividend;
			break;
		}
		int quotient = 0, splitSize = subNumber.value.size();
		int indexPosition = (dividendLength-(subNumber.value.size()+(dividendLength-dividend.value.size())));
		while(divisor <= subNumber){
			subNumber-=divisor;
			++quotient;
		}
		bigRemainder = subNumber;
		result.value[indexPosition] = quotient; 
		int leadingNumbersToRemove = splitSize-bigRemainder.value.size();
		while(leadingNumbersToRemove--) dividend.value.pop_back();
		for(int i = 0; i<bigRemainder.value.size(); i++){
			dividend.value[dividend.value.size()-i-1] = bigRemainder.value[bigRemainder.value.size()-1-i];
		}
	}
	result.removeLeadingZeros();
	result.positive = dividendSign == divisorSign;
	return bigRemainder;
}

}