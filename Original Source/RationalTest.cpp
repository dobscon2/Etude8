//
// Created by Hugo on 15/04/2022.
//
#include "../src/Integer.h"
#include <gtest/gtest.h>
#include "../src/Rational.h"

namespace cosc326 {

    class RationalTest : public ::testing::Test {

    protected:
        Rational a = Rational(Integer("1"), Integer("2"));
        Rational b = Rational(Integer("3"));
        Rational c = Rational(Integer("6"));
        Rational d = Rational(Integer("2"));
        Rational e = Rational(Integer("7"));
        Rational f = Rational(Integer("-2"));
        Rational g = Rational();
        Rational h = Rational(Integer("1"));
        Rational i = Rational(Integer("5"), Integer("9"));
        Rational j = Rational(Integer("-1"));
    };

    TEST_F(RationalTest, TestUnary) {
        EXPECT_EQ("-1/2", (-a).toString());
        EXPECT_EQ("-1", (+a).toString());
        EXPECT_EQ("2", (-f).toString());
    }

    TEST_F(RationalTest, TestToString) {
        EXPECT_EQ("-1/2", (h / f).toString());
        EXPECT_EQ("1/3", (d / c).toString());
        EXPECT_EQ("2.1/3", (e / b).toString());
        EXPECT_EQ("6", c.toString());
    }

    TEST_F(RationalTest, TestArithmetic) {
        // Standard operations
        EXPECT_EQ("2", (c / b).toString());
        EXPECT_EQ("1/7", (h / e).toString());
        EXPECT_EQ("19/18", (i + a).toString());
        EXPECT_EQ("-7", (j * e).toString());
        EXPECT_EQ("5", (f - d).toString());
        EXPECT_EQ("2/3", (h - h / b).toString());
        EXPECT_EQ("4/3", (h + h / b).toString());
        EXPECT_EQ("1/7", (h / e).toString());

        // Cancellation of negatives
        EXPECT_EQ("1", (j / j).toString());
        EXPECT_EQ("1", (j * j).toString());
        EXPECT_EQ("0", (j - j).toString());
    }

    TEST_F(RationalTest, TestCompoundAssignment) {
        a *= d;
        EXPECT_EQ("1", a.toString());
        b += c;
        EXPECT_EQ("9", b.toString());
        g -= f;
        EXPECT_EQ("1", g.toString());
        h /= e;
        EXPECT_EQ("1/7", h.toString());
    }

    TEST_F(RationalTest, TestConstructors) {
        EXPECT_EQ("0", Rational().toString());
        EXPECT_EQ("-1", j.toString());
    }

    TEST_F(RationalTest, TestAssignment) {
        Rational n1 = Rational();
        n1 = a;
        EXPECT_EQ("1/2", n1.toString());
    }

    TEST_F(RationalTest, TestExamples) {
        EXPECT_NO_THROW(Rational("+15.32/2"));
        EXPECT_NO_THROW(Rational("-3.2/4"));
        EXPECT_NO_THROW(Rational("4/3"));
        EXPECT_NO_THROW(Rational("0.1/3"));
    }

    TEST_F(RationalTest, TestInvalidInput) {
        EXPECT_ANY_THROW(Rational("gibberish"));
        EXPECT_ANY_THROW(Rational(""));
        EXPECT_ANY_THROW(Rational(nullptr));

    }

    TEST_F(RationalTest, TestComparision) {
        EXPECT_EQ(true, a == a);
        EXPECT_EQ(true, a >= a);
        EXPECT_EQ(true, a <= a);
        EXPECT_EQ(false, a < a);
        EXPECT_EQ(false, a > a);
        EXPECT_EQ(true, b > a);
        EXPECT_EQ(false, b < a);
        EXPECT_EQ(false, a != a);
    };

};