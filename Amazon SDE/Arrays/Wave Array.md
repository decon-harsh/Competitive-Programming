# (Question Link)[https://practice.geeksforgeeks.org/problems/wave-array-1587115621/1/?track=amazon-arrays&batchId=192#]

# Given a sorted array arr[] of distinct integers. Sort the array into a wave-like array and return it. In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5..... (considering the increasing lexicographical order).

# Example 1:

# Input:
# n = 5
# arr[] = {1,2,3,4,5}
# Output: 2 1 4 3 5
# Explanation: Array elements after 
# sorting it in wave form are 
# 2 1 4 3 5.
 

# Example 2:

# Input:
# n = 6
# arr[] = {2,4,7,8,9,10}
# Output: 4 2 8 7 10 9
# Explanation: Array elements after 
# sorting it in wave form are 
# 4 2 8 7 10 9.
# Your Task:
# The task is to complete the function convertToWave() which converts the given array to wave array.

# Expected Time Complexity: O(n).
# Expected Auxiliary Space: O(1).

# Constraints:
# 1 ≤ n ≤ 106
# 0 ≤ A[i] ≤107


```
class Solution:
    #Complete this function
    #Function to sort the array into a wave-like array.
    def convertToWave(self,arr,N):
        if N%2==0:
            for i in range(0,N,2):
                arr[i],arr[i+1]=arr[i+1],arr[i]    
        else:
            for i in range(0,N-1,2):
                arr[i],arr[i+1]=arr[i+1],arr[i]
        
        return arr        
            
        #Your code here

#{ 
#  Driver Code Starts
#Initial Template for Python 3

import math

def main():
    
    T=int(input())
    
    while(T>0):
        
        
        N=int(input())
        
        A=[int(x) for x in input().split()]
        ob=Solution()
        ob.convertToWave(A,N)
        for i in A:
            print(i,end=" ")
        
        
        print()
        
       
        T-=1

if __name__=="__main__":
    main()
# } Driver Code Ends
```