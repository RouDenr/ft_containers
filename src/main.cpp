// Copyright 2022 by decordel

#include <iostream>
#include <string>
//#include <exception>
#include <vector>
#include <stack>
//#include <map>
#include "../inc/containers.h"
#include "../inc/vector.hpp"
#include "../inc/stack.h"
#include "../inc/map.h"



int main() {


    ft::map<int, int> ft_map;
    std::map<int, int> std_map;


    std::cout << "REV_VEC" << std::endl;
    int n_r[5] = {5,4,3,2,1};
    ft::vector<int> rev_vec(n_r, n_r + 5);
    for (ft::reverse_iterator<ft::vector<int>::iterator> i = rev_vec.rbegin();
         i != rev_vec.rend() ; i++) {
        std::cout << *i;
    }
    std::cout << std::endl;

    int n[6] = {1, 2, 3, 4, 5, 6};
    size_t t1 = 5;
    size_t t2 = 6;
    ft::vector<int> ft_test(n, n + 5);
    std::vector<int> orig_v(t1, t2);
    ft::vector<int> ft_v(t1, t2);

    ft::stack<int> s;


//
    std::cout << "FT ITER " << std::endl;
    std::cout << "SIZE = " << ft_test.size() << std::endl;
    for (ft::vector<int>::iterator i = ft_test.begin(); i != ft_test.end(); ++i) {
        std::cout << *i << ", ";
    }
    std::cout << "SIZE = " << ft_test.size() << std::endl;



    std::cout << "\nFT TEST " << std::endl;
    for (ft::vector<int>::iterator i = ft_v.begin(); i != ft_v.end(); ++i) {
        std::cout << *i << ", ";
    }
    std::cout << std::endl;
    ft_v.insert(ft_v.begin() + 6, n, n + 5);
    ft_v.assign(n, n + 6);
    for (ft::vector<int>::iterator i = ft_v.begin(); i != ft_v.end(); ++i) {
        std::cout << *i << ", ";
    }
    std::cout << "SIZE = " << ft_v.size() << std::endl;
    std::cout << "MAX_SIZE = " << ft_v.max_size() << std::endl;
    std::cout << "cap = " << ft_v.capacity() << std::endl;
    ft_v.reserve(20);
    std::cout << "new cap = " << ft_v.capacity() << std::endl;

    ft_v.erase(ft_v.begin() + 3, ft_v.begin() + 2);
    ft_v.push_back(7);
    ft_v.resize(0, 8);

    for (ft::vector<int>::iterator i = ft_v.begin(); i != ft_v.end(); ++i) {
        std::cout << *i << ", ";
    }

    std::cout << std::endl;

    ft_v.swap(ft_test);
    for (ft::vector<int>::iterator i = ft_v.begin(); i != ft_v.end(); ++i) {
        std::cout << *i << ", ";
    }

    std::cout << std::endl;




    std::cout << "\nORIG " << std::endl;
    orig_v.insert(orig_v.begin() + 5, n, n + 5);
    for (std::vector<int>::iterator i = orig_v.begin(); i != orig_v.end(); ++i)
        std::cout << *i << ", ";
    std::cout << "SIZE = " << orig_v.size() << " " << std::ends;
    std::cout << "SIZE = " << orig_v.size() << " " << std::ends;
    std::cout << "MAX_SIZE = " << orig_v.max_size() << std::endl;
    orig_v.clear();
    orig_v.assign(3, 6);
    orig_v.erase(orig_v.begin());
    std::cout << "SIZE = " << orig_v.size() << " " << std::ends;
    std::cout << "cap = " << orig_v.capacity() << " " << std::endl;


//
//    std::allocator<int> allocator;
//    allocator.deallocate()








    std::cout << "Hello Containers!" << std::endl;
    return 0;
}