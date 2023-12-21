/*Longest Increasing Subsequence*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// T.C. = O(n^2)   S.C. = O(1)
int solve(vector<vector<int>> &dp, vector<int> &nums, int index, int maxi)
{
    if (index == nums.size())
        return 0;

    if (dp[index][maxi + 1] != -1)
        return dp[index][maxi + 1];

    int incl = 0;
    if (maxi == -1 || nums[index] > nums[maxi])
    {
        incl = 1 + solve(dp, nums, index + 1, index);
    }

    int excl = solve(dp, nums, index + 1, maxi);

    return dp[index][maxi + 1] = max(incl, excl);
}

// T.C. = O(nlog n)   S.C. = O(1)
int binarySearch(vector<int> &v, int target)
{
    int start = 0;
    int end = v.size() - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (v[mid] >= target)
            end = mid;
        else
            start = mid + 1;
    }

    return end;
}

int lengthOfLIS(vector<int> &nums)
{

// Top-down approach (Recursion + Memoization)
// T.C. = O(n^2)   S.C. = O(n^2)
    //  vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1,-1));
    //  return solve(dp, nums, 0, -1);


// Bottom-up approach (Tabulation)
// T.C. = O(n^2)   S.C. = O(n^2)
//      vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1));

//     int prev = -1;
//     for(int i=nums.size()-1; i>=0; i--)
//     {
//         for(int j=i-1; j>=-1; j--)
//         {
//             dp[i][j+1] = dp[i+1][j+1];

//             if(j == -1 || nums[i] > nums[j])
//                 dp[i][j+1] = max(dp[i][j+1], 1+dp[i+1][i+1]);
//         }
//     }

//     return dp[0][0];



// Space-optimised Approach
// T.C. = O(n^2)   S.C. = O(n)
    //  vector<int> next(nums.size()+1);

    // int prev = -1;
    // for(int i=nums.size()-1; i>=0; i--)
    // {
    //     for(int j=i-1; j>=-1; j--)
    //     {

    //         if(j == -1 || nums[i] > nums[j])
    //             next[j+1] = max(next[j+1], 1+next[i+1]);
    //     }
    // }

    // return next[0];

    
    
// DP + Binary Search
// T.C. = O(nlog n)   S.C. = O(n)
    // vector<int> v;
    // v.push_back(nums[0]);

    // for (int i = 1; i < nums.size(); i++)
    // {
    //     if (nums[i] > v.back())
    //         v.push_back(nums[i]);
    //     else
    //     {
    //         int idx = binarySearch(v, nums[i]);
    //         v[idx] = nums[i];
    //     }
    // }

    // return v.size();

    // vector<vector<int>> v;
    // v.push_back({nums[0]});
    // int ans = 1;

    // for (int i = 1; i < nums.size(); i++)
    // {
    //     bool flag = true;
    //     for(int j=0; j<v.size(); j++)
    //     {
    //         if(nums[i] > v[j].back())
    //         {
    //             flag = false;
    //             v[j].push_back(nums[i]);
    //             ans = max(ans, (int)v[j].size());
    //         }
    //     }
    //     if(flag)
    //         v.push_back({nums[i]});
    // }

    // cout << endl << endl;

    // for(int i=0; i<v.size(); i++)
    // {
    //     if(v[i].size() == ans)
    //     {
    //         for(int j=0; j<v[i].size(); j++)
    //             cout << v[i][j] << " ";

    //         break;
    //     }
    // }

    // cout << endl << endl;

    // return ans;


// Also prints one of the possible subsequence
    vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1));
    vector<vector<bool>> arr(nums.size()+1, vector<bool>(nums.size()+1));

    int prev = -1;
    for(int i=nums.size()-1; i>=0; i--)
    {
        for(int j=i-1; j>=-1; j--)
        {
            dp[i][j+1] = dp[i+1][j+1];

            if(j == -1 || nums[i] > nums[j])
            {
                if(dp[i][j+1] < 1+dp[i+1][i+1])
                {
                    arr[i][j+1] = 1;
                }
                dp[i][j+1] = max(dp[i][j+1], 1+dp[i+1][i+1]);
            }
        }
    }

    for(int i=0, j=0; i<=nums.size(),j<nums.size();i++)
    {
        if(arr[i][j] == 1)
        {
            cout << nums[i] << " ";

            j = i+1;
        }
        
    }

    cout << endl << endl;

    return dp[0][0];

}


int main()
{
    int n;
    cout << "Input no. of elements : ";
    cin >> n;

    vector<int> nums(n);
    
    cout << "Input elements : " << endl;
    for(int i= 0; i<nums.size(); i++)
    {
        cin >> nums[i];
    }

    int maxi = lengthOfLIS(nums);
    cout << "Length of Longest Increasing Subsequence : " << maxi << endl;
    cout << endl << endl;
    

    return 0;
}

/*

Input :
8
2 3 1 10 20 1 2 30

Output : 5 

Input :
8
10 9 2 5 3 7 101 18

Output : 4

*/