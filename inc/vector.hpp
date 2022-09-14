// Copyright 2022 by decordel

#ifndef __VECTOR_H__
# define __VECTOR_H__
# include <memory>
# include "containers.h"

namespace ft {
    template <typename T, typename Allocator = std::allocator<T> >
    class vector {
    public:
        typedef T value_type;
        typedef Allocator allocator_type;
        typedef typename std::ptrdiff_t difference_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef typename Allocator::pointer pointer;
        typedef typename Allocator::const_pointer const_pointer;
        typedef typename std::size_t size_type;

        class const_iterator;
        class iterator;



        //! Constructors
        vector(); // (1)
        explicit vector(Allocator& alloc); // (2)
        explicit vector(size_type count,   // (3)
                        const T& value = T(),
                        const Allocator& allocator = Allocator());
        template<
                class InputIt
                ,typename = typename enable_if< !is_integral<InputIt>::value >::type
        >
        vector(InputIt first, InputIt last,
               const Allocator& alloc = Allocator()
//                       , typename enable_if< _is_not_integral<T>::value >::type* = NULL
                       );

        vector(const vector& other); // (6)

        //! Destructor
        ~vector();

        //!  assigns values to the container
        vector& operator=(const vector& other);

        //!  Element access
        reference at(size_type pos);
        const_reference at(size_type pos) const;

        reference front();
        const_reference front() const;

        reference back();
        const_reference back() const;
        T* data();
        const T* data() const;

        //! Iterators functions
        const_iterator  begin() const;
        const_iterator  end()   const;
        iterator        begin();
        iterator        end();

        reverse_iterator<iterator> rbegin();
        reverse_iterator<iterator> rend();

        //! Capacity
        bool empty() const;
        size_type size() const;
        size_type max_size() const;
        void reserve( size_type new_cap );
        size_type capacity() const;

        void assign( size_type count, const T& value );
//        template< class InputIt >
        void assign( pointer first, pointer last );


        //! Modifiers
        void clear();

        iterator insert( iterator pos, const T& value );
        void insert( iterator pos, size_type count, const T& value );

//        template< class InputIt, typename = enable_if<is_integral<InputIt> > >
        void insert( iterator pos, pointer first, pointer last );

        iterator erase( iterator pos );
        iterator erase( iterator first, iterator last );

        void push_back( const T& value );
        void pop_back();

        void resize( size_type count, T value = T() );

        void swap( vector& other );




        reference operator[](size_type n);
        //! lexicographically compares the values in the vector
        bool operator==(const vector& other);
        bool operator!=(const vector& other);
        bool operator<(const vector& other);
        bool operator<=(const vector& other);
        bool operator>(const vector& other);
        bool operator>=(const vector& other);

        allocator_type get_allocator() const;





    private:

        Allocator _alloc;
        T* _data;


        size_type _size;
        size_type _capacity;

    public:
        class const_iterator {
         public:
            typedef T                                           value_type;
            typedef Allocator                                   allocator_type;
            typedef typename std::ptrdiff_t                     difference_type;
            typedef value_type&                                 reference;
            typedef const value_type&                           const_reference;
            typedef typename Allocator::pointer                 pointer;
            typedef typename Allocator::const_pointer           const_pointer;
            typedef typename std::size_t                        size_type;
            typedef typename std::random_access_iterator_tag    iterator_category;

            const_iterator();
            explicit const_iterator(pointer ptr);
            explicit const_iterator(const_pointer ptr);
            const_iterator(const const_iterator& other);


            const_iterator&         operator=(const const_iterator&);

            virtual const_iterator&         operator++();

            virtual const const_iterator    operator++(int);

            virtual const_iterator&         operator--();

            virtual const const_iterator    operator--(int);

            const_iterator         operator+(size_type n) const;
            const_iterator         operator-(size_type n) const;

            const_reference         operator*() const;
            operator const_pointer() const;

            bool operator!=(const const_iterator&);


            ~const_iterator();

         protected:
            pointer _data;
         private:
            operator iterator();
        };

        class iterator : public const_iterator {
         public:




            iterator() : const_iterator() {}
            explicit iterator(pointer ptr) : const_iterator(ptr) {}
            iterator(const iterator& other) : const_iterator(other) {}
            explicit iterator(const const_iterator& other) : const_iterator(other) {}



            iterator&           operator=(const iterator&);
            iterator&           operator++();
            const iterator      operator++(int);
            iterator&           operator--();
            const iterator      operator--(int);


            iterator         operator+(size_type n);
            iterator         operator-(size_type n);

            reference   operator*();
            operator pointer();


            ~iterator();
        };
    };


# include "../src/vector.tpp"
}

#endif //__VECTOR_H__
