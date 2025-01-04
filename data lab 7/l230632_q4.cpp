#include<iostream>
using namespace std;

int numberOfLeaves=0;

struct node
{
    public:
    int data;
    node* left;
    node* right;
    int count=0;

    node(int data): data(data), left(nullptr), right(nullptr){}
    node():  left(nullptr), right(nullptr){}


    //copy constructor to replicate exact tree structure

    node(const node& other)
    {
        data = other.data;
        if (other.left != nullptr)
        {
            left = new node(*other.left);
        }
        else
        {
            left = nullptr;
        }

        if (other.right != nullptr)
        {
            right = new node(*other.right);
        }
        else
        {
            right = nullptr;
        }
    }

    void deAllocate(node*& root)
    {
        ///deletion by inorder
        if (root == nullptr) return;
        node* temp = root;
        deAllocate(temp->left);
        deAllocate(temp->right);
        delete root;
        root = nullptr;
        //cout << "root deleted\n";
    }




    
    /// current-left-right
    void preOrder(node* root)
    {
        if (root == nullptr) return;
        cout << root->data << "  ";
        preOrder(root->left);
        preOrder(root->right);							
    }

    //left curr right
    void inOrder(node*root)
    {
        if(root==nullptr) return;
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }

    //left right current
    void postOrder(node*root)
    {
        if(root==nullptr) return;
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }

    int leaves(node* root)
    {   
        
        if (root == nullptr) return count;
        if (root->right == nullptr && root->left == nullptr)
            numberOfLeaves++;
            
        leaves(root->left);
        leaves(root->right);

        return numberOfLeaves;
    }


    int length(node* root)
    {
        if (root == nullptr) return 0;
        return 1 + length(root->left) + length(root->right);
    }

        
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

};


int main()
{

    node*root=new node(0);
    root=nullptr;

    cout<<"Enter the number of nodes you want to insert in the tree: ";

    int n;

    cin>>n;

    for(int i=0;i<n;i++)
    {
        int data;
        cout<<"Enter data:  ";
        cin>>data;
        node*newNode=new node(data);
        root->Insertion_binary_Search_Tree(root,newNode);
    }

    cout<<"PreOrder: ";
    root->preOrder(root);

    cout<<"\nInOrder: ";
    root->inOrder(root);

    cout<<"\nPostOrder: ";
    root->postOrder(root);

    cout<<"\nNumber of leaves: "<<root->leaves(root);

    cout<<"\nLength of tree: "<<root->length(root);


    node*root2=new node(*root);

    cout<<"\nPreOrder of copied tree: ";
    root2->preOrder(root2);

    cout<<"\nInOrder of copied tree: ";
    root2->inOrder(root2);

    cout<<"\nPostOrder of copied tree: ";
    root2->postOrder(root2);

    cout<<"\nNumber of leaves of copied tree: "<<root2->leaves(root2);

    cout<<"\nLength of copied tree: "<<root2->length(root2);

    root->deAllocate(root);

    root2->deAllocate(root2);




    return 0;
}