#include <iostream>
using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val): data(val), left(nullptr), right(nullptr) {};
};

void Insert(BSTNode* &root, int val) {
    if (root == nullptr) {
        root = new BSTNode(val);
        return;
    }
    else if (val <= root->data) {
        Insert(root->left, val);
    }
    else {
        Insert(root->right, val);
    }
    return;
}

bool Search(BSTNode* root, int val) {
    if (root == nullptr) {
        return false;
    }
    else if (root->data == val) {
        return true;
    }
    else if (root->data > val) {
        return Search(root->left, val);
    }
    else
    {
        return Search(root->right, val);
    }
}

void InOrderTraverse(BSTNode* root) {
    if (root == nullptr) {
        return;
    }
    InOrderTraverse(root->left);
    cout << root->data << endl;
    InOrderTraverse(root->right);
}




int main() {
    BSTNode* root = nullptr;
    Insert(root, 22);
    Insert(root, 12);
    Insert(root, 32);
    Insert(root, 2);

    InOrderTraverse(root);

    bool ret = Search(root, 22);
    if (ret == true)
    {
        cout << "found 22." << endl;
    }
    else
    {
        cout << "Not found 22." << endl;
    }
    return 0;
}


