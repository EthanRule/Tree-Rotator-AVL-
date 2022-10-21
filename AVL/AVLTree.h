#include "AVLNode.h"
using namespace std;
template <class T>
class AVLTree
{
    AVLNode<T> *root;

public:
    AVLTree() // constructor
    {
        root = NULL;
    }

private:
    // HELPER FUNCTIONS
    int heightHelper(AVLNode<T> *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return node->height;
    }
    int maxHelper(int a, int b) // returns the max of 2 values
    {
        return (a > b) ? a : b;
    }
    // Helper function for the insert (left rotation, right rotation, max and balance check)
    // left rotation
    AVLNode<T> *leftRotation(AVLNode<T> *node)
    {
        AVLNode<T> *_right = node->right; // store the pointer to the right
        AVLNode<T> *temp = _right->left;

        _right->left = node; // rotate the right node up to a parent
        node->right = temp;  // rotate the left node down to a child

        node->height = maxHelper(heightHelper(node->left), heightHelper(node->right)) + 1;       // increase height of prev right furthest child
        _right->height = maxHelper(heightHelper(_right->left), heightHelper(_right->right)) + 1; // increase height of the right child ptr off the temp
        return _right;
    }
    // same but opposite for right rotation by flipping right's to lefts vice versa
    AVLNode<T> *rightRotation(AVLNode<T> *node)
    {

        AVLNode<T> *_left = node->left;
        AVLNode<T> *temp = _left->right;

        _left->right = node;
        node->left = temp;

        node->height = maxHelper(heightHelper(node->right), heightHelper(node->left)) + 1;
        _left->height = maxHelper(heightHelper(_left->right), heightHelper(_left->left)) + 1;

        return _left;
    }
    // check for balance returns the result that will decide wether to rotate or not, and which direction
    int balanceHelper(AVLNode<T> *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return heightHelper(node->left) - heightHelper(node->right);
    }
    AVLNode<T> *insert(AVLNode<T> *pCur, T data)
    {
        if (pCur == NULL)
        {
            return new AVLNode<T>(data); // create root node
        }
        if (data < pCur->data) // go left
        {
            pCur->left = insert(pCur->left, data);
        }
        else if (data > pCur->data) // go right
        {
            pCur->right = insert(pCur->right, data);
        }
        else // pCur = data
        {
            return pCur;
        }

        // check height to see if we need to rotate at all
        pCur->height = maxHelper(heightHelper(pCur->left), heightHelper(pCur->right)) + 1;
        int balance = balanceHelper(pCur);
        // some help from a microsoft word doc textbook i found
        // Left Left Case
        /*
        a
         \
          b
           \
            c
        */
        if (balance > 1 && data < pCur->left->data)
        {
            return rightRotation(pCur);
        }
        // Right Right Case
        /*
        a
       /
      b
     /
    c
        */
        if (balance < -1 && data > pCur->right->data)
        {
            return leftRotation(pCur);
        }
        // Left Right Case (double left)
        /*
        a
         \
          b
         /
        c
        */
        if (balance > 1 && data > pCur->left->data)
        {
            pCur->left = leftRotation(pCur->left); // 1st rotation
            return rightRotation(pCur);            // 2nd
        }
        // Right Left Case (double right)
        /*
        a
       /
      b
       \
        c
        */
        if (balance < -1 && data < pCur->right->data)
        {
            pCur->right = rightRotation(pCur->right); // 1st rotation
            return leftRotation(pCur);                // 2nd
        }
        return pCur;
    }

    bool search(AVLNode<T> *pCur, T data)
    {
        if (pCur)
        {
            if (pCur->data == data)
            {
                return 1;
            }
            else
            {
                return search(pCur->left, data) || search(pCur->right, data); // recursively call function to check the next nodes
            }
        }
        return 0;
    }
    // recursively check for if the tree is balanced
    bool balanceHelper2(AVLNode<T> *pCur)
    {
        if (pCur == NULL)
        {
            return 1;
        }
        // abs returns absolute val
        if (abs(heightHelper(pCur->left) - heightHelper(pCur->right)) <= 1)
        {
            return balanceHelper2(pCur->right) && balanceHelper2(pCur->left); // parse through recursion to check balance
        }
        return 0; // balanced
    }

public:
    void insert(T data)
    {
        this->root = insert(this->root, data);
    }
    int height()
    {
        return heightHelper(this->root);
    }
    bool contains(T data)
    {
        return search(this->root, data);
    }
    bool validate()
    {
        return balanceHelper2(this->root);
    }
    ~AVLTree()
    {
        delete root; // destructor
    }
};
