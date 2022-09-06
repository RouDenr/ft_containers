// Copyright 2022 by decordel

#ifndef __CONTAINERS_H__
# define __CONTAINERS_H__
# include "vector.hpp"
# include <vector>

namespace ft {

    template< class T >
            void swap(T& a, T& b) {
                T temp = a;
                a = b;
                b = temp;
            }

    template< class Iter >
    struct iterator_traits {

    };

    template< class T >
    struct iterator_traits<T*> {

    };

    template< class T >
    struct iterator_traits<const T*> {

    };
}

#endif //__CONTAINERS_H__
