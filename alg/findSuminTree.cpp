#include <iostream>
#include <vector>
using namespace std;

/*
 * http://codercareer.blogspot.com/2011/09/no-04-paths-with-specified-sum-in.html
 * http://www.jianshu.com/p/cbfe0b3d7c12
 */
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(const int i): data(i), left(nullptr), right(nullptr) {};
};

bool isLeaf(Node* root) {
    return (root && !root->left && !root->right);
}

void findSum(Node* root, int sum, vector<int> & v, int cur_sum) {
    if (!root) return;
    cur_sum += root->data;
    v.push_back(root->data);
    if (isLeaf(root) && cur_sum == sum) {
        for (auto p = v.begin(); p != v.end(); ++p) {
            cout << *p << " ";
        }
        cout << endl;
    }
    if (root->left) {
        findSum(root->left, sum, v, cur_sum);
    }
    if (root->right) {
        findSum(root->right, sum, v, cur_sum);
    }
    path.pop_back();
}





int main() {
    
    return 0;
}
