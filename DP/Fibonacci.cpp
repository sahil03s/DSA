#include <iostream>
#include <vector>

using namespace std;

//T.C. = O(n)   S.C. = O(n)
int fibonacci(int n, vector<int> &dp)
{
//Top-down approach
    // if(n==1 || n == 2)
    //     return dp[n] = n-1;
    
    // if(dp[n] != -1)
    //     return dp[n];
    
    // dp[n] = fibonacci(n-1, dp) + fibonacci(n-2, dp);
    // return dp[n];

//Top-down approach
//T.C. = O(n)   S.C. = O(n)
    // if(n==1 || n==2)
    //     return dp[n]=n-1;
    
    // for(int i=3; i<=n; i++)
    //     dp[i] = dp[i-1]+dp[i-2];
    
    // return dp[n];

//Space-optimised Approach
//T.C. = O(n)   S.C. = O(1)
    if(n==1)
        return 0;
    
    int prev1 = 0;
    int prev2 = 1;

    for(int i=3; i<=n; i++)
    {
        int curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;

}

int main()
{
    int n;
    cout << "Enter value of n : " ;
    cin >> n;
    vector<int> dp(n+1,-1);

    cout << fibonacci(n, dp) << endl;
    // for(int i=1; i<dp.size(); i++)
    // {
    //     cout << dp[i] << " ";
    // }
    cout << endl << endl;
    return 0;

}