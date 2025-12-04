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
    Vector(size_t initialCapacity);
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other) noexcept;

    ~Vector();
};

template<typename T>
Vector<T>::Vector() : m_data(nullptr), m_size(0), m_capacity(0)
{
}

template <typename T>
Vector<T>::Vector(size_t initialCapacity)
    : m_data(new T[initialCapacity]), m_size(0), m_capacity(initialCapacity)
{
}

template <typename T>
Vector<T>::Vector(const Vector &other)
    : m_data(new T[other.m_capacity]), m_capacity(other.m_capacity), m_size(other.m_size)
{
    for (size_t i = 0; i < m_size; ++i)
    {
        m_data[i] = other.m_data[i];
    }
    
}

template <typename T>
Vector<T>::Vector(Vector &&other) noexcept
    : m_data(other.m_data), m_capacity(other.m_capacity), m_size(other.m_size)
{
    other.m_data = nullptr;
    other.m_capacity = 0;
    other.m_size = 0;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector &other)
{
    if (this != &other)
    {
        delete[] m_data;

        m_data = new T [other.m_capacity];
        m_capacity = other.m_capacity;
        m_size = other.m_size;

        for (size_t i = 0; i < m_size; ++i)
        {
            m_data[i] = other.m_data[i];
        }
    }
    return *this;

}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector &&other) noexcept
{
    if (this != &other)
    {
        delete[] m_data;

        m_data = other.m_data;
        m_capacity = other.m_capacity;
        m_size = other.m_size;

        other.m_data = nullptr;
        other.m_capacity = 0;
        other.m_size = 0;
        

    }
    return *this;
    
}

template<typename T>
Vector<T>::~Vector()
{
    delete[] m_data;
}

int main(int argc, char const *argv[])
{
    Vector<int> a(5);
    Vector<int> b(4);
    a = std::move(b);
    return 0;
}
