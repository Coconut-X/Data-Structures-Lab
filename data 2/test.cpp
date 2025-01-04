#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> leftt{};
vector<int> rightt{};

void InOrder(TreeNode *root, vector<int> &leftt)
{
    if (root)
    {
        InOrder(root->left, leftt);
        leftt.push_back(root->val);
        InOrder(root->right, leftt);
    }
    else
    {
        leftt.push_back(-1);
    }
}

bool isSymmetric(TreeNode *root)
{
    InOrder(root->left, leftt);
    InOrder(root->right, rightt);

    int size1 = leftt.size();
    int size2 = rightt.size();
    if (size1 != size2)
    {
        return false;
    }
    for (int i = 0; i < size1; i++)
    {
        if (leftt[i] != rightt[size1 - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(2);
    // root->left->right = new TreeNode(nullptr);
    root->right->left = new TreeNode(2);
    // root->right->right = new TreeNode(3);

    cout << isSymmetric(root) << endl;
    return 0;

}