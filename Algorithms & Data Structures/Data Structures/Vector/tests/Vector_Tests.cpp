#include <gtest/gtest.h>
#include "../include/Vector.hpp" 

class VectorTest : public ::testing::Test {
protected:

    void SetUp() override {}
    void TearDown() override {}
};

// Tests for Constructors and opearators =

TEST_F(VectorTest, DefaultConstructor)
{
    Vector<int> vec;
    EXPECT_EQ(vec.getSize(), 0);
    EXPECT_EQ(vec.getCapacity(), 0);
}

TEST_F(VectorTest, CapacityConstructor)
{
    Vector<int> vec(10);
    EXPECT_EQ(vec.getSize(), 0);
    EXPECT_EQ(vec.getCapacity(), 10);
}

TEST_F(VectorTest, CopyConstructor)
{
    Vector<int> vec1;

    vec1.push_back(10);
    vec1.push_back(20);

    Vector<int> vec2(vec1);

    EXPECT_EQ(vec1.getSize(), vec2.getSize());
    EXPECT_EQ(vec1.getCapacity(), vec2.getCapacity());
    EXPECT_EQ(vec1[0], vec2[0]);
    EXPECT_EQ(vec1[1], vec2[1]);
}

TEST_F(VectorTest, MoveConstructor)
{
    Vector<int> vec1;

    vec1.push_back(10);
    vec1.push_back(20);

    Vector<int> vec2(std::move(vec1));

    EXPECT_EQ(vec2.getSize(), 2);
    EXPECT_EQ(vec2[0], 10);
    EXPECT_EQ(vec2[1], 20);
    EXPECT_EQ(vec1.getSize(), 0);
    EXPECT_EQ(vec1.getCapacity(), 0);
}

TEST_F(VectorTest, CopyAssignmentOperator)
{
    Vector<int> vec1;
    vec1.push_back(10);
    vec1.push_back(20);

    Vector<int> vec2;
    vec2 = vec1;

    EXPECT_EQ(vec1.getSize(), vec2.getSize());
    EXPECT_EQ(vec1.getCapacity(), vec2.getCapacity());
    EXPECT_EQ(vec1[0], vec2[0]);
    EXPECT_EQ(vec1[1], vec2[1]);
}

TEST_F(VectorTest, MoveAssignmentOperator)
{
    Vector<int> vec1;
    vec1.push_back(10);
    vec1.push_back(20);

    Vector<int> vec2;
    vec2 = std::move(vec1);

    EXPECT_EQ(vec2.getSize(), 2);
    EXPECT_EQ(vec2.getCapacity(), 2);
    EXPECT_EQ(vec2[0], 10);
    EXPECT_EQ(vec2[1], 20);
    EXPECT_EQ(vec1.getSize(), 0);
    EXPECT_EQ(vec1.getCapacity(), 0);
}

// Tests methods

TEST_F(VectorTest, PushBack)
{
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);

    EXPECT_EQ(vec.getSize(), 2);
    EXPECT_EQ(vec[0], 10);
    EXPECT_EQ(vec[1], 20);
}

TEST_F(VectorTest, PushBackMove)
{
    Vector<std::string> vec;
    std::string str1 = "Hello";
    std::string str2 = "World";

    vec.push_back(std::move(str1));
    vec.push_back(std::move(str2));

    EXPECT_EQ(vec.getSize(), 2);
    EXPECT_EQ(vec[0], "Hello");
    EXPECT_EQ(vec[1], "World");
    EXPECT_TRUE(str1.empty());
    EXPECT_TRUE(str2.empty());
}

TEST_F(VectorTest, PopBack)
{
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.pop_back();
    EXPECT_EQ(vec.getSize(), 1);
    EXPECT_EQ(vec[0], 10);
}

TEST_F(VectorTest, PopBackEmptyVector)
{
    Vector<int> vec;
    EXPECT_THROW(vec.pop_back(), std::out_of_range);
}

TEST_F(VectorTest, AccessOperator)
{
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);

    EXPECT_EQ(vec[0], 10);
    EXPECT_EQ(vec[1], 20);
}

TEST_F(VectorTest, AccessOperatorNoThrow)
{
    Vector<int> vec;
    vec.push_back(10);

    EXPECT_NO_THROW(vec[1]);
}

TEST_F(VectorTest, At)
{
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);

    EXPECT_EQ(vec.at(0), 10);
    EXPECT_EQ(vec.at(1), 20);
}

TEST_F(VectorTest, AtOutOfRange)
{
    Vector<int> vec;
    vec.push_back(10);

    EXPECT_THROW(vec.at(1), std::out_of_range);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
