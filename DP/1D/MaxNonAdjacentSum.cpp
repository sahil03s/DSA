/* You are given an array/list of 'N' integers. You are supposed to return the maximum sum of the subsequence
with the constraint that no two elements are adjacent in the given array/list.*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

int solve(vector<int>& nums, vector<int>& dp, int n)
{
    if(n<0)
        return 0;

    if(n==0)
        return nums[n];

    if(dp[n] != -1)
        return dp[n]; 

    int incl = solve(nums, dp, n-2) + nums[n];
    int excl = solve(nums, dp, n-1);

    dp[n] = max(incl, excl);
    return dp[n];

}

int maxNonAdjacentSum(vector<int>& nums)
{
    
//Top-down approach (Recursion + Memoization)
//T.C. = O(n)   S.C. = O(n)
    // int n = nums.size(); 
    // vector<int> dp(n,-1);

    // return solve(nums, dp, n-1);


//Bottom-up approach (Tabulation)
//T.C. = O(n)   S.C. = O(n)
    // int n = nums.size();
    // vector<int> dp(n,0);
    
    // dp[0] = nums[0];
    // dp[1] = max(nums[0], nums[1]);

    // for(int i=2; i<nums.size(); i++)
    // {
    //     dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
    // }
    
    // return dp[n-1];

//Space-optimised approach
//T.C. = O(n)   S.C. = O(1)
    int n = nums.size();
    
    int prev1 = nums[0];
    int prev2 = max(nums[0], nums[1]);

    for(int i=2; i<nums.size(); i++)
    {
        int curr = max(prev2, prev1 + nums[i] );
        prev1 = prev2;
        prev2 = curr;
    }
    
    return prev2;

}

int main()
{
    int n;
    cout << "Input no. of values : ";
    cin >> n;

    cout << "Input values : ";
    vector<int> nums(n);

    for(int i= 0; i<nums.size(); i++)
    {
        cin >> nums[i];
    }
    
    int sum = maxNonAdjacentSum(nums);
    cout << endl << "Maximum Non-Adjacent Sum = " << sum << endl << endl;

    return 0;
}

/*
9
1 2 3 1 3 5 8 1 9
Output : 24

5
1 2 3 5 4
Output : 8

4
2 1 4 9
Output : 11


*/