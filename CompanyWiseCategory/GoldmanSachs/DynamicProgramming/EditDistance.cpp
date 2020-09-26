/*
   Method:1 Recursion + BruteForce
   Time Complexity  : O(3^n)
   Space Complexity : O(3^n)
*/

/*
  Recursive function to find minimum edit distance
*/

int minEditDistance(string s1 , int ptr1 , string s2 , int ptr2)
{
    /*
       Base case
    */
    if (ptr1 == 0)
    return ptr2;

    if (ptr2 == 0)
    return ptr1;

    int cost;

    /*
      If current characters of both the strings are same
    */ 
    if (s1[ptr1 - 1] == s2[ptr2 - 1])
    {
        cost = 0;
    }
    else
    {   
        int deletionCost     =   1+minEditDistance(s1, ptr1 - 1, s2 , ptr2);
        int insertionCost    =   1+minEditDistance(s1, ptr1, s2 , ptr2 - 1);
        int substitutionCost =   1+minEditDistance(s1, ptr1 - 1, s2, ptr2 - 1);
        
        cost=min(deletionCost , min(insertionCost , substitutionCost));
    }
    return cost;
}


////////////////////////////////////////////////////////////////////////////



/*
   Method:2 Recursion + Memoization (Top-Down DP)
   Time Complexity  : O(n^2)
   Space Complexity : O(n^2)
*/
ll dp[1005][1005];
/*
  Recursive function to find minimum edit distance with memoization
*/
int minEditDistance(string s1 , int ptr1 , string s2 , int ptr2)
{
    /*
       Base case
    */
    if (ptr1 == 0 )
    return ptr2;

    if (ptr2 == 0)
    return ptr1;
    
    if(dp[ptr1][ptr2]!=-1)
        return dp[ptr1][ptr2];

    int cost;

    /*
      If current characters of both the strings are same
    */ 
    if (s1[ptr1 - 1] == s2[ptr2 - 1])
    {
        cost = 0;
    }
    else
    {   
        int deletionCost     =   1+minEditDistance(s1, ptr1 - 1, s2 , ptr2);
        int insertionCost    =   1+minEditDistance(s1, ptr1, s2 , ptr2 - 1);
        int substitutionCost =   1+minEditDistance(s1, ptr1 - 1, s2, ptr2 - 1);
        
        cost=min(deletionCost , min(insertionCost , substitutionCost));
    }

    dp[ptr1][ptr2]=cost;

    return cost;
}


////////////////////////////////////////////////////////////////////////////



/*
   Method 3 : Bottom-Up DP
   Time Complexity  : O(n^2)
   Space Complexity : O(n^2)
*/

/*
   Iterative function to find length of longest increasing subsequeces
*/
int minEditDistance(string s1 , int m , string s2 , int n)
{
    /* 
      For all i and j, dp[i,j] will hold the Levenshtein distance between
      the first i characters of X and the first j characters of Y
      note that dp has (m+1)*(n+1) values
    */
    int dp[m + 1][n + 1] = { 0 };

    /* 
      Source prefixes can be transformed into empty string by
      dropping all characters
    */
    for (int i = 1; i <= m; i++)
        dp[i][0] = i;            

    /* 
      Target prefixes can be reached from empty source prefix
      by inserting every character
    */
    for (int j = 1; j <= n; j++)
        dp[0][j] = j;               

    int cost;

    // Fill the lookup table in bottom-up manner
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])                
            {
                dp[i][j] = T[i - 1][j - 1];
            }           
            else
            {
               int deletionCost     =   1+T[i - 1][j];
               int insertionCost    =   1+T[i][j - 1];
               int substitutionCost =   1+T[i - 1][j - 1];
        
              T[i][j]=min(deletionCost , min(insertionCost , substitutionCost));           
            }
        }
    }

    return T[m][n];
}


////////////////////////////////////////////////////////////////////////////
