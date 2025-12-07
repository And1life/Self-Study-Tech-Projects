#include "../include/Vector.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    Vector<int> vec = {1, 2, 3, 4, 5, 6};
    for (auto &&element : vec)
    {
        std::cout << element << " ";
    }
    

    return 0;
}
