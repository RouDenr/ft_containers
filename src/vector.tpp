// Copyright 2022 by decordel

#include "../inc/containers.h"
#include "../inc/vector.hpp"

#include <exception>
//#include <algorithm>
//


template <typename T, typename Allocator>
vector<T, Allocator>::vector() {
    this->_alloc = Allocator();
    this->_data = NULL;
    this->_capacity = 0;
    this->_size = 0;

}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(Allocator &alloc) {
    this->_alloc = alloc;
    this->_data = NULL;
    this->_capacity = 0;
    this->_size = 0;
}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(size_type count,
                const T& value,
                const Allocator& allocator) {
    this->_alloc = allocator;
    this->_data = this->_alloc.allocate(count);
    for (size_type i = 0; i < count; ++i) {
        _data[i] = value;
    }
    this->_capacity = count;
    this->_size = count;
}

template <typename T, typename Allocator>
template <
        typename InputIt
        , typename
         >
vector<T, Allocator>::vector(InputIt first, InputIt last,
                             const Allocator& alloc
//        , typename enable_if< _is_not_integral<T>::value >::type*
                             ) {
    this->_alloc = alloc;
    this->_capacity = 0;
    for (InputIt i = first; i != last ; ++i) {
        this->_capacity++;
    }
    this->_size = this->_capacity;
    this->_data = this->_alloc.allocate(this->_capacity);
    size_type n = 0;
    for (InputIt i = first; i != last ; i++, n++) {
        this->_data[n] = *i;
    }
}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(const vector& other) {
    this->_capacity = other._capacity;
    this->_size = other.size();
    this->_alloc = Allocator();
    this->_data = this->_alloc.allocate(other._capacity);
    for (size_type i; i < this->_size; i++)
        this->_data = other._data[i];
}

template <typename T, typename Allocator>
vector<T, Allocator>& vector<T, Allocator>::operator=(const vector& other) {
    if (this->_data != other._data) {
        if (this->data() != NULL)
            this->_alloc.deallocate(this->_data, this->_capacity);
        this->_capacity = other._capacity;
        this->_size = other.size();
        this->_data = this->_alloc.allocate(other._capacity);
        for (size_type i = 0; i < this->_size; i++)
            this->_data[i] = other._data[i];
    }
    return *this;
}

template <typename T, typename Allocator>
vector<T, Allocator>::~vector() {
    this->_alloc.deallocate(this->_data, this->_capacity);
}


template <typename T, typename Allocator>
T& vector<T, Allocator>::operator[](size_type n) {
    return this->_data[n];
}

template <typename T, typename Allocator>
bool vector<T, Allocator>:: operator==(const vector& other) {
    return this->_data == other.data();
}
template <typename T, typename Allocator>
bool vector<T, Allocator>:: operator!=(const vector& other) {
    return this->_data != other.data();
}
template <typename T, typename Allocator>
bool vector<T, Allocator>:: operator>=(const vector& other) {
    for (size_type i = 0; i <= size(); i++) {
        if (this->_data[i] >= other._data[i])
            return true;
    }
    return false;
}
template <typename T, typename Allocator>
bool vector<T, Allocator>:: operator>(const vector& other) {
    for (size_type i = 0; i <= size(); i++) {
        if (this->_data[i] > other._data[i])
            return true;
    }
    return false;

}
template <typename T, typename Allocator>
bool vector<T, Allocator>:: operator<=(const vector& other) {
    for (size_type i = 0; i <= size(); i++) {
        if (this->_data[i] <= other._data[i])
            return true;
    }
    return false;

}
template <typename T, typename Allocator>
bool vector<T, Allocator>:: operator<(const vector& other) {
    for (size_type i = 0; i <= size(); i++) {
        if (this->_data[i] < other._data[i])
            return true;
    }
    return false;

}

//template <typename T, typename Allocator>
//template<class InputIt>
//void vector<T, Allocator>::assign( InputIt first, InputIt last ) {
//
//}

template <typename T, typename Allocator>
Allocator vector<T, Allocator>::get_allocator() const {
    return this->_alloc;
}


template<typename T, typename Allocator>
const T& vector<T, Allocator>::at(vector::size_type pos) const {
    if (pos >= size() || size() == 0)
        throw std::out_of_range("vector");
    return this->_data[pos];
}

template<typename T, typename Allocator>
T& vector<T, Allocator>::at(vector::size_type pos) {
    if (pos >= size() || size() == 0)
        throw std::out_of_range("vector");
    return this->_data[pos];
}

template<typename T, typename Allocator>
T& vector<T, Allocator>::front() {
    return *begin();
}

template<typename T, typename Allocator>
const T& vector<T, Allocator>::front() const {
    return *begin();
}

template<typename T, typename Allocator>
T& vector<T, Allocator>::back() {
    return *(end() - 1);
}

template<typename T, typename Allocator>
const T& vector<T, Allocator>::back() const {
    return *(end() - 1);
}

template<typename T, typename Allocator>
T *vector<T, Allocator>::data() {
    return this->_data;
}

template<typename T, typename Allocator>
const T *vector<T, Allocator>::data() const {
    return this->_data;
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::begin() {
    return vector::iterator(data());
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::end() {
    return vector::iterator(this->_data + this->_size);
}
template<typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::begin() const {
    return vector::const_iterator(data());
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::end() const {
    return vector::const_iterator(data() + size());
}


template<typename T, typename Allocator>
bool vector<T, Allocator>::empty() const {
    return !size();
}



template<typename T, typename Allocator>
size_t vector<T, Allocator>::size() const {
    return this->_size;
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::size_type vector<T, Allocator>::max_size() const {
    return this->_alloc.max_size();
}

template<typename T, typename Allocator>
void vector<T, Allocator>::reserve(vector::size_type new_cap) {
    if (new_cap <= capacity())
        return;

    pointer copy;
    size_type tmp_cap;

    if (capacity() * 2 < new_cap)
        tmp_cap = (new_cap > 128) ? new_cap : 128;
    else
        tmp_cap = capacity() * 2;
    if (tmp_cap > max_size())
        throw std::length_error("vector");
    copy = this->_alloc.allocate(tmp_cap);
    std::copy(begin(), end(), copy);

    this->_alloc.deallocate(this->_data, this->_capacity);
    this->_capacity = tmp_cap;
    this->_data = copy;
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::size_type vector<T, Allocator>::capacity() const {
    return this->_capacity;
}

template<typename T, typename Allocator>
void vector<T, Allocator>::clear() {
//    this->_alloc.deallocate(this->_data, this->_capacity);
//    this->_capacity = 0;
    this->_size = 0;
//    this->_data = NULL;
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::insert(vector::iterator pos, const T &value) {
    value_type temp = *pos;
    size_type index_pos;

    for (index_pos = 0; &(this->_data[index_pos]) != pos; ++index_pos);
    *pos = value;
    if (size() + 1 > capacity())
        reserve(size() + 1);
    this->_size++;
    for (size_type i = index_pos + 1; i < size(); ++i) {
        std::swap(at(i), temp);
    }
    return iterator(this->_data + index_pos);
}

template<typename T, typename Allocator>
void vector<T, Allocator>::insert(vector::iterator pos, vector::size_type count,
                                  const T &value) {
    size_type index_pos;

    for (index_pos = 0; &(this->_data[index_pos]) != pos; ++index_pos);
    if (size() + count > capacity())
        reserve(size() + count);
    this->_size += count;
    std::cout << index_pos << std::endl;
    std::memmove(this->_data + index_pos + count, this->_data + index_pos,
                 count * sizeof value);
    for (size_type i = index_pos; i < count; i++) {
        at(i) = value;
    }
}

template<typename T, typename Allocator>
void vector<T, Allocator>::insert(vector::iterator pos, pointer first,
                                  pointer last) {
    size_type index_pos;
    size_type count = 0;

    for (index_pos = 0; &(this->_data[index_pos]) != pos; ++index_pos);
    for (pointer i = first; i != last; i++)
        count++;
    if (size() + count > capacity())
        reserve(size() + count);
    this->_size += count;
    if (index_pos < size())
        std::memmove(this->_data + index_pos + count, this->_data + index_pos,
                     count * sizeof *first);
    for (size_type i = index_pos; i < count + index_pos; i++) {
        this->_data[i] = *first;
        first++;
    }
}

template<typename T, typename Allocator>
void vector<T, Allocator>::assign(vector::size_type count, const T &value) {
    reserve(count);
    for (size_type i = 0; i < count; i++) {
        at(i) = value;
    }
    this->_size = count;
}

template<typename T, typename Allocator>
void vector<T, Allocator>::assign(pointer first, pointer last) {
    size_type count = 0;

    for (pointer i = first; i != last; i++)
        count++;
    for (size_type i = 0; i < count; i++) {
        at(i) = *first;
        first++;
    }
    this->_size = count;

}

template<typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>
        ::erase(vector::iterator pos) {
    if (size() == 0)
        return pos;
    size_type count = 0;
    for (const_iterator i = begin(); i != pos; i++)
        count++;
    for (iterator i = pos; i != end(); i++)
        *i = *(i + 1);
    this->_size--;
    return pos;
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::erase(vector::iterator first, vector::iterator last) {
    size_type tmp_size = size();
    iterator j = last + 1;
    for (iterator i = first; i != end(); i++) {
        if (i < last + 1)
            tmp_size--;
        if (j != end()) {
            *i = *j;
            j++;
        }
    }
    this->_size = tmp_size;
    return first;
}

template<typename T, typename Allocator>
void vector<T, Allocator>::push_back(const T &value) {
    if (size() + 1 > capacity())
        reserve(size() + 1);
    this->_size++;
    *(end() - 1) = value;
}

template<typename T, typename Allocator>
void vector<T, Allocator>::pop_back() {
    _size--;
}

template<typename T, typename Allocator>
void vector<T, Allocator>::resize(vector::size_type count, T value) {
    if (size() < count) {
        reserve(count);
        iterator t = end();
        for (size_type i = 0; i < count; ++i, ++t) {
            *t = value;
        }
    }
    this->_size = count;
}

template<typename T, typename Allocator>
void vector<T, Allocator>::swap(vector &other) {
    std::swap(this->_data, other._data);
    if (std::allocator_traits<allocator_type>::propagate_on_container_swap::value)
        std::swap(this->_alloc, other._alloc);
    std::swap(this->_size, other._size);
    std::swap(this->_capacity, other._capacity);
}

template<typename T, typename Allocator>
reverse_iterator<typename vector<T, Allocator>::iterator> vector<T, Allocator>::rbegin() {
    return reverse_iterator<iterator>(end());
}

template<typename T, typename Allocator>
reverse_iterator<typename vector<T, Allocator>::iterator> vector<T, Allocator>::rend() {
    return reverse_iterator<iterator>(begin());
}






//! CONST_ITERATOR

template<typename T, typename Allocator>
vector<T, Allocator>::const_iterator::const_iterator() {
    this->_data = NULL;
}

template<typename T, typename Allocator>
vector<T, Allocator>::const_iterator::const_iterator(pointer ptr) {
    this->_data = ptr;
}

template<typename T, typename Allocator>
vector<T, Allocator>::const_iterator::const_iterator(const const_iterator& other) {
//    if (this->_data != other._data) {
        this->_data = other._data;
//    }
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator &vector<T, Allocator>::const_iterator::operator=(
        const vector::const_iterator &other) {
    if (this->_data != other._data) {
        this->_data = other._data;
    }
    return *this;
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator &vector<T, Allocator>::const_iterator::operator++() {
    this->_data++;
    return *this;
}
template<typename T, typename Allocator>
const typename vector<T, Allocator>::const_iterator vector<T, Allocator>::const_iterator::operator++(int) {
    const_iterator temp(*this);
    this->_data++;
    return temp;
}
template<typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator &vector<T, Allocator>::const_iterator::operator--() {
    this->_data--;
    return *this;
}
template<typename T, typename Allocator>
const typename vector<T, Allocator>::const_iterator vector<T, Allocator>::const_iterator::operator--(int) {
    const_iterator temp(*this);
    this->_data--;
    return temp;
}

template<typename T, typename Allocator>
vector<T, Allocator>::const_iterator::operator iterator() {
    return vector::iterator(this->_data);
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::const_iterator::operator*() const {
    return *this->_data;
}


template<typename T, typename Allocator>
vector<T, Allocator>::const_iterator::~const_iterator() {

}

template<typename T, typename Allocator>
bool vector<T, Allocator>::const_iterator::operator!=(
        const vector::const_iterator &other) {
    return this->_data != other._data;
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::const_iterator::operator+(size_type n) const {
    return vector::const_iterator(this->_data + n);
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::const_iterator::operator-(vector::size_type n) const {
    return vector::const_iterator(this->_data - n);
}

template<typename T, typename Allocator>
vector<T, Allocator>::const_iterator::operator const_pointer() const {
    return this->_data;
}

//! ITERATOR

//

template<typename T, typename Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::iterator::operator*() {
    return *this->_data;
}

template<typename T, typename Allocator>
vector<T, Allocator>::iterator::~iterator() {}

template<typename T, typename Allocator>
vector<T, Allocator>::iterator::operator pointer() {
    return this->_data;
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::iterator::operator+(vector::size_type n) {
    return vector::iterator(this->_data + n);
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::iterator::operator-(vector::size_type n) {
    return vector::iterator(this->_data - n);
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::iterator &
vector<T, Allocator>::iterator::operator=(const vector::iterator &other) {
    if (this->_data != other._data) {
        this->_data = other._data;
    }
    return *this;
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::vector::iterator
&vector<T, Allocator>::iterator::operator++() {
    this->_data++;
    return *this;
}

template<typename T, typename Allocator>
const typename vector<T, Allocator>::iterator
vector<T, Allocator>::iterator::operator++(int) {
    iterator temp(*this);
    this->_data++;
    return temp;
}
template<typename T, typename Allocator>
typename vector<T, Allocator>::vector::iterator
&vector<T, Allocator>::iterator::operator--() {
    this->_data--;
    return *this;
}

template<typename T, typename Allocator>
const typename vector<T, Allocator>::iterator
vector<T, Allocator>::iterator::operator--(int) {
    iterator temp(*this);
    this->_data--;
    return temp;
}
