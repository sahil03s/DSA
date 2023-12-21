#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int>& weight, vector<int>& value, int capacity, int index, vector<vector<int>>& dp)
{
    if(index == 0)
    {
        if(weight[index] <= capacity)  
            return value[index];
        else
            return 0;
    }

    if(dp[index][capacity] != -1)
        return dp[index][capacity];

    int incl = 0;
    if(weight[index] <= capacity)
        incl = value[index] + solve(weight, value, capacity-weight[index], index-1, dp);
    
    int excl = solve(weight, value, capacity, index-1, dp);

    return dp[index][capacity] = max(incl, excl);

}

int knapsack(vector<int>& weight, vector<int>& value, int n, int capacity)
{
//Top-down approach (Recursion + Memoization)
//T.C. = O(n*capacity)   S.C. = O(n*capacity)
    // vector<vector<int>> dp(n, vector<int>(capacity+1,-1));
    // return solve(weight, value, capacity, n-1, dp);


//Bottom-up approach (Tabulation)
//T.C. = O(n*capacity)   S.C. = O(n*capacity)
    // vector<vector<int>> dp(n, vector<int>(capacity+1,0));
    // for(int w=weight[0]; w <= capacity; w++)
    //     dp[0][w] = value[0];
    
    // for(int index=1; index < n; index++)
    // {
    //     for(int w=0; w <= capacity; w++)
    //     {
    //         int incl = 0;
    //         if(weight[index] <= w)
    //             incl = value[index] + dp[index-1][w-weight[index]];
            
    //         int excl = dp[index-1][w];

    //         dp[index][w] = max(incl, excl);
    //     }
    // }

    // return dp[n-1][capacity];


//Space-optimised Approach
//T.C. = O(n*capacity)   S.C. = O(2*capacity)

    // vector<int> prev(capacity+1, 0);
    // vector<int> curr(capacity+1, 0);

    // for(int w=weight[0]; w<=capacity; w++)
    //     prev[w] = value[0];

    // for(int index= 1; index<n; index++)
    // {
    //     for(int w=0; w<=capacity; w++)
    //     {
    //         int incl = 0;
    //         if(weight[index] <= w)
    //             incl = value[index] + prev[w-weight[index]];
            
    //         int excl = prev[w];

    //         curr[w] = max(incl, excl);
    //     }

    //     prev = curr;
    // }
    

    // return prev[capacity];


//Space-optimised Approach
//T.C. = O(n*capacity)   S.C. = O(capacity)
    vector<int> curr(capacity+1, 0);

    for(int w=weight[0]; w<=capacity; w++)
        curr[w] = value[0];

    for(int index= 1; index<n; index++)
    {
        // for(int w=0; w<=capacity; w++)
        for(int w=capacity; w>=0; w--)
        {
            int incl = 0;
            if(weight[index] <= w)
                incl = value[index] + curr[w-weight[index]];
            
            int excl = curr[w];

            curr[w] = max(incl, excl);
        }
    }
    
    return curr[capacity];

}

int main()
{
    int n, capacity;

    cout << "Input no. of items : ";
    cin >> n;

    vector<int> weight(n); 
    vector<int> value(n); 

    cout << "Input weights : " << endl;
    for(int i= 0; i<n; i++)
    {
        cin >> weight[i];
    }

    cout << "Input values : " << endl;
    for(int i= 0; i<n; i++)
    {
        cin >> value[i];
    }
    
    cout << "Input max Capacity : ";
    cin >> capacity;

    int maxi = knapsack(weight, value, n, capacity);

    cout << "Maximum value = " << maxi << endl << endl;

    return 0;
}

/*


7
6 5 1 5 6 5 9 
5 3 4 9 6 1 1 
63
Output : 29

7
1 5 6 9 7 9 7 
1 7 1 5 1 7 7 
37
Output : 28

38
3 4 32 33 23 21 11 25 39 37 17 19 40 11 32 31 1 25 34 20 15 42 48 15 35 42 34 38 26 4 37 47 11 29 35 22 31 31 
66 73 96 51 21 76 69 93 25 34 53 39 59 92 31 61 89 65 17 34 77 89 9 29 46 43 6 41 72 53 11 49 13 95 49 23 28 51 
781
Output : 1832

27
6 19 50 11 21 15 24 31 29 23 26 11 46 44 24 24 31 47 35 36 18 13 43 33 4 43 12 
3 71 43 41 58 21 26 66 61 85 85 4 33 19 51 3 17 2 57 1 52 21 61 61 85 93 53 
463
Output : 1070


*/