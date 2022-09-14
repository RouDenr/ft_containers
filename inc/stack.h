// Copyright 2022 by decordel

#ifndef __STACK_H__
# define __STACK_H__
#include "vector.hpp"
//#include <memory>

namespace ft {

    template <typename T, typename Container = vector<T> >
    class stack {
    public:
        typedef Container container_type;
        typedef typename Container::value_type      value_type;
        typedef typename Container::size_type       size_type;
        typedef typename Container::reference       reference;
        typedef typename Container::const_reference const_reference;

//        stack() : c() {}
        explicit stack(const Container& cont = Container()) {
            this->c = cont;
        }
        stack( const stack& other ) : c(other.c) {}
        ~stack() {}

        stack& operator=(const stack& other) {
            this->c = other.c;
        }
        reference top() { return c.back(); }
        const_reference top() const { return c.back(); }

        bool empty() const { return c.empty(); }
        size_type size() const { return c.size(); }
        void push( const value_type& value ) { c.push_back(value); }
        void pop() { c.pop_back(); }

        bool operator==(const stack<T,Container>& rhs ) { return this->c == rhs.c;}
        bool operator!=(const stack<T,Container>& rhs ) { return this->c != rhs.c;}
        bool operator< (const stack<T,Container>& rhs ) { return this->c < rhs.c;}
        bool operator<=(const stack<T,Container>& rhs ) { return this->c <= rhs.c;}
        bool operator> (const stack<T,Container>& rhs ) { return this->c > rhs.c;}
        bool operator>=(const stack<T,Container>& rhs ) { return this->c >= rhs.c;}

    protected:
        Container c;
    };
}

#endif //__STACK_H__
