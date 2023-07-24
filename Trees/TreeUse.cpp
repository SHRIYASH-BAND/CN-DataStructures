#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

int countLeafNodes(TreeNode<int> *root)
{
    int count = 0;
    if (root->children.size() == 0)
        return 1;
    else
    {
        for (int i = 0; i < root->children.size(); i++)
        {
            count += countLeafNodes(root->children[i]);
        }
    }
    return count;
}

int countNodes(TreeNode<int> *root)
{
    int count = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += countNodes(root->children[i]);
    }

    return count + 1;
}

void printAtLevelK(TreeNode<int> *root, int k)
{
    if (root == NULL)
        return;

    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    else
    {
        for (int i = 0; i < root->children.size(); i++)
        {
            printAtLevelK(root->children[i], k - 1);
        }
    }
}

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter Root: " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter No of Childs of node : " << front->data << endl;
        int noChild;
        cin >> noChild;
        for (int i = 0; i < noChild; i++)
        {
            int child;
            cout << "Enter " << i << " th child of root node " << front->data << endl;
            cin >> child;
            TreeNode<int> *childNode = new TreeNode<int>(child);
            pendingNodes.push(childNode);
            front->children.push_back(childNode);
        }
    }

    return root;
}

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Root: " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int noOfChildrens;
    cout << "Enter no of children of root: " << rootData << endl;
    cin >> noOfChildrens;
    for (int i = 0; i < noOfChildrens; i++)
    {
        root->children.push_back(takeInput());
    }

    return root;
}

void printLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> listNodes;
    listNodes.push(root);

    while (listNodes.size() != 0)
    {
        cout << listNodes.front()->data << ":";
        for (int i = 0; i < listNodes.front()->children.size(); i++)
        {
            listNodes.push(listNodes.front()->children[i]);
            if (i + 1 == listNodes.front()->children.size())
                cout << listNodes.front()->children[i]->data;
            else
                cout << listNodes.front()->children[i]->data << ",";
        }
        listNodes.pop();
        cout << endl;
    }
}

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children.at(i)->data << ",";
    }

    cout << endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children.at(i));
    }
}

void preorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}

void postorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        postorder(root->children[i]);
    }
    cout << root->data << " ";
}

void deleteTree(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    cout<<"deleting root "<<root->data<<endl;
    delete root;
}

int main()
{
    // Tree 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

    TreeNode<int> *root = takeInputLevelWise();
    // arrays of objects. 
    //TreeNode<int> * r1 = new TreeNode<int>[5]();
    cout<<"\nPrint level wise: \n";
    printLevelWise(root);
    // int k;
    // cin>>k;
    // cout<<"\nPrint nodes at depth "<<k<<endl;
    // printAtLevelK(root,k);
    cout<<"\nThere are " <<countLeafNodes(root)<<" Leaf nodes \n";
    cout << "\nPreorder of tree :\n";
    preorder(root);
    cout << "\nPostorder of tree:\n";
    postorder(root);
    cout<<endl<<endl;
    // deleteTree(root);
    delete root;

    return 0;
}
