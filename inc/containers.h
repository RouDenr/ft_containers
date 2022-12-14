// Copyright 2022 by decordel

#ifndef __CONTAINERS_H__
# define __CONTAINERS_H__

namespace ft {

    template< class T >
            void swap(T& a, T& b) {
                T temp = a;
                a = b;
                b = temp;
            }

    template< class Iter >
    struct iterator_traits {
        typedef typename Iter::difference_type      difference_type;
        typedef typename Iter::value_type           value_type;
        typedef typename Iter::pointer              pointer;
        typedef typename Iter::reference            reference;
        typedef typename Iter::iterator_category    iterator_category;
    };

    template< class T >
    struct iterator_traits<T*> {
        typedef std::ptrdiff_t                  difference_type;
        typedef T                               value_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef std::random_access_iterator_tag iterator_category;
    };


    template< class Iter >
    class reverse_iterator {
     public:
        typedef Iter iterator_type;
        typedef typename iterator_traits<Iter>::iterator_category iterator_category;
        typedef typename iterator_traits<Iter>::value_type value_type;
        typedef typename iterator_traits<Iter>::difference_type difference_type;
        typedef typename iterator_traits<Iter>::pointer pointer;
        typedef typename iterator_traits<Iter>::reference reference;

        reverse_iterator();
        explicit reverse_iterator( iterator_type x );
        template< class U >
        explicit reverse_iterator( const reverse_iterator<U>& other );

        template< class U >
        reverse_iterator& operator=( const reverse_iterator<U>& other );

        iterator_type base() const;


        reverse_iterator& operator++();
        reverse_iterator& operator--();
        reverse_iterator operator++( int );
        reverse_iterator operator--( int );
        reverse_iterator operator+( difference_type n ) const;
        reverse_iterator operator-( difference_type n ) const;
        reverse_iterator& operator-=( difference_type n );
        reverse_iterator& operator+=( difference_type n );

        reference operator*() const;
        pointer operator->() const;
//        operator[]( difference_type n ) const;



     private:
        iterator_type _base;
};



    template< class Iterator1, class Iterator2 >
    bool operator==( const reverse_iterator<Iterator1>& lhs,
                     const reverse_iterator<Iterator2>& rhs ) {
        return lhs.base() == rhs.base();

    }
    template< class Iterator1, class Iterator2 >
    bool operator!=( const reverse_iterator<Iterator1>& lhs,
                     const reverse_iterator<Iterator2>& rhs ) {
        return lhs.base() != rhs.base();
    }
    template< class Iterator1, class Iterator2 >
    bool operator<( const reverse_iterator<Iterator1>& lhs,
                    const reverse_iterator<Iterator2>& rhs ) {
        return lhs.base() < rhs.base();
    }
    template< class Iterator1, class Iterator2 >
    bool operator<=( const reverse_iterator<Iterator1>& lhs,
                     const reverse_iterator<Iterator2>& rhs ) {
        return lhs.base() <= rhs.base();
    }
    template< class Iterator1, class Iterator2 >
    bool operator>( const reverse_iterator<Iterator1>& lhs,
                    const reverse_iterator<Iterator2>& rhs )  {
        return lhs.base() > rhs.base();
    }
    template< class Iterator1, class Iterator2 >
    bool operator>=( const reverse_iterator<Iterator1>& lhs,
                     const reverse_iterator<Iterator2>& rhs ) {
        return lhs.base() >= rhs.base();
    }


    template< class Iter >
    reverse_iterator<Iter>
    operator+( typename reverse_iterator<Iter>::difference_type n,
               const reverse_iterator<Iter>& it );

    template< class Iterator >
    typename reverse_iterator<Iterator>::difference_type
    operator-( const reverse_iterator<Iterator>& lhs,
               const reverse_iterator<Iterator>& rhs );




    template< bool B, typename T = void >
    struct enable_if { };

    template< typename T>
    struct enable_if<true, T> { typedef T type; };


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

    template <class Tp> struct _is_integral : public is_integral<Tp> {};

    template<> struct is_integral<char16_t> : public true_type {};
    template<> struct is_integral<char32_t> : public true_type {};



    template< class InputIt1, class InputIt2 >
    bool equal( InputIt1 first1, InputIt1 last1,
                InputIt2 first2 ) {
        for (; first1 != last1; ++first1, ++first2)
            if (*first1 != *first2)
                return false;
        return true;
    }

    template< class InputIt1,
            class InputIt2,
            class BinaryPredicate >
    bool equal( InputIt1 first1,
                InputIt1 last1,
                InputIt2 first2,
                BinaryPredicate p ) {
        for (; first1 != last1; ++first1, ++first2) {
            if (!p(*first1, *first2)) {
                return false;
            }
        }
        return true;
    }

    template<
            class T1,
            class T2
    > struct pair {
     public:
        typedef T1 first_type;
        typedef T2 second_type;

        pair() { first = first_type(); second = second_type(); }
//        pair( const T1& x, T2& y ) : first(x), second(y) {}
        pair( const T1& x, const T2& y ) : first(x), second(y) {}
        pair( const pair& p ) {
            if (this != &p) {
                this->first = p.first;
                this->second= p.second;
            }
        }

        pair& operator=( const pair& other ) {
            if (this != &other) {
                this->first = other.first;
                this->second = other.second;
            }
            return *this;
        }


        T1 first;
        T2 second;
    };
//
    template <class T1, class T2>
    pair<T1,T2> make_pair (T1 x, T2 y) {
        return pair<T1, T2>(x, y);
    }






#include "../src/iterator.tpp"

}


#endif //__CONTAINERS_H__
