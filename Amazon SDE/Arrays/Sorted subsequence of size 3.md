# [Question Link](https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1/?track=amazon-arrays&batchId=192#)

# Given an array A of N integers, find any 3 elements in it such that A[i] < A[j] < A[k] and i < j < k.

# Example 1:

# Input:
# N = 5
# A[] = {1,2,1,1,3}
# Output: 1
# Explanation: a sub-sequence 1 2 3 exist.
# Example 2:

# Input:
# N = 3
# A[] = {1,1,3}
# Output: 0
# Explanation: no such sub-sequence exist.
# Your Task:
# Your task is to complete the function find3Numbers which finds any 3 elements in it such that A[i] < A[j] < A[k] and i < j < k. You need to return them as a vector/ArrayList/array (depending on the language cpp/Java/Python), if no such element is present then return the empty vector of size 0.

# Note: The output will be 1 if the sub-sequence returned by the function is present in array A else 0. If the sub-sequence returned by the function is not in the format as mentioned then the output will be -1.

# Expected Time Complexity: O(N)
# Expected Auxiliary Space: O(N)

# Constraints:
# 1 <= N <= 105
# 1 <= A[i] <= 106, for each valid i

```
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2, int n, int m) {

    if (m == 0) return true;
    if (n == 0) return false;

    if (v1[n - 1] == v2[m - 1]) return isSubSequence(v1, v2, n - 1, m - 1);

    return isSubSequence(v1, v2, n - 1, m);
}


 // } Driver Code Ends
/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        int larr[N];
        int rarr[N];
        vector <int> res;
        larr[0]=-1;
        rarr[N-1]=-1;
        int min_idx = 0;
        int max_idx=N-1;
        for(int i=1;i<N;i++)
        {
            if (arr[i]>arr[min_idx]){
                larr[i]=min_idx;
            }
            else{
                larr[i]=-1;
                min_idx=i;
            }
        }
        
        for(int i=N-2;i>-1;i--)
        {
            if (arr[i]<arr[max_idx]){
                rarr[i]=max_idx;
            }
            else{
                rarr[i]=-1;
                max_idx=i;
            }
        }
        
        for(int i=0;i<N;i++)
        {
            if((larr[i]!=-1 && rarr[i]!=-1)&&(larr[i]<i) && (i<rarr[i]))
            {
                res.push_back(arr[larr[i]]);
                res.push_back(arr[i]);
                res.push_back(arr[rarr[i]]);
                break;
            }

        }
        
        return res;
        
        
    }
};




// { Driver Code Starts.

// Driver program to test above function
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        auto res = obj.find3Numbers(a, n);

        // wrong format output
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] and res[1] < res[2]) and
                   isSubSequence(a, res, n, res.size())) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}  // } Driver Code Ends
```