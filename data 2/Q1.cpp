#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> arr;

class tree
{
public:

    int data;
    tree* left;
    tree* right;

    tree(int data): data(data), right(nullptr), left(nullptr){}
    tree(): data(0), right(nullptr), left(nullptr){}

    void insert(tree*& root, tree* newNode)
    {
        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        if (newNode->data >= root->data)
        {
            if (root->right == nullptr)
            {
                root->right = newNode;
                return;
            }
            else
            {
                insert(root->right, newNode);
            }
        }
        else
        {
            if (root->left == nullptr)
            {
                root->left = newNode;
                return;
            }
            else
            {
                insert(root->left, newNode);
            }
        }
    }

    void printlevelOrderUniDirectional(tree* root)
    {
        if(root==nullptr)
        {
            return;
        }

        queue<tree*> q;
        q.push(root);

        while(!q.empty())
        {
            tree* temp=q.front();
            cout<<temp->data<<" ";
            q.pop();


            if(temp->left!=nullptr)
            {
                q.push(temp->left);
            }

            if(temp->right!=nullptr)
            {
                q.push(temp->right);
            }
        }
    }

    void storeInOrder(tree* root)
    {
        if(root==nullptr)
        {
            return;
        }

        storeInOrder(root->left);
        arr.push_back(root->data);
        storeInOrder(root->right);
    }


    void insertLevelOrder(tree* &root, int data)
    {
        if(root==nullptr)
        {
            root=new tree(data);
            return;
        }

        queue<tree*> q;
        q.push(root);

        while(!q.empty())
        {
            tree* temp=q.front();
            q.pop();

            if(temp->left==nullptr)
            {
                temp->left=new tree(data);
                break;
            }
            else
            {
                q.push(temp->left);
            }

            if(temp->right==nullptr)
            {
                temp->right=new tree(data);
                break;
            }
            else
            {
                q.push(temp->right);
            }
        }
    }


    void makeDummyCompleteTree(tree* &dummy, int count)
    {
        for(int i=1;i<=count;i++)
        {
            insertLevelOrder(dummy,-1);
        }
    }

    void replaceInorder(tree*&root,int& d)
    {
        if(root==nullptr)
            return;

        replaceInorder(root->left,d);

        if(root->data==-1 )
        {
            root->data=arr[d++];   
        }
        replaceInorder(root->right,d);
    }


    void deallocate(tree* root)
    {
        if(root==nullptr)
        {
            return;
        }

        deallocate(root->left);
        deallocate(root->right);

        delete root;
    }   

};


int main()
{

    tree* head=new tree(0);
    head=nullptr;

    tree* root=new tree(0);
    root=nullptr;


    // head->insert(head,new tree(10));
    // head->insert(head,new tree(5));
    // head->insert(head,new tree(15));
    // head->insert(head,new tree(3));
    // head->insert(head,new tree(7));
    // head->insert(head,new tree(12));
    // head->insert(head,new tree(18));
    // head->insert(head,new tree(1));
    // head->insert(head,new tree(4));
    // head->insert(head,new tree(19));
    // head->insert(head,new tree(17));

    //0-11

    for(int i=1;i<=7;i++)
    {
        head->insert(head,new tree(i));
    }


    // int x=0;
    // for(int i=1;i<=11;i++)
    // {
    //     cin>>x;
    //     head->insert(head,new tree(i));
    // }

    head->storeInOrder(head);
    sort(arr.begin(),arr.end());

    cout<<endl;

    root->makeDummyCompleteTree(root,arr.size());

   // root->printlevelOrderUniDirectional(root);

   //display arr
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl<<"bla"<<endl;

    //root->insertElementsInDummy(root);
    int d=0;
    root->replaceInorder(root,d);

    root->printlevelOrderUniDirectional(root);

    head->deallocate(head);
    root->deallocate(root);


    return 0;
}