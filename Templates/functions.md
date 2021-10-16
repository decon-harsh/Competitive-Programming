# ARRAYS

### Prefix/Left Sum Arr

```
vector<int> lsA(length);
lsA[0]=A[0];
for(int k=1;k<A.size();k++)
{lsA[k]=lsA[k-1]+A[k];}
```

### Suffix/Right Sum Arr 

```
vector<int> rsA(length);
rsA[length-1]=A[length-1];
for(int nk=length-2;nk>=0;nk--)
{rsA[nk]=rsA[nk+1]+A[nk];}
```

### Count Less and Equal

```
pair<int,int> count_less_equal(vector<int>A,int num)
{
    int e_count=0;
    int l_count=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]<num)
        {
            l_count++;
        }
        else if(A[i]==num)
        {
            e_count++;
        }
    }
    return make_pair(l_count,e_count);
}
```

# BINARY SEARCH

### Count Ocurrence of B 

```
int OccurenceCount(const vector<int> &A, int B) {
    int n= A.size();
    int start=0;
    int end=n-1;
    int res=-1;
    while(start<=end)
    {
        int mid = (start+end)/2;
        if(A[mid]==B)
        {
            int pos=mid-1;
            res=1;
            while(A[pos]==B && pos>=0)
            {
                res++;
                pos--;
            }
            pos=mid+1;
            while(A[pos]==B && pos < n)
            {
                res++;
                pos++;
            }
            return res;
        }
        else if(A[mid]>B)
        {
            end=mid-1;
        }
        else if(A[mid] < B)
        {
            start=mid+1;
        }
    }
    if(res==-1) return 0;
}
```

### Lower Binary Search (Return number of elements less than num)

```
int lower_bs(int low,int high,vector<int>A, int num)
{
    if(A[0]>=num)   return -1;
    else if(A[A.size()-1]<num)   return A.size();
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(A[mid]>=num)
        {
            if(A[mid-1]<num)    return mid;
            high = mid-1;
        }
        else if(A[mid]<num)
        {
            if(A[mid+1]>num)    return mid+1;
            low = mid+1;
        }
    }
    return -1;
}
```

### Num Lower Binary Search (Return the number just less than num)

```
int num_lower_bs(int low,int high,vector<int>A, int num)
{
    if(A[0]>=num)   return INT_MIN;
    else if(A[A.size()-1]<num)   return A[A.size()-1];
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(A[mid]>=num)
        {
            if(A[mid-1]<num)    return A[mid-1];
            high = mid-1;
        }
        else if(A[mid]<num)
        {
            if(A[mid+1]>num)    return A[mid];
            low = mid+1;
        }
    }
    return INT_MIN;
}
```

### Upper Binary Search (Returns number of elements greater than num)

```
int upper_bs(int low,int high,vector<int>A,int num)
{
    if(A[0]>num)    return A.size();
    else if(A[high]<=num)
    {
        return -1;
    }
    
    while(low<=high)
    {
        int mid = (low+high)/2;
        
        if(A[mid]<=num)
        {
            low=mid+1;
            if(A[low]>num)  return A.size()-low;
        }
        else if(A[mid]>num) high = mid-1;
    }
    return -1;
}
```

### Num Upper Binary Search (Return the number just greater than num)

```
int num_upper_bs(int low,int high,vector<int>A,int num)
{
    if(A[0]>num)    return A[0];
    else if(A[high]<=num)
    {
        return INT_MAX;
    }
    
    while(low<=high)
    {
        int mid = (low+high)/2;
        
        if(A[mid]<=num)
        {
            low=mid+1;
            if(A[low]>num)  return A[low];
        }
        else if(A[mid]>num) high = mid-1;
    }
    return INT_MAX;
}
```

### Equal or Upper Binary Search

```
while(low<=high)
{
    int mid = (low+high)/2;
    if(A[mid]==B)   return mid;
    else if(A[mid]>B)
    {
        high=mid-1;
        if(A[high]==B)   return high;
        else if(A[high]<B)   return high+1;
    }
    else if(A[mid]<B)
    {
        low=mid+1;
        if(A[low]>=B)   return low;
    }
}
```

# BIT MANIPULATION

### Reverse a binary number

```
unsigned int reverse(unsigned int A) {
    unsigned int num=0; 
    for(int i=0;i<32;i++)
    {
        num=(num<<1)|(A&1);        
        A=A>>1;
    }
    return num;
}
```

# LINKED LISTS

### Find Length of a Linked List

```
int findLength(ListNode *temp){
     int l=0;
     while(temp!=NULL){
         l++;
         temp=temp->next;
     }
     return l;
}
```


### Merge two sorted linked list 

```
ListNode* merge_ll(ListNode *A,ListNode* B)
{
    
    ListNode *trav1=A,*trav2=B;
    ListNode dummy(-1);
    ListNode *temp=&dummy;
    
    while(trav1 && trav2)
    {
        
        if(trav1->val<trav2->val)
        {
            temp->next=trav1;
            trav1=trav1->next;
        }
        else
        {
            temp->next=trav2;
            trav2=trav2->next;
        }
        
        temp=temp->next;
    }
    while(trav1)
    {
        temp->next=trav1;
        trav1=trav1->next;
        temp=temp->next;
    }
    
    while(trav2)
    {
        temp->next=trav2;
        trav2=trav2->next;
        temp=temp->next;
    }
    temp->next=NULL;
    return dummy.next;
}
```

### Merge Sort in Linked List

```
void mergesort(ListNode*& A)
{
    if(A==NULL || A->next==NULL)    return;
    
    ListNode *prev=NULL,*mid=A,*fast=mid;
    while(fast&&fast->next)
    {
        prev=mid;
        mid=mid->next;
        fast=fast->next->next;
    }
    if(prev)    prev->next=NULL;
    mergesort(A);
    mergesort(mid);
    A = merge_ll(A,mid);
}
```

# TREES

# Binary Tree Preorder Traversal

```
    vector<int>ans;
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)   return{};
        ans.push_back(root->val);
        
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ans;
    }
```

# Binary Tree Inorder Traversal

```
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root){
        if(!root)   return {};
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
        return ans;
    }
```

# Binary Tree Postorder Traversal
```
    vector<int>ans;
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)   return {};
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);
        return ans;
    }
```

### Binary Tree Level Order Traversal

```
vector<vector<int>> levelOrder(TreeNode* root)
{
        if(root==NULL)  return{};
        vector<vector<int>> v;
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode *tempNode=root;
        while(!q.empty())
        {
            int n = q.size();
            vector<int> ans(n);
            for(int i=0;i<n;i++)
            {
                ans[i]= q.front()->val;
                // cout<<ans[i]<<endl;
                if(tempNode->left)  q.push(tempNode->left);
                if(tempNode->right)  q.push(tempNode->right);
                q.pop();
                tempNode=q.front();
            }
            v.push_back(ans);

        }
        return v;
}
```

# Max Depth of Binary Tree using top-down approach

```
int answer; // don't forget to initialize answer before call maximum_depth
void maximum_depth(TreeNode* root, int depth) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        answer = max(answer, depth);
    }
    maximum_depth(root->left, depth + 1);
    maximum_depth(root->right, depth + 1);
}
```

# Max Depth of Binary Tree using bottom-up approach

```
int maximum_depth(TreeNode* root) {
    if (!root) {
        return 0;                                 // return 0 for null node
    }
    int left_depth = maximum_depth(root->left);
    int right_depth = maximum_depth(root->right);
    return max(left_depth, right_depth) + 1;      // return depth of the subtree rooted at root
}
```

```
When you meet a tree problem, ask yourself two questions: Can you determine some parameters to help the node know its answer? Can you use these parameters and the value of the node itself to determine what should be the parameters passed to its children? If the answers are both yes, try to solve this problem using a "top-down" recursive solution.

Or, you can think of the problem in this way: for a node in a tree, if you know the answer of its children, can you calculate the answer of that node? If the answer is yes, solving the problem recursively using a bottom up approach might be a good idea.
```

# Is symmetric Binary Tree(Iterative)
```
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)  return true;
        TreeNode *tempNode = root;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty() && !q2.empty())
        {
            TreeNode *node1=q1.front();
            TreeNode *node2=q2.front();
            if(!node1 && !node2)
            {
                q1.pop();
                q2.pop();
                continue;
            }
            if((!node1 || !node2) || (node1->val != node2->val))    return false;
            q1.push(node1->left);
            q1.push(node1->right);
            q2.push(node2->right);
            q2.push(node2->left);
            q1.pop();
            q2.pop();
        }
        return true;
    }
```

# Is symmetric Binary Tree(Recursive)
```
  bool isSymmetricHelper(TreeNode* n1, TreeNode* n2) {
	  if (!n1 && !n2) return true;
	  if (!n1 || !n2) return false;
	  if (n1->val != n2->val) return false;
	  return isSymmetricHelper(n1->left, n2->right) && isSymmetricHelper(n1->right, n2->left);
  }

  bool isSymmetric(TreeNode* root) {
	  return isSymmetricHelper(root->left, root->right);
  }
```

# Heapify (Iterative)
```
  void minHeapify(int i)
  {
    while(true)
    {
      int lt=left(i);
      int rt=right(i);
      int smallest=i;
      if(lt<size && arr[lt]<arr[i])
      smallest=lt;
      if(rt<size && arr[rt]<arr[smallest])
      smallest=rt;
      if(smallest==i)
      break;
      else
      {
        swap(arr[i],arr[smallest]);
        i=smallest;
      }
    }
  }
```

# Heapify (Recursive)
```
void heapify(int arr[], int n, int i)
{
    int smallest = i;  
    int l = 2*i + 1; 
    int r = 2*i + 2;  
    if (l < n && arr[l] < arr[smallest])
        smallest = l;
    if (r < n && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}
```

# Longest common subsequence (Dynamic programming)
```
int lcs(int x, int y, string s1, string s2)
    {
        int t[x+1][y+1];
        for(int i=0; i<x+1; i++)
        {
          for(int j=0; j<y+1; j++)
          {
              if(i==0 || j==0)
                t[i][j]=0;
          
                else if(s1[i-1] == s2[j-1])
                t[i][j] = 1 + t[i-1][j-1];
                
                else 
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
            }
        }
        return t[x][y];
    }
 ```
# 0-1 Knapsack (Dynamic programming)
```
 int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int t[n+1][W+1];
       for(int i=0; i<(n+1); i++){
           for(int j=0; j<(W+1); j++){
               if(i==0 || j==0){
                   t[i][j]=0;
               }
           }
       }
       for(int i =1; i<(n+1); i++){
           for(int j=1; j<(W+1); j++){
               if(wt[i-1] <=j){
                   t[i][j]= max(val[i-1]+t[i-1][j-wt[i-1]] , t[i-1][j]);
               }
               else{
                   t[i][j] = t[i-1][j];
               }
           }
       }
       return t[n][W];
    }
    ```
    
