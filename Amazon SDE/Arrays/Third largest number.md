# (Question Link)[https://practice.geeksforgeeks.org/problems/third-largest-element/1/?track=amazon-arrays&batchId=192]

# Given an array of distinct elements. Find the third largest element in it. 

# Example 1:

# Input:
# N = 5
# A[] = {2,4,1,3,5}
# Output: 3
# Example 2:

# Input:
# N = 2
# A[] = {10,2}
# Output: -1
# Your Task:
# Complete the function thirdLargest() which takes the array a[] and the size of the array, n, as input parameters and returns the third largest element in the array. It return -1 if there are less than 3 elements in the given array.

# Expected Time Complexity: O(N)
# Expected Auxiliary Space: O(1)

# Constraints:
# 1 ≤ N ≤ 105
# 1 ≤ A[i] ≤ 105



# Python Solution

```
import sys

class Solution:
    def thirdLargest(self,arr, n):
        first = arr[0]
        second = -sys.maxsize 
        third  = -sys.maxsize
        
        if n<3:
            return -1
        
        for i in range(1,n):
            if arr[i] > first:
                third = second
                second = first
                first = arr[i]
            elif arr[i] > second:
                third = second
                second = arr[i]
            elif arr[i] > third:
                third = arr[i]
        
        return third
#{ 
#  Driver Code Starts
# Your code goes here
if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        print(Solution().thirdLargest(arr, n))
# } Driver Code Ends
```

# (GFG Solution)[https://www.geeksforgeeks.org/third-largest-element-array-distinct-elements/]