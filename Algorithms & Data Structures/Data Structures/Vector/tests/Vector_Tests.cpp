#include <gtest/gtest.h>
#include "../include/Vector.hpp" 

class VectorTest : public ::testing::Test {
protected:

    void SetUp() override {}
    void TearDown() override {}
};

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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
