#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class avl {
public:
    int data;
    int bf;  
    avl* left;
    avl* right;

    avl(int d) : data(d), bf(0), left(nullptr), right(nullptr) {}

    int height(avl* node) {
        if (node == nullptr) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    void updateBF(avl* node) {
        if (node != nullptr)
            node->bf = height(node->left) - height(node->right);
    }

    avl* rotateRight(avl* node) {
        avl* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        updateBF(node);
        updateBF(newRoot);
        return newRoot;
    }

    avl* rotateLeft(avl* node) {
        avl* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        updateBF(node);
        updateBF(newRoot);
        return newRoot;
    }


    avl* rotateLeftRight(avl* node) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

   
    avl* rotateRightLeft(avl* node) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    avl* balanceNode(avl* node) {
        updateBF(node);
        if (node->bf > 1) { // left heavy
            if (node->left->bf >= 0) {
                return rotateRight(node); // left left case
            } else {
                return rotateLeftRight(node); // left right case
            }
        } else if (node->bf < -1) { // right heavy
            if (node->right->bf <= 0) {
                return rotateLeft(node); // right right case
            } else {
                return rotateRightLeft(node); 
            }
        }
        return node;
    }


    avl* insert(int d, avl* node) {
        if (node == nullptr) return new avl(d);

        if (d < node->data)
            node->left = insert(d, node->left);
        else if (d > node->data)
            node->right = insert(d, node->right);
        else
            return node; 

        return balanceNode(node);
    }

    void displayLevelOrder(avl* root) {
        if (root == nullptr) return;

        queue<avl*> q;
        q.push(root);

        while (!q.empty()) {
            avl* temp = q.front();
            q.pop();
            cout << "Node: " << temp->data << ", BF: " << temp->bf << endl;

            if (temp->left != nullptr)
                q.push(temp->left);
            if (temp->right != nullptr)
                q.push(temp->right);
        }
    }


    bool isTreeAVL(avl* root) {
        if (root == nullptr) return true;

        if (abs(root->bf) > 1) return false;

        return isTreeAVL(root->left) && isTreeAVL(root->right);
    }

   void bstinsertwithoutBalancing(int d, avl* &root) {
        if (root == nullptr) {
            root = new avl(d);
            root->bf = height(root->left) - height(root->right);
            return;
    }

    if (d < root->data) { 
        if (root->left == nullptr) {
            root->left = new avl(d);
            root->left->bf = height(root->left->left) - height(root->left->right);
        } else {
            bstinsertwithoutBalancing(d, root->left); 
        }
    } else if (d > root->data) { 
        if (root->right == nullptr) {
            root->right = new avl(d);
            root->right->bf = height(root->right->left) - height(root->right->right);
        } else {
            bstinsertwithoutBalancing(d, root->right); 
        }
    }

    root->bf = height(root->left) - height(root->right);
}

    void preOrder(avl* root) {
        if (root == nullptr) return;
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(avl* root) {
        if (root == nullptr) return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }


    void postOrder(avl* root) {
        if (root == nullptr) return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }

    // int findSecondMin(avl* root) {
    //     if (!root || (!root->right and !root->left) ) return -1;

    //     if(!root->left and root->right and !root->right->right)
    //         return root->right->data;

    //     avl* current = root;
    //     while (current->left->left != nullptr) {
    //         current = current->left;
    //     }

    //     return current->data;
    // }

    int findSecondMin(avl* root, avl* mainRoot) {
        if (!mainRoot || (!mainRoot->right && !mainRoot->left)) 
            return -1;

        if (!mainRoot->left && mainRoot->right && !mainRoot->right->right)
            return mainRoot->right->data;
        
        if (root->left && root->left->left != nullptr) 
            return findSecondMin(root->left, mainRoot);
        
        return root->data;
    }


    bool search(avl* root, int key)
    {
        if(root->data==key)
            return true;
        if(root->data>key)
        {
            if(root->left==nullptr)
                return false;
            return search(root->left,key);
        }
        else
        {
            if(root->right==nullptr)
                return false;
            return search(root->right,key);
        }

    }


};

int main() {
    avl* root = nullptr;
    avl tree(0);

    vector<int> values = {33, 13, 53, 11, 21, 61, 8, 9};
    //vector<int> values= {5,2,7,1,4,6,9,3,8,10};
    //vector<int> values = {1,2};

    for (int val : values) {
        root = tree.insert(val, root);
    }

    cout << "After inserting and balancing:\n";
    cout<<"level order"<<endl;
    tree.displayLevelOrder(root);

    cout<<"\nPreorder"<<endl;
    tree.preOrder(root);

    cout<<"\nInorder"<<endl;
    tree.inOrder(root);

    cout<<"\nPostorder"<<endl;
    tree.postOrder(root);


    cout << "\nSecond minimum: " << tree.findSecondMin(root, root) << endl;

    int key=77;

    if(root->search(root,key))
        cout<<"\nFound"<<endl;
    else 
        cout<<"\nNot Found"<<endl;

    avl* root2 = nullptr;
    avl tree2(0);

    //vector<int> values2 = {2,1,3};
    //vector<int> values2= {5,2,7,1,4,6,9,3,8,10};
    vector<int> values2 = {33, 13, 53, 11, 21, 61, 8, 9};

    for (int val : values2) {
        tree2.bstinsertwithoutBalancing(val, root2);
    }

    cout<<"\n\nAfter inserting without balancing:\n";
    tree2.displayLevelOrder(root2);

    //check if avl
    if (tree2.isTreeAVL(root2)) {
        cout << "\nIt is AVL" << endl;
    } else {
        cout << "It is not AVL" << endl;
    }

    return 0;
}
