#pragma once
#ifndef NODE_HPP
#define NODE_HPP "NODE_HPP"

#include <iostream>
#include <vector>

using std::vector;

template <typename T>
class Node
{
private:
    T &x;
    T &y;
public:
    Node(T &x, T &y);
    ~Node();
};

#endif