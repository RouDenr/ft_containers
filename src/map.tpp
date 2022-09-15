// Copyright 2022 by decordel
# include "../inc/containers.h"
# include "../inc/map.h"
# include <exception>

#define __MAP ft::map<Key, T, Compare, Allocator>
#define __REBIND_ALLOC(x, n) typename Allocator::rebind<x>::other(get_allocator()).allocate(n)

#define __REBIND_DEALLOC(type, pointer, n) typename Allocator::rebind<type>:: \
    other(get_allocator()).deallocate(pointer, n)

//template<typename Key, typename T, typename Compare, typename Allocator>
//map<Key, T, Compare, Allocator>::map(pointer first, pointer last,
//                                     const Compare &comp,
//                                     const Allocator &alloc)
//                                     : _compare(comp), _alloc(alloc) {
//}


template<typename Key, typename T, typename Compare, typename Allocator>
map<Key, T, Compare, Allocator>::map(const map &other) {

}

template<typename Key, typename T, typename Compare, typename Allocator>
map<Key, T, Compare, Allocator>::~map() {

}

template<typename Key, typename T, typename Compare, typename Allocator>
__MAP &map<Key, T, Compare, Allocator>::operator=(const map &other) {
    return ;
}



template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::value_type
&map<Key, T, Compare, Allocator>::at(const Key &key) {
    return ;
}

template<typename Key, typename T, typename Compare, typename Allocator>
const typename __MAP::value_type &
map<Key, T, Compare, Allocator>::at(const Key &key) const {
    return ;
}



template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::const_iterator
map<Key, T, Compare, Allocator>::begin() const {
    return map::const_iterator();
}


template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::const_iterator
map<Key, T, Compare, Allocator>::end() const {
    return map::const_iterator();
}



template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::iterator
map<Key, T, Compare, Allocator>::begin() {
    return map::iterator();
}

template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::iterator map<Key, T, Compare, Allocator>::end() {
    return map::iterator();
}


template<typename Key, typename T, typename Compare, typename Allocator>
bool map<Key, T, Compare, Allocator>::empty() const {
    return !this->size();
}

template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::size_type map<Key, T, Compare, Allocator>::size() const {
    return this->_size;
}

template<typename Key, typename T, typename Compare, typename Allocator>
void map<Key, T, Compare, Allocator>::assign(pointer first, pointer last) {

}

template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::size_type map<Key, T, Compare, Allocator>::max_size() const {
    return this->_alloc.max_size();
}

template<typename Key, typename T, typename Compare, typename Allocator>
void map<Key, T, Compare, Allocator>::assign(map::size_type count,
                                             const T &value) {

}

template<typename Key, typename T, typename Compare, typename Allocator>
void map<Key, T, Compare, Allocator>::clear() {

}

template<typename Key, typename T, typename Compare, typename Allocator>
void map<Key, T, Compare, Allocator>::insert(map::iterator pos,
                                             map::size_type count,
                                             const T &value) {

}

template<typename Key, typename T, typename Compare, typename Allocator>
ft::pair<typename __MAP::iterator, bool>
map<Key, T, Compare, Allocator>::insert(const T &value) {
    return pair<iterator, bool>();
}

template<typename Key, typename T, typename Compare, typename Allocator>
void map<Key, T, Compare, Allocator>::insert(pointer first, pointer last) {

}

template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::size_type map<Key, T, Compare, Allocator>::erase(const Key &key) {
    return 0;
}

template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::iterator map<Key, T, Compare, Allocator>::erase(map::iterator first,
                                                     map::iterator last) {
    return map::iterator();
}

template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::iterator map<Key, T, Compare, Allocator>::erase(map::iterator pos) {
    return map::iterator();
}

template<typename Key, typename T, typename Compare, typename Allocator>
void map<Key, T, Compare, Allocator>::swap(map &other) {

}

template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::size_type
map<Key, T, Compare, Allocator>::count(const Key &key) const {
    return 0;
}

template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::iterator map<Key, T, Compare, Allocator>::find(const Key &key) {
    return map::iterator();
}

template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::const_iterator
map<Key, T, Compare, Allocator>::find(const Key &key) const {
    return map::const_iterator();
}

template<typename Key, typename T, typename Compare, typename Allocator>
pair<typename __MAP::iterator, typename __MAP::iterator>
map<Key, T, Compare, Allocator>::equal_range(const Key &key) {
    return pair<iterator, iterator>();
}

template<typename Key, typename T, typename Compare, typename Allocator>
pair<typename __MAP::const_iterator, typename __MAP::const_iterator>
map<Key, T, Compare, Allocator>::equal_range(const Key &key) const {
    return pair<const_iterator, const_iterator>();
}

template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::iterator map<Key, T, Compare, Allocator>::lower_bound(const Key &key) {
    return map::iterator();
}

template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::const_iterator
map<Key, T, Compare, Allocator>::lower_bound(const Key &key) const {
    return map::const_iterator();
}

template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::iterator map<Key, T, Compare, Allocator>::upper_bound(const Key &key) {
    return map::iterator();
}

template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::const_iterator
map<Key, T, Compare, Allocator>::upper_bound(const Key &key) const {
    return map::const_iterator();
}

template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::key_compare
map<Key, T, Compare, Allocator>::key_comp() const {
    return ;
}

template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::value_type &
map<Key, T, Compare, Allocator>::operator[](const Key key) {
    return ;
}

template<typename Key, typename T, typename Compare, typename Allocator>
bool map<Key, T, Compare, Allocator>::operator==(const map &other) {
    return false;
}

template<typename Key, typename T, typename Compare, typename Allocator>
bool map<Key, T, Compare, Allocator>::operator!=(const map &other) {
    return false;
}

template<typename Key, typename T, typename Compare, typename Allocator>
bool map<Key, T, Compare, Allocator>::operator<(const map &other) {
    return false;
}

template<typename Key, typename T, typename Compare, typename Allocator>
bool map<Key, T, Compare, Allocator>::operator<=(const map &other) {
    return false;
}

template<typename Key, typename T, typename Compare, typename Allocator>
bool map<Key, T, Compare, Allocator>::operator>(const map &other) {
    return false;
}

template<typename Key, typename T, typename Compare, typename Allocator>
bool map<Key, T, Compare, Allocator>::operator>=(const map &other) {
    return false;
}

template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::allocator_type map<Key, T, Compare, Allocator>::get_allocator() const {
    return this->_alloc;
}

template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::map::value_compare
map<Key, T, Compare, Allocator>::value_comp() const {
    return this->_compare;
}



template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::Node *map<Key, T, Compare, Allocator>::create_new_node(map::Node *left,
                                                            map::Node *right,
                                                            map::Node *parent,
                                                            map::value_type key_value) {
    Node *new_node = __REBIND_ALLOC(Node, 1);
    new_node->key_value = key_value;
    new_node->left = left;
    new_node->right = right;
    new_node->parent = parent;
    return new_node;
}

template<typename Key, typename T, typename Compare, typename Allocator>
void map<Key, T, Compare, Allocator>::destroy_node(map::Node *node) {
    __REBIND_DEALLOC(Node, node, 1);
}

template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::Node *map<Key, T, Compare, Allocator>::next_node(map::Node *this_n) {
    return nullptr;
}

template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::Node *map<Key, T, Compare, Allocator>::prev_node(map::Node *this_n) {
    return nullptr;
}

template<typename Key, typename T, typename Compare, typename Allocator>
bool map<Key, T, Compare, Allocator>::is_last_node(map::Node *node) {
    return node->right;
}


/// ! ITERATOR

template<typename Key, typename T, typename Compare, typename Allocator>
typename __MAP::const_iterator &
map<Key, T, Compare, Allocator>::const_iterator::operator++() {

//    if(!node1->isLast && !node1->right->isLast)
//    {
//        if(!node1->right->left->isLast)
//        {
//            node1 = node1->right;
//            while(!node1->isLast)
//                node1= node1->left;
//            node1 = node1->parent;
//        }
//        else
//            node1 = node1->right;
//    }
//    else
//    {
//        if(node1 == node1->parent->left)
//            node1 = node1->parent;
//        else if(node1 == node1->parent->right)
//        {
//            if(node1->key < node1->parent->parent->key)
//                node1 = node1->parent->parent;
//            else
//                node1 = node1->right; //end
//        }
//    }
    return *this;
}