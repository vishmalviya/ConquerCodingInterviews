/*
   Method:1 Recursion + BruteForce
   Time Complexity  : O(2^n)
   Space Complexity : O(2^n)
*/

/* 
  Recursive function to find length of longest increasing subsequeces
*/
int LIS(int a[] , int index , int arraySize , int previousElement)
{
    /* 
       Base case
    */
    if (index >= arraySize)
        return 0;
    /*
       Case 1: Exclude the current element and process
       the remaining elements
    */
    int exclude = LIS(a , index + 1 , arraySize , previousElement);

    /*
       Case 2: Include the current element such that it is
       greater than the previous element in LIS and process
       the remaining elements
    */

    int include = 0;
    if ( a[index] > previousElement)
        include = 1 + LIS(a , index + 1 , arraySize , a[index]);

    /*
       Return the maximun of above two choices
    */

    int lisLength = max(include, exclude);

    return lisLength;
}


////////////////////////////////////////////////////////////////////////////



/*
   Method:2 Recursion + Memoization (Top-Down DP)
   Time Complexity  : O(n^2)
   Space Complexity : O(n^2)
*/
ll dp[1005][1005];
/* 
  Recursive function to find length of longest increasing subsequeces
  with memoization
*/
int LIS(int a[] , int index , int arraySize , int previousElementPtr)
{
    /* 
       Base case
    */
    if (index >= arraySize)
        return 0;
    /*
      Check whether the state is already computued if yes than
      directly return the result.
    */
    if (dp[index][previousElementPtr] != -1)
        return dp[index][previousElementPtr];

    /*
       Case 1: Exclude the current element and process
       the remaining elements
    */
    int exclude = LIS(a , index + 1 , arraySize , previousElementPtr);

    /*
       Case 2: Include the current element such that it is
       greater than the previous element in LIS and process
       the remaining elements
    */

    int include = 0;
    if (previousElementPtr==-1 || (previousElementPtr>=0  && a[index] > a[previousElementPtr]))
    include = 1 + LIS(a , index + 1 , arraySize , index);

    /*
       Return the maximun of above two choices
    */

    int lisLength = max(include, exclude);

    /*
      Memoise the result of current state
    */
    dp[index][previousElementPtr] = lisLength;

    return lisLength;
}


////////////////////////////////////////////////////////////////////////////



/*
   Method 3 : Bottom-Up DP
   Time Complexity  : O(n^2)
   Space Complexity : O(n)
*/

/* 
   Iterative function to find length of longest increasing subsequeces
*/
int LIS(int a[], int n)
{
    /*
      Array to store sub-problem solution. 
      L[i] stores the length of the longest increasing subsequence 
      ends with a[i]
    */
    int lisLength[n] = { 0 };

    /*
      longest increasing subsequence ending with a[0] has length 1
    */
    lisLength[0] = 1;


    /*
      Start from second element in the array
    */
    for (int i = 1; i < n; i++)
    {
        /*
          Do for each element in subarray a[0..i-1]
        */
        for (int j = 0; j < i; j++)
        {
            /* 
              Find longest increasing subsequence that ends with a[j]
              where a[j] is less than the current element a[i]
            */

            if (a[j] < a[i] && lisLength[j] > lisLength[i])
                lisLength[i] = lisLength[j];
        }

        /* 
          Include a[i] in LIS
        */
        lisLength[i]++;
    }

    /*
      Find longest increasing subsequence having maximum length
    */

    int lis = INT_MIN;
    for (int x : lisLength)
    lis = max(lis, x);
    
    /*
       Return the lis
    */
    return lis;
}


////////////////////////////////////////////////////////////////////////////



/*
   Method 4 : Binary Search - Most Optimised Method
*/

/* 
   Utility function to find index using binary search
   Time Complexity  : O(nlogn)
   Space Complexity : O(n)
*/
int findIndex(int &a[],int low,int high,int key)
{
        if(low<high)
        {
            int mid = (low+high)/2;
            if(arr[mid]>=key)
            return (FindIndex(arr,low,mid,key));
            
            return (FindIndex(arr,mid+1,high,key));
        }
        return high;
}
/* 
   Iterative function to find length of longest increasing subsequeces
*/
int LIS(int a[], int n)
{
        int LIS[n];
        int index=0;
        LIS[index++]=a[0];
        for(int i=1;i<n;i++)
        {
            if(a[i]>LIS[index-1])
                LIS[index++]=a[i];
            else
                LIS[FindIndex(LIS,0,index-1,a[i])]=a[i];
        }  
        return index;
}


////////////////////////////////////////////////////////////////////////////

