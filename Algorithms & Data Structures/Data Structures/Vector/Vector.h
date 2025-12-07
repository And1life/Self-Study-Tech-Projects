#include <iostream>

/**
 * @brief Dynamic array implementation similar to std::vector.
 *
 * This class provides a dynamic array that can resize itself automatically
 * when elements are added or removed. It supports various operations such
 * as insertion, deletion, and random access.
 *
 * @tparam T The type of elements stored in the vector.
 */
template<typename T>
class Vector
{
private:
    /**
     * @brief Pointer to a dynamic array: stores the elements of a vector.
     */
    T* m_data; 

    /**
     * @brief Current size: the number of elements in the vector.
     */
    size_t m_size;

    /**
     * @brief Capacity: The number of elements that the allocated memory can hold without reallocation.
     */
    size_t m_capacity;

public:
    /**
     * @brief Default constructor: Initializes an empty vector.
     */
    Vector();

    /**
     * @brief Constructor with parameter: allows you to set the initial capacity.
     *
     * @param initialCapacity The initial capacity of the vector.
     */
    Vector(size_t initialCapacity);

    /**
     * @brief Copy constructor: Creates a copy of another vector.
     *
     * @param other The vector to copy from.
     */
    Vector(const Vector& other);

    /**
     * @brief Move constructor: Moves resources from another vector.
     *
     * @param other The vector to move from. After moving, other will be in a valid but unspecified state.
     */
    Vector(Vector&& other) noexcept;

    /**
     * @brief Constructor for initializing a vector with elements from an initialization list.
     *
     * @param init_list The initializer list to initialize the vector with.
     */
    Vector(std::initializer_list<T> init_list);

    /**
     * @brief Copy assignment operator: copies data from another vector.
     *
     * @param other The vector to copy from.
     * @return Reference to the current vector.
     */
    Vector& operator=(const Vector& other);

    /**
     * @brief Move assignment operator: Moves resources from another vector.
     *
     * @param other The vector to move from. After moving, other will be in a valid but unspecified state.
     * @return Reference to the current vector.
     */
    Vector& operator=(Vector&& other) noexcept;

    /**
     * @brief Index access operator: Allows access to elements by index.
     *
     * @param index The index of the element to access.
     * @return Reference to the element at the specified index.
     */
    T& operator[](size_t index);

    /**
     * @brief Const version Index access operator.
     *
     * @param index The index of the element to access.
     * @return Const reference to the element at the specified index.
     */
    const T& operator[](size_t index) const;

    /**
     * @brief Returns the current size of the vector.
     *
     * @return The number of elements in the vector.
     */
    size_t getSize() const;

    /**
     * @brief Returns the current capacity of the vector.
     *
     * @return The number of elements that the vector can hold without reallocation.
     */
    size_t getCapacity() const;

    /**
     * @brief Checks if a vector is empty.
     *
     * @return True if the vector is empty, false otherwise.
     */
    bool empty() const;

    /**
     * @brief Access to a vector element at a specified index with bounds checking.
     *
     * @param index The position of the element to access.
     * @return Reference to the element at the specified position.
     * @throw std::out_of_range If the index is out of range.
     */
    T& at(size_t index);

    /**
     * @brief Const version at().
     *
     * @param index The position of the element to access.
     * @return Const reference to the element at the specified position.
     * @throw std::out_of_range If the index is out of range.
     */
    const T& at(size_t index) const;

    /**
     * @brief Adds an element to the end of the vector.
     *
     * @param value The value to be added to the vector.
     */
    void push_back(const T& value);

    /**
     * @brief Adds an element to the end of the vector using move semantics.
     *
     * @param value The value to be added to the vector.
     */
    void push_back(T&& value);

    /**
     * @brief Removes the last element.
     *
     * @throw std::out_of_range If the vector is empty.
     */
    void pop_back();

    /**
     * @brief Pre-allocation of memory for vector elements.
     *
     * @param new_capacity The new capacity of the vector.
     */
    void reserve(size_t new_capacity);

    /**
     * @brief Changes in the number of elements in a vector.
     *
     * @param new_size The new size of the vector.
     * @param value The value to initialize new elements with (default is T()).
     */
    void resize(size_t new_size, const T& value = T());

    /**
     * @brief Decreasing the capacity of a vector to its current size.
     */
    void shrink_to_fit();

    /**
     * @brief Clears the vector but does't free the memory.
     */
    void clear();

    /**
     * @brief Inserts an element at the specified position.
     *
     * @param index The position at which the element will be inserted.
     * @param value The value to be inserted.
     * @throw std::out_of_range If the index is out of range.
     */
    void insert(size_t index, const T& value);

    /**
     * @brief Removes an element from the specified position.
     *
     * @param index The position of the element to be removed.
     * @throw std::out_of_range If the index is out of range.
     */
    void erase(size_t index);

    /**
     * @brief Destructor: Frees allocated memory.
     */
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

    /**
    * @brief Returns an iterator pointing to the first element of the vector.
    *
    * @return Iterator pointing to the first element.
    */
    Iterator begin()
    {
        return Iterator(m_data);
    }

    /**
    * @brief Returns an iterator pointing to the position beyond the last element of the vector.
    *
    * @return Iterator pointing to the position beyond the last element.
    */
    Iterator end()
    {
        return Iterator(m_data + m_size);
    }

    /**
    * @brief Returns a const iterator pointing to the first element of the vector.
    *
    * @return ConstIterator pointing to the first element.
    */
    ConstIterator begin() const
    {
        return ConstIterator(m_data);
    }

    /**
    * @brief Returns a const iterator pointing to the position beyond the last element of the vector.
    *
    * @return ConstIterator pointing to the position beyond the last element.
    */
    ConstIterator end() const
    {
        return ConstIterator(m_data + m_size);
    }

    /**
    * @brief Returns a const iterator pointing to the first element of the vector.
    *
    * @return ConstIterator pointing to the first element.
    */
    ConstIterator cbegin() const
    {
        return ConstIterator(m_data);
    }
    
    /**
    * @brief Returns a const iterator pointing to the position beyond the last element of the vector.
    *
    * @return ConstIterator pointing to the position beyond the last element.
    */
    ConstIterator cend() const
    {
        return ConstIterator(m_data + m_size);
    }
};

template<typename T>
Vector<T>::Vector() : m_data(nullptr), m_size(0), m_capacity(0)
{
    // Initialize an empty vector.
}

template <typename T>
Vector<T>::Vector(size_t initialCapacity)
    : m_data(new T[initialCapacity]), m_size(0), m_capacity(initialCapacity)
{
    // Initialize a vector with the specified initial capacity.
}

template <typename T>
Vector<T>::Vector(const Vector &other)
    : m_data(new T[other.m_capacity]), m_capacity(other.m_capacity), m_size(other.m_size)
{
    // Copy elements from the other vector.
    for (size_t i = 0; i < m_size; ++i)
    {
        m_data[i] = other.m_data[i];
    }
    
}

template <typename T>
Vector<T>::Vector(Vector &&other) noexcept
    : m_data(other.m_data), m_capacity(other.m_capacity), m_size(other.m_size)
{
    // Move resources from the other vector.
    other.m_data = nullptr;
    other.m_capacity = 0;
    other.m_size = 0;
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> init_list)
    : m_data(new T[init_list.size()]), m_capacity(init_list.size()), m_size(init_list.size())
{
    // Initialize the vector with elements from the initializer list.
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
T& Vector<T>::at(size_t index)
{
    if (index >= m_size)
    {
        throw std::out_of_range("Index out of range");
    }
    return m_data[index];
}

template <typename T>
const T &Vector<T>::at(size_t index) const
{
    if (index >= m_size)
    {
        throw std::out_of_range("Index out of range");
    }
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
    if (m_size == 0)
    {
        throw std::out_of_range("Can't pop_back from an empty vector");
    }
    --m_size;
    
}

template <typename T>
void Vector<T>::reserve(size_t new_capacity)
{
    if (new_capacity <= m_capacity)
    {
        return;
    }

    T* new_data = new T[new_capacity];
    for (size_t i = 0; i < m_size; ++i)
    {
        new_data[i] = std::move(m_data[i]);
    }
    delete[] m_data;
    m_data = new_data;
    m_capacity = new_capacity;  
}

template <typename T>
void Vector<T>::resize(size_t new_size, const T& value)
{
    if (new_size == m_size)
    {
        return;
    }

    if (new_size > m_capacity)
    {
        reserve(new_size);
    }

    if (new_size > m_size)
    {
        for (size_t i = m_size; i < new_size; ++i)
        {
            m_data[i] = value;
        }
    }
    
    m_size = new_size; 
}

template <typename T>
void Vector<T>::shrink_to_fit()
{
    if (m_capacity == m_size)
    {
        return;
    }

    T* new_data = new T[m_size];
    for (size_t i = 0; i < m_size; ++i)
    {
        new_data[i] = std::move(m_data[i]);
    }
    delete[] m_data;
    m_data = new_data;
    m_capacity = m_size; 
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
