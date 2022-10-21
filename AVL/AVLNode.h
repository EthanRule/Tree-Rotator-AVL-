#include <bits/stdc++.h> // includes every header file
using namespace std;

template <class T>
class AVLNode
{
public:
    T data;
    AVLNode<T> *left;
    AVLNode<T> *right;
    int height;
    // Constructor (set initial values)
    AVLNode(T key)
    {
        data = key;
        left = NULL;
        right = NULL;
        height = 1;
    }
    // Destructor (destroys children in node and goes up recursively)
    ~AVLNode()
    {
        delete left;
        delete right;
    }
};