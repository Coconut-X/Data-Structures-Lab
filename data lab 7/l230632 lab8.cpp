#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node
{
    public:
    int data;
    node *left;
    node *right;

    node():data(0),left(NULL),right(NULL){}

    node(int value):data(value),left(NULL),right(NULL){}

    void Insertion_binary_Search_Tree(node*& root,node* newNode)
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
                Insertion_binary_Search_Tree(root->right, newNode);
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
                Insertion_binary_Search_Tree(root->left, newNode);
            }
        }
    }


     int length(node* root)
    {
        if (root == nullptr) return 0;
        return 1 + length(root->left) + length(root->right);
    }


    void deleteWithKey(node*&root,int key)
    {
        if(root==nullptr)
        {
            return;
        }
        if(root->data==key)
        {
            if(root->left==nullptr && root->right==nullptr)
            {
                delete root;
                root=nullptr;
            }
            else if(root->left==nullptr)
            {
                node*temp=root;
                root=root->right;
                delete temp;
            }
            else if(root->right==nullptr)
            {
                node*temp=root;
                root=root->left;
                delete temp;
            }
            else
            {
                node*temp=root->right;
                while(temp->left!=nullptr)
                {
                    temp=temp->left;
                }
                root->data=temp->data;
                deleteWithKey(root->right,temp->data);
            }
        }
        else if(root->data<key)
        {
            deleteWithKey(root->right,key);
        }
        else
        {
            deleteWithKey(root->left,key);
        }
    }


    void deAllocate(node*& root)
    {
        if (root == nullptr) return;
        deAllocate(root->left);
        deAllocate(root->right);
        delete root;
        root = nullptr;
    }

    void preOrder(node* root)
    {
        if (root == nullptr) return;
        cout << root->data << "  ";
        preOrder(root->left);
        preOrder(root->right);							
    }

     void rangedSearch(node* root,int low,int high)
    {
        if (root == nullptr) return;

        if (root->data >= low && root->data <= high)
        {
            cout << root->data << "  ";
        }

        rangedSearch(root->left,    low,    high);
        rangedSearch(root->right,   low,    high);							
    }

    int secondLargest(node* root)
    {
        if (root == nullptr) return -1;

        if (root->right == nullptr && root->left == nullptr)
        {
            return -1;
        }

        if (root->right == nullptr && root->left != nullptr)
        {
            node* temp = root->left;
            while (temp->right != nullptr)
            {
                temp = temp->right;
            }
            return temp->data;
        
        }

        if (root->right != nullptr && root->right->right == nullptr && root->right->left == nullptr)
        {
            return root->data;
        }

        return secondLargest(root->right);
    }


    void levelOrderTraversal(node*root)
    {
       if (root == nullptr) return;

        queue<node*> Q;
        Q.push(root);

        while (!Q.empty())
        {
            node* current = Q.front();
                cout << current->data << "  ";
            Q.pop();
            if (current->left != nullptr) Q.push(current->left);
            if (current->right != nullptr) Q.push(current->right);
            
        }
        cout << endl;
        
    }


    void zigzagLevelOrderTraversal(node* root) 
    {
        //using two stacks and bool variable to keep track of the direction

        if (root == nullptr) return;

        stack<node*> currentLev;
        stack<node*> nextLev;

        currentLev.push(root);
        bool direction = true;

        while (!currentLev.empty())
        {
            if(root==nullptr) return;


            node* temp = currentLev.top();
            currentLev.pop();

            if (temp)
            {
                cout << temp->data << "  ";

                if (direction)
                {
                    if (temp->left)
                    {
                        nextLev.push(temp->left);
                    }
                    if (temp->right)
                    {
                        nextLev.push(temp->right);
                    }
                }
                else
                {
                    if (temp->right)
                    {
                        nextLev.push(temp->right);
                    }
                    if (temp->left)
                    {
                        nextLev.push(temp->left);
                    }
                }
            }

            if (currentLev.empty())
            {
                direction = !direction;
                swap(currentLev, nextLev);
            }
        }

        
    }
};


int main()
{


    node*root=new node(0);
    root=nullptr;

    int count=0;
    cout<<"Enter the number of nodes you want to insert in the tree: ";
    cin>>count;

    cout<<"\nEnter the values: ";

    for(int i=0;i<count;i++)
    {
        int value;
        cin>>value;
        node*newNode=new node(value);
        root->Insertion_binary_Search_Tree(root,newNode);
    }

    cout<<"Enter the key you want to delete: ";
    int key;
    cin>>key;

    root->deleteWithKey(root,key);

    cout<<"PreOrder: ";
    root->preOrder(root);

    cout<<"Enter the range: ";
    int low,high;
    cin>>low>>high;

    cout<<"Ranged Search: ";
    root->rangedSearch(root,low,high);


    cout<<"Second Largest: ";
    cout<<root->secondLargest(root);


    cout<<"Level Order: ";
    root->levelOrderTraversal(root);

    cout<<"ZigZag Level Order: ";

    root->zigzagLevelOrderTraversal(root);





    root->deAllocate(root);

    return 0;
}