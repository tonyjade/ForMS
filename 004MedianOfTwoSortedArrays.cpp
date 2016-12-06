// Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Author : Jaden
// Data   : 2016-11-30

/***********************************************************************************************************************
 * 4. Median of Two Sorted Arrays
 * 
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 * Example:
 * nums1 = [1, 3] nums2 = [2]    The median is 2.0
 * nums1 = [1, 2] nums2 = [3, 4] The median is (2 + 3)/2 = 2.5
 *
 **********************************************************************************************************************/
#include <vector>
#include <iostream>

using namespace std;
double findKth(vector<int>, vector<int>, int);
// Analysis:
// Note that the definition of the Median:
// If the size of m + n is even, the median is average of the (m+n)/2th and the (m+n)/2+1th elements. 
// If the size is odd, the median is (m+n)/2+1th element.
//
// So the task is converted to find the kth and/or (k+1)th member of the sorted arrays. 
// Respect to the constraint of O(log(m+n)) complexity, yeah, binary search!
// Similar to but slight different from binary search, we divide K into 2 halves, not m+n. 
// If we consider m/2 and n/2, it would be uncontrollable. (We have to judge whether m+n is even or odd?)
//
// For example:
// Two pointers pa and pb are used for locating the pivot elments of the two arrays. 
// m = 5, n = 8. k = 6.   pa = k/2 --> 3. pb = k/2 -pa --> 3. 
// A = [1, 3, 5, 7, 9]  B = [2, 4, 8, 10, 12, 14, 16, 18].   
//            ^                    ^
//            pa                   pb
// We should find the kth element.
// if (A[pa] < B[pb])
//     cut A[0]-A[pa], because they are all less than the kth element, then just find the (k-pa)th element.
// if (A[pa] > B[pb])
//     cut B[0]-B[pb], the same reason, just find the (k-pb)th element.


double findMedian(vector<int>& arr_a, vector<int>& arr_b) {
    int m = arr_a.size();
    int n = arr_b.size();
    int total = m + n;
    if (total % 2 != 0)
        return findKth(arr_a, arr_b, total/2 + 1);
    else
        return (findKth(arr_a, arr_b, total/2) + findKth(arr_a, arr_b, total/2+1)) / 2.0;
}

double findKth(vector<int> arr_a, vector<int> arr_b, int k) {
    int m = arr_a.size();
    int n = arr_b.size();
    int total = m + n;
    if (m > n)  return findKth(arr_b, arr_a, k);
    if (m == 0) return arr_b[k - 1];
    if (k == 1) return min(arr_a[0], arr_b[0]);
    int pa = min(m, k/2);
    int pb = k - pa;
    if (arr_a[pa] < arr_b[pb]) {
        arr_a.erase(begin(arr_a), begin(arr_a) + pa);
	return findKth(arr_a, arr_b, k - pa);
    } else {
        arr_b.erase(begin(arr_b), begin(arr_b) + pb);
        return findKth(arr_a, arr_b, k - pb);
    }
}

int main()
{
    vector<int> va = {2, 4, 5, 10};
    vector<int> vb = {1, 6, 9, 11};

    cout << findMedian(va, vb) << endl;
    return 0;
}
