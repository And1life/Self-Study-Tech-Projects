#include <iostream>


template<typename T>
class Vector
{
private:
    T* m_data;
    size_t m_size;
    size_t m_capacity;
public:
    Vector();
    ~Vector();
};

template<typename T>
Vector<T>::Vector() : m_data(nullptr), m_size(0), m_capacity(0)
{
}

template<typename T>
Vector<T>::~Vector()
{
    delete[] m_data;
}

int main(int argc, char const *argv[])
{
    Vector<int> a;
    return 0;
}
