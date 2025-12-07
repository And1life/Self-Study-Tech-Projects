#include <gtest/gtest.h>
#include "../Vector.h" // Подключите ваш файл с реализацией Vector

class VectorTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Этот метод вызывается перед каждым тестом
    }

    void TearDown() override {
        // Этот метод вызывается после каждого теста
    }
};


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
