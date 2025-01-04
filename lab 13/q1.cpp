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

    bool isOnRight(tree* root, int a)
    {
        if(root==NULL)
        {
            return false;
        }
        if(root->data==a)
        {
            return true;
        }
        return isOnRight(root->right,a) || isOnRight(root->left,a);
    }

    tree* LCA(tree* root, int a, int b)
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->data==a || root->data==b)
        {
            return root;
        }
        bool aOnRight=isOnRight(root->right,a);
        bool bOnRight=isOnRight(root->right,b);

        if(aOnRight!=bOnRight)
        {
            return root;
        }
        if(aOnRight)
        {
            return LCA(root->right,a,b);
        }
        return LCA(root->left,a,b);
    }

   

  
       void distFromRoot(tree* root, int& heigth, int a, int current)
    {


        if(root)
        {
            if(root->data==a)
            {
                heigth=current;
                return ;
            }
            distFromRoot(root->left,heigth,a,current+1);
            distFromRoot(root->right,heigth,a,current+1);
        }


        
    }


    int dist(tree* root, int a, int b)
    {
        tree* temp=LCA(root,a,b);
        cout<<"LCA: "<<temp->data<<endl;
      
        int dist1=0;
        distFromRoot(root,dist1,a,0);
        cout<<"dist1: "<<dist1<<endl;
        int dist2=0;
        distFromRoot(root,dist2,b,0);
        cout<<"dist2: "<<dist2<<endl;
        int distLCA=0;
        distFromRoot(root,distLCA,temp->data,0);
        cout<<"distLCA: "<<distLCA<<endl;




        return dist1+dist2 -2*distLCA ;
        //cout<<dist1+dist2;

    }


};


int main()
{

    //hardcoding a tree
    tree* root=new tree(1);

    root->left=new tree(2);
    root->right=new tree(3);
    root->left->left=new tree(4);
    root->left->right=new tree(5);
    root->right->left=new tree(6);
    root->right->right=new tree(7);
    root->right->left->right=new tree(8);

    //root->levelOrder(root);

    cout<<endl;


    cout<<root->dist(root,8,7);



    return 0;
}