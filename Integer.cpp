#include "Integer.h"
#include <iostream>
#include <algorithm>

using namespace cosc326;
using namespace std;

cosc326::Integer::Integer(usigned int integer) {
    setInteger(integer);
}

cosc326::Integer::Integer(string integer) {
    for (int i = 0; i < (int)integer.size() && integer[i] >= '0' && integer[i] <= '9'; i++) {
        this->integer += integer[i];
    }

    if (this->integer.size() == 0) {
        this->integer = "0";
    } else {
        this->integer = integer.substr(getTrimIndex(integer));
    }
}

void cosc326::Integer::setInteger(unsigned int integer) {
    if (integer == 0) {
        this->integer = "0";
    }

    while (integer) {
        this->integer = (char)((integer % 10) + '0') + this->integer;
        integer /= 10;
    }
}

void cosc326::Integer::setInteger(string integer) {
    this->integer = integer;
}

unsigned int cosc326::Integer::getIntValue() const {
    unsigned int ret = 0;
    unsigned int biggest = 0xFFFFFFFF;

    for (int i = 0; i < (int) integer.size(); i++) {
        int unit = integer[i] - '0';
        if (ret > (biggest - unit) / 10.0) {
            return 0;
        }
        ret = ret * 10 + unit;
    }
    return ret;
}

string cosc326::Integer::toString() const {
    return integer;
}

Integer cosc326::Integer::addInteger(const Integer& integer_to_add) const {
    int x = max((int)(integer_to_add.toString().size() - toString().size()), 0);
    int y = max((int)(toString().size() - integer_to_add.toString().size()), 0);

    string a = string(x, '0') + toString();
    string b = string(y, '0') + integer_to_add.toString();

    reverse(a.begin(), a.end());
    reverse(b.beign(), b.end());

    string result;
    int carry_value = 0;

    for (int i = 0; i < (int) a.size(); i++) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result += ((char)(sum % 10 + '0'));
        carry = sum / 10;
    }

    if (carry != 0) {
        result += ((char)(carry + '0'));
    }

    reverse(result.begin(), result.end());

    return Integer(result.substr(getTrimIndex(result)));
}

Integer cosc326::Integer::addInteger(const string& integer_to_add) const {
    return addInteger(Integer(integer_to_add));
}

Integer cosc326::Integer::multiplyInteger(const Integer& integer_to_multiply) const {
    string a = integer_to_multiply.toString();
    string b = toString();

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    Integer ret("0");

    for (int i = 0; i < (int) a.size(); i++) {
        int carry = 0;
        string temp = string(i, '0');

        for (int j = 0; j < (int) b.size(); j++) {
            int multiply (a[i] - '0') * (b[j] - '0') + carry;
            temp += ((char)(multiply % 10 + '0'));
            carry = multiply / 10;
        }

        if (carry != 0) {
            temp += (carry + '0');
        }

        reverse(temp.begin(), temp.end());
        ret = ret.addInteger(temp.substr(getTrimIndex(temp)));
    }

    return ret;

}

Integer cosc326::Integer::multiplyInteger(const string& integer_to_multiply) const {
    return multiplyInteger(Integer(integer_to_multiply));
}

size_t cosc326::Integer::getTrimIndex(cost string& integer) {
    size_t index = 0;
    while (integer[index] == '0' && index < integer.size() - 1) {
        index++;
    }
    return index;
}

bool cosc326::Integer::operator==(const Integer& integer) const {
    return this->integer == integer.toString;
}

Integer cosc326::Integer::operator+(const Integer& integer) const {
    return addInteger(integer);
}

Integer cosc326::Integer::operator*(const Integer& integer) const {
    return multiplyInteger(integer);
}

ostream& operator<<(ostream& in, Integer& integer) {
    in << integer.toString();

    return in;
}