#include <iostream>;
#include <vector>;
#include "MyTree.h";
//using generalAVL;

// Driver Code
int main()
{
    Node<int>* root = NULL;
    
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
    Node<int>* root2 = NULL;
    root2 = insert(root2, 100);
    root2 = insert(root2, 250);
    root2 = insert(root2, 370);
    root2 = insert(root2, 400);
    root2 = insert(root2, 520);
    root2 = insert(root2, 260);
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
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

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

    cout << "\nchecking if DS is good\n";
    void* DS = NULL;
    DS = root;
    Node<int>* ptr1 = (Node<int>*)(DS);
    preOrder(ptr1);
    return 0;
}

// This code is contributed by
// rathbhupendra