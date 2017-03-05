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

int FindHeight(BSTNode* root) {
    if (root == nullptr) {
        return -1;
    }
    else {
        int leftHeight = FindHeight(root->left);
        int rightHeight = FindHeight(root->right);
        if (leftHeight > rightHeight) {
            return (leftHeight + 1);
        }
        else {
            return (rightHeight + 1);
        }
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

BSTNode* Find(BSTNode* root, int val) {
    if (root == nullptr) {
        return nullptr;
    }
    else if (root->data == val) {
        return root;
    }
    else if (root->data > val) {
        return Find(root->left, val);
    }
    else if (root->data < val) {
        return Find(root->right, val);
    }
}

// Jaden: a bit tricky.
BSTNode* GetInorderSuccessor(BSTNode* root, int val) {
    BSTNode* current = Find(root, val);
    if (current == nullptr) {
        return nullptr;
    }
    if (current->right) {
        BSTNode* tmp = current->right;
        while (tmp->left) {
            tmp = tmp->left;
            return tmp;
        }
    }
    else {
        BSTNode* successor = nullptr;
        BSTNode* ancestor = root;
        while (ancestor != current) {
            if (current->data < ancestor->data) {
                successor = ancestor;
                ancestor = succssor->left;
            }
            else {
                ancestor = ancestor->right;
            }
        }
        return successor;	
    }
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
 
    int height = FindHeight(root);
    cout << "Height is : " << height << endl;

    return 0;
}


