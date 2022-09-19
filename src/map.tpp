// Copyright 2022 by decordel
# include "../inc/containers.h"
# include "../inc/map.h"
# include <exception>

#define __MAP ft::map<Key, T, Compare, Allocator, NodeAllocator>
//#define __REBIND_ALLOC(x, n) typename Allocator::rebind<x>::other(get_allocator()).allocate(n)
//
//#define __REBIND_DEALLOC(type, pointer, n) typename Allocator::rebind<type>:: \
//    other(get_allocator()).deallocate(pointer, n)
//#define __REBIND_DESTROY(type, pointer) typename Allocator::rebind<type>:: \
//    other(get_allocator()).destroy(pointer)

//template<typename Key, typename T, typename Compare, typename Allocator
// , typename NodeAllocator>
//map<Key, T, Compare, Allocator, NodeAllocator>::map(pointer first, pointer last,
//                                     const Compare &comp,
//                                     const Allocator &alloc)
//                                     : _compare(comp), _alloc(alloc) {
//}


template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
__MAP::map(const map &other) : _compare(Compare()) {
    if (this != &other) {
        this->_alloc = other._alloc;
        this->_node_alloc = other._node_alloc;
        this->_nil = _create_nil_node();
        this->_head = _nil;
//        for (iterator i = other.begin(); i != other.end(); ++i) {
//            this->insert(i->first, i->second);
//        }
        this->_size = 0;
        this->_capacity = 0;
        _insert_all_tree(other._head);
    }
}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
__MAP::~map() {
    if (this->_head != _nil)
        _delete_all_tree(this->_head);
}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
__MAP &map<Key, T, Compare, Allocator, NodeAllocator>::operator=(const map &other) {
    if (this != &other) {
        this->_alloc = other._alloc;
        this->_node_alloc = other._node_alloc;
        this->_capacity = other._capacity;
        this->_size = other._size;
        this->_nil = _create_nil_node();
//        for (iterator i = other.begin(); i != other.end(); ++i) {
//            this->insert(i->first, i->second);
//        }
        _insert_all_tree(other._head);
    }
}



template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
typename __MAP::value_type
&map<Key, T, Compare, Allocator, NodeAllocator>::at(const Key &key) {
    node_type *tmp = this->_head;
    while (tmp != _nil) {
        if (tmp->value->first == key)
            return tmp->value->second;
        if (this->_compare(tmp->value->first, key))
            tmp = tmp->right;
        else
            tmp = tmp->left;
    }
    throw std::out_of_range("map");
}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
const typename __MAP::value_type &
map<Key, T, Compare, Allocator, NodeAllocator>::at(const Key &key) const {
    node_type *tmp = this->_head;
    while (tmp != _nil) {
        if (tmp->value->first == key)
            return tmp->value->second;
        if (this->_compare(tmp->value->first, key))
            tmp = tmp->right;
        else
            tmp = tmp->left;
    }
    throw std::out_of_range("map");
}



template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
typename __MAP::const_iterator
map<Key, T, Compare, Allocator, NodeAllocator>::begin() const {
    node_type *tmp = this->_head;
    if (tmp == _nil)
        return map::iterator(_nil);
    while (tmp->left != _nil)
        tmp = tmp->left;
    return map::const_iterator(tmp);
}


template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
typename __MAP::const_iterator
map<Key, T, Compare, Allocator, NodeAllocator>::end() const {
    return map::iterator(_nil);
}



template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
typename __MAP::iterator
map<Key, T, Compare, Allocator, NodeAllocator>::begin() {
    node_type *tmp = this->_head;
    if (tmp == _nil)
        return map::iterator(_nil);
    while (tmp->left != _nil)
        tmp = tmp->left;
    return map::iterator(tmp);
}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
typename __MAP::iterator map<Key, T, Compare, Allocator, NodeAllocator>::end() {
    return map::iterator(_nil);
}


template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
bool map<Key, T, Compare, Allocator, NodeAllocator>::empty() const {
    return !this->size();
}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
typename __MAP::size_type map<Key, T, Compare, Allocator, NodeAllocator>::size() const {
    return this->_size;
}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
void map<Key, T, Compare, Allocator, NodeAllocator>::assign(pointer first, pointer last) {

}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
typename __MAP::size_type map<Key, T, Compare, Allocator, NodeAllocator>::max_size() const {
    return this->_alloc.max_size();
}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
void map<Key, T, Compare, Allocator, NodeAllocator>::assign(map::size_type count,
                                             const T &value) {

}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
void map<Key, T, Compare, Allocator, NodeAllocator>::clear() {
    _delete_all_tree(this->_head);
    this->_size = 0;
    this->_capacity = 0;
}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
ft::pair<typename __MAP::iterator, bool>
map<Key, T, Compare, Allocator, NodeAllocator>::insert(const value_type &value) {
    node_type    *tmp = this->_head;
    if (tmp == _nil) {
        this->_head = _create_new_node(_nil, _nil, _nil, value);
        this->_size++;
        this->_capacity++;
        return make_pair(iterator(this->_head), true);
    }
    while (1) {
        if (tmp->value->first == value.first) {
            tmp->value->second = value.second;
            return make_pair(iterator(tmp), true);
        }
        if (this->_compare(value, *tmp->value)) {
            if (tmp->left == _nil) {
                node_type *new_n = _create_new_node(tmp->left, _nil, tmp, value);
                this->_size++;
                this->_capacity++;
                tmp->left = new_n;
                return make_pair(iterator(new_n), true);
            }
            tmp = tmp->left;
        } else {
            if (tmp->right == _nil) {
                node_type *new_n = _create_new_node(_nil, tmp->right, tmp,
                                                    value);
                this->_size++;
                this->_capacity++;
                tmp->right = new_n;
                return make_pair(iterator(new_n), true);
            }
            tmp = tmp->right;
        }
    }
    return make_pair(iterator(), false);

}

//template<typename Key, typename T, typename Compare, typename Allocator
//        , typename NodeAllocator>
//void map<Key, T, Compare, Allocator, NodeAllocator>::insert(map::iterator pos,
//                                             map::size_type count,
//                                             const T &value) {
//
//}
//
//template<typename Key, typename T, typename Compare, typename Allocator
//        , typename NodeAllocator>
//void map<Key, T, Compare, Allocator, NodeAllocator>::insert(pointer first, pointer last) {
//
//}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
typename __MAP::size_type map<Key, T, Compare, Allocator, NodeAllocator>::erase(const Key &key) {
    return 0;
}

//template<typename Key, typename T, typename Compare, typename Allocator
//        , typename NodeAllocator>
//typename __MAP::iterator map<Key, T, Compare, Allocator, NodeAllocator>::erase(map::iterator first,
//                                                     map::iterator last) {
//    return map::iterator();
//}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
typename __MAP::iterator map<Key, T, Compare, Allocator, NodeAllocator>::
                erase(map::iterator pos) {


    return map::iterator();
}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
void map<Key, T, Compare, Allocator, NodeAllocator>::swap(map &other) {

}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
typename __MAP::size_type
map<Key, T, Compare, Allocator, NodeAllocator>::count(const Key &key) const {
    return 0;
}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
typename __MAP::iterator map<Key, T, Compare, Allocator, NodeAllocator>::find(const Key &key) {
    node_type *tmp = this->_head;
    while (tmp != _nil) {
        if (tmp->value->first == key)
            return iterator(tmp);
        if (this->_compare(tmp->value->first, key))
            tmp = tmp->right;
        else
            tmp = tmp->left;
    }
//    for (iterator i = begin(); i != end() ; ++i) {
//        if (i->first == key)
//            return i->second;
//    }
    throw std::out_of_range("map");
}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
typename __MAP::const_iterator
map<Key, T, Compare, Allocator, NodeAllocator>::find(const Key &key) const {
    node_type *tmp = this->_head;
    while (tmp != _nil) {
        if (tmp->value->first == key)
            return const_iterator(tmp);
        if (this->_compare(tmp->value->first, key))
            tmp = tmp->right;
        else
            tmp = tmp->left;
    }
//    for (iterator i = begin(); i != end() ; ++i) {
//        if (i->first == key)
//            return i->second;
//    }
    throw std::out_of_range("map");
}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
pair<typename __MAP::iterator, typename __MAP::iterator>
map<Key, T, Compare, Allocator, NodeAllocator>::equal_range(const Key &key) {
    return pair<iterator, iterator>();
}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
pair<typename __MAP::const_iterator, typename __MAP::const_iterator>
map<Key, T, Compare, Allocator, NodeAllocator>::equal_range(const Key &key) const {
    return pair<const_iterator, const_iterator>();
}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
typename __MAP::iterator map<Key, T, Compare, Allocator, NodeAllocator>::lower_bound(const Key &key) {
    return map::iterator();
}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
typename __MAP::const_iterator
map<Key, T, Compare, Allocator, NodeAllocator>::lower_bound(const Key &key) const {
    return map::const_iterator();
}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
typename __MAP::iterator map<Key, T, Compare, Allocator, NodeAllocator>::upper_bound(const Key &key) {
    return map::iterator();
}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
typename __MAP::const_iterator
map<Key, T, Compare, Allocator, NodeAllocator>::upper_bound(const Key &key) const {
    return map::const_iterator();
}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
typename __MAP::key_compare
map<Key, T, Compare, Allocator, NodeAllocator>::key_comp() const {
    return this->_compare.comp;
}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
T& map<Key, T, Compare, Allocator, NodeAllocator>::operator[](const Key key) {
    node_type *tmp = this->_head;
    while (tmp != _nil) {
        if (tmp->value->first == key)
            return tmp->value->second;
        if (this->_compare(tmp->value->first, key))
            tmp = tmp->right;
        else
            tmp = tmp->left;
    }
    return insert(ft::make_pair<key_type, mapped_type>(key, mapped_type())).first->second;

}
//
//template<typename Key, typename T, typename Compare, typename Allocator
//        , typename NodeAllocator>
//bool map<Key, T, Compare, Allocator, NodeAllocator>::operator==(const map &other) {
//    return false;
//}
//
//template<typename Key, typename T, typename Compare, typename Allocator
//        , typename NodeAllocator>
//bool map<Key, T, Compare, Allocator, NodeAllocator>::operator!=(const map &other) {
//    return false;
//}
//
//template<typename Key, typename T, typename Compare, typename Allocator
//        , typename NodeAllocator>
//bool map<Key, T, Compare, Allocator, NodeAllocator>::operator<(const map &other) {
//    return false;
//}
//
//template<typename Key, typename T, typename Compare, typename Allocator
//        , typename NodeAllocator>
//bool map<Key, T, Compare, Allocator, NodeAllocator>::operator<=(const map &other) {
//    return false;
//}
//
//template<typename Key, typename T, typename Compare, typename Allocator
//        , typename NodeAllocator>
//bool map<Key, T, Compare, Allocator, NodeAllocator>::operator>(const map &other) {
//    return false;
//}
//
//template<typename Key, typename T, typename Compare, typename Allocator
//        , typename NodeAllocator>
//bool map<Key, T, Compare, Allocator, NodeAllocator>::operator>=(const map &other) {
//    return false;
//}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
typename __MAP::allocator_type map<Key, T, Compare, Allocator, NodeAllocator>::get_allocator() const {
    return this->_alloc;
}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
typename __MAP::map::value_compare
map<Key, T, Compare, Allocator, NodeAllocator>::value_comp() const {
    return this->_compare;
}



template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
typename __MAP::node_type *map<Key, T, Compare, Allocator, NodeAllocator>::_create_new_node(map::node_type *left,
                                                                                            map::node_type *right,
                                                                                            map::node_type *parent,
                                                                                            map::value_type key_value) {
    node_type *new_node = _node_alloc.allocate(1);

    new_node->value = _alloc.allocate(1);
    new_node->value->first = key_value.first;
    new_node->value->second = key_value.second;
    new_node->left = left;
    new_node->right = right;
    new_node->parent = parent;
    return new_node;
}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
typename __MAP::node_type *map<Key, T, Compare, Allocator, NodeAllocator>::_create_nil_node() {
    node_type *new_node = _node_alloc.allocate(1);

    new_node->value =  NULL;
    new_node->left =  NULL;
    new_node->right =  NULL;
    new_node->parent =  NULL;
    return new_node;
}

template<typename Key, typename T, typename Compare, typename Allocator, typename NodeAllocator>
void map<Key, T, Compare, Allocator, NodeAllocator>::_delete_all_tree(
        map::node_type *head) {
    if (head->right != _nil)
        _delete_all_tree(head->right);
    if (head->left != _nil)
        _delete_all_tree(head->left);
//    delete head->value;
    _alloc.deallocate(head->value, 1);
    _node_alloc.deallocate(head, 1);
}


template<typename Key, typename T, typename Compare, typename Allocator, typename NodeAllocator>
void map<Key, T, Compare, Allocator, NodeAllocator>::_insert_all_tree(
        map::node_type *head) {
    insert(*head->value);
    if (head->right->value)
        _insert_all_tree(head->right);
    if (head->left->value)
        _insert_all_tree(head->left);
}

//template<typename Key, typename T, typename Compare, typename Allocator
//        , typename NodeAllocator>
//void map<Key, T, Compare, Allocator, NodeAllocator>::destroy_node(map::node_type *node) {
//    _node_alloc.deallocate(node, 1);
//}


/// ! ITERATOR

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
typename __MAP::const_iterator &
map<Key, T, Compare, Allocator, NodeAllocator>::const_iterator::operator++() {
    node_type *tmp = this->_data;
    if (tmp->right == _nil) {
        tmp = tmp->parent;
        while (tmp != _nil && this->_comp(*tmp->value,
                                *this->_data->value)) {
            tmp = tmp->parent;
        }
    } else {
        tmp = this->_data->right;
        while (tmp != _nil && tmp->left != _nil)
            tmp = tmp->left;
    }
    this->_data = tmp;
    return *this;
}


template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
const typename __MAP::const_iterator
map<Key, T, Compare, Allocator, NodeAllocator>::const_iterator::operator++(int) {
    const const_iterator tmp(this->_data);
    operator++();
    return (tmp);
}

template<typename Key, typename T, typename Compare, typename Allocator
        , typename NodeAllocator>
typename __MAP::const_iterator &
map<Key, T, Compare, Allocator, NodeAllocator>::const_iterator::operator--() {
    node_type *tmp = this->_data;
    if (tmp->left == _nil) {
        tmp = tmp->parent;
        while (tmp != _nil && !this->_comp(*tmp->value,
                *this->_data->key_value)) {
            tmp = tmp->parent;
        }
    } else {
        tmp = this->_data->left;
        while (tmp->right != _nil)
            tmp = tmp->right;
    }
    this->_data = tmp;
    return *this;
}

template<typename Key, typename T, typename Compare, typename Allocator, typename NodeAllocator>
const typename __MAP::const_iterator
map<Key, T, Compare, Allocator, NodeAllocator>::const_iterator::operator--(
        int) {
    const const_iterator tmp(this->_data);
    operator--();
    return (tmp);
}

template<typename Key, typename T, typename Compare, typename Allocator, typename NodeAllocator>
typename __MAP::const_iterator
map<Key, T, Compare, Allocator, NodeAllocator>::const_iterator::operator+(
        map::size_type n) const {
    const_iterator tmp(this->_data);
    while (n-- != 0)
        ++tmp;
    return tmp;
}

template<typename Key, typename T, typename Compare, typename Allocator, typename NodeAllocator>
typename __MAP::const_iterator
map<Key, T, Compare, Allocator, NodeAllocator>::const_iterator::operator-(
        map::size_type n) const {
    const_iterator tmp(this->_data);
    while (n-- != 0)
        --tmp;
    return tmp;
}

template<typename Key, typename T, typename Compare, typename Allocator, typename NodeAllocator>
typename __MAP::node_type *
map<Key, T, Compare, Allocator, NodeAllocator>::const_iterator::_find_nil() {
    node_type *tmp = this->_data;
    while (tmp->value)
        tmp = tmp->parent;
    return tmp;
}
