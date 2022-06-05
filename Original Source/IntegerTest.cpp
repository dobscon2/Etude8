//
// Created by Hugo on 15/04/2022.
//

#include <gtest/gtest.h>
#include "../src/Integer.cpp"

namespace cosc326 {

    class IntegerTest : public ::testing::Test {
    protected :
        Integer pos1 = Integer("1");
        Integer pos2 = Integer("2");
        Integer zero = Integer("0");
        Integer pos3 = Integer("3");
        Integer min5 = Integer("-5");
        Integer min10 = Integer("-10");
        Integer min2 = Integer("-2");
        Integer pos7 = Integer("7");
        Integer min1 = Integer("-1");
        Integer pos18 = Integer("18");
        Integer min6 = Integer("-6");
    };

    TEST_F(IntegerTest, TestBasicArithmetic) {
        EXPECT_EQ("3", (pos1 + pos2).getValue());
        EXPECT_EQ("0", (pos1 / pos2).getValue());
        EXPECT_EQ("2", (pos2 / pos1).getValue());
        EXPECT_EQ("6", (pos2 * pos3).getValue());
    }

    TEST_F(IntegerTest, TestAssignment) {
        Integer x = Integer("4");
        x = min2;
        EXPECT_EQ("-2", x.getValue());
        EXPECT_EQ("-2", min2.getValue());
        x+=pos2;
        EXPECT_EQ("0", x.getValue());
        EXPECT_EQ("-2", min2.getValue());
    }

    TEST_F(IntegerTest, TestReassignment) {
        pos1 += pos2;
        EXPECT_EQ("3", pos1.getValue());
        pos2 *= pos3;
        EXPECT_EQ("6", pos2.getValue());
        min10 /= min2;
        EXPECT_EQ("5", min10.getValue());
        pos7 -= pos3;
        EXPECT_EQ("4", pos7.getValue());
        pos7 %= pos3;
        EXPECT_EQ("1", pos7.getValue());
    }

    TEST_F(IntegerTest, TestUnary) {
        EXPECT_EQ("-1", (-pos1).getValue());
        EXPECT_EQ("5", (-min5).getValue());
        EXPECT_EQ("0", (-zero).getValue());
        EXPECT_EQ("-1", (+min1).getValue());
        EXPECT_EQ("1", (-min1).getValue());
    }

    TEST_F(IntegerTest, TestGCD) {
        EXPECT_EQ("1", gcd(pos1, pos1).getValue());
        // GCD of zero is not defined!

        EXPECT_EQ("5", gcd(min10, min5).getValue());
        EXPECT_EQ("5", gcd(min10, -min5).getValue());
        EXPECT_EQ("6", gcd(pos18, min6).getValue());
    }

    TEST_F(IntegerTest, TestEquality) {
        EXPECT_TRUE(pos1 == pos1);
        EXPECT_TRUE(pos1 != pos2);
        EXPECT_FALSE(pos1 == pos2);
        Integer x = -pos1;
        EXPECT_FALSE(x == pos1);
        EXPECT_TRUE(x != pos1);
    }

    TEST_F(IntegerTest, TestInEqualities) {
        EXPECT_TRUE(pos1 <= pos1);
        EXPECT_TRUE(pos1 >= pos1);
        EXPECT_FALSE(pos1 < pos1);
        EXPECT_TRUE(pos1 < pos2);
        EXPECT_FALSE(pos2 < pos1);
        EXPECT_TRUE(pos3 > min5);
        EXPECT_TRUE(min1 < pos7);
        EXPECT_TRUE(min5 < min1);
    }

    TEST_F(IntegerTest, TestAbsValue) {
        EXPECT_EQ("1", pos1.absValue().getValue());
        EXPECT_EQ("10", min10.absValue().getValue());
        EXPECT_EQ("0", zero.absValue().getValue());
    }

    TEST_F(IntegerTest, TestSubtraction) {
        EXPECT_EQ("-8", (min5 - pos3).getValue());
        EXPECT_EQ("-5", (min10 - min5).getValue());
        EXPECT_EQ("-3", (min5 - min2).getValue());
        EXPECT_EQ("-1", (pos2 - pos3).getValue());
        EXPECT_EQ("1", (pos3 - pos2).getValue());
        EXPECT_EQ("4", (pos7 - pos3).getValue());
        EXPECT_EQ("0", (pos3 - pos3).getValue());
        EXPECT_EQ("0", (zero - zero).getValue());

        EXPECT_EQ("9999999", (Integer("10000000") - pos1).getValue());
    }

    TEST_F(IntegerTest, TestAddition) {
        EXPECT_EQ("5", (pos3 + pos2).getValue());
        EXPECT_EQ("-15", (min10 + min5).getValue());
        EXPECT_EQ("-3", (pos2 + min5).getValue());
        EXPECT_EQ("-3", (min5 + pos2).getValue());
        EXPECT_EQ("0", (zero + zero).getValue());
        EXPECT_EQ("2", (pos2 + zero).getValue());
    }

    TEST_F(IntegerTest, TestMultiplication) {
        /*
         * Test
         * multiplication by zero
         * positive positive
         * negative positive
         * postive negative
         * negative negative
         * zero negative
         * zero positive
         */
        EXPECT_EQ("0", (zero * zero).getValue());
        EXPECT_EQ("0", (zero * min5).getValue());
        EXPECT_EQ("0", (zero * pos1).getValue());

        EXPECT_EQ("1", (pos1 * pos1).getValue());
        EXPECT_EQ("-5", (pos1 * min5).getValue());
        EXPECT_EQ("-10", (min10 * pos1).getValue());
        EXPECT_EQ("3", (pos1 * pos3).getValue());
        EXPECT_EQ("6", (pos2 * pos3).getValue());

        EXPECT_EQ("50", (min5 * min10).getValue());
        EXPECT_EQ("50", (min10 * min5).getValue());
        EXPECT_EQ("-14", (min2 * pos7).getValue());
        EXPECT_EQ("-14", (pos7 * min2).getValue());

        // Big Numbers
        EXPECT_EQ("62386149467931173657937623830189851280126870913571634187803335663909242", (Integer("456787484812957596827") * Integer("136575872899575287489595712748754917457626458917646")).getValue());
    }

    TEST_F(IntegerTest, TestDivision) {
        /*
         * Test
         * division with numerator zero
         * positive positive
         * negative positive
         * postive negative
         * negative negative
         * zero negative
         * zero positive
         */
        EXPECT_EQ("0", (zero / pos3).getValue());
        EXPECT_EQ("0", (zero / min1).getValue());
        EXPECT_EQ("-7", (pos7 / min1).getValue());
        EXPECT_EQ("3", (pos3 / pos1).getValue());
        EXPECT_EQ("6", (pos18 / pos3).getValue());
        EXPECT_EQ("-6", (-pos18 / pos3).getValue());
        EXPECT_EQ("-9", (pos18 / min2).getValue());
        EXPECT_EQ("2", (min10 / min5).getValue());
        EXPECT_EQ("1", (min1 / min1).getValue());

        EXPECT_EQ("25", (Integer("125") / Integer("5")).getValue());
        EXPECT_EQ("312", (Integer("1248") / Integer("4")).getValue());
        EXPECT_EQ("97", (Integer("291") / Integer("3")).getValue());

        EXPECT_EQ("2", (pos18 / pos7).getValue());
        EXPECT_EQ("-2", (Integer("-15") / Integer("7")).getValue());
        EXPECT_EQ("2", (Integer("-15") / Integer("-7")).getValue());

        // Big Number tests!
        EXPECT_EQ("500", (Integer("2000") / Integer("4")).getValue());
        EXPECT_EQ("10444451", (Integer("52222255") / Integer("5")).getValue());
    }

    TEST_F(IntegerTest, TestBigNumberDivision) {
        EXPECT_EQ("500", (Integer("2000") / Integer("4")).getValue());
        EXPECT_EQ("10444451", (Integer("52222255") / Integer("5")).getValue());

        // 100!/50!
        Integer fact100 = Integer(
                "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000");
        Integer fact50 = Integer("30414093201713378043612608166064768844377641568960512000000000000");
        EXPECT_EQ("3068518756254966037202730459529469739228459721684688959447786986982158958772355072000000000000",
                  (fact100 / fact50).getValue());
    }

    TEST_F(IntegerTest, TestStringConstructor) {
        Integer i = Integer("1");
        EXPECT_EQ("1", i.getValue());
        Integer j = Integer("-1");
        EXPECT_EQ("-1", j.getValue());

        EXPECT_EQ("0", Integer("+0").getValue());

        EXPECT_EQ("10", Integer("+10").getValue());

        EXPECT_EQ("0", Integer("0").getValue());
        EXPECT_EQ("0", Integer("-0").getValue());
        EXPECT_EQ("0", Integer("-0000000").getValue());
        EXPECT_EQ("0", Integer("0000000").getValue());
    }

    TEST_F(IntegerTest, TestModulo) {
        EXPECT_EQ("0", (pos18 % pos3).getValue());
        EXPECT_EQ("6", (Integer("-15") % Integer("7")).getValue());
        EXPECT_EQ("6", (Integer("-15") % Integer("-7")).getValue());
        EXPECT_EQ("1", (Integer("15") % Integer("7")).getValue());
        EXPECT_EQ("0", (Integer("14") % Integer("7")).getValue());
        EXPECT_EQ("0", (zero % min2).getValue());
        EXPECT_EQ("0", (zero % pos2).getValue());
        EXPECT_EQ("0", (pos7 % pos7).getValue());
        EXPECT_EQ("0", (pos7 % (-pos7)).getValue());
        EXPECT_EQ("0", ((-pos7) % (-pos7)).getValue());
        EXPECT_EQ("0", ((-pos7) % (+pos7)).getValue());
        EXPECT_EQ("5", (Integer("5") % Integer("10")).getValue());
    }

    TEST_F(IntegerTest, TestCopyConstructor) {
        Integer x = Integer(pos1);
        EXPECT_EQ("1", x.getValue());

        Integer y = Integer(min1);
        EXPECT_EQ("-1", y.getValue());
        y -= pos1; // Check memory spot not tethered
        EXPECT_EQ("-2", y.getValue());
        EXPECT_EQ("-1", min1.getValue());
    }
}