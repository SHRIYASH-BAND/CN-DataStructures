#include<climits>

class BalancedBSTTreeNode
{
public:
    int key;
    BalancedBSTTreeNode *left;
    BalancedBSTTreeNode *right;
    int height;

    BalancedBSTTreeNode(){
        this->key=INT_MIN;
        left=nullptr;
        right=nullptr;
        height=0;
    }
    BalancedBSTTreeNode(int key)
    {
        this->key = key;
        left = nullptr;
        right = nullptr;
        height = 1;
    }

    ~BalancedBSTTreeNode()
    {
        delete left;
        delete right;
    }
};
