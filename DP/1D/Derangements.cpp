/*
A Derangement is a permutation of 'N' elements, such that no element appears in its original position. For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is not at its initial position which is 2 and similarly for other elements of the sequence.
Given a number 'N', find the total number of derangements possible of a set of 'N' elements.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;

long long solve(vector<long long> &dp, int n)
{
    if(n == 2)
        return 1;
        
    if(n == 1)
        return 0;
    
    if(dp[n] != -1)
        return dp[n];
        
    return dp[n]=(n-1)*(solve(dp,n-1) + solve(dp, n-2))%mod;
}


long long int countDerangements(int n) 
{
//Top-down approach (Recursion + Memoization)
//T.C. = O(n)   S.C. = O(n)
    //vector<long long> dp(n+1,-1);
    // return solve(dp, n);


//Bottom-up approach (Tabulation)
//T.C. = O(n)   S.C. = O(n)
    // if(n == 1)
    //     return 0;
    
    // vector<long long> dp(n+1);
    // dp[2] = 1;
    // for(int i=3; i<=n; i++)
    //     dp[i] = (i-1)*(dp[i-1]+dp[i-2])%mod;
    
    // return dp[n];

//Space-optimised Approach
//T.C. = O(n)   S.C. = O(1)
    if(n == 1)
        return 0;
    
    long long prev1 = 0;
    long long prev2 = 1;
    for(int i=3; i<=n; i++)
    {
        long long curr = ((i-1)*(prev1+prev2))%mod;
        prev1 = prev2;
        prev2 = curr;
    }
    
    return prev2;
    

}


int main()
{
    int n;
    cout << "Input n : ";
    cin >> n;

    long long derangements = countDerangements(n);

    cout << endl << "No. of derangements possible = " << derangements << endl << endl;

    return 0;
}
