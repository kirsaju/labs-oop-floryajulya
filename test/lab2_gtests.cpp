#include <gtest/gtest.h>
#include "../include/eleven.h"

TEST(ElevenTest, DefaultConstructor)
{

    Eleven e;

    size_t size = e.getSize();
    unsigned char *data = e.getData();

    EXPECT_EQ(size, 0);
    EXPECT_EQ(data, nullptr);
}

TEST(ElevenTest, SizeAndDefaultConstructor)
{

    size_t n = 5;
    unsigned char t = '0';
    Eleven e(n, t);

    size_t size = e.getSize();
    unsigned char *data = e.getData();

    EXPECT_EQ(size, n);
    for (size_t i = 0; i < size; ++i)
    {
        EXPECT_EQ(data[i], t);
    }
}

TEST(ElevenTest, InitializerListConstructor)
{

    std::initializer_list<unsigned char> t = {'1', '5', 'A', '3'};
    Eleven e(t);

    size_t size = e.getSize();
    unsigned char *data = e.getData();

    EXPECT_EQ(size, t.size());
    size_t i = 0;
    for (unsigned char digit : t)
    {
        EXPECT_EQ(data[i++], digit);
    }
}

TEST(ElevenTest, StringConstructor)
{

    std::string t = "15A3";
    Eleven e(t);

    size_t size = e.getSize();
    unsigned char *data = e.getData();

    EXPECT_EQ(size, t.size());
    for (size_t i = 0; i < size; ++i)
    {
        EXPECT_EQ(data[i], t[i]);
    }
}

TEST(ElevenTest, AssignmentOperator)
{

    Eleven e1("15A3");
    Eleven e2("15A3");

    e2 = e1;

    EXPECT_EQ(e2.getSize(), e1.getSize());
    for (int i = 0; i < e2.getSize(); ++i)
    {
        EXPECT_EQ(e1.getData()[i], e2.getData()[i]);
    }
}

TEST(ElevenTest, AdditionOperator)
{

    Eleven e1("15A3");
    Eleven e2("147");

    e1 += e2;

    std::string ans = "173A";
    EXPECT_EQ(e1.getSize(), 4);
    for (int i = 0; i < e1.getSize(); ++i)
    {
        EXPECT_EQ(e1.getData()[i], ans[i]);
    }
}

TEST(ElevenTest, SubtractionOperator)
{

    Eleven e1("A12");
    Eleven e2("123");

    e1 -= e2;

    std::string ans = "89A";
    EXPECT_EQ(e1.getSize(), 3);
    for (int i = 0; i < e1.getSize(); ++i)
    {
        EXPECT_EQ(e1.getData()[i], ans[i]);
    }
}

TEST(ElevenTest, EqualityOperator)
{

    Eleven e1("A12");
    Eleven e2("A12");
    Eleven e3("167");

    EXPECT_TRUE(e1 == e2);
    EXPECT_FALSE(e1 == e3);
}

TEST(ElevenTest, LessThanOperator)
{

    Eleven e1("123");
    Eleven e2("267");

    EXPECT_TRUE(e1 < e2);
    EXPECT_FALSE(e2 < e1);
}

TEST(ElevenTest, GreaterThanOperator)
{

    Eleven e1("267");
    Eleven e2("123");

    EXPECT_TRUE(e1 > e2);
    EXPECT_FALSE(e2 > e1);
}