#include <iostream>
using namespace std;

/*
 * Description: Convert a givin binary tree to a doubly linked list.
 * Example:
 *          10
 *         /   \
 *       12     15
 *      /  \    / 
 *    25   30  36 
 *
 *   25 <=> 12 <=> 30 <=> 10 <=> 36 <=> 15
 *
 * http://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/
 * http://www.geeksforgeeks.org/convert-a-given-binary-tree-to-doubly-linked-list-set-2/
 * http://www.geeksforgeeks.org/convert-given-binary-tree-doubly-linked-list-set-3/
 * http://www.geeksforgeeks.org/convert-a-given-binary-tree-to-doubly-linked-list-set-4/
 */

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(const int i) : data(i), left(nullptr), right(nullptr) {};
};

/* 思路：
 * 1. 递归思想，只是返回的是当前节点而已。
 * 2. 在返回当前节点之前，递归左子树，找到它的最右节点，和当前节点的left关联。
 * 3. 在返回当前节点之前，递归右子树，找到它的最左节点，和当前节点的right关联。
 * 4. 关联完毕，返回当前节点。该算法的实现类似于后序遍历。
 */
Node* convert(Node* &root) {
    if (root == nullptr) {
        return root;
    }
    if (root->left) {
        Node* leftNode = convert(root->left);
        while (leftNode->right) {
            leftNode = leftNode->right;
        }
        leftNode->right = root;
        root->left = leftNode;
    }
    if (root->right) {
        Node* rightNode = convert(root->right);
        while (rightNode->left) {
            rightNode = rightNode->left;
        }
        root->right = rightNode;
        rightNode->left = root;
    }
    return root;
}

int main() {
    Node* r0 = new Node(10);
    Node* r1 = new Node(12);
    Node* r2 = new Node(15);
    Node* r3 = new Node(25);
    Node* r4 = new Node(30);
    Node* r5 = new Node(36);
    r0->left =  r1;
    r0->right = r2;
    r1->left =  r3;
    r1->right = r4;
    r2->left =  r5;

    Node* h = convert(r0);
    while (h->left) {
        h = h->left;
    }
    while (h) {
        cout << h->data << " ";
	h = h->right;
    }
    cout << endl;
    return 0;
}






