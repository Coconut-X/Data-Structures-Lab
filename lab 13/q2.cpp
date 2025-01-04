#include<iostream>
#include<queue>

using namespace std;

class tree
{
    public:
    int data;
    tree* left;
    tree* right;
    tree(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }

    tree()
    {
        data=0;
        left=NULL;
        right=NULL;
    }

    void levelOrder(tree* root)
    {
        queue<tree*> q;
        q.push(root);
        while(!q.empty())
        {
            tree* temp=q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }


    void mirrorTree(tree* root)
    {
        if(root==NULL)
        {
            return;
        }
        mirrorTree(root->left);
        mirrorTree(root->right);
        tree* temp=root->left;
        root->left=root->right;
        root->right=temp;
    }

};


int main(){

     //hardcoding a tree
    tree* root=new tree(1);

    root->left=new tree(2);
    root->right=new tree(3);
    root->left->left=new tree(4);
    root->left->right=new tree(5);
    root->right->left=new tree(6);
    root->right->right=new tree(7);
    root->right->left->right=new tree(8);

    root->levelOrder(root);


    root->mirrorTree(root);

    cout<<"\n\n";

    root->levelOrder(root);




    return 0;
}