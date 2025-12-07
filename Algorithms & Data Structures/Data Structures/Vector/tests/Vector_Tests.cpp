#include <gtest/gtest.h>
#include "../include/Vector.hpp" 

class VectorTest : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
};


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
