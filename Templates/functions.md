# Arrays

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

# Binary Search

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
            while(A[pos]==B && pos<n)
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
        else if(A[mid]<B)
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