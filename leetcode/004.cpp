#include <iostream>
#include <vector>

using namespace std;

double findMedian(vector<int> a, vector<int> b) {
    if (a.size() < 1 || b.size() < 1) {
        return 0;
    }
    int la = 0, ra = a.size()-1;
    int lb = 0, rb = b.size()-1;
    int mid_a = (la + ra) / 2, mid_b = (lb + rb) / 2;
    while (la <= ra && lb <= rb) {
        if (mid_a < mid_b) {
            la = mid_a;
            rb = mid_b;
        }
        else {
            ra = mid_a;
            lb = mid_b;
        }
        mid_a = (la + ra) / 2;
        mid_b = (lb + rb) / 2;
    }
    



}


int main() {

    return 0;
}
