#include "MyTree.h"
#include <assert.h>
#include <iostream>
using std::cout;
using mtm::Node;
using mtm::AVLTree;
namespace mtm{
}
int main()
{
    Node<int,int>* root = NULL;
    AVLTree<int,int> mytree = AVLTree<int,int>();
    /* Constructing tree given in
    the above figure *//*
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    /* The constructed AVL Tree would be
          30
          / \
         20 40
         / \ \
        10 25 50
    *//*
    cout << "Preorder traversal of the "
        "constructed AVL tree is \n";
    preOrder(root);
    cout << "\n";
    cout << "inorder traversal is: \n";
    inOrder(root);
    cout << "\n";
    cout << "postorder traversal is: \n";
    postOrder(root);
    */
    Node<int,int>* root2 = NULL;
    root2 = insert(root2, 100,1);
    root2 = insert(root2, 250,1);
    root2 = insert(root2, 370,1);
    root2 = insert(root2, 400,1);
    root2 = insert(root2, 520,1);
    root2 = insert(root2, 260,1);
    /*
    cout << "Preorder traversal of the "
        "constructed AVL tree is \n";
    preOrder(root2);
    cout << "\n";
    cout << "inorder traversal is: \n";
    inOrder(root2);
    cout << "\n";
    cout << "postorder traversal is: \n";
    postOrder(root2);*/
    /* Constructing tree given in
    the above figure */
    root = insert(root, 9,1);
    root = insert(root, 5,1);
    root = insert(root, 10,1);
    root = insert(root, 0,1);
    root = insert(root, 6,1);
    root = insert(root, 11,1);
    root = insert(root, -1,1);
    root = insert(root, 1,1);
    root = insert(root, 2,1);

    /* The constructed AVL Tree would be
       9
      / \
      1 10
     / \ \
     0 5 11
    / / \
   -1 2 6
    */

    cout << "Preorder traversal of the "
        "constructed AVL tree is \n";
    preOrder(root);

    root = deleteNode(root, 10);

    /* The AVL Tree after deletion of 10
        1
       / \
       0 9
      / / \
    -1 5   11
      / \
      2 6
    */

    cout << "\nPreorder traversal after"
        << " deletion of 10 \n";
    preOrder(root);
    mytree.tree = root;
    AVLTree<int,int> newmytree;
    newmytree.tree = root2;
    cout<< "\n tree #2 preorder before is : \n";
    preOrder(newmytree.tree);
    newmytree = mytree;
    cout << "\ntesting copy constructor\n";
    cout << "\nnewmytree preorder after\n";
    preOrder(newmytree.tree);
    cout << "\nmytree preorder was: (And is:)\n";
    preOrder(mytree.tree);
    cout << "\nchecking if DS is good\n";
    void* DS = NULL;
    DS = root;
    Node<int,int>* ptr1 = (Node<int,int>*)(DS);
    preOrder(ptr1);
    cout << "\n end \n";
    cout <<"\n test find \n";
    preOrder(root);
    mytree.find(6);
    
    return 0;
}
