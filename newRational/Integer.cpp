/**
 * @file Integer.cpp
 * @author Connor Dobson & Ariana van Lith
 * @brief The integer class is a new data type that can hold an integer bigger than the typical formats built into C++
 * @version 0.1
 * @date 2022-06-07
 * 
 * 
 */

#include "Integer.h"


namespace cosc326
{
    /**
     * @brief Construct a new Integer:: Integer object with the default value of "0"
     * 
     */
    Integer::Integer(){
        this->value = "0";
    }

    /**
     * @brief Construct a new Integer from an existing integer variable
     * 
     * @param i is the Integer variable that is getting copied to the new variable
     */
    Integer::Integer(const Integer& i)
    {
        value = parseValue(i.value);
    }
    
    /**
     * @brief Construct a new Integer:: Integer object from a string input
     * 
     * @param s is the string that is getting parsed into a variable
     */
    Integer::Integer(const std::string& s)
    {
        value = parseValue(s);
    }


    /**
     * @brief The setValue method changes the current value of the integer from the string input
     * 
     * @param val is the string value that is getting reassigned
     */
    void Integer::setValue(std::string val)
    {
        value = parseValue(std::move(val));
    }

    //Destructor
    Integer::~Integer(){}

    /**
     * @brief This method overrides the = operator and assigns an integer with a new value
     * 
     * @param i is the new integer value going to be assigned to the current integer variable
     * @return returns the address variable of the integer that have been changed
     */
    Integer& Integer::operator=(const Integer& i)
    {
        this->value = i.value;
        return *this;
    }

    /**
     * @brief This method overirdes the - operator but does not take in any parameters as this converts an integer to a negative value
     * 
     * @return the result as an integer
     */
    Integer Integer::operator-() const
    {
        if (isPositive())
        {
            return Integer("-" + value);
        }
        return Integer(absValue().toString());
    }

    /**
     * @brief This method overrides the / operator is able to divide between 2 Integer numbers
     * 
     * @param lhs the left hand integer
     * @param rhs the right hand integer
     * @return the result as an integer
     */
    Integer operator/(const Integer &lhs, const Integer &rhs)
    {
        if (rhs != ZERO && lhs != ZERO)
        {
            if (lhs.isPositive() && rhs.isPositive())
            {
                return Integer::divide(lhs, rhs)[0];
            }
            else if (lhs.isPositive() && !rhs.isPositive())
            {
                return -Integer::divide(lhs, rhs.absValue())[0];
            }
            else if (!lhs.isPositive() && rhs.isPositive())
            {
                return -Integer::divide(lhs.absValue(), rhs)[0];
            }
            return Integer::divide(lhs.absValue(), rhs.absValue())[0];
        }
        else
        {
            return Integer("0");
        }
    }

    /**
     * @brief The divide method returns 2 integer values, the result of the division and the remainder. We have implemented 
     * the repeated subraction division method for dividing our values.
     * 
     * @param lhs The left hand integer value
     * @param rhs The right hand integer value
     * @return A Integer* pointer with 2 Integer values attached to it.
     */
    Integer *Integer::divide(const Integer &lhs, const Integer &rhs)
    {
        if (rhs != ZERO  && lhs != ZERO)
        {
            Integer lhsTemp = lhs;
            Integer rhsTemp = Integer(rhs.absValue());
            auto *result_values = new Integer[2];
            Integer remainder = Integer("0");
            Integer result = Integer("0");

            if (lhs == rhs) {
                result_values[0] = Integer("1");
                result_values[1] = Integer("0");
                return result_values;
            }

            remainder = lhs - rhs;
            result = Integer("1");
            while (remainder >= rhsTemp) {
                remainder = remainder - rhsTemp;
                result = result + Integer("1");
                if (remainder.value == "01") {
                    remainder = Integer("1");
                    break;
                } else if (remainder == rhs){
                    result_values[0] = result + Integer("1");
                    result_values[1] = remainder;
                    return result_values;
                }
            }
            result_values[0] = result;
            result_values[1] = remainder;
            return result_values;
        }
        else
        {
            return NULL;
        }
    }

    /**
     * @brief This method overirdes the * operator and times the 2 values together
     * 
     * @param lhs The left hand integer
     * @param rhs The right hand integer
     * @return returns the result as an integer 
     */
    Integer operator*(const Integer &lhs, const Integer &rhs)
    {
        if (lhs.isPositive() && rhs.isPositive())
        {
            return Integer::multiply(lhs, rhs);
        }
        else if (lhs.isPositive() && !rhs.isPositive())
        {
            return -Integer::multiply(lhs, rhs.absValue());
        }
        else if (!lhs.isPositive() && rhs.isPositive())
        {
            return -Integer::multiply(lhs.absValue(), rhs);
        }
        return Integer::multiply(lhs.absValue(), rhs.absValue());
    }

    /**
     * @brief The multiply function times the 2 integers together
     * 
     * @param lhs the left hand side integer
     * @param rhs the right hand side integer
     * @return returns the result as an integer 
     */
    Integer Integer::multiply(const Integer &lhs, const Integer &rhs)
    {
        if (lhs.isPositive() == true && lhs.isPositive() == true)
        {
            std::string num1 = lhs.toString();
            std::string num2 = rhs.toString();
            int len1 = num1.size();
            int len2 = num2.size();
            if (len1 == 0 || len2 == 0)
                return Integer("0");
            std::vector<int> result(len1 + len2, 0);
            int i_n1 = 0;
            int i_n2 = 0;
            for (int i = len1 - 1; i >= 0; i--)
            {
                int carry = 0;
                int n1 = num1[i] - '0';
                i_n2 = 0;
                for (int j = len2 - 1; j >= 0; j--)
                {
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
        else
        {
            return Integer("0");
        }
    }

    /**
     * @brief This method overirdes the - operator and subtracts the 2 integers
     * 
     * @param lhs the left hand side integer 
     * @param rhs the right hand side integer
     * @return returns the result as an integer 
     */
    Integer operator-(const Integer &lhs, const Integer &rhs)
    {
        if (!lhs.isPositive() && !rhs.isPositive())
        {
            return -(lhs.absValue() - rhs.absValue());
        }
        else if (!lhs.isPositive() && rhs.isPositive())
        {
            return -(lhs.absValue() + rhs.absValue());
        }
        else if (lhs.isPositive() && !rhs.isPositive())
        {
            return lhs + rhs.absValue();
        }
        else
        {
            if (lhs >= rhs)
            {
                return Integer::diff(lhs, rhs);
            }
            else
            {
                return -Integer::diff(lhs, rhs);
            }
        }
    }

    /**
     * @brief The diff method calculates the difference between the 2 integers
     * 
     * @param lhs the left hand side integer
     * @param rhs the right hand side integer
     * @return returns the result as an integer 
     */
    Integer Integer::diff(const Integer &lhs, const Integer &rhs)
    {
        assert(lhs.isPositive() && rhs.isPositive());
        std::string str1 = lhs.absValue().toString();
        std::string str2 = rhs.absValue().toString();
        if (Integer(str1) < Integer(str2))
        {
            swap(str1, str2);
        }
        std::string str = "";
        int n1 = str1.length(), n2 = str2.length();
        int diff = n1 - n2;
        int carry = 0;
        for (int i = n2 - 1; i >= 0; i--)
        {
            int sub = ((str1[i + diff] - '0') - (str2[i] - '0') - carry);
            if (sub < 0)
            {
                sub = sub + 10;
                carry = 1;
            }
            else
                carry = 0;
            str.push_back(sub + '0');
        }
        for (int i = n1 - n2 - 1; i >= 0; i--)
        {
            if (str1[i] == '0' && carry)
            {
                str.push_back('9');
                continue;
            }
            int sub = ((str1[i] - '0') - carry);
            if (i > 0 || sub > 0)
                str.push_back(sub + '0');
            carry = 0;
        }
        reverse(str.begin(), str.end());
        return Integer(str);
    }

    /**
     * @brief This method overrides the + function and adds the 2 integers together
     * 
     * @param lhs the left hand side integer
     * @param rhs the right hand side integer
     * @return returns the result as an integer 
     */
    Integer operator+(const Integer &lhs, const Integer &rhs)
    {
        if (lhs.isPositive() && rhs.isPositive())
        {
            return cosc326::Integer::addition(lhs, rhs);
        }
        else if (lhs.isPositive() && !rhs.isPositive())
        {
            return -(rhs.absValue() - lhs.absValue());
        }
        else if (!lhs.isPositive() && rhs.isPositive())
        {
            return -(lhs.absValue() - rhs.absValue());
        }
        return -(lhs.absValue() + rhs.absValue());
    }

    /**
     * @brief The addition method adds the 2 integers together
     * 
     * @param lhs the left hand side integer
     * @param rhs the right hand side integer
     * @return returns the result as an integer 
     */
    Integer Integer::addition(const Integer &lhs, const Integer &rhs)
    {
        std::string str1 = lhs.toString();
        std::string str2 = rhs.toString();
        if (str1.length() > str2.length())
            swap(str1, str2);
        std::string result = "";
        int n1 = str1.length(), n2 = str2.length();
        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());
        int carry = 0;
        for (int i = 0; i < n1; i++)
        {
            int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
            result.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        for (int i = n1; i < n2; i++)
        {
            int sum = ((str2[i] - '0') + carry);
            result.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        if (carry)
            result.push_back(carry + '0');
        reverse(result.begin(), result.end());
        return Integer(result);
    }

    /**
     * @brief This function overrides the % operator and calculates the mod of the 2 integers by getting the remainder from the divide function
     * 
     * @param lhs the left hand side integer
     * @param rhs the right hand side integer
     * @return returns the result as an integer 
     */
    Integer operator%(const Integer &lhs, const Integer &rhs)
    {
        if (lhs == ZERO || (lhs.absValue() == rhs.absValue()))
        {
            return Integer("0");
        }
        Integer positiveRemainder = Integer::divide(lhs.absValue(), rhs.absValue())[1];
        if (lhs < ZERO || rhs < ZERO)
        {
            return (rhs.absValue() - positiveRemainder).absValue();
        }
        else
        {
            return positiveRemainder;  
        }
    }

    /**
     * @brief The gcd function calculates the greatest common divisor of the 2 integers
     * 
     * @param a an integer value
     * @param b an integer value
     * @return returns the result as an integer 
     */
    Integer gcd(const Integer &a, const Integer &b)
    {
        Integer a1 = a.absValue();
        Integer b1 = b.absValue();
        if (a1 == ZERO)
        {
            return b1;
        }
        else if (b1 == ZERO)
        {
            return a1;
        }
        Integer remainder = a1 % b1;
        return gcd(b1, remainder);
    }

    /**
     * @brief This function overrides the/= operator and divides the current integer with the other integer passed through
     * 
     * @param i the other integer being divided with
     * @return returns the address of the modified Integer& 
     */
    Integer &Integer::operator/=(const Integer &i)
    {
        *this = *this / i;
        return *this;
    }

    /**
     * @brief This function overrides the %= operator and mods the curent integer with the other integer passed through
     * 
     * @param i the other integer being mod with
     * @return returns the address of the modified Integer& 
     */
    Integer &Integer::operator%=(const Integer &i)
    {
        *this = *this % i;
        return *this;
    }

    /**
     * @brief This function overrides the *= operator and times the curent integer with the other integer passed through
     * 
     * @param i the other integer being times with
     * @return returns the address of the modified Integer& 
     */
    Integer &Integer::operator*=(const Integer &i)
    {
        *this = (*this) * i;
        return *this;
    }

    /**
     * @brief This function overrides the -= operator and subtracts the current integer with the other integer passed through
     * 
     * @param i the other integer being subtracted with
     * @return returns the address of the modified Integer& 
     */
    Integer &Integer::operator-=(const Integer &i)
    {
        *this = *this - i;
        return *this;
    }

    /**
     * @brief This function overrides the += operator and adds the current integer with the other integer passed through
     * 
     * @param i the other integer being added with
     * @return returns the address of the modified Integer& 
     */
    Integer &Integer::operator+=(const Integer &i)
    {
        *this = *this + i;
        return *this;
    }

    /**
     * @brief This function overrides the < operator and compares if the left hand side is less than the right hand side
     * 
     * @param lhs the left hand side integer
     * @param rhs the right hand side integer
     * @return true if the left hand side is less than the right hand side
     * @return false if the left hand side is greater than the right hand side
     */
    bool operator<(const Integer &lhs, const Integer &rhs)
    {
        if (lhs == rhs)
        {
            return false;
        }
        if (lhs.isPositive() && rhs.isPositive())
        {
            return Integer::compare(lhs, rhs);
        }
        else if (lhs.isPositive() && !rhs.isPositive())
        {
            return false;
        }
        else if (!lhs.isPositive() && rhs.isPositive())
        {
            return true;
        }
        return !Integer::compare(lhs.absValue(), rhs.absValue());
    }

    /**
     * @brief This function overrides the > operator and compares if the left hand side is greater than the right hand side
     * 
     * @param lhs the left hand side integer
     * @param rhs the right hand side integer
     * @return true if the left hand side is greater than the right hand side
     * @return false if the left hand side is less than the right hand side
     */
    bool operator>(const Integer &lhs, const Integer &rhs)
    {
        return !(lhs <= rhs);
    }

    /**
     * @brief This function overrides the <= operator and compares if the left hand side is less than or equals the right hand side
     * 
     * @param lhs the left hand side integer
     * @param rhs the right hand side integer
     * @return true if the left hand side is less than or equals the right hand side
     * @return false if the left hand side is greater than the right hand side
     */
    bool operator<=(const Integer &lhs, const Integer &rhs)
    {
        return (lhs < rhs) || (lhs == rhs);
    }

    /**
     * @brief This function overrides the >= operator and compares if the left hand side is greater than or equals the right hand side
     * 
     * @param lhs the left hand side integer
     * @param rhs the right hand side integer
     * @return true if the left hand side is greater or equals the right hand side
     * @return false if the left hand side is less than the right hand side
     */
    bool operator>=(const Integer &lhs, const Integer &rhs)
    {
        return (lhs > rhs) || (lhs == rhs);
    }

    /**
     * @brief The compare function provides the logic for the comparision methods
     * 
     * @param lhs the left hand side integer
     * @param rhs the right hand side integer
     * @return true if the comparision is true
     * @return false if the comparision is false
     */
    bool Integer::compare(const Integer &lhs, const Integer &rhs)
    {
        if (lhs.isPositive() == true && rhs.isPositive() == true)
        {
            std::string str1 = lhs.toString();
            std::string str2 = rhs.toString();
            int n1 = str1.length(), n2 = str2.length();
            if (n1 < n2)
                return true;
            if (n2 < n1)
                return false;
            for (int i = 0; i < n1; i++)
            {
                if (str1[i] < str2[i])
                    return true;
                else if (str1[i] > str2[i])
                    return false;
            }
            return false;
        }
        else
        {
            return false;
        }
    }

    /**
     * @brief This function overrides the == operator and compares if the left hand side and right hand side equal
     * 
     * @param lhs the left hand side integer
     * @param rhs the right hand side integer
     * @return true if the left hand side and right hand side equal
     * @return false if the left hand side and right hand side don't equal
     */
    bool operator==(const Integer &lhs, const Integer &rhs)
    {
        return lhs.toString() == rhs.toString();
    }

    /**
     * @brief This function overrides the != operator and compares if the left and side and right hand side don't equal
     * 
     * @param lhs the left hand side integer
     * @param rhs the right hand side integer
     * @return true if the left hand side does't equal the right hand side
     * @return false if the left hand side equls the right hand side
     */
    bool operator!=(const Integer &lhs, const Integer &rhs)
    {
        return !(lhs == rhs);
    }

    /**
     * @brief This function overrides the + operator and converts an integer into a positive value
     * 
     * @return return a positive Integer 
     */
    Integer Integer::operator+() const
    {
        return Integer(value);
    }

    
    /**
     * @brief This function returns a boolean if the integer is positive or not
     * 
     * @return true if the integer is positive
     * @return false if the integer is negative
     */
    bool Integer::isPositive() const
    {
        return Integer::isStringPositive(value);
    }

    /**
     * @brief This function parses the string input and removes an excess zeros and positive signs if need be
     * 
     * @param val the input string value
     * @return the result as a std::string 
     */
    std::string Integer::parseValue(std::string val)
    {
        if (isInteger(val) == true)
        {
            val = removePositiveSign(val);
            val = removeLeadingZeros(val);
            if (strAbsValue(val) == "0")
            {
                val = "0";
            }
            return val;
        }
        else
        {
            return NULL;
        }
    }

    /**
     * @brief This function returns the absolute value of the integer as a string
     * 
     * @param str the input string
     * @return returns a std::string value
     */
    std::string Integer::strAbsValue(std::string str) const
    {
        if (!isStringPositive(str))
        {
            return str.substr(1);
        }
        return str;
    }

    /**
     * @brief This function returns the absolute value as a Integer
     * 
     * @return returns the absolute value as integer 
     */
    Integer Integer::absValue() const
    {
        return Integer(strAbsValue(value));
    }

    /**
     * @brief This function detects if the integer string input is a positive value or not
     * 
     * @param str the string input
     * @return true if the string input is a positive value
     * @return false if the string input is a negative value
     */
    bool Integer::isStringPositive(std::string str)
    {
        if (!str.empty())
        {
            return str[0] != '-';
        }
        return false;
    }

    /**
     * @brief This function detects if the string input is a valid integer
     * 
     * @param str the string input
     * @return true if the string is a integer value
     * @return false if the string is not an integer value
     */
    bool Integer::isInteger(std::string str)
    {
        int i = 0;
        if (str[0] == '+' || str[0] == '-')
        {
            i++;
        }
        while (i < str.size())
        {
            if (!('0' <= str[i] && str[i] <= '9'))
            {
                return false;
            }
            i++;
        }
        return true;
    }

    /**
     * @brief This function removes the leading zeros from the string input
     * 
     * @param str the string input
     * @return returns a std::string value 
     */
    std::string Integer::removeLeadingZeros(std::string str)
    {

        if (Integer::isStringPositive(str) && str != "0")
        {
            int current = 0;
            int length = str.length();
            while (current < length)
            {

                if (str.at(current) == '0')
                {
                    current++;
                }
                else
                {
                    break;
                }
            }
            str = str.substr(current);
            return str;
        }
        else
        {

            return str;
        }
    }

    /**
     * @brief This function removes the positive sign from the string input
     * 
     * @param str the string input
     * @return returns a std::string value 
     */
    std::string Integer::removePositiveSign(std::string str)
    {
        if (str[0] == '+')
        {
            if (str.size() == 1)
            {
                return "";
            }
            else
            {
                return str.substr(1);
            }
        }
        return str;
    }

    /**
     * @brief This function overrides the << operator and sends the integer value to the output stream
     * 
     * @param os the output stream
     * @param i the integer value to output
     * @return returns a std::ostream& output stream 
     */
    std::ostream& operator<<(std::ostream& os, const Integer& i)
    {
        os << i.toString() << std::endl;
        return os;
    }

    /**
     * @brief This function overrides the >> operator and manages the input coming in through the input stream
     * 
     * @param is the input stream
     * @param i the integer being inputed
     * @return returns a std::istream& input stream
     */
    std::istream& operator>>(std::istream& is, Integer& i)
    {
        std::string val;
        is >> val;
        i.setValue(val);
        return is;
    }

    /**
     * @brief The toString() function returns the integer as a string
     * 
     * @return returns a std::string 
     */
    std::string Integer::toString() const
    {
        return value;
    }
}
