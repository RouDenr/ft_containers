// Copyright 2022 by decordel
#ifndef __MAP_H__
#define __MAP_H__


# include <memory>
#include <map>

namespace ft {
    template <typename First, typename Second>
    class pair;

    template <  typename Key,
                typename T,
                typename Compare = std::less<Key>,
                typename Allocator = std::allocator<pair<const Key, T> >
                >
    class map {
    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef pair<const Key, T> value_type;
        typedef Allocator allocator_type;
        typedef typename std::ptrdiff_t difference_type;
        typedef Compare key_compare;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef typename Allocator::pointer pointer;
        typedef typename Allocator::const_pointer const_pointer;
        typedef typename std::size_t size_type;

        class const_iterator;
        class iterator;


        //! Constructors
        map(); // (1)
        explicit map(const Compare& comp,
                     const Allocator& alloc = Allocator()); // (2)
        explicit map(Allocator& alloc); // (3)
//        template<typename InputIt> // (4)
        map(pointer first, pointer last,
                const Compare& comp = Compare(),
                const Allocator& alloc = Allocator());

        map(const map& other); // (6)

        //! Destructor
        ~map();

        //!  assigns values to the container
        map& operator=(const map& other);

        //!  Element access
        reference at(size_type pos);
        const_reference at(size_type pos) const;

        //! Iterators functions
        const_iterator begin() const;
        const_iterator end()   const;
        iterator begin();
        iterator end();

        //! Capacity
        bool empty() const;
        size_type size() const;
        size_type max_size() const;

        void assign( size_type count, const T& value );
//        template< class InputIt >
        void assign( pointer first, pointer last );


        //! Modifiers
        void clear();

        pair<iterator, bool> insert(const T& value );
        void insert( iterator pos, size_type count, const T& value );
//        template< class InputIt >
        void insert(pointer first, pointer last );

        iterator erase( iterator pos );
        iterator erase( iterator first, iterator last );
        size_type erase( const Key& key );

        void swap( map& other );

        //! Lookup
        size_type count( const Key& key ) const;

        iterator find( const Key& key );
        const_iterator find( const Key& key ) const;

        pair<iterator,iterator> equal_range( const Key& key );
        pair<const_iterator,const_iterator> equal_range( const Key& key ) const;

        iterator lower_bound( const Key& key );
        const_iterator lower_bound( const Key& key ) const;

        iterator upper_bound( const Key& key );
        const_iterator upper_bound( const Key& key ) const;

        key_compare key_comp() const;


        reference operator[](size_type n);
        //! lexicographically compares the values in the map
        bool operator==(const map& other);
        bool operator!=(const map& other);
        bool operator<(const map& other);
        bool operator<=(const map& other);
        bool operator>(const map& other);
        bool operator>=(const map& other);

        allocator_type get_allocator() const;


        class value_compare {

        };

        value_compare value_comp() const;

    private:
        Allocator _alloc;
        T* _data;


        size_type _size;
        size_type _capacity;

    public:
        class const_iterator {
        public:
            typedef T value_type;
            typedef Allocator allocator_type;
            typedef typename std::ptrdiff_t difference_type;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef typename Allocator::pointer pointer;
            typedef typename Allocator::const_pointer const_pointer;
            typedef typename std::size_t size_type;
            typedef typename std::random_access_iterator_tag iterator_category;

            const_iterator();
            explicit const_iterator(pointer ptr);
            explicit const_iterator(const_pointer ptr);
            const_iterator(const const_iterator& other);


            const_iterator&         operator=(const const_iterator&);
            const_iterator&         operator++();
            const const_iterator    operator++(int);
            const_iterator&         operator--();
            const const_iterator    operator--(int);

            const_iterator         operator+(size_type n) const;
            const_iterator         operator-(size_type n) const;

            const_reference         operator*() const;
            operator const_pointer() const;

            bool operator!=(const const_iterator&);


            ~const_iterator();

        protected:
            pointer _data;
        };
        class iterator : public const_iterator {
        public:




            iterator() : const_iterator() {}
            explicit iterator(pointer ptr) : const_iterator(ptr) {}
            iterator(const iterator& other) : const_iterator(other) {}
            explicit iterator(const const_iterator& other) : const_iterator(other) {}


            iterator         operator+(size_type n);
            iterator         operator-(size_type n);

            reference   operator*();
            operator pointer();


            ~iterator();
        };
    };


# include "../src/map.tpp"
}
#endif //__MAP_H__
