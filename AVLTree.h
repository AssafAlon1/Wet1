#ifndef _DS_AVL_TREE_HW2
#define _DS_AVL_TREE_HW2

#include <stdexcept>
#include <assert.h>

template<class T>
class TreeNode
{
public:
    TreeNode(T Value)
    ~TreeNode() = default;

    T* getData();

    Node<T>* find(T value); // return nullptr if not found??
    void insert(T value); // throw exception if failed??
    void remove(T value); // throw exception if failed??
private:
    Node<T>* right;
    Node<T>* left;
    int height;
    T value;
};




#endif _DS_AVL_TREE_HW2