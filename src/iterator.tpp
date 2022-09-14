// Copyright 2022 by decordel

#include "../inc/containers.h"


template<class Iter>
reverse_iterator<Iter>::reverse_iterator() {
    this->base = Iter();
}

template<class Iter>
reverse_iterator<Iter>::reverse_iterator(iterator_type x) {
    this->_base = x;
}

template<class Iter>
template< class U >
reverse_iterator<Iter>::reverse_iterator( const reverse_iterator<U>& other ) {
    if (this != &other) {
        this->_base = other._base;
    }
}

template<class Iter>
typename reverse_iterator<Iter>::iterator_type
reverse_iterator<Iter>::base() const {
    return this->_base;
}

template<class Iter>
reverse_iterator<Iter> &reverse_iterator<Iter>::operator++() {
    this->_base--;
    return *this;
}
template<class Iter>
reverse_iterator<Iter> &reverse_iterator<Iter>::operator--() {
    this->_base++;
    return *this;
}
template<class Iter>
reverse_iterator<Iter> reverse_iterator<Iter>::operator++(int) {
    reverse_iterator<Iter> tmp(_base);
    this->_base--;
    return tmp;
}

template<class Iter>
reverse_iterator<Iter> reverse_iterator<Iter>::operator--(int) {
    reverse_iterator<Iter> tmp(_base);
    this->_base++;
    return tmp;
}

template<class Iter>
reverse_iterator<Iter>
reverse_iterator<Iter>::operator+(reverse_iterator::difference_type n) const {
    return reverse_iterator(this->_base - n);
}

template<class Iter>
reverse_iterator<Iter>
reverse_iterator<Iter>::operator-(reverse_iterator::difference_type n) const {
    return reverse_iterator(this->_base + n);
}
template<class Iter>
reverse_iterator<Iter> &
reverse_iterator<Iter>::operator-=(reverse_iterator::difference_type n) {
    this->_base += n;
    return *this;
}
template<class Iter>
reverse_iterator<Iter> &
reverse_iterator<Iter>::operator+=(reverse_iterator::difference_type n) {
    this->_base -= n;
    return *this;
}

template<class Iter>
typename reverse_iterator<Iter>::reference
reverse_iterator<Iter>::operator*() const {
    Iter tmp = this->_base;
    return *(--tmp);
}

template<class Iter>
typename reverse_iterator<Iter>::pointer
reverse_iterator<Iter>::operator->() const {
    return std::addressof(operator*());
}

template<class Iter>
template<class U>
reverse_iterator<Iter> &
reverse_iterator<Iter>::operator=(const reverse_iterator<U> &other) {
    if (this != &other) {
        this->_base = other._base;
    }
    return *this;
}
