/*
Given a binary matrix mat of size n * m, find out the maximum size square sub-matrix with all 1s.
Input: n = 2, m = 2
mat = {{1, 1}, 
       {1, 1}}
Output: 2
Explaination: The maximum size of the square sub-matrix is 2. The matrix itself is the maximum sized sub-matrix in this case.
*/

#include <iostream>
#include <vector>

using namespace std;
    
int solve(vector<vector<int>>& mat, int r, int c, vector<vector<int>>& dp, int &maxi)
{
    if(r >= mat.size() || c >= mat[0].size())
        return 0;
        
    if(dp[r][c] != -1)
        return dp[r][c];
        
    int right = solve(mat, r, c+1, dp, maxi);
    int dia = solve(mat, r+1, c+1, dp, maxi);
    int down = solve(mat, r+1, c, dp, maxi);
        
    if(mat[r][c])
    {
        dp[r][c] = 1+min(right, min(dia, down));
        maxi = max(maxi, dp[r][c]);
        return  dp[r][c] ;
    }
    else
        return  dp[r][c] = 0;
        
}

void print(vector<vector<int>>& arr)
{
    cout << endl;
    for(int i=0; i<arr.size(); i++)
    {
        for(int j=0; j<arr[0].size(); j++)
            cout << arr[i][j] << " "; 
        cout << endl;
    }

    cout << endl << endl;
}


int maxSquare(vector<vector<int>>& mat, int n, int m)
{

//Top-down approach (Recursion + Memoization)
//T.C. = O(n*m)   S.C. = O(n*m)
    // vector<vector<int>> dp(n, vector<int>(m,-1));  
    // int maxi = 0;
    // solve(mat, 0, 0, dp, maxi);   
        
    // return maxi;
        
        
//Bottom-up approach (Tabulation)
//T.C. = O(n*m)   S.C. = O(n*m)
    // vector<vector<int>> dp(n+1, vector<int>(m+1));
    // int maxi = 0;
        
    // for(int i=n-1; i>=0; i--)
    // {
    //     for(int j=m-1; j>=0; j--)
    //     {
    //         if(mat[i][j])
    //         {
    //             dp[i][j] = 1+min(dp[i+1][j], min(dp[i+1][j+1], dp[i][j+1]));
    //             maxi = max(maxi, dp[i][j]);
    //         }
    //     }
    // }
        
    // return maxi;
        
//Space-optimised Approach
//T.C. = O(n*m)   S.C. = O(m)     
    // vector<int>curr(m+1);
    // vector<int>next(m+1);
    // int maxi = 0;
        
    // for(int i=n-1; i>=0; i--)
    // {
    //     for(int j=m-1; j>=0; j--)
    //     {
    //         if(mat[i][j])
    //         {
    //             curr[j] = 1+min(min(next[j], next[j+1]), curr[j+1]);
    //             maxi = max(maxi, curr[j]);
    //         }
    //         else
    //             curr[j] = 0;
    //     }
    //     next = curr;
    // }
        
    // return maxi;
        
//Space-optimised Approach
//T.C. = O(n*m)   S.C. = O(n)      
    // vector<int>curr(n+1);
    // vector<int>next(n+1);
    // int maxi = 0;
        
    // for(int j=m-1; j>=0; j--)
    // {
    //     for(int i=n-1; i>=0; i--)
    //     {
    //         if(mat[i][j])
    //         {
    //             curr[i] = 1+min(min(next[i], next[i+1]), curr[i+1]);
    //             maxi = max(maxi, curr[i]);
    //         }
    //         else
    //             curr[i] = 0;
    //     }
    //     next = curr;
    // }
        
    // return maxi;
        
//Space-optimised Approach
//T.C. = O(n*m)   S.C. = O(1)     
    int maxi = 0;
        
    for(int i=n-1; i>=0; i--)
    {
        for(int j=m-1; j>=0; j--)
        {
            if(mat[i][j])
            {
                int down = i+1<n ? mat[i+1][j] : 0;
                int dia = (i+1<n && j+1<m) ? mat[i+1][j+1] : 0;
                int right = j+1<m ? mat[i][j+1] : 0;

                mat[i][j] = 1+min(down, min(dia, right));
                maxi = max(maxi, mat[i][j]);
            }
        }
    }
        
    return maxi;
}

int main()
{
    int n,m;
    cout << "Input no. of rows : ";
    cin >> n;
    cout << "Input no. of columns : ";
    cin >> m;

    vector<vector<int>> mat(n, vector<int>(n));
    cout << "Input values : " << endl;
    for(int i= 0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> mat[i][j];
        }
        
    }

    int maxi = maxSquare(mat, n, m);
    cout << "Maximum size of sub-square possible = " << maxi << endl;
    print(mat);
    

    return 0;
}
 

/*
Input :
3
3
0 1 0 1 0 1 0 1 1 
Output : 1

Input :
2
2
1 1 1 1
Output : 2

Input :
2
2
0 0 0 0
Output : 0
*/