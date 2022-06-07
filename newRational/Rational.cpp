/**
 * @file Rational.cpp
 * @author Connor Dobson & van Lith
 * @brief The Rational class uses the previous Integer class and is able to work with fractions and mixed numbers in C++
 * @version 0.1
 * @date 2022-06-07
 * 
 */

#include "Rational.h"

namespace cosc326
{
    // Default constructor
    Rational::Rational()
    {
        num = Integer();
        den = Integer("1");
    }

    // String Constructor
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

    // Rational Constructor
    Rational::Rational(const Rational &r)
    {
        this->den = r.den;
        this->num = r.num;
        this->whole = r.whole;
    }

    // Single Integer Constructor
    Rational::Rational(const Integer &a)
    {
        this->num = a;
        this->den = Integer("1");
        this->whole = Integer("0");
    }

    // Two integers Constructor
    Rational::Rational(const Integer &a, const Integer &b)
    {
        this->num = a;
        this->den = b;
        this->whole = Integer("0");
    }


    // Three Integer Constuctor - Third integer is the whole number
    Rational::Rational(const Integer& a, const Integer& b, const Integer& c)
    {
        this->den = c;
        this->num = b;
        this->whole = a;
    }

    // Destructor
    Rational::~Rational() = default;

    // Assignment Operator
    Rational &Rational::operator=(const Rational &r)
    {

        this->num = r.num;
        this->den = r.den;
        return *this;
    }

    // Negative assignment Opereator
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

    // Positive Assignment Operator
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

    // Addition assignment operator
    Rational &Rational::operator+=(const Rational &r)
    {

        *this = Rational(*this + r);
        return *this;
    }

    // Substration assignment Operator
    Rational &Rational::operator-=(const Rational &r)
    {

        *this = Rational(*this - r);
        return *this;
    }

    // Multiplacation assignment operator
    Rational &Rational::operator*=(const Rational &r)
    {

        *this = Rational(*this * r);
        return *this;
    }

    // Division assignment operator
    Rational &Rational::operator/=(const Rational &r)
    {

        *this = Rational(*this / r);
        return *this;
    }

    // Addition Operator
    Rational operator+(const Rational &lhs, const Rational &rhs)
    {
        Rational lhsTemp;
        Rational rhsTemp;
        Integer tempWhole;
        Integer intTemp;
        //bool negative = false;
        if(lhs.whole != ZERO) {
            tempWhole = lhs.whole;
            if (tempWhole.toString()[0] == '-') {
                tempWhole = lhs.whole.absValue();
                Integer result = ((tempWhole * lhs.den) + lhs.num);
                std::string final = "-" + result.toString();
                intTemp = Integer(final);

            } else {
                intTemp = (tempWhole * lhs.den) + lhs.num;
            }
            lhsTemp.num = intTemp;
            lhsTemp.den = lhs.den;
            lhsTemp.whole = Integer("0");
        } else {
            //printf("2:  \n");  // Debugging
            lhsTemp = lhs;
        }
        if (rhs.whole != ZERO) {
            //printf("3:  \n");  // Debugging
            tempWhole = rhs.whole;
            if (tempWhole.toString()[0] == '-')  {
                //negative = true;   
                tempWhole = rhs.whole.absValue();
                Integer result = ((tempWhole * rhs.den) + rhs.num);
                std::string final = "-" + result.toString();
                intTemp = Integer(final);
            } else {
                intTemp = (tempWhole * rhs.den) + rhs.num;
            }
            ///printf("1:  \n");  // Debugging
            
            rhsTemp.num = intTemp;
            rhsTemp.den = rhs.den;
            rhsTemp.whole = Integer();
            
        } else {
            //printf("4:  \n");  // Debugging
            rhsTemp = rhs;
        }

        //printf("lhs Not whole: %s/%s\n", lhsTemp.num.toString().c_str(), lhsTemp.den.toString().c_str());
        //printf("rhs Not whole: %s/%s\n", rhsTemp.num.toString().c_str(), rhsTemp.den.toString().c_str());
        Rational temp;
        Integer tempNum = ((lhsTemp.num * rhsTemp.den) + (rhsTemp.num * lhsTemp.den));
        Integer tempDen = rhsTemp.den * lhsTemp.den;
        
        tempWhole = lhsTemp.whole + rhsTemp.whole;

        temp.num = tempNum;
        temp.den = tempDen;
        temp.whole = tempWhole;
        //printf("Before simplify = %s / %s\n", temp.num.toString().c_str(), temp.den.toString().c_str());
        return temp.simplify();
    }


    //Subtraction Operator
    Rational operator-(const Rational &lhs, const Rational &rhs)
    {
        Rational lhsTemp;
        Rational rhsTemp;
        Integer tempWhole;
        Integer intTemp;
        if(lhs.whole != ZERO) {
            tempWhole = lhs.whole;
            if (tempWhole.toString()[0] == '-') {
                //printf("Executed   \n");
                tempWhole = lhs.whole.absValue();
                Integer result = ((tempWhole * lhs.den) + lhs.num);
                std::string final = "-" + result.toString();
                intTemp = Integer(final);

            } else {
                intTemp = (tempWhole * lhs.den) + lhs.num;
            }
            lhsTemp.num = intTemp;
            lhsTemp.den = lhs.den;
            lhsTemp.whole = Integer("0");
        } else {
            //printf("2:  \n");  // Debugging
            lhsTemp = lhs;
        }
        if (rhs.whole != ZERO) {
            //printf("3:  \n");  // Debugging
            tempWhole = rhs.whole;
            if (tempWhole.toString()[0] == '-')  {
                //negative = true;   
                tempWhole = rhs.whole.absValue();
                Integer result = ((tempWhole * rhs.den) + rhs.num);
                std::string final = "-" + result.toString();
                intTemp = Integer(final);
            } else {
                intTemp = (tempWhole * rhs.den) + rhs.num;
            }
            ///printf("1:  \n");  // Debugging
            
            rhsTemp.num = intTemp;
            rhsTemp.den = rhs.den;
            rhsTemp.whole = Integer();
            
        } else {
            //printf("4:  \n");  // Debugging
            rhsTemp = rhs;
        }
        //printf("lhs Not whole: %s/%s\n", lhsTemp.num.toString().c_str(), lhsTemp.den.toString().c_str());
        //printf("rhs Not whole: %s/%s\n", rhsTemp.num.toString().c_str(), rhsTemp.den.toString().c_str());

        Rational temp;
        temp.num = (lhsTemp.num * rhsTemp.den) - (rhsTemp.num * lhsTemp.den);
        temp.den = lhsTemp.den * rhsTemp.den;
        temp.whole = Integer("0");
        return temp.simplify();
    }


    // Multiplacation operator
    Rational operator*(const Rational &lhs, const Rational &rhs)
    {
        Rational lhsTemp;
        Rational rhsTemp;
        Integer tempWhole;
        Integer intTemp;
        if(lhs.whole != ZERO) {
            tempWhole = lhs.whole;
            if (tempWhole.toString()[0] == '-') {
                //printf("Executed   \n");
                tempWhole = lhs.whole.absValue();
                Integer result = ((tempWhole * lhs.den) + lhs.num);
                std::string final = "-" + result.toString();
                intTemp = Integer(final);

            } else {
                intTemp = (tempWhole * lhs.den) + lhs.num;
            }
            lhsTemp.num = intTemp;
            lhsTemp.den = lhs.den;
            lhsTemp.whole = Integer("0");
        } else {
            //printf("2:  \n");  // Debugging
            lhsTemp = lhs;
        }
        if (rhs.whole != ZERO) {
            //printf("3:  \n");  // Debugging
            tempWhole = rhs.whole;
            if (tempWhole.toString()[0] == '-')  {
                tempWhole = rhs.whole.absValue();
                Integer result = ((tempWhole * rhs.den) + rhs.num);
                std::string final = "-" + result.toString();
                intTemp = Integer(final);
            } else {
                intTemp = (tempWhole * rhs.den) + rhs.num;
            }
            
            rhsTemp.num = intTemp;
            rhsTemp.den = rhs.den;
            rhsTemp.whole = Integer();
            
        } else {
            rhsTemp = rhs;
        }
        Rational temp;
        temp.num = lhsTemp.num * rhsTemp.num;
        temp.den = lhsTemp.den * rhsTemp.den;
        return temp.simplify();
    }

    // Division Operator
    Rational operator/(const Rational &lhs, const Rational &rhs)
    {
        Rational lhsTemp;
        Rational rhsTemp;
        Integer tempWhole;
        Integer intTemp;
        if(lhs.whole != ZERO) {
            tempWhole = lhs.whole;
            if (tempWhole.toString()[0] == '-') {
                //printf("Executed   \n");
                tempWhole = lhs.whole.absValue();
                Integer result = ((tempWhole * lhs.den) + lhs.num);
                std::string final = "-" + result.toString();
                intTemp = Integer(final);

            } else {
                intTemp = (tempWhole * lhs.den) + lhs.num;
            }
            lhsTemp.num = intTemp;
            lhsTemp.den = lhs.den;
            lhsTemp.whole = Integer("0");
        } else {
            //printf("2:  \n");  // Debugging
            lhsTemp = lhs;
        }
        if (rhs.whole != ZERO) {
            //printf("3:  \n");  // Debugging
            tempWhole = rhs.whole;
            if (tempWhole.toString()[0] == '-')  {
                tempWhole = rhs.whole.absValue();
                Integer result = ((tempWhole * rhs.den) + rhs.num);
                std::string final = "-" + result.toString();
                intTemp = Integer(final);
            } else {
                intTemp = (tempWhole * rhs.den) + rhs.num;
            }
            
            rhsTemp.num = intTemp;
            rhsTemp.den = rhs.den;
            rhsTemp.whole = Integer();
            
        } else {
            rhsTemp = rhs;
        }
        //printf("lhs Not whole: %s/%s\n", lhsTemp.num.toString().c_str(), lhsTemp.den.toString().c_str());
        //printf("rhs Not whole: %s/%s\n", rhsTemp.num.toString().c_str(), rhsTemp.den.toString().c_str());
        Rational temp;
        if (!lhsTemp.num.isPositive() && !rhs.num.isPositive())
        {
            Integer lhsNum = lhsTemp.num.absValue();
            Integer rhsNum = rhsTemp.num.absValue();
            temp.num = lhsNum * rhsTemp.den;
            temp.den = lhsTemp.den * rhsNum;
            return temp.simplify();
        }
        else
        {
            temp.num = lhsTemp.num * rhsTemp.den;
            temp.den = lhsTemp.den * rhsTemp.num;
            if (temp.den.toString()[0] == '-'){
                temp.den = temp.den.absValue();
                std::string final = "-" + temp.num.toString();
                temp.num = Integer(final);
                
            }

            return temp.simplify();
        }
    }

    // Streaming Insertion operator
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

    // Streaming extraction Operator
    std::istream &operator>>(std::istream &is, Rational &i)
    {
        is >> i.den >> i.num;
        return is;
    }

    // Less than Comparison Operator
    bool operator<(const Rational &lhs, const Rational &rhs)
    {
        Integer temp1;
        Integer temp2;
        if (lhs.whole == rhs.whole){
            temp1 = (lhs.num * rhs.den);
            //printf("< temp1 %s\n", temp1.toString().c_str());
            
            temp2 = (lhs.den * rhs.num);
            //printf("< temp2 %s\n", temp2.toString().c_str());

        } else {
            temp1 = lhs.whole;
            temp2 = rhs.whole;
        }
        if (temp1 < temp2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Greater than comparison Operator
    bool operator>(const Rational &lhs, const Rational &rhs)
    {
        Integer temp1;
        Integer temp2;
        if (lhs.whole == rhs.whole){
            temp1 = (lhs.num * rhs.den);
            //printf("> temp1 %s\n", temp1.toString().c_str());
            temp2 = (lhs.den * rhs.num);
            //printf("> temp2 %s\n", temp2.toString().c_str());

        } else {
            temp1 = lhs.whole;
            //printf("> whole temp1 %s\n", temp1.toString().c_str());
            temp2 = rhs.whole;
            //printf("> whole temp2 %s\n", temp2.toString().c_str());
        }

        
        if (temp1 > temp2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Less Than Or Equal Too Comparison Operator
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


    // Greater Than Or Equal Too Comparison Operator
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


    // Equal too coparison operator
    bool operator==(const Rational &lhs, const Rational &rhs)
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
        Rational temp = lhsTemp / rhsTemp;

        if ((temp.num == ONE && temp.den == ONE))
        {
            return true;
        }
        else
        {
            return false;
        }
        return false;
    }


    // Not Equal Too Comparison Operator
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


    /**
    * Simplyfy Method - Takes a rational and converts into its simplest form
    * @returns temp - the simplified rational
    */
    Rational Rational::simplify() const
    {
        Rational temp;
        Integer greatestCD;
        greatestCD = gcd(this->den, this->num);
        temp.den = den / greatestCD;
        temp.num = num / greatestCD;
        return temp;
    }

    
    /**
    * Get Vaue Method - returns a rational with the values of this
    * @returns temp - the rational
    */
    Rational Rational::getValue() const
    {
        Rational temp;
        temp.den = this->den;
        temp.num = this->num;
        temp.whole = this->whole;
        return temp;
    }


};
