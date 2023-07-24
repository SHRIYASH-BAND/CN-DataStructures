#include "BinaryTreeNode.h"
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

class BinarySearchTree 
{
private:
    BinaryTreeNode<int> *root;

    void print(BinaryTreeNode<int> *);
    BinaryTreeNode<int> *insert(BinaryTreeNode<int> *, int );
    BinaryTreeNode<int> *remove(BinaryTreeNode<int> *, int );

public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    ~BinarySearchTree()
    {
        delete root;
    }

    void remove(int data)
    {
        root = remove(root, data);
    }

    void print()
    {
        this->print(root);
    }

    bool search(int data)
    {
        if (root == nullptr)
            return false;

        BinaryTreeNode<int> *temp = root;
        while (temp != nullptr)
        {
            if (temp->data > data)
            {
                temp = temp->left;
            }
            else if (temp->data < data)
            {
                temp = temp->right;
            }
            else
            {
                return true;
            }
        }

        return false;
    }

    void insert(int data){
        root = insert(root,data);
    }
};


BinaryTreeNode<int> *remove(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data > data)
    {
        root->left = remove(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = remove(root->right, data);
    }
    else
    {
        if (root->left != NULL && root->right != NULL)
        {
            BinaryTreeNode<int>* minNode = root->right;
            while (minNode->left!=NULL)
            {
                minNode = minNode->left;
            }
            
            root->data = minNode->data;
            root->right = remove(root->right, minNode->data);
            return root;
        }
        else if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left == NULL)
        {

            return root->right;
        }
        else
        {
            return root->left;
        }
    }
}

BinaryTreeNode<int> *BinarySearchTree::insert(BinaryTreeNode<int> *node, int data)
{
    if(node==nullptr){
        return new BinaryTreeNode<int>(data);
    }

    if(data<=node->data){
        node->left = insert (node->left, data);
    }
    else{
        node->right = insert(node->right , data);
    }

    return node;
}

void BinarySearchTree::print(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    if (root->left != NULL)
        cout << "L:" << root->left->data << ",";
    if (root->right != NULL)
        cout << "R:" << root->right->data ;
    cout<< endl;
    print(root->left);
    print(root->right);
}
