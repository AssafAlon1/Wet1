#ifndef MYTREE
#define MYTREE
#include <iostream>
using namespace std;
namespace mtm
{
    
    // C++ program to insert a node in AVL tree
//#include<bits/stdc++.h>

// An AVL tree node
//namespace generalAVL
//{
    template<class T,class S>
    class Node
    {
    public:
        T key;
        S val;
        Node<T,S>* left;
        Node<T,S>* right;
        int height;
        ~Node() = default;
    };
    template<class T,class S>
    Node<T,S>* newNode(T key, S val);
    template<class T, class S>
class AVLTree{
public:
    Node<T,S>* tree;
	AVLTree();
    //AVLTree(const AVLTree<T>& tree);
	~AVLTree();
    AVLTree<T,S>& operator=(const AVLTree<T,S>& tree);
    //template<class S>
    //AVLTree<T> apply(S function);
    //template<class J>
    //AVLTree<T,S> filter(J perdict);
    Node<T,S>& find(const T& key);
    void insert(const T& key, const S& val);
    void remove(T& key);
    int length() const;
};

template<class T, class S>
Node <T,S>* copyhelper(Node<T, S>* source);
template<class T,class S>
mtm::AVLTree<T,S>::AVLTree() : tree(nullptr)
{
    
}
template<class T,class S>
mtm::AVLTree<T,S>::~AVLTree()
{
    clearTree(tree);
}
template<class T,class S>
void clearTree(Node<T,S>* temp)
{
    if(temp == nullptr)
    {
        return;
    }
    clearTree(temp->left);
    clearTree(temp->right);
    delete temp;
}
template<class T,class S>
AVLTree<T,S>& AVLTree<T,S>::operator=(const AVLTree<T,S>& newtree)
{
    if(this == &newtree)
    {
        return *this;
    }
    else
    {
        Node<T,S>* newthis = nullptr;
        clearTree<T,S>(this->tree);
        this->tree = newthis;
        Node<T,S>* temp = newtree.tree;
        if(temp!=nullptr)
        {
            newthis = copyhelper<T,S>(temp);
            //EXCEPTION
        }
        this->tree = newthis;
        
        //EXCEPTION
    }
    //dad please not the belt ;-;
}

template <class T,class S>
Node<T,S>& mtm::AVLTree<T,S>::find(const T& key)
{
    if(this->tree==nullptr)
    {
        return nullptr;
    }
    else
    {
        return findhelper(key, this->tree);
    }
}
template <class T,class S>
Node<T,S>& findhelper(const T& key, Node<T,S>* node)
{
    if(node==nullptr)
    {
        return nullptr;
    }
    else
    {
        if (key < node->key)
            return findhelper(key, node->left);
        else if (key > node->key)
            return findhelper(key,node->right);
        else // Equal keys are not allowed in BST
            return &node;
    }
}

template<class T, class S>
Node <T,S>* copyhelper(Node<T, S>* source)
{
    if (source == nullptr)
    {
        return nullptr;
    }
    
    Node<T,S>* current = newNode<T,S>(source->key, source->val);
    current->left = copyhelper<T,S>(source->left);
    current->right = copyhelper<T,S>(source->right);
    return current;
      
}



    // A utility function to get maximum
    // of two integers
    int max(int a, int b);

    // A utility function to get the
    // height of the tree
    template<class T,class S>
    int height(Node<T, S>* N)
    {
        if (N == NULL)
            return 0;
        return N->height;
    }

    // A utility function to get maximum
    // of two integers
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    /* Helper function that allocates a
       new node with the given key and
       NULL left and right pointers. */
    template<class T,class S>
    Node<T,S>* newNode(T key, S val)
    {
        Node<T,S>* node = new Node<T,S>();
        node->key = key;
        node->val = val;
        node->left = NULL;
        node->right = NULL;
        node->height = 1; // new node is initially
                          // added at leaf
        return(node);
    }

    // A utility function to right
    // rotate subtree rooted with y
    // See the diagram given above.
    template<class T,class S>
    Node<T, S>* rightRotate(Node<T, S>* y)
    {
        Node<T, S>* x = y->left;
        Node<T, S>* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height<T,S>(y->left),
            height<T>(y->right)) + 1;
        x->height = max(height<T,S>(x->left),
            height<T>(x->right)) + 1;

        // Return new root
        return x;
    }

    // A utility function to left
    // rotate subtree rooted with x
    // See the diagram given above.
    template<class T,class S>
    Node<T, S>* leftRotate(Node<T, S>* x)
    {
        Node<T, S>* y = x->right;
        Node<T, S>* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(height<T>(x->left),
            height<T,S>(x->right)) + 1;
        y->height = max(height<T>(y->left),
            height<T,S>(y->right)) + 1;

        // Return new root
        return y;
    }

    // Get Balance factor of node N
    template<class T, class S>
    int getBalance(Node<T, S>* N)
    {
        if (N == NULL)
            return 0;
        return height<T>(N->left) - height<T>(N->right);
    }

    // Recursive function to insert a key
    // in the subtree rooted with node and
    // returns the new root of the subtree.
    template<class T,class S>
    Node<T, S>* insert(Node<T, S>* node, T key,S val)
    {
        /* 1. Perform the normal BST insertion */
        if (node == NULL)
            return(newNode<T, S>(key,val));

        if (key < node->key)
            node->left = insert<T,S>(node->left, key , val);
        else if (key > node->key)
            node->right = insert<T,S>(node->right, key, val);
        else // Equal keys are not allowed in BST
            return node;

        /* 2. Update height of this ancestor node */
        node->height = 1 + max(height<T,S>(node->left),
            height(node->right));

        /* 3. Get the balance factor of this ancestor
            node to check whether this node became
            unbalanced */
        int balance = getBalance<T,S>(node);

        // If this node becomes unbalanced, then
        // there are 4 cases

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rightRotate<T,S>(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return leftRotate<T,S>(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate<T,S>(node->left);
            return rightRotate<T,S>(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate<T,S>(node->right);
            return leftRotate<T,S>(node);
        }

        /* return the (unchanged) node pointer */
        return node;
    }
    /* Given a non-empty binary search tree,
return the node with minimum key value
found in that tree. Note that the entire
tree does not need to be searched. */
    template <class T, class S>
    Node<T, S>* minValueNode(Node<T, S>* node)
    {
        Node<T, S>* current = node;

        /* loop down to find the leftmost leaf */
        while (current->left != NULL)
            current = current->left;

        return current;
    }
    // Recursive function to delete a node
// with given key from subtree with
// given root. It returns root of the
// modified subtree.
    template <class T, class S>
    Node<T, S>* deleteNode(Node<T, S>* root, int key)
    {

        // STEP 1: PERFORM STANDARD BST DELETE
        if (root == NULL)
            return root;

        // If the key to be deleted is smaller
        // than the root's key, then it lies
        // in left subtree
        if (key < root->key)
            root->left = deleteNode<T, S>(root->left, key);

        // If the key to be deleted is greater
        // than the root's key, then it lies
        // in right subtree
        else if (key > root->key)
            root->right = deleteNode<T, S>(root->right, key);

        // if key is same as root's key, then
        // This is the node to be deleted
        else
        {
            // node with only one child or no child
            if ((root->left == NULL) ||
                (root->right == NULL))
            {
                Node<T, S>* temp = root->left ?
                    root->left :
                    root->right;

                // No child case
                if (temp == NULL)
                {
                    temp = root;
                    root = NULL;
                }
                else // One child case
                    *root = *temp; // Copy the contents of
                                   // the non-empty child
                delete temp;
            }
            else
            {
                // node with two children: Get the inorder
                // successor (smallest in the right subtree)
                Node<T, S>* temp = minValueNode<T, S>(root->right);

                // Copy the inorder successor's
                // data to this node
                root->key = temp->key;

                // Delete the inorder successor
                root->right = deleteNode<T, S>(root->right,
                    temp->key);
            }
        }

        // If the tree had only one node
        // then return
        if (root == NULL)
            return root;

        // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
        root->height = 1 + max(height<T>(root->left),
            height<T>(root->right));

        // STEP 3: GET THE BALANCE FACTOR OF
        // THIS NODE (to check whether this
        // node became unbalanced)
        int balance = getBalance<T>(root);

        // If this node becomes unbalanced,
        // then there are 4 cases

        // Left Left Case
        if (balance > 1 &&
            getBalance<T>(root->left) >= 0)
            return rightRotate<T>(root);

        // Left Right Case
        if (balance > 1 &&
            getBalance<T>(root->left) < 0)
        {
            root->left = leftRotate<T>(root->left);
            return rightRotate<T>(root);
        }

        // Right Right Case
        if (balance < -1 &&
            getBalance<T>(root->right) <= 0)
            return leftRotate<T>(root);

        // Right Left Case
        if (balance < -1 &&
            getBalance<T>(root->right) > 0)
        {
            root->right = rightRotate<T>(root->right);
            return leftRotate<T>(root);
        }

        return root;
    }

    // A utility function to print preorder
    // traversal of the tree.
    // The function also prints height
    // of every node
    template<class T, class S>
    void preOrder(Node<T, S>* root)
    {
        if (root != NULL)
        {
            cout << root->key << " ";
            preOrder<T>(root->left);
            preOrder<T>(root->right);
        }
    }
    template<class T, class S>
    void inOrder(Node<T, S>* root)
    {
        if (root != NULL)
        {
            inOrder<T>(root->left);
            cout << root->key << " ";
            inOrder<T>(root->right);
        }
    }
    template<class T, class S>
    void postOrder(Node<T, S>* root)
    {
        if (root != NULL)
        {
            postOrder<T>(root->left);
            postOrder<T>(root->right);
            cout << root->key << " ";
        }
    }

}
#endif