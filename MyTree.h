// C++ program to insert a node in AVL tree
//#include<bits/stdc++.h>
using namespace std;
#include <iostream>;
#include <vector>;
// An AVL tree node
//namespace generalAVL
//{
    template<class T>
    class Node
    {
    public:
        int key;
        Node<T>* left;
        Node<T>* right;
        vector<Node<T>*> extra;
        int height;
    };

    // A utility function to get maximum
    // of two integers
    int max(int a, int b);

    // A utility function to get the
    // height of the tree
    template<class T>
    int height(Node<T>* N)
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
    template<class T>
    Node<T>* newNode(int key)
    {
        Node<T>* node = new Node<T>();
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->height = 1; // new node is initially
                          // added at leaf
        return(node);
    }

    // A utility function to right
    // rotate subtree rooted with y
    // See the diagram given above.
    template<class T>
    Node<T>* rightRotate(Node<T>* y)
    {
        Node<T>* x = y->left;
        Node<T>* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height<T>(y->left),
            height<T>(y->right)) + 1;
        x->height = max(height<T>(x->left),
            height<T>(x->right)) + 1;

        // Return new root
        return x;
    }

    // A utility function to left
    // rotate subtree rooted with x
    // See the diagram given above.
    template<class T>
    Node<T>* leftRotate(Node<T>* x)
    {
        Node<T>* y = x->right;
        Node<T>* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(height<T>(x->left),
            height<T>(x->right)) + 1;
        y->height = max(height<T>(y->left),
            height<T>(y->right)) + 1;

        // Return new root
        return y;
    }

    // Get Balance factor of node N
    template<class T>
    int getBalance(Node<T>* N)
    {
        if (N == NULL)
            return 0;
        return height<T>(N->left) - height<T>(N->right);
    }

    // Recursive function to insert a key
    // in the subtree rooted with node and
    // returns the new root of the subtree.
    template<class T>
    Node<T>* insert(Node<T>* node, int key)
    {
        /* 1. Perform the normal BST insertion */
        if (node == NULL)
            return(newNode<T>(key));

        if (key < node->key)
            node->left = insert<T>(node->left, key);
        else if (key > node->key)
            node->right = insert<T>(node->right, key);
        else // Equal keys are not allowed in BST
            return node;

        /* 2. Update height of this ancestor node */
        node->height = 1 + max(height<T>(node->left),
            height(node->right));

        /* 3. Get the balance factor of this ancestor
            node to check whether this node became
            unbalanced */
        int balance = getBalance<T>(node);

        // If this node becomes unbalanced, then
        // there are 4 cases

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rightRotate<T>(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return leftRotate<T>(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate<T>(node->left);
            return rightRotate<T>(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate<T>(node->right);
            return leftRotate<T>(node);
        }

        /* return the (unchanged) node pointer */
        return node;
    }
    /* Given a non-empty binary search tree,
return the node with minimum key value
found in that tree. Note that the entire
tree does not need to be searched. */
    template <class T>
    Node<T>* minValueNode(Node<T>* node)
    {
        Node<T>* current = node;

        /* loop down to find the leftmost leaf */
        while (current->left != NULL)
            current = current->left;

        return current;
    }
    // Recursive function to delete a node
// with given key from subtree with
// given root. It returns root of the
// modified subtree.
    template <class T>
    Node<T>* deleteNode(Node<T>* root, int key)
    {

        // STEP 1: PERFORM STANDARD BST DELETE
        if (root == NULL)
            return root;

        // If the key to be deleted is smaller
        // than the root's key, then it lies
        // in left subtree
        if (key < root->key)
            root->left = deleteNode<T>(root->left, key);

        // If the key to be deleted is greater
        // than the root's key, then it lies
        // in right subtree
        else if (key > root->key)
            root->right = deleteNode<T>(root->right, key);

        // if key is same as root's key, then
        // This is the node to be deleted
        else
        {
            // node with only one child or no child
            if ((root->left == NULL) ||
                (root->right == NULL))
            {
                Node<T>* temp = root->left ?
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
                Node<T>* temp = minValueNode<T>(root->right);

                // Copy the inorder successor's
                // data to this node
                root->key = temp->key;

                // Delete the inorder successor
                root->right = deleteNode<T>(root->right,
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
    template<class T>
    void preOrder(Node<T>* root)
    {
        if (root != NULL)
        {
            cout << root->key << " ";
            preOrder<T>(root->left);
            preOrder<T>(root->right);
        }
    }
    template<class T>
    void inOrder(Node<T>* root)
    {
        if (root != NULL)
        {
            inOrder<T>(root->left);
            cout << root->key << " ";
            inOrder<T>(root->right);
        }
    }
    template<class T>
    void postOrder(Node<T>* root)
    {
        if (root != NULL)
        {
            postOrder<T>(root->left);
            postOrder<T>(root->right);
            cout << root->key << " ";
        }
    }
//};