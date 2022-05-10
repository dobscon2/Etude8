#ifndef INTEGER_H_
#define INTEGER_H_

#include <iostream>

namespace cosc326 {
    class Integer {
        string integer;
        public:
            Integer();
            Integer(unsigned int integer);
            Integer(string integer);
            void setInteger(unsigned int integer);
            void setInteger(string integer);
            unsigned int getIntValue() const;
            string toString() const;

            Integer addInteger(const Integer& integer_to_add) const;
            Integer addInteger(const string& integer_to_add) const;
            Integer subtractInteger(const Integer& integer_to_subtract) const;
            Integer subtractInteger(const string& integer_to_subtract) const;
            Integer multiplyInteger(const Integer& integer_to_multiply) const;
            Integer multiplyIntger(const string& integer_to_multiply) const;
            Integer divideInteger(const Integer& integer_to_divide) const;
            Integer divideInteger(const string& integer_to_divide) const;
            Integer modInteger(const Integer& integer_to_mod) const;
            Integer modInteger(const string& integer_to_mod) const;

            static size_t getTrimIndex(const string& integer);

            bool operator==(const Integer& integer) const;
            Integer operator+(const Integer& integer) const;
            Integer operator*(const Integer& integer) const;

            friend ostream& operator<<(ostrean& in, Integer& integer);

    };
}

#endif