#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int data): data(data), next(NULL) {}


    void insert(node* &root, int val)
    {
        if(root==NULL)
        {
            node* newNode=new node(val);
            root=newNode;
            return;
        }

        node*temp=root;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        temp->next=new node(val);

    }

    void display(node*root)
    {

        while(root!=nullptr)
        {
            cout<<root->data<<"  ";
            root=root->next;
        }

    }

    void deleteNode(node*&root, int val)
    {
        // if(root==nullptr)
        // {
        //     cout<<"List is empty"<<endl;
        //     return;
        // }

        // node* temp=root;

        // if(temp->data==val)
        // {
        //     node* toDelete=root;
        //     root=root->next;
        //     delete toDelete;
        //     return;
        // }

        // while(temp->next!=nullptr and temp->next->data!=val )
        // {
        //     temp=temp->next;
        // }


        // node* toDelete=temp->next;

        // temp->next=temp->next->next;
        // delete toDelete;


        if(root==nullptr)
        {
            cout<<"List is empty"<<endl;
            return;
        }

        if(root->data==val)
        {
            node* toDelete=root;
            root=root->next;
            delete toDelete;
            return;
        }

        node* temp=root;

        while(temp->next!=nullptr and temp->next->data!=val)
        {
            temp=temp->next;
        }

        if(temp->next==nullptr)
        {
            cout<<"Element not found"<<endl;
            return;
        }


        node* toDelete=temp->next;

        temp->next=temp->next->next;

        delete toDelete;

    }

    void insetAtbeginning(node*&root, int val)
    {
        if(root==NULL)
        {
            node* newNode=new node(val);
            root=newNode;
            return;
        }

        node* newNode=new node(val);
        newNode->next=root;
        root=newNode;
    }

};

int main()
{

   //node->next==null this is tail of list
    //node->next!=null this is not tail of list

    
    node* root=new node(0);
    root=nullptr;

    root->insert(root,1);
    root->insert(root,2);
    root->insert(root,3);
    root->insert(root,4);
    root->insert(root,5);
    root->insert(root,6);
    root->insert(root,7);
    root->insert(root,8);

    root->insetAtbeginning(root,99);
    root->display(root);


    return 0;
}