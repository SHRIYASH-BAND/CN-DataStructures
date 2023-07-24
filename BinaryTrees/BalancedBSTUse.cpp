#include<iostream>
#include"BalancedBSTTreeNode.h"
#include<math.h>
#include<algorithm>
using namespace std;

int height(BalancedBSTTreeNode *N)
{
    if (N == NULL)
        return 0;

    return N->height;
}



// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
BalancedBSTTreeNode *rightRotate(BalancedBSTTreeNode *y)
{
    BalancedBSTTreeNode *x = y->left;
    BalancedBSTTreeNode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;

    // Return new root
    return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
BalancedBSTTreeNode *leftRotate(BalancedBSTTreeNode *x)
{
    BalancedBSTTreeNode *y = x->right;
    BalancedBSTTreeNode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;

    // Return new root
    return y;
}

// Get Balance factor of BalancedBSTTreeNode N
int getBalance(BalancedBSTTreeNode *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key
// in the subtree rooted with BalancedBSTTreeNode and
// returns the new root of the subtree.
BalancedBSTTreeNode *insert(BalancedBSTTreeNode *Node, int key)
{
    /* 1. Perform the normal BST insertion */
    if (Node == NULL){
        BalancedBSTTreeNode * b = new BalancedBSTTreeNode(key);
        return b;
    }

    if (key < Node->key)
        Node->left = insert(Node->left, key);
    else if (key > Node->key)
        Node->right = insert(Node->right, key);
    else // Equal keys are not allowed in BST
        return Node;

    /* 2. Update height of this ancestor BalancedBSTTreeNode */
    Node->height = 1 + max(height(Node->left),
                                          height(Node->right));

    /* 3. Get the balance factor of this ancestor
        BalancedBSTTreeNode to check whether this BalancedBSTTreeNode became
        unbalanced */
    int balance = getBalance(Node);

    // If this BalancedBSTTreeNode becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && key < Node->left->key)
        return rightRotate(Node);

    // Right Right Case
    if (balance < -1 && key > Node->right->key)
        return leftRotate(Node);

    // Left Right Case
    if (balance > 1 && key > Node->left->key)
    {
        Node->left = leftRotate(Node->left);
        return rightRotate(Node);
    }

    // Right Left Case
    if (balance < -1 && key < Node->right->key)
    {
        Node->right = rightRotate(Node->right);
        return leftRotate(Node);
    }

    /* return the (unchanged) BalancedBSTTreeNode pointer */
    return Node;
}

void inorder(BalancedBSTTreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main()
{
    BalancedBSTTreeNode *root=NULL;
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
    */
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    inorder(root);
    return 0;
}