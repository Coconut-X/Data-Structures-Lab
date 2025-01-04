#include<iostream>
#include<vector>
using namespace std;

class bst
{
    public:
    int data;
    bst* left;
    bst* right;

    bst(): data(0), left(nullptr), right(nullptr) {}

    bst(int d): data(d), left(nullptr), right(nullptr) {}

    void insert(int d)
    {
        if(d < data)
        {
            if(left == nullptr)
                left = new bst(d);
            else
                left->insert(d);
        }
        else
        {
            if(right == nullptr)
                right = new bst(d);
            else
                right->insert(d);
        }
    }

    int calculateSum()
    {
        return data + (left ? left->calculateSum() : 0) + (right ? right->calculateSum() : 0);
    }
};

class list
{
    public:
    bst* root;
    list* next;
    int sum = 0;

    list(): root(nullptr), next(nullptr) {}

    void setSum()
    {   sum=0;
        if (root != nullptr)
        {
            sum = root->calculateSum();
        }
    }


    void displayAllSum()
    {
        list* temp = this;
        while (temp != nullptr)
        {
            cout << temp->sum << " ";
            temp = temp->next;
        }
    }


    void sortList()
    {
        list* temp = this;
        while (temp != nullptr)
        {
            list* temp2 = temp->next;
            while (temp2 != nullptr)
            {
                if (temp->sum > temp2->sum)
                {
                    int t = temp->sum;
                    temp->sum = temp2->sum;
                    temp2->sum = t;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }
    



};

int main()
{

    vector<int> v1 = {10, 5, 15, 8, 3};
    vector<int> v2 = {3, 4, 5, 6, 7};
    vector<int> v3 = {1, 2, 3, 4, 5};
    vector<int> v4 = {13, 2, 33, 4, 5};

    list* head1 = new list();
    list* head2 = new list();
    list* head3 = new list();
    list* head4 = new list();
    head1->root = new bst(v1[0]); // Initialize the root with a value
    for (int i = 1; i < v1.size(); i++)
        head1->root->insert(v1[i]);

    head1->next=head2;
    head2->root = new bst(v2[0]); // Initialize the root with a value
    for (int i = 1; i < v2.size(); i++)
        head2->root->insert(v2[i]);

    head2->next=head3;
    head3->root = new bst(v3[0]); // Initialize the root with a value
    for (int i = 1; i < v3.size(); i++)
        head3->root->insert(v3[i]);

    head3->next=head4;
    head4->root = new bst(v4[0]); // Initialize the root with a value
    for (int i = 1; i < v4.size(); i++)
        head4->root->insert(v4[i]);

    head1->setSum();
    head2->setSum();
    head3->setSum();
    head4->setSum();

    cout<<"\nSum before sorting list: "<<endl;
    head1->displayAllSum();
    cout<<endl;

    head1->sortList();

    cout<<"\nSum after sorting list: "<<endl;
    head1->displayAllSum();



    return 0;
}
