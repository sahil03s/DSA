#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int>& cost, int n, vector<int>& dp)
{
    if(n<=1)
        return dp[n] = cost[n];
    
    if(dp[n] != -1)
        return dp[n];
    
    dp[n] = cost[n] + min(solve(cost, n-2, dp), solve(cost, n-1, dp));
    return dp[n];
}

int minCostClimbingStairs(vector<int>& cost)
{

//Top-down approach (Recursion + Memoization)
//T.C. = O(n)   S.C. = O(n)
    // int n = cost.size();
    // vector<int> dp(n,-1);
    // solve(cost, n-1, dp);

    // return min(dp[n-2], dp[n-1]);


//Bottom-up approach (Tabulation)
//T.C. = O(n)   S.C. = O(n)
    // int n = cost.size(); 
    // vector<int> dp(n,-1);
    // dp[0] = cost[0];
    // dp[1] = cost[1];

    // for(int i= 2; i<cost.size(); i++)
    // {
    //     dp[i] = cost[i] + min(dp[i-2], dp[i-1]);
    // }

    // return min(dp[n-2], dp[n-1]);
    
//Space-optimised Approach
//T.C. = O(n)   S.C. = O(1)
    int prev1 = cost[0];
    int prev2 = cost[1];

    for(int i= 2; i<cost.size(); i++)
    {
        int curr = cost[i] + min(prev1, prev2);
        prev1 = prev2;
        prev2 = curr;
    }

    return min(prev1, prev2);
    

}

int main()
{
    int n;
    cout << "Input no. of values : ";
    cin >> n;
    vector<int> cost(n);
    cout << "Enter values : " << endl;
    for(int i= 0; i<cost.size(); i++)
    {
        cin >> cost[i];
    }
    
    int ans = minCostClimbingStairs(cost);

    cout << "Minimum Cost for climbing stairs = " << ans << endl << endl;

    return 0;
}

/*

Input : 
10
1 100 1 1 1 100 1 1 100 1

Output :
6

Input : 
3
10 15 20

Output :
15

*/