// Copyright 2022 by decordel

#ifndef __CONTAINERS_H__
# define __CONTAINERS_H__
# include "vector.hpp"
# include "stack.h"
//# include "map.h"
# include <vector>

namespace ft {
//
//    template< class T >
//            void swap(T& a, T& b) {
//                T temp = a;
//                a = b;
//                b = temp;
//            }
//
//    template< class Iter >
//    struct iterator_traits {
//
//    };
//
//    template< class T >
//    struct iterator_traits<T*> {
//
//    };
//
//    template< class T >
//    struct iterator_traits<const T*> {
//
//    };
//
//    template< class Iter >
//    class reverse_iterator {
//        typedef Iter iterator_type;
//        typedef iterator_traits<Iter>::iterator_category iterator_category;
//        typedef iterator_traits<Iter>::value_type value_type;
//        typedef iterator_traits<Iter>::difference_type difference_type;
//        typedef iterator_traits<Iter>::pointer pointer;
//        typedef iterator_traits<Iter>::reference reference;
//
//        reverse_iterator();
//        explicit reverse_iterator( iterator_type x );
//        template< class U >
//        reverse_iterator( const reverse_iterator<U>& other );
//
//        template< class U >
//        reverse_iterator& operator=( const reverse_iterator<U>& other );
//
//        iterator_type base() const;
//
//
//        reverse_iterator& operator++();
//        reverse_iterator& operator--();
//        reverse_iterator operator++( int );
//        reverse_iterator operator--( int );
//        reverse_iterator operator+( difference_type n ) const;
//        reverse_iterator operator-( difference_type n ) const;
//        reverse_iterator& operator-=( difference_type n );
//        reverse_iterator& operator+=( difference_type n );
//
//        reference operator*() const;
//        pointer operator->() const;
//        operator[]( difference_type n ) const;
//
//
//}
//
//
//    template< class Iterator1, class Iterator2 >
//    bool operator==( const reverse_iterator<Iterator1>& lhs,
//                     const reverse_iterator<Iterator2>& rhs );
//    template< class Iterator1, class Iterator2 >
//    constexpr bool operator==( const reverse_iterator<Iterator1>& lhs,
//                               const reverse_iterator<Iterator2>& rhs );
//    template< class Iterator1, class Iterator2 >
//    bool operator!=( const reverse_iterator<Iterator1>& lhs,
//                     const reverse_iterator<Iterator2>& rhs );
//    template< class Iterator1, class Iterator2 >
//    constexpr bool operator!=( const reverse_iterator<Iterator1>& lhs,
//                               const reverse_iterator<Iterator2>& rhs );
//    template< class Iterator1, class Iterator2 >
//    bool operator<( const reverse_iterator<Iterator1>& lhs,
//                    const reverse_iterator<Iterator2>& rhs );
//    template< class Iterator1, class Iterator2 >
//    constexpr bool operator<( const reverse_iterator<Iterator1>& lhs,
//                              const reverse_iterator<Iterator2>& rhs );
//    template< class Iterator1, class Iterator2 >
//    bool operator<=( const reverse_iterator<Iterator1>& lhs,
//                     const reverse_iterator<Iterator2>& rhs );
//    template< class Iterator1, class Iterator2 >
//    constexpr bool operator<=( const reverse_iterator<Iterator1>& lhs,
//                               const reverse_iterator<Iterator2>& rhs );
//    template< class Iterator1, class Iterator2 >
//    bool operator>( const reverse_iterator<Iterator1>& lhs,
//                    const reverse_iterator<Iterator2>& rhs );
//    template< class Iterator1, class Iterator2 >
//    constexpr bool operator>( const reverse_iterator<Iterator1>& lhs,
//                              const reverse_iterator<Iterator2>& rhs );
//    template< class Iterator1, class Iterator2 >
//    bool operator>=( const reverse_iterator<Iterator1>& lhs,
//                     const reverse_iterator<Iterator2>& rhs );
//
//
//    template< class Iter >
//    reverse_iterator<Iter>
//    operator+( typename reverse_iterator<Iter>::difference_type n,
//               const reverse_iterator<Iter>& it );
//
//    template< class Iterator >
//    typename reverse_iterator<Iterator>::difference_type
//    operator-( const reverse_iterator<Iterator>& lhs,
//               const reverse_iterator<Iterator>& rhs );
//
//
//
//    template< bool B, class T = void >
//    struct enable_if {
//
//    };



    //// IS INTEGRAL
//
    template <typename T, T val>
    struct integral_constant {
        static const T  value = val;
        typedef T value_type;
        typedef integral_constant type;
    };

    typedef integral_constant<bool, true> true_type;
    typedef integral_constant<bool, false> false_type;

    template <class> struct is_integral : public false_type {};

    template<> struct is_integral<bool> : public true_type {};
    template<> struct is_integral<char> : public true_type {};
    template<> struct is_integral<wchar_t> : public true_type {};



    template<> struct is_integral<unsigned char> : public true_type {};
    template<> struct is_integral<unsigned short int> : public true_type {};
    template<> struct is_integral<unsigned int> : public true_type {};
    template<> struct is_integral<unsigned long int> : public true_type {};

# ifdef LLONG_MAX
    template<> struct is_integral<unsigned long long int> : public true_type {};
# endif

    template<> struct is_integral<signed char> : public true_type {};
    template<> struct is_integral<short int> : public true_type {};
    template<> struct is_integral<int> : public true_type {};
    template<> struct is_integral<long int> : public true_type {};

# ifdef LLONG_MAX
    template<> struct is_integral<long long int> : public true_type {};
# endif

    template <class _Tp> struct _is_integral : public is_integral<_Tp> {};

    template<> struct is_integral<char16_t> : public true_type {};
    template<> struct is_integral<char32_t> : public true_type {};

//




//
//
//    template< class InputIt1,
//            class InputIt2,
//            class BinaryPredicate >
//    bool equal( InputIt1 first1,
//                InputIt1 last1,
//                InputIt2 first2,
//                BinaryPredicate p );
//
//    template< class InputIt1, class InputIt2 >
//    bool equal( InputIt1 first1, InputIt1 last1,
//                InputIt2 first2 );
//
//
    template<
            class T1,
            class T2
    > struct pair {
     public:
        typedef T1 first_type;
        typedef T2 second_type;

        pair() { first = first_type(); second = second_type(); }
        pair( const T1& x, const T2& y ) : first(x), second(y) {}
//        pair( const pair& p ) = default;

        pair& operator=( const pair& other ) {
            this->first = other.first;
            this->second = other.second;
        }


        T1 first;
        T2 second;
    };
//
    template <class T1, class T2>
    pair<T1,T2> make_pair (T1 x, T2 y) {
        return pair<T1, T2>(x, y);
    }








}


#endif //__CONTAINERS_H__
