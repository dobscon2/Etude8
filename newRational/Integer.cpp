#include "Integer.h"


namespace cosc326
{
    // default constructor
    Integer::Integer(){
        this->value = "0";
    }

    // Integer Constructor
    Integer::Integer(const Integer& i)
    {
        value = i.value;
    }
    
    // String Constructor
    Integer::Integer(const std::string& s)
    {
        value = parseValue(s);
    }


    void Integer::setValue(std::string val)
    {
        value = parseValue(std::move(val));
    }

    //Destructor
    Integer::~Integer(){}

    // Assignment Operator
    Integer& Integer::operator=(const Integer& i)
    {
        this->value = i.value;
        return *this;
    }

    // Negative Assignment
    Integer Integer::operator-() const
    {
        if (isPositive())
        {
            return Integer("-" + value);
        }
        return Integer(absValue().toString());
    }

    Integer operator/(const Integer &lhs, const Integer &rhs)
    {
        if (rhs != ZERO)
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

    Integer *Integer::divide(const Integer &lhs, const Integer &rhs)
    {
        if (rhs != ZERO)
        {
            Integer lhsTemp = lhs;
            Integer rhsTemp = Integer(rhs.absValue());
            auto *result_values = new Integer[2];
            Integer remainder = Integer("0");
            Integer result = Integer("0");

            remainder = lhs - rhs;
            result = Integer("1");
            while (remainder >= rhsTemp) {
                remainder = remainder - rhsTemp;
                result = result + Integer("1");
                if (remainder.value == "01") {
                    remainder = Integer("1");
                    break;
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

    

    Integer &Integer::operator/=(const Integer &i)
    {
        *this = *this / i;
        return *this;
    }

    Integer &Integer::operator%=(const Integer &i)
    {
        *this = *this % i;
        return *this;
    }

    Integer &Integer::operator*=(const Integer &i)
    {
        *this = (*this) * i;
        return *this;
    }

    Integer &Integer::operator-=(const Integer &i)
    {
        *this = *this - i;
        return *this;
    }

    Integer &Integer::operator+=(const Integer &i)
    {
        *this = *this + i;
        return *this;
    }

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

    bool operator>(const Integer &lhs, const Integer &rhs)
    {
        return !(lhs <= rhs);
    }

    bool operator<=(const Integer &lhs, const Integer &rhs)
    {
        return (lhs < rhs) || (lhs == rhs);
    }

    bool operator>=(const Integer &lhs, const Integer &rhs)
    {
        return (lhs > rhs) || (lhs == rhs);
    }
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

    bool operator==(const Integer &lhs, const Integer &rhs)
    {
        return lhs.toString() == rhs.toString();
    }

    bool operator!=(const Integer &lhs, const Integer &rhs)
    {
        return !(lhs == rhs);
    }

    Integer Integer::operator+() const
    {
        return Integer(value);
    }

    

    bool Integer::isPositive() const
    {
        return Integer::isStringPositive(value);
    }

    std::string Integer::parseValue(std::string val)
    {
        if (isInteger(val) == true)
        {
            printf("HI\n"); //debugging
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
            printf("ye\n"); //debugging
            return NULL;
        }
    }

    std::string Integer::strAbsValue(std::string str) const
    {
        if (!isStringPositive(str))
        {
            return str.substr(1);
        }
        return str;
    }

    Integer Integer::absValue() const
    {
        return Integer(strAbsValue(value));
    }

    bool Integer::isStringPositive(std::string str)
    {
        if (!str.empty())
        {
            return str[0] != '-';
        }
        return false;
    }

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

    std::string Integer::removeLeadingZeros(std::string str)
    {
        if (Integer::isStringPositive(str) && str.size() == 1)
        {
            printf("HI2\n"); //debugging
            int current = 0;
            int length = str.length();
            while (current < length)
            {
            printf("HI3\n"); //debugging

                if (str.at(current) == '0')
                {
            printf("HI4\n"); //debugging
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
            printf("BYE2\n"); //debugging
            return str;
        }
    }

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

    std::ostream& operator<<(std::ostream& os, const Integer& i)
    {
        os << i.toString() << std::endl;
        return os;
    }

    std::istream& operator>>(std::istream& is, Integer& i)
    {
        std::string val;
        is >> val;
        i.setValue(val);
        return is;
    }


    // To String Method
    std::string Integer::toString() const
    {
        return value;
    }
}
