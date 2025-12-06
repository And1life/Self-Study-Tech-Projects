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
    Vector(std::initializer_list<T> init_list);
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other) noexcept;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    size_t getSize() const;
    size_t getCapacity() const;
    bool empty() const;

    void push_back(const T& value);
    void push_back(T&& value);
    void pop_back();
    void resize(size_t new_capacity);
    void clear();
    void insert(size_t index, const T& value);
    void erase(size_t index);

    ~Vector();

    class Iterator
    {
    private:

        T* ptr;
    
    public:

        using difference_type = std::ptrdiff_t;

        Iterator(T* p) : ptr(p) {}

        T& operator*() const
        {
            return *ptr;
        }

        T* operator->() const
        {
            return ptr;
        }

        Iterator& operator++()
        {
            ++ptr;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator temp = *this;
            ++ptr;
            return temp;
        }

        Iterator& operator--()
        {
            --ptr;
            return *this;
        }

        Iterator operator--(int)
        {
            Iterator temp = *this;
            --ptr;
            return temp;
        }

        Iterator operator+(difference_type n) const
        {
            return Iterator(ptr + n);
        }
        
        Iterator operator-(difference_type n) const
        {
            return Iterator(ptr - n);
        }

        Iterator& operator+=(difference_type n)
        {
            ptr += n;
            return *this;
        }

        Iterator& operator-=(difference_type n)
        {
            ptr -= n;
            return *this;
        }

        T& operator[](difference_type n) const
        {
            return *(ptr + n);
        }

        bool operator==(const Iterator& other) const
        {
            return ptr == other.ptr;
        }

        bool operator!=(const Iterator& other) const
        {
            return ptr != other.ptr;
        }

        bool operator<(const Iterator& other) const
        {
            return ptr < other.ptr;
        }

        bool operator>(const Iterator& other) const
        {
            return ptr > other.ptr;
        }

        bool operator<=(const Iterator& other) const
        {
            return ptr <= other.ptr;
        }

        bool operator>=(const Iterator& other) const
        {
            return ptr >= other.ptr;
        }

        difference_type operator-(const Iterator& other) const
        {
            return ptr - other.ptr;
        }

    };

    class ConstIterator
    {
    private:

        T* ptr;
    
    public:

        using difference_type = std::ptrdiff_t;

        ConstIterator(T* p) : ptr(p) {}

        const T& operator*() const
        {
            return *ptr;
        }

        const T* operator->() const
        {
            return ptr;
        }

        ConstIterator& operator++()
        {
            ++ptr;
            return *this;
        }

        ConstIterator operator++(int)
        {
            ConstIterator temp = *this;
            ++ptr;
            return temp;
        }

        ConstIterator& operator--()
        {
            --ptr;
            return *this;
        }

        ConstIterator operator--(int)
        {
            ConstIterator temp = *this;
            --ptr;
            return temp;
        }

        ConstIterator operator+(difference_type n) const
        {
            return ConstIterator(ptr + n);
        }
        
        ConstIterator operator-(difference_type n) const
        {
            return ConstIterator(ptr - n);
        }

        ConstIterator& operator+=(difference_type n)
        {
            ptr += n;
            return *this;
        }

        ConstIterator& operator-=(difference_type n)
        {
            ptr -= n;
            return *this;
        }

        T& operator[](difference_type n) const
        {
            return *(ptr + n);
        }

        bool operator==(const ConstIterator& other) const
        {
            return ptr == other.ptr;
        }

        bool operator!=(const ConstIterator& other) const
        {
            return ptr != other.ptr;
        }

        bool operator<(const ConstIterator& other) const
        {
            return ptr < other.ptr;
        }

        bool operator>(const ConstIterator& other) const
        {
            return ptr > other.ptr;
        }

        bool operator<=(const ConstIterator& other) const
        {
            return ptr <= other.ptr;
        }

        bool operator>=(const ConstIterator& other) const
        {
            return ptr >= other.ptr;
        }

        difference_type operator-(const ConstIterator& other) const
        {
            return ptr - other.ptr;
        }

    };

    Iterator begin()
    {
        return Iterator(m_data);
    }

    Iterator end()
    {
        return Iterator(m_data + m_size);
    }

    ConstIterator begin() const
    {
        return ConstIterator(m_data);
    }

    ConstIterator end() const
    {
        return ConstIterator(m_data + m_size);
    }

    ConstIterator cbegin() const
    {
        return ConstIterator(m_data);
    }

    ConstIterator cend() const
    {
        return ConstIterator(m_data + m_size);
    }
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
Vector<T>::Vector(std::initializer_list<T> init_list)
    : m_data(new T[init_list.size()]), m_capacity(init_list.size()), m_size(init_list.size())
{
    size_t i = 0;
    for (auto &&element : init_list)
    {
        m_data[i++] = element; 
    }
    
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
    if (index >= m_size)
    {
        throw std::out_of_range("Index out of range");
    }
    
    return m_data[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const
{
    return m_data[index];
}

template <typename T>
size_t Vector<T>::getSize() const
{
    return m_size;
}

template <typename T>
size_t Vector<T>::getCapacity() const
{
    return m_capacity;
}

template <typename T>
bool Vector<T>::empty() const
{
    return this->getSize() == 0;
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
    if (m_size = 0)
    {
        throw std::out_of_range("Can't pop_back from an empty vector");
    }
    --m_size;
    
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
void Vector<T>::insert(size_t index, const T &value)
{
    if(index > m_size)
    {
        throw std::out_of_range("Index out of range");
    }

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

    for (size_t i = m_size; i > index; --i)
    {
        m_data[i] = std::move(m_data[i - 1]); 
    }

    m_data[index] = value;

    ++m_size;
    
}

template <typename T>
void Vector<T>::erase(size_t index)
{
    if (index >= m_size)
    {
        throw std::out_of_range("Index out of range");
    }

    for (size_t i = index; i < m_size - 1; ++i)
    {
        m_data[i] = std::move(m_data[i + 1]);
    }
    
    --m_size;
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] m_data;
}

int main(int argc, char const *argv[])
{
    Vector<int> vec = {1, 2, 3, 4, 5};

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    const Vector<int> constVec = {6, 7, 8, 9, 10};
    for (auto it = constVec.cbegin(); it != constVec.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl; 

    return 0;
}
