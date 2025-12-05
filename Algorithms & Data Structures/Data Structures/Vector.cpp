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

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    void push_back(const T& value);

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

template <typename T>
T& Vector<T>::operator[](size_t index)
{
    return m_data[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const
{
    return m_data[index];
}

template <typename T>
void Vector<T>::push_back(const T &value)
{
    if (m_size >= m_capacity)
    {
        size_t new_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;

        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < m_size; ++i)
        {
            new_data[i] = m_data[i];
        }
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }

    m_data[m_size++] = value;
}

template<typename T>
Vector<T>::~Vector()
{
    delete[] m_data;
}

int main(int argc, char const *argv[])
{
    Vector<int> a(1);
    a.push_back(4);
    a.push_back(3);
    a.push_back(18);
    a.push_back(5);
    a.push_back(9);
    a.push_back(0);
    for (size_t i = 0; i < 6; ++i)
    {
        std::cout << a[i] << " ";
    }
    

    return 0;
}
