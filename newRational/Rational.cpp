#include "Rational.h"

namespace cosc326
{

    Rational::Rational()
    {
        num = Integer();
        den = Integer("1");
    }

    Rational::Rational(const std::string& str)
    {
        Integer whole = Integer();
        Rational temp;
        std::size_t foundDot = str.find(".");
        std::size_t foundSlash = str.find("/");
        if (foundDot != std::string::npos) {
            std::string wholeS = str.substr(0, foundDot);
            std::string num = str.substr(foundDot + 1, foundSlash - foundDot - 1);
            std::string den = str.substr(foundSlash + 1, str.length() + 1);
            this->den = Integer(den);
            this->num = Integer(num);
            this->whole = Integer(wholeS);
        } else {
            std::string num = str.substr(0, foundSlash);
            std::string den = str.substr(foundSlash + 1, foundSlash - str.length() + 1);
            this->num = Integer(num);
            this->den = Integer(den);
        }

    };

    Rational::Rational(const Rational &r)
    {
        this->den = r.den;
        this->num = r.num;
        this->whole = r.whole;
    }

    Rational::Rational(const Integer &a)
    {
        this->num = a;
        this->den = Integer("1");
        this->whole = Integer("0");
    }

    Rational::Rational(const Integer &a, const Integer &b)
    {
        this->num = a;
        this->den = b;
        this->whole = Integer("0");
    }

    Rational::Rational(const Integer& a, const Integer& b, const Integer& c)
    {
        this->den = c;
        this->num = b;
        this->whole = a;
    }

    Rational::~Rational() = default;

    Rational &Rational::operator=(const Rational &r)
    {

        this->num = r.num;
        this->den = r.den;
        return *this;
    }

    Rational Rational::operator-() const
    {
        if (this->num.isPositive())
        {
            Integer num = Integer("-" + this->num.toString());
            Rational temp = Rational(num, den);
            return temp;
        }
        else
        {
            return Rational(getValue());
        }
    }

    Rational Rational::operator+() const
    {
        if (!this->num.isPositive())
        {
            Integer num = this->num.absValue();
            Rational temp = Rational(num, den);
            return temp;
        }
        else
        {
            return Rational(getValue());
        }
    }

    Rational &Rational::operator+=(const Rational &r)
    {

        *this = Rational(*this + r);
        return *this;
    }

    Rational &Rational::operator-=(const Rational &r)
    {

        *this = Rational(*this - r);
        return *this;
    }

    Rational &Rational::operator*=(const Rational &r)
    {

        *this = Rational(*this * r);
        return *this;
    }

    Rational &Rational::operator/=(const Rational &r)
    {

        *this = Rational(*this / r);
        return *this;
    }

    Rational operator+(const Rational &lhs, const Rational &rhs)
    {
        //printf("Executed   \n");
        Rational lhsTemp;
        Rational rhsTemp;
        if(lhs.whole != ZERO) {
            ///printf("1:  \n");  // Debugging
            Integer temp = (lhs.whole * lhs.den) + lhs.num;
            lhsTemp.num = temp;
            lhsTemp.den = lhs.den;
            lhsTemp.whole = Integer("0");
        } else {
            //printf("2:  \n");  // Debugging
            lhsTemp = lhs;
        }
        if (rhs.whole != ZERO) {
            //printf("3:  \n");  // Debugging
            Integer temp = (rhs.whole * rhs.den) + rhs.num;
            rhsTemp.num = temp;
            rhsTemp.den = rhs.den;
            rhsTemp.whole = Integer();
            
        } else {
            //printf("4:  \n");  // Debugging
            rhsTemp = rhs;
        }
        Rational temp;
        Integer tempNum = ((lhsTemp.num * rhsTemp.den) + (rhsTemp.num * lhsTemp.den));
        Integer tempDen = rhsTemp.den * lhsTemp.den;
        Integer tempWhole;
        
        tempWhole = lhsTemp.whole + rhsTemp.whole;
        temp.num = tempNum;
        temp.den = tempDen;
        temp.whole = tempWhole;
        //printf("Executed simplify \n");
        //printf("Before simplify = %s / %s\n", temp.num.toString().c_str(), temp.den.toString().c_str());
        return temp.simplify();
    }

    Rational operator-(const Rational &lhs, const Rational &rhs)
    {
        Rational lhsTemp;
        Rational rhsTemp;
        if(lhs.whole != ZERO) {
            //printf("1:  \n");  // Debugging
            Integer temp = (lhs.whole * lhs.den) + lhs.num;
            lhsTemp.num = temp;
            lhsTemp.den = lhs.den;
            lhsTemp.whole = Integer("0");
        } else {
            //printf("2:  \n");  // Debugging
            lhsTemp = lhs;
        }
        if (rhs.whole != ZERO) {
            //printf("3:  \n");  // Debugging
            Integer temp = (rhs.whole * rhs.den) + rhs.num;
            rhsTemp.num = temp;
            rhsTemp.den = rhs.den;
            rhsTemp.whole = Integer("0");
            
        } else {
            //printf("4:  \n");  // Debugging
            rhsTemp = rhs;
        }


        Rational temp;
        temp.num = (lhsTemp.num * rhsTemp.den) - (rhsTemp.num * lhsTemp.den);
        temp.den = lhsTemp.den * rhsTemp.den;
        temp.whole = Integer("0");
        //printf("Executed simplify \n");
        //printf("Before simplify = %s / %s\n", temp.num.toString().c_str(), temp.den.toString().c_str());
        return temp.simplify();
    }

    Rational operator*(const Rational &lhs, const Rational &rhs)
    {
        Rational temp;
        temp.num = lhs.num * rhs.num;
        temp.den = lhs.den * rhs.den;
        return temp.simplify();
    }

    Rational operator/(const Rational &lhs, const Rational &rhs)
    {
        Rational temp;
        if (!lhs.num.isPositive() && !rhs.num.isPositive())
        {
            Integer lhsNum = lhs.num.absValue();
            Integer rhsNum = rhs.num.absValue();
            temp.num = lhsNum * rhs.den;
            temp.den = lhs.den * rhsNum;
            return temp.simplify();
        }
        else
        {
            temp.num = lhs.num * rhs.den;
            temp.den = lhs.den * rhs.num;
            return temp.simplify();
        }
    }

    std::ostream &operator<<(std::ostream &os, const Rational &i)
    {
        std::string s;
        Integer whole, numerator, denominator;
        whole = i.whole;
        
        Rational simplified = i.simplify();
        //printf("\nsimplified num: %s\n", simplified.num.toString().c_str()); // debugging
        //printf("simplified den: %s\n", simplified.den.toString().c_str()); // debugging
        Integer num = simplified.num;
        Integer den = simplified.den;
        whole = i.whole;
        if (den == Integer("1") && whole == ZERO)
        {
            //printf("hi1\t");  // debugging
            Integer g = Integer(num);
            s = g.toString();
            os << s;
        } else if (num.absValue() > den.absValue())
        {
            //printf("hi2\t"); // debugging
            whole = whole + (num / den);
            Integer p = num.absValue() % den;
            numerator = Integer(p);
            if (numerator == Integer("0")) {
                s = whole.toString();
            } else {
                denominator = Integer(den.absValue());
                Rational t = Rational(numerator, denominator).simplify();
                s = whole.toString() + "." + t.num.toString() + "/" + t.den.toString();
            }
            
            os << s;
            return os;
        }
        else if (num.absValue() == den.absValue())
        {
            if (whole == ZERO) {
                //printf("hi3\t"); // debugging
                os << "1";
            } else {
                //printf("hi4\t"); // debugging
                whole = whole + Integer("1");
                s = whole.toString();
                os << s;

            }
            
        }
        else if (num == ZERO)
        {
            //printf("hi5\t"); // debugging
            os << "0";
        }
        else
        {
            if (whole != ZERO) {
                s = whole.toString() + "." + num.toString() + "/" + den.toString();
            } else {
                s = num.toString() + "/" + den.toString();
            }
            os << s;
        }
        return os;
    }

    std::istream &operator>>(std::istream &is, Rational &i)
    {
        is >> i.den >> i.num;
        return is;
    }

    bool operator<(const Rational &lhs, const Rational &rhs)
    {
        Integer temp1 = lhs.num * rhs.den;
        Integer temp2 = lhs.den * rhs.num;
        if (temp1 < temp2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator>(const Rational &lhs, const Rational &rhs)
    {

        Integer temp1 = lhs.num * rhs.den;
        Integer temp2 = lhs.den * rhs.num;
        if (temp1 > temp2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator<=(const Rational &lhs, const Rational &rhs)
    {

        if ((lhs < rhs) || (lhs == rhs))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator>=(const Rational &lhs, const Rational &rhs)
    {

        if ((lhs > rhs) || (lhs == rhs))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator==(const Rational &lhs, const Rational &rhs)
    {
        Rational temp = lhs / rhs;
        if ((temp.num.absValue() == ONE && temp.den.absValue() == ONE))
        {
            return true;
        }
        else
        {
            return false;
        }
        return false;
    }

    bool operator!=(const Rational &lhs, const Rational &rhs)
    {

        if (!(lhs == rhs))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Rational Rational::simplify() const
    {
        Rational temp;
        Integer greatestCD;
        greatestCD = gcd(this->den, this->num);
        //printf("GCD value = %s\n", greatestCD.toString().c_str());
        //printf("num = %s\n", num.toString().c_str());
        //printf("den = %s\n", den.toString().c_str());
        temp.den = den / greatestCD;
        temp.num = num / greatestCD;
        //printf("num after divid of gcd = %s\n", temp.num.toString().c_str());
        //printf("den after divid of gcd = %s\n", temp.den.toString().c_str());
        //temp.whole = whole;
        return temp;
        //return Rational();
    }

    Rational Rational::getValue() const
    {
        Rational temp;
        temp.den = this->den;
        temp.num = this->num;
        temp.whole = this->whole;
        return temp;
    }
/*
    Rational Rational::convertToImproper(Integer w, Integer n, Integer d)
    {
        if (w == Integer("0"))
        {
            return Rational(n, d);
        }
        else
        {
            Rational temp;
            temp.den = d;
            Integer wholeSign = w.absValue();
            temp.num = (w * d) + n;
            return temp;
        }
    }
    */
};
