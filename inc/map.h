// Copyright 2022 by decordel

#ifndef __MAP_H__
# define __MAP_H__


# include "containers.h"
# include <memory>
# include <map>
# include <iostream>

namespace ft {

    template <typename T>
    struct Node {
        Node*       left;
        Node*       right;
        Node*       parent;
        T           *value;
        bool red;
        //! NODE
//            Node *_create_new_node(
//                    Node* left,
//                    Node* right,
//                    Node* parent,
//                    value_type key_value);
//            void destroy_node(Node *node);
    };



    template <typename First, typename Second>
    struct pair;

    template <  typename Key,
                typename T,
                typename Compare = std::less<Key>,
                typename Allocator = std::allocator<pair<Key, T> >,
                typename NodeAllocator = std::allocator<Node<typename Allocator::value_type> >
                >
    class map {
     public:
        typedef Key                                 key_type;
        typedef T                                   mapped_type;
        typedef pair<key_type, mapped_type>         value_type;
        typedef Node<value_type>                    node_type;
        typedef Allocator                           allocator_type;
        typedef typename std::ptrdiff_t             difference_type;
        typedef Compare                             key_compare;
        typedef value_type&                         reference;
        typedef const value_type&                   const_reference;
        typedef typename Allocator::pointer         pointer;
        typedef typename Allocator::const_pointer   const_pointer;
        typedef typename std::size_t                size_type;

        class const_iterator;
        class iterator;

     private:
//        Node    *next_node(Node *this_n);
//        Node    *prev_node(Node *this_n);
//        bool is_last_node(Node *node);

     public:
        //! Constructors
        map()   : _head(NULL), _capacity(0), _size(0), _alloc(Allocator())
                , _node_alloc(NodeAllocator()), _compare(Compare()) {} // (1)
        map(const Compare& comp, const Allocator& alloc = Allocator())
                : _head(NULL), _capacity(0), _size(0), _alloc(alloc)
                , _node_alloc(NodeAllocator()), _compare(comp) {} // (2)
        map(Allocator& alloc)
                : _head(NULL), _capacity(0), _size(0), _alloc(alloc)
                , _node_alloc(NodeAllocator()), _compare(Compare()) {} // (3)
//        template<typename InputIt> // (4)
//        map(pointer first, pointer last,
//                const Compare& comp = Compare(),
//                const Allocator& alloc = Allocator());

        map(const map& other); // (6)

        //! Destructor
        ~map();

        //!  assigns values to the container
        map& operator=(const map& other);

        //!  Element access
        reference at(const Key& key);
        const_reference at(const Key& key) const;

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

        pair<iterator, bool> insert(const value_type& value );
        void insert( iterator pos, size_type count, const T& value );
//        template< class InputIt >
        void insert(pointer first, pointer last );

        iterator erase( iterator pos );
        iterator erase( iterator first, iterator last );
        size_type erase( const Key& key );

        void swap( map& other );

        //! Lookup
        size_type count( const Key& key ) const;

        iterator        find( const Key& key );
        const_iterator  find( const Key& key ) const;

        pair<iterator,iterator>                 equal_range( const Key& key );
        pair<const_iterator,const_iterator>     equal_range( const Key& key ) const;

        iterator        lower_bound( const Key& key );
        const_iterator  lower_bound( const Key& key ) const;

        iterator        upper_bound( const Key& key );
        const_iterator  upper_bound( const Key& key ) const;

        key_compare key_comp() const;


        T& operator[](Key key);
        //! lexicographically compares the values in the map
        bool operator==(const map& other);
        bool operator!=(const map& other);
        bool operator<(const map& other);
        bool operator<=(const map& other);
        bool operator>(const map& other);
        bool operator>=(const map& other);

        allocator_type get_allocator() const;

     protected:
        class value_compare  {
         public:
            typedef bool        result_type;
            typedef value_type  first_arg_type;
            typedef value_type  second_arg_type;

            value_compare(Compare c) : comp(c) {}
            bool operator()( const value_type& lhs, const value_type& rhs ) const {
                return this->comp(lhs.first, rhs.first);
            }
            bool operator()( const key_type& lhs, const key_type& rhs ) const {
                return this->comp(lhs, rhs);
            }

         protected:
            Compare comp;

        };

     public:
        value_compare value_comp() const;


     private:
        Node<value_type>    *_head;
        Allocator           _alloc;
        NodeAllocator       _node_alloc;
        size_type           _size;
        size_type           _capacity;
        value_compare       _compare;



        node_type *_create_new_node(
                node_type* left,
                node_type* right,
                node_type* parent,
                value_type key_value);

        void _delete_all_tree(node_type *head);
//        void map_init(co);

     public:
        class const_iterator {
         public:
            const_iterator() : _data(NULL), _comp(Compare()) {}
            const_iterator(node_type *ptr) : _data(ptr), _comp(Compare()) {}
            const_iterator(const node_type * ptr) : _data(ptr), _comp(Compare()) {}
            const_iterator(const const_iterator& other)
                            : _data(other._data), _comp(Compare()) {}


            const_iterator&         operator=(const const_iterator& other) {
                if (this != &other)
                    this->_data = other._data;
                return *this;
            }
            const_iterator&         operator++();
            const const_iterator    operator++(int);
            const_iterator&         operator--();
            const const_iterator    operator--(int);

            const_iterator         operator+(size_type n) const;
            const_iterator         operator-(size_type n) const;

            const_reference         operator*() const {
                return *this->_data->value ;
            }

            bool operator!=(const const_iterator& other) {
                return this->_data != other._data;
            }

            value_type* operator->() {
                return this->_data->value;
            }

            ~const_iterator() {}

        protected:
            node_type* _data;
            value_compare _comp;
        };
        class iterator : public const_iterator {
        public:




            iterator() : const_iterator() {}
            iterator(node_type *ptr) : const_iterator(ptr) {}
            iterator(const iterator& other) : const_iterator(other) {}
            iterator(const const_iterator& other) : const_iterator(other) {}


            iterator         operator+(size_type n);
            iterator         operator-(size_type n);

            reference   operator*() {
                return this->_data->key_value ;
            }

            ~iterator() {}
        };
    };

# include "../src/map.tpp"

}
#endif //__MAP_H__
