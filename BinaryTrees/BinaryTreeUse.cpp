#include <iostream>
#include<climits>
#include <math.h>
#include "BinaryTreeNode.h"
#include <queue>
#include "PairHeightDiameter.h"

using namespace std;

int height(BinaryTreeNode<int> *&root)
{
    if (root == NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);

    return max(left, right) + 1;
}

void printLevelWise(BinaryTreeNode<int> *&root)
{
    if (root == nullptr)
        return;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        cout << q.front()->data << ":";
        if (q.front()->left != nullptr)
        {
            cout << "L:" << q.front()->left->data << ",";
            q.push(q.front()->left);
        }
        else
        {
            cout << "L:-1,";
        }
        if (q.front()->right != nullptr)
        {
            cout << "R:" << q.front()->right->data;
            q.push(q.front()->right);
        }
        else
        {
            cout << "R:-1";
        }
        cout << endl;
        q.pop();
    }
}

void print(BinaryTreeNode<int> *&root)
{
    if (root == nullptr)
        return;
    cout << root->data << ":";
    if (root->left != nullptr)
    {
        cout << "L" << root->left->data;
    }
    if (root->right != nullptr)
    {
        cout << "R" << root->right->data;
    }

    cout << endl;
    print(root->left);
    print(root->right);
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Data " << endl;
    cin >> rootData;
    if (rootData == -1)
        return nullptr;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = takeInput();
    root->right = takeInput();
   
    return root;
}

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter Root Data: ";
    cin >> rootData;
    if (rootData == -1)
    {
        return nullptr;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        int left, right;
        cout << "Enter left child of Node " << q.front()->data << " ";
        cin >> left;
        cout << "Enter right child of Node " << q.front()->data << " ";
        cin >> right;
        if (left != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(left);
            q.front()->left = leftNode;
            q.push(leftNode);
        }
        if (right != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(right);
            q.front()->right = rightNode;
            q.push(rightNode);
        }
        q.pop();
    }

    return root;
}

int count(BinaryTreeNode<int> *&root)
{
    if (root == nullptr)
        return 0;

    return count(root->left) + count(root->right) + 1;
}

void inorder(BinaryTreeNode<int> *&root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(BinaryTreeNode<int> *&root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(BinaryTreeNode<int> *&root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

BinaryTreeNode<int> *buildTree(int *preOrderBinaryTree, int *inOrderBinaryTree, int size, int spo, int epo, int sio, int eio)
{
    if (spo > epo || sio > eio || size == 0)
        return nullptr;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preOrderBinaryTree[spo]);

    int ri = sio; // ri---> Root Index in Inorder
    for (int i = sio; i <= eio; i++)
    {
        if (inOrderBinaryTree[i] == root->data)
        {
            break;
        }
        ri++;
    }

    if (sio != eio && spo != epo)
    {
        int lsio = sio;                // left start of inoreder
        int leio = ri - 1;             // left end of inorder
        int rsio = ri + 1;             // right start of inorder
        int reio = eio;                // right end of inorder
        int lspo = spo + 1;            // left start of pre order
        int lepo = leio - lsio + lspo; // left end of pre order
        int rspo = lepo + 1;           // right start of preorder
        int repo = epo;                // right end of preorder
        int lsize = ri - sio;          // left size
        int rsize = size - lsize - 1;  // right size

        root->left = buildTree(preOrderBinaryTree, inOrderBinaryTree, lsize, lspo, lepo, lsio, leio);
        root->right = buildTree(preOrderBinaryTree, inOrderBinaryTree, rsize, rspo, repo, rsio, reio);
    }

    return root;
}

BinaryTreeNode<int> *buildTree(int *postorder, int *inorder, int spo, int epo, int sio, int eio)
{
    if (spo > epo || sio > eio)
        return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(postorder[epo]);

    int ri = sio;
    for (int i = sio; i <= eio; i++)
    {
        if (inorder[i] == root->data)
        {
            break;
        }
        ri++;
    }

    if (sio != eio && spo != epo)
    {
        int lsio = sio;
        int leio = ri - 1;
        int rsio = ri + 1;
        int reio = eio;

        int lspo = spo;
        int lepo = (ri - sio - 1) + spo;
        int rspo = lepo + 1;
        int repo = epo - 1;

        root->left = buildTree(postorder, inorder, lspo, lepo, lsio, leio);
        root->right = buildTree(postorder, inorder, rspo, repo, rsio, reio);
    }

    return root;
}

int diameter(BinaryTreeNode<int> *&root)
{
    if (root == NULL)
        return 0;

    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, max(option2, option3));
}

PairHeightDiameter<int> *optimizedDiameter(BinaryTreeNode<int> *&root)
{
    if (root == nullptr)
        return new PairHeightDiameter<int>();
    PairHeightDiameter<int> left(height(root->left), optimizedDiameter(root->left)->diameter);
    PairHeightDiameter<int> right(height(root->right), optimizedDiameter(root->right)->diameter);

    int d = max(max(left.diameter, right.diameter), left.height + right.height);

    return new PairHeightDiameter<int>(max(left.height, right.height) + 1, d);
}

int maxi(BinaryTreeNode<int>* root){
    if (root == nullptr)
        return  INT_MIN;
    return max(root->data, max(maxi(root->left), maxi(root->right)));    
}

int mini(BinaryTreeNode<int> *root){
    if(root==nullptr)
        return INT_MAX;
    
    return min(root->data, min(mini(root->left), mini(root->right)));

}

bool isBST(BinaryTreeNode<int> *root){

    if(root==NULL)
        return true;
    
    int leftMax = maxi(root->left);
    int rightMin = mini(root->right);

    return (leftMax<root->data) && (rightMin>=root->data) && isBST(root->left) && isBST(root->right);
}

// Time complex optimized isBst
pair<bool,pair<int,int>> optimizedIsBST(BinaryTreeNode<int>* &root){
    pair<bool, pair<int,int>> q;
    if (root==nullptr)
    {
        q.first = true;
        q.second.first = INT_MIN;
        q.second.second = INT_MAX;
        return q;
    }

    pair<bool, pair<int,int>> left = optimizedIsBST(root->left);
    pair<bool, pair<int,int>> right = optimizedIsBST(root->right);

    q.first = left.first && right.first && left.second.first<root->data && right.second.second>= root->data;
    q.second.first = max(max(right.second.first ,left.second.first), root->data);
    q.second.second = min(min(right.second.second,left.second.second), root->data);
    return  q;
    
}

// optimal approach
bool isBST(BinaryTreeNode<int>* root, int min, int max){
    if(root==NULL){
        return true;
    }

    if(root->data<min || root->data>max)
        return false;

    bool left = isBST(root->left, min, root->data-1);
    bool right = isBST(root->right, root->data, max);

    return left && right ;
    
}


int main()
{
    // binary tree 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    // BST 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    // NON BST 4 2 6 1 10 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    cout << endl;
    cout << "No of Nodes in Binary Tree are : " << count(root);

    cout << " \n Inorder of tree: " << endl;
    inorder(root);
    cout << " \n Preorder of tree: " << endl;
    preorder(root);
    cout << " \n Postorder of tree: " << endl;
    postorder(root);
    cout << "\n Diameter of tree is: " << diameter(root) << endl;
    PairHeightDiameter<int> *p = optimizedDiameter(root);
    cout << "\n Diameter  and height of tree using optimized approach is: " << p->diameter << " " << p->height << endl;

    cout<<"\n Checking if the tree is a BST "<<isBST(root)<<endl;
    cout<<"\n Checking if the tree is a BST Optimized method "<<optimizedIsBST(root).first<<endl;
    cout<<"\n Checking if the tree is a BST Optimal method "<<isBST(root, INT_MIN, INT_MAX)<<endl;



    // cout << "Constructing Binary Tree from Pre-order and In order" << endl;
    // int size = 0;
    // cout << "Enter No of Nodes: ";
    // cin >> size;
    // int *preOrderBinaryTree = new int[size];
    // int *inOrderBinaryTree = new int[size];

    // cout << "Enter Pre-Order of Binary Tree seperated by space" << endl;
    // for (int i = 0; i < size; i++)
    // {
    //     cin >> preOrderBinaryTree[i];
    // }
    // cout << "Enter In-Order of Binary Tree seperated by space" << endl;
    // for (int i = 0; i < size; i++)
    // {
    //     cin >> inOrderBinaryTree[i];
    // }
    // BinaryTreeNode<int> *r = buildTree(preOrderBinaryTree, inOrderBinaryTree, size, 0, size - 1, 0, size - 1);
    // printLevelWise(r);
    // delete[] preOrderBinaryTree;
    // delete[] inOrderBinaryTree;

    // cout << "\nConstructing Binary Tree from Post-order and In order" << endl;
    // cout << "Enter No of Nodes: ";
    // cin >> size;
    // int *postOrderBinaryTree = new int[size];
    // inOrderBinaryTree = new int[size];

    // cout << "Enter Post-Order of Binary Tree seperated by space" << endl;
    // for (int i = 0; i < size; i++)
    // {
    //     cin >> postOrderBinaryTree[i];
    // }
    // cout << "Enter In-Order of Binary Tree seperated by space" << endl;
    // for (int i = 0; i < size; i++)
    // {
    //     cin >> inOrderBinaryTree[i];
    // }
    // BinaryTreeNode<int> *r2 = buildTree(postOrderBinaryTree, inOrderBinaryTree, 0, size - 1, 0, size - 1);
    // printLevelWise(r2);
    // delete[] postOrderBinaryTree;
    // delete[] inOrderBinaryTree;
    // delete r2;
    // delete r;
    delete root;

 
    return 0;
}