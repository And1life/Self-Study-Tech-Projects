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
    void push_back(T&& value);
    void pop_back();
    void resize(size_t new_capacity);
    void clear();

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

template <typename T>
void Vector<T>::push_back(T &&value)
{
    if (m_size >= m_capacity)
    {
        size_t new_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < m_size; ++i)
        {
            new_data[i] = std::move(m_data[i]);
        }
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }

    m_data[m_size ++] = std::move(value);
    
}

template <typename T>
void Vector<T>::pop_back()
{
    if (m_size > 0)
    {
        --m_size;
    }
    
}

template <typename T>
void Vector<T>::resize(size_t new_capacity)
{
    if (new_capacity == m_capacity)
    {
        return;
    }
    
    T* new_data = new T[new_capacity];
    size_t elements_to_copy = (new_capacity < m_size) ? new_capacity : m_size;

    for (size_t i = 0; i < elements_to_copy; ++i)
    {
        new_data[i] = std::move(m_data[i]);
    }

    delete[] m_data;
    m_data = new_data;
    m_capacity = new_capacity;

    if (new_capacity < m_size)
    {
        m_size = new_capacity;
    }    
}

template <typename T>
void Vector<T>::clear()
{
    m_size = 0;
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] m_data;
}

int main(int argc, char const *argv[])
{
    Vector<int> vec(5);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.clear();

    for (size_t i = 0; i < 5; ++i)
    {
        std::cout << vec[i] << " ";
    }
    


    return 0;
}
