#include "AVLTree.h"
using namespace std;

int main()
{

    // creating the 3 data sequences using vectors
    vector<int> v1, v2, v3;
    for (int i = 1; i < 100; i += 2)
    {
        v1.push_back(i);
        v2.push_back(i);
        v3.push_back(i);
    }
    // using help from cplusplus.com
    // make v2 decending
    reverse(v2.begin(), v2.end());
    // make v3 shuffled
    shuffle(v3.begin(), v3.end(), default_random_engine(0));
    // Default random engine
    //"This is a random number engine class that generates pseudo-random numbers."

    AVLTree<int> *tree1 = new AVLTree<int>();

    cout << "Tree 1: " << endl;
    for (int i : v1) // for each index i in vector v1 insert the ith element into tree1
    {
        tree1->insert(i);
    }
    cout << "Tree 1 Height: " + tree1->height() << endl;
    for (int i = 1; i <= 100; i++)
    {
        bool check = tree1->contains(i);
        if ((!check && i % 2 == 1) || (check && i % 2 == 0))
        {
            cout << "HEIGHT TEST 1 FAILED" << endl;
        }
        else
        {
            cout << i << " : " << (check ? "Yes\n" : "No\n"); // if check == true yes, false == no
        }
    }
    cout << "Validation tree1: " << tree1->validate() << endl;

    AVLTree<int> *tree2 = new AVLTree<int>();

    cout << "Tree 2: " << endl;
    for (int i : v2) // for each index i in vector v1 insert the ith element into tree1
    {
        cout << i << endl;
        tree2->insert(i);
    }
    cout << "Tree 2 Height: " + tree2->height() << endl;
    for (int i = 1; i <= 100; i++)
    {
        bool check = tree2->contains(i);
        if ((!check && i % 2 == 1) || (check && i % 2 == 0))
        {
            cout << "HEIGHT TEST 2 FAILED" << endl;
        }
        else
        {
            cout << i << " : " << (check ? "Yes\n" : "No\n"); // if check == true yes, false == no
        }
    }
    cout << "Validation tree2: " << tree2->validate() << endl;

    AVLTree<int> *tree3 = new AVLTree<int>();
    cout << "Tree 3: " << endl;
    for (int i : v3) // for each index i in vector v1 insert the ith element into tree1
    {
        tree3->insert(i);
    }
    cout << "Tree 3 Height: " + tree3->height() << endl;
    for (int i = 1; i <= 100; i++)
    {
        bool check = tree3->contains(i);
        if ((!check && i % 2 == 1) || (check && i % 2 == 0))
        {
            cout << "HEIGHT TEST 3 FAILED" << endl;
        }
        else
        {
            cout << i << " : " << (check ? "Yes\n" : "No\n"); // if check == true yes, false == no
        }
    }
    cout << "Validation tree3: " << tree1->validate() << endl;
    return 0;
}