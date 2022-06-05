//
// Created by Hugo on 14/04/2022.
//

#include "Integer.h"
#include <cstdlib>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

#include <assert.h>

// TODO, tidy up class!

namespace cosc326 {

    /* Constructors */

    Integer::Integer() = default;

    Integer::~Integer() = default;

    Integer::Integer(const std::string &digits) {
        value = parseValue(digits);
    }

    Integer::Integer(const Integer &b) {
        value = b.getValue();
    }

    /* General methods */

    std::string Integer::getValue() const {
        return value;
    }

    void Integer::setValue(std::string val) {
        value = parseValue(std::move(val));
    }

    std::string Integer::repr() const {
        return value;
    }

    /* Doing Arithmetic */

    // Division

    /**
     * Division operator
     *
     * @param lhs Integer
     * @param rhs Integer
     * @return a new Integer
     */
    Integer operator/(const Integer &lhs, const Integer &rhs) {
        assert(rhs != ZERO);
        if (lhs.isPositive() && rhs.isPositive()) {
            return Integer::findQuotientAndRemainder(lhs, rhs)[0];
        } else if (lhs.isPositive() && !rhs.isPositive()) {
            return -Integer::findQuotientAndRemainder(lhs, rhs.absValue())[0];
        } else if (!lhs.isPositive() && rhs.isPositive()) {
            return -Integer::findQuotientAndRemainder(lhs.absValue(), rhs)[0];
        }
        return Integer::findQuotientAndRemainder(lhs.absValue(), rhs.absValue())[0];
    }

    /**
     * Finds the Quotient and Remainder when one number is divided by another
     *
     * NOTE, assumes lhs and rhs are both POSITIVE.
     * 
     * @param lhs
     * @param rhs
     * @return
     */
    Integer *Integer::findQuotientAndRemainder(const Integer &lhs, const Integer &rhs) {
        assert((rhs != ZERO));
        Integer quotient = Integer("0");
        Integer remainder = Integer("0");
        auto *result = new Integer[2];
        if ((ZERO < lhs) && (lhs < rhs)) {
            remainder = Integer(rhs);
        }
        if ((lhs != ZERO)) {
            if (lhs == rhs) {
                quotient = Integer("1");
            } else {
                std::string dvd = lhs.getValue();
                std::string dvs = rhs.getValue();
                remainder = Integer("" + dvd);
                int baseCount;
                int magDiff;
                Integer dvsAdj;
                while (remainder >= rhs) {
                    baseCount = 0;
                    magDiff = std::max(int(remainder.getValue().size() - dvs.size() - 1), 0);
                    dvsAdj = Integer(dvs + (std::string(magDiff, '0')));
                    while (remainder > ZERO) {
                        if ((remainder - dvsAdj) >= ZERO) {
                            remainder -= dvsAdj;
                            baseCount++;
                        } else {
                            break;
                        }
                    }
                    quotient += Integer(to_string(baseCount) + std::string(magDiff, '0'));
                }
            }
        }
        result[0] = quotient;
        result[1] = remainder;
        return result;
    }

    // Multiplication

    /**
     * Multiplication operator
     *
     * @param lhs Integer
     * @param rhs Integer
     * @return a new Integer
     */
    Integer operator*(const Integer &lhs, const Integer &rhs) {
        if (lhs.isPositive() && rhs.isPositive()) {
            return Integer::mulPositiveIntegers(lhs, rhs);
        } else if (lhs.isPositive() && !rhs.isPositive()) {
            return -Integer::mulPositiveIntegers(lhs, rhs.absValue());
        } else if (!lhs.isPositive() && rhs.isPositive()) {
            return -Integer::mulPositiveIntegers(lhs.absValue(), rhs);
        }
        return Integer::mulPositiveIntegers(lhs.absValue(), rhs.absValue());
    }

    /**
     * Multiplies two Positive Integers together
     *
     * Fails if lhs and rhs are not both positive Integers
     *
     * @param lhs Integer
     * @param rhs Integer
     * @return a new Integer object
     */
    Integer Integer::mulPositiveIntegers(const Integer &lhs, const Integer &rhs) {
        assert(lhs.isPositive() && lhs.isPositive());

        std::string num1 = lhs.getValue();
        std::string num2 = rhs.getValue();
        int len1 = num1.size();
        int len2 = num2.size();
        if (len1 == 0 || len2 == 0)
            return Integer("0");
        std::vector<int> result(len1 + len2, 0);
        int i_n1 = 0;
        int i_n2 = 0;
        for (int i = len1 - 1; i >= 0; i--) {
            int carry = 0;
            int n1 = num1[i] - '0';
            i_n2 = 0;
            for (int j = len2 - 1; j >= 0; j--) {
                int n2 = num2[j] - '0';
                int sum = n1 * n2 + result[i_n1 + i_n2] + carry;
                carry = sum / 10;
                result[i_n1 + i_n2] = sum % 10;
                i_n2++;
            }
            if (carry > 0)
                result[i_n1 + i_n2] += carry;
            i_n1++;
        }
        int i = result.size() - 1;
        while (i >= 0 && result[i] == 0)
            i--;
        if (i == -1)
            return Integer("0");
        std::string s = "";
        while (i >= 0)
            s += std::to_string(result[i--]);
        return Integer(s);
    }

    // Subtraction

    /**
     * Subtraction operator
     *
     * @param lhs
     * @param rhs
     * @return
     */
    Integer operator-(const Integer &lhs, const Integer &rhs) {
        if (!lhs.isPositive() && !rhs.isPositive()) {
            return -(lhs.absValue() - rhs.absValue());
        } else if (!lhs.isPositive() && rhs.isPositive()) {
            return -(lhs.absValue() + rhs.absValue());
        } else if (lhs.isPositive() && !rhs.isPositive()) {
            return lhs + rhs.absValue();
        } else {
            if (lhs >= rhs) {
                return Integer::diff(lhs, rhs);
            } else {
                return -Integer::diff(lhs, rhs);
            }
        }

    }

    /**
     * Finds the difference between two (positive) integers.
     *
     * Fails if lhs and rhs aren't both positive.
     *
     * Ie computes |lhs-rhs|
     *
     * @param lhs
     * @param rhs
     * @return
     */
    Integer Integer::diff(const Integer &lhs, const Integer &rhs) {
        assert(lhs.isPositive() && rhs.isPositive());
        std::string str1 = lhs.absValue().getValue();
        std::string str2 = rhs.absValue().getValue();
        if (Integer(str1) < Integer(str2)) {
            swap(str1, str2);
        }
        std::string str = "";
        int n1 = str1.length(), n2 = str2.length();
        int diff = n1 - n2;
        int carry = 0;
        for (int i = n2 - 1; i >= 0; i--) {
            int sub = ((str1[i + diff] - '0') - (str2[i] - '0')
                       - carry);
            if (sub < 0) {
                sub = sub + 10;
                carry = 1;
            } else
                carry = 0;
            str.push_back(sub + '0');
        }
        for (int i = n1 - n2 - 1; i >= 0; i--) {
            if (str1[i] == '0' && carry) {
                str.push_back('9');
                continue;
            }
            int sub = ((str1[i] - '0') - carry);
            if (i > 0 || sub > 0) // remove preceding 0's
                str.push_back(sub + '0');
            carry = 0;
        }
        reverse(str.begin(), str.end());
        return Integer(str);
    }

    // Addition

    /**
     * Addition operator
     *
     * @param lhs Integer
     * @param rhs Integer
     * @return a new Integer
     */
    Integer operator+(const Integer &lhs, const Integer &rhs) {
        if (lhs.isPositive() && rhs.isPositive()) {
            return cosc326::Integer::addPositiveIntegers(lhs, rhs);
        } else if (lhs.isPositive() && !rhs.isPositive()) {
            return -(rhs.absValue() - lhs.absValue());
        } else if (!lhs.isPositive() && rhs.isPositive()) {
            return -(lhs.absValue() - rhs.absValue());
        }
        return -(lhs.absValue() + rhs.absValue());
    }

    /**
     * Adds two positive Integers together
     *
     * @param lhs Integer
     * @param rhs Integer
     * @return Integer
     */
    Integer Integer::addPositiveIntegers(const Integer &lhs, const Integer &rhs) {
        std::string str1 = lhs.getValue();
        std::string str2 = rhs.getValue();
        if (str1.length() > str2.length())
            swap(str1, str2);
        std::string result = "";
        int n1 = str1.length(), n2 = str2.length();
        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());
        int carry = 0;
        for (int i = 0; i < n1; i++) {
            int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
            result.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        for (int i = n1; i < n2; i++) {
            int sum = ((str2[i] - '0') + carry);
            result.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        if (carry)
            result.push_back(carry + '0');
        reverse(result.begin(), result.end());
        return Integer(result);
    }

    // Modulo

    /**
     * Modulo operator
     *
     * @param lhs Integer
     * @param rhs Integer
     * @return a new Integer
     */
    Integer operator%(const Integer &lhs, const Integer &rhs) {
        if (lhs == ZERO || (lhs.absValue() == rhs.absValue())) {
            return Integer("0");
        }
        Integer positiveRemainder = Integer::findQuotientAndRemainder(lhs.absValue(), rhs.absValue())[1];
        if (lhs < ZERO || rhs < ZERO) {
            return (rhs.absValue() - positiveRemainder).absValue();
        } else {
            return positiveRemainder;
        }

    }

    // GCD

    /**
     * Finds the greatest common divisor between two integers.
     *
     * @param a
     * @param b
     * @return
     */
    Integer gcd(const Integer &a, const Integer &b) {
        Integer a1 = a.absValue();
        Integer b1 = b.absValue();
        if (a1 == ZERO) {
            return b1;
        } else if (b1 == ZERO) {
            return a1;
        }
        Integer remainder = a1 % b1;
        return gcd(b1, remainder);
    }

    /* Reassignment operators */

    Integer &Integer::operator=(const Integer &i) {
        this->setValue(i.getValue());
        return *this;
    }

    Integer &Integer::operator/=(const Integer &i) {
        *this = *this / i;
        return *this;
    }

    Integer &Integer::operator%=(const Integer &i) {
        *this = *this % i;
        return *this;
    }

    Integer &Integer::operator*=(const Integer &i) {
        *this = (*this) * i;
        return *this;
    }

    Integer &Integer::operator-=(const Integer &i) {
        *this = *this - i;
        return *this;
    }

    Integer &Integer::operator+=(const Integer &i) {
        *this = *this + i;
        return *this;
    }

    /* Inequality operators */

    bool operator<(const Integer &lhs, const Integer &rhs) {
        if (lhs == rhs) {
            return false;
        }
        if (lhs.isPositive() && rhs.isPositive()) {
            return Integer::comparePositiveIntegers(lhs, rhs);
        } else if (lhs.isPositive() && !rhs.isPositive()) {
            return false;
        } else if (!lhs.isPositive() && rhs.isPositive()) {
            return true;
        }
        return !Integer::comparePositiveIntegers(lhs.absValue(), rhs.absValue());
    }

    bool operator>(const Integer &lhs, const Integer &rhs) {
        return !(lhs <= rhs);
    }

    bool operator<=(const Integer &lhs, const Integer &rhs) {
        return (lhs < rhs) || (lhs == rhs);
    }

    bool operator>=(const Integer &lhs, const Integer &rhs) {
        return (lhs > rhs) || (lhs == rhs);
    }

    /**
     * Compares two positive Integers to see which one is bigger
     *
     * True if lhs < rhs
     *
     * Asserts that both lhs and rhs are positive
     *
     * @param lhs Integer
     * @param rhs Integer
     * @return bool as described
     */
    bool Integer::comparePositiveIntegers(const Integer &lhs, const Integer &rhs) {
        assert(lhs.isPositive() && rhs.isPositive());
        std::string str1 = lhs.getValue();
        std::string str2 = rhs.getValue();
        int n1 = str1.length(), n2 = str2.length();
        if (n1 < n2)
            return true;
        if (n2 < n1)
            return false;
        for (int i = 0; i < n1; i++) {
            if (str1[i] < str2[i])
                return true;
            else if (str1[i] > str2[i])
                return false;
        }
        return false;
    }

    /* Equality operators */

    bool operator==(const Integer &lhs, const Integer &rhs) {
        return lhs.getValue() == rhs.getValue();
    }

    bool operator!=(const Integer &lhs, const Integer &rhs) {
        return !(lhs == rhs);
    }

    /* Unary operators */

    Integer Integer::operator+() const {
        return Integer(value);
    }

    Integer Integer::operator-() const {
        if (isPositive()) {
            return Integer("-" + value);
        }
        return Integer(absValue().getValue());
    }

    /* General helper methods */

    /**
     * Finds out if an Integer is positive or not
     *
     * A positive number is defined as being greater than or equal to zero. A negative number is anything less than 0.
     *
     * @return bool
     */
    bool Integer::isPositive() const {
        return Integer::strIsPositive(value);
    }

    /**
     * Parses an inputted string value for the value of an Integer
     *
     * Asserts that the inputted value can be interpreted as an integer in the first place
     *
     * Tries to account for edge cases that may mess things up. Eg -0 etc
     *
     * @param val string for a integer value inputted by a user
     * @return value parsed into a usable form
     */
    std::string Integer::parseValue(std::string val) {
        assert(strIsInteger(val));
        val = stripPositiveSign(val);
        val = stripLeadingZeros(val);
        if (strAbsValue(val) == "0") {
            val = "0";
        }
        return val;
    }

    /**
     * Finds the absolute value of an string that can presumably be interpreted as a string
     *
     * @return string for inputted string in it's absolute value form
     */
    std::string Integer::strAbsValue(std::string str) const {
        if (!strIsPositive(str)) {
            return str.substr(1);
        }
        return str;
    }

    /**
     * Finds the absolute value of this Integer
     *
     * @return a new Integer object
     */
    Integer Integer::absValue() const {
        return Integer(strAbsValue(value));
    }

    /**
     * Finds out if a string is positive.
     *
     * Assumes that the inputted string can be interpreted as a integer
     *
     * Any str that doesn't have a leading minus sign is treated as positive.
     *
     * @param str string
     * @return
     */
    bool Integer::strIsPositive(std::string str) {
        if (!str.empty()) {
            return str[0] != '-';
        }
        return false;
    }

    /**
     * Checks if a string is an integer or not
     *
     * @param str string inputted by a user
     * @return bool as described
     */
    bool Integer::strIsInteger(std::string str) {
        int i = 0;
        if (str[0] == '+' || str[0] == '-') {
            i++;
        }
        while (i < str.size()) {
            if (!('0' <= str[i] && str[i] <= '9')) {
                return false;
            }
            i++;
        }
        return true;
    }

    /**
     * Strips leading zeros from an inputted string.
     *
     * Accounts for cases where str has negative sign in front
     *
     * @param str string inputted by a user
     * @return string
     */
    std::string Integer::stripLeadingZeros(std::string str) {
        if (!Integer::strIsPositive(str)) {
            if (str.size() > 1) {
                int i = 1;
                while (str[i] == '0' && i < str.size() - 1) {
                    i++;
                }
                return str.substr(0, 1) + str.substr(i);
            } else {
                return str;
            }
        } else {
            int i = 0;
            while (str[i] == '0' && i < str.size() - 1) {
                i++;
            }
            return str.substr(i);
        }
    }

    std::string Integer::stripPositiveSign(std::string str) {
        if (str[0] == '+') {
            if (str.size() == 1) {
                return "";
            } else {
                return str.substr(1);
            }
        }
        return str;
    }

    /* Extraction and insertion */

    std::ostream &operator<<(std::ostream &os, const Integer &i) {
        os << i.getValue() << std::endl;
        return os;
    }

    std::istream &operator>>(std::istream &input, Integer &b) {
        std::string val;
        input >> val;
        b.setValue(val);
        return input;
    }
}

