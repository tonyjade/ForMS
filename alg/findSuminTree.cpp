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

/* 思路：
 * 1. 暂时不考虑vector，如果找到了一条路径（当前为叶子节点，且加到当前叶子节点的cur_sum等于总的sum），则打印。
 * 2. 若当前节点有左子树，则递归找左子树。
 * 3. 若当前节点有右子树，则递归找右子树。
 * 4. 关于v.push_back()和v.pop()这两个函数的调用点，我暂时不大理解，只能死记硬背，只能直观地认为是"各人自扫门前雪"的策略。
 *    即每一层递归都只push当前节点的data，因此也只pop当前节点的data，这样才能最终匹配起来。
 * 5. 若不打印每一条路径，只打印路径数，则比较容易，只考虑1~3步骤。
 */
void findSum(Node* root, int sum, vector<int> & v, int cur_sum) {
    if (!root) return;
    cur_sum += root->data;
    v.push_back(root->data);
    if (root->left) {
        findSum(root->left, sum, v, cur_sum);
    }
    if (root->right) {
        findSum(root->right, sum, v, cur_sum);
    }
    if (isLeaf(root) && cur_sum == sum) {
        for (auto p = v.begin(); p != v.end(); ++p) {
            cout << *p << " ";
        }
        cout << endl;
    }
    v.pop_back();
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

    vector<int> v;
    findSum(r0, 52, v, 0);

    return 0;
}
