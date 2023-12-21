#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

int solveMem(vector<int>& coins, int target, vector<int>& dp)
{
    if(target==0)
        return dp[0] = 0;
    
    if(target<0)
        return INT_MAX;
    
    if(dp[target] != -1)
        return dp[target];
    
    int mini = INT_MAX;
    for(int i=0; i<coins.size(); i++)
    {
        int ans = solveMem(coins, target-coins[i], dp);
        if(ans != INT_MAX)
            mini = min(mini, 1+ans);
    }

    return dp[target] = mini; 
}

int minCoins(vector<int>& coins, int target)
{

//Top-down approach (Recursion + Memoization)
//T.C. = O(n*t)   S.C. = O(t), where n is size of coins vector, t is target
    // vector<int> dp(target+1, -1);
    // int ans = solveMem(coins, target, dp);

    // if(ans == INT_MAX)
    //     return -1;
    // else 
    //     return ans;


//Bottom-up approach (Tabulation)
//T.C. = O(n*t)   S.C. = O(t), where n is size of coins vector, t is target
    vector<int> dp(target+1, INT_MAX);
    dp[0] = 0;

    for(int i=1; i<=target; i++)
    {
        for(int j= 0; j<coins.size(); j++)
        {
            if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i-coins[j]] );
        }
        
    }

    if(dp[target] == INT_MAX)
        return -1;
    else 
        return dp[target];
}

int main()
{
    int n;
    cout << "Input no. of values : ";
    cin >> n;
    vector<int> coins(n);
    cout << "Enter values : " << endl;
    for(int i= 0; i<coins.size(); i++)
    {
        cin >> coins[i];
    }

    int target;
    cout << "Enter target sum : ";
    cin >> target;
    
    int ans = minCoins(coins, target);

    cout << "Minimum Cost for climbing stairs = " << ans << endl << endl;

    return 0;
}
