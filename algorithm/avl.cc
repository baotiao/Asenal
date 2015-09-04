#include <iostream>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    int h;
    explicit TreeNode(int v) :
        val(v)
    {
        left = NULL;
        right = NULL;
        h = 1;
    }
};

class AVLTree
{
public:
    AVLTree(TreeNode* root) :
        root_(root)
    {
    }

    AVLTree()
    {
    }

    TreeNode *root() { return root_; };

    bool Insert(int val);
    bool Search(int val);


private:

    TreeNode* root_;

};



int main()
{
    AVLTree* avlTree = new AVLTree();

    return 0;
}
