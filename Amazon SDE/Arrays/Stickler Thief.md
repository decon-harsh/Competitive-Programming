# [Question Link](https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1/?track=amazon-arrays&batchId=192#)

# Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i] amount of money present in it.

# Example 1:

# Input:
# n = 6
# a[] = {5,5,10,100,10,5}
# Output: 110
# Explanation: 5+100+5=110
# Example 2:

# Input:
# n = 3
# a[] = {1,2,3}
# Output: 4
# Explanation: 1+3=4
# Your Task:
# Complete the function FindMaxSum() which takes an array arr[] and n as input which returns the maximum money he can get following the rules
 

# Expected Time Complexity: O(N).
# Expected Space Complexity: O(N).


```
class Solution:    
    def FindMaxSum(self,a, n):
        '''
        :param a:  given list of values
        :param n: size of a
        :return: Integer
        '''
        if n==1:
            return a[0]
        elif n==2:
            return max(a[0],a[1])
        else:
            dp=[a[0],max(a[0],a[1])]
            for i in range(2,n):
                dp.append(max(dp[-1],dp[-2]+a[i]))
        
            return dp[-1]
            
        # code here

#{ 
#  Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

# Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        a = list(map(int,input().strip().split()))
        ob=Solution()
        print(ob.FindMaxSum(a,n))
# } Driver Code Ends
```