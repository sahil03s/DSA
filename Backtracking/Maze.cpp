//In this question, a maze is given in form of N X N matrix where 1 indicates a position which could be visited and 0 indicates blocked positions. A rat is at (0,0) and it has to reach (n-1, n-1), we have to return all the possible paths in alphabetical order.

#include <iostream>
#include <vector>

using namespace std;

void solve(vector<vector<int>> &arr, vector<vector<bool>> &visited, int n, int i, int j, vector<string> &ans, string &temp)
    {
        //if current position is (n-1, n-1), push temp to ans and return.
        if(i== n-1 && j == n-1)
        {
            ans.push_back(temp);
            return;
        }

        //checking for downward movement i.e. if cell down to current cell is not visited and is 1, then we will move to it
        if(i+1 < n && !visited[i+1][j] && arr[i+1][j])
        {
            //updating the visited vector and temp path accordingly
            visited[i+1][j] = 1;
            temp.push_back('D');

            solve(arr, visited, n, i+1, j, ans, temp);
            
            //backtracking
            temp.pop_back();
            visited[i+1][j] = 0;
        }

        //checking for left movement i.e. if cell left to current cell is not visited and is 1, then we will move to it
        if(j-1>=0 && !visited[i][j-1] && arr[i][j-1] )
        {
            //updating the visited vector and temp path accordingly
            visited[i][j-1] = 1;
            temp.push_back('L');

            solve(arr, visited, n, i, j-1, ans, temp);
            
            //backtracking
            temp.pop_back();
            visited[i][j-1] = 0;
        }

        //checking for right movement i.e. if cell right to current cell is not visited and is 1, then we will move to it
        if(j+1 < n && !visited[i][j+1] && arr[i][j+1])
        {
            //updating the visited vector and temp path accordingly
            visited[i][j+1] = 1;
            temp.push_back('R');

            solve(arr, visited, n, i, j+1, ans, temp);
            
            //backtracking
            temp.pop_back();
            visited[i][j+1] = 0;
        }

        //checking for upward movement i.e. if cell which is above the current cell is not visited and is 1, then we will move to it
        if(i-1 >= 0 && !visited[i-1][j] && arr[i-1][j])
        {
            //updating the visited vector and temp path accordingly
            visited[i-1][j] = 1;
            temp.push_back('U');

            solve(arr, visited, n, i-1, j, ans, temp);
            
            //backtracking
            temp.pop_back();
            visited[i-1][j] = 0;
        }
    }

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
    //ans keeps all possible answers
    vector<string> ans;
    
    //if (0,0) element is 0, rat can't move, so return.
    if(arr[0][0] == 0)
        return {};

    //temp keeps path taken to reach current position
    string temp = "";

    //visited keeps track of positions already visited in current path
    vector<vector<bool>> visited(n, vector<bool>(n));
    
    //(0,0) index is already visited for each path
    visited[0][0] = 1;
    
    //row and col index of current position
    int row = 0,col = 0;

    solve(arr,visited, n, row, col, ans, temp);

    return ans;
}

void print(vector<vector<int>> &v)
{
    for(auto &arr : v)
    {
        for(auto &x : arr)
            cout << x << " ";

        cout << endl;
    }
    
    cout << endl << endl;
}

void print(vector<string> &v)
{
    for(auto &str : v)
        cout << str << " ";
    
    cout << endl << endl;
}

int main()
{
    vector<vector<int>> maze = {
                                {1,0,0,0},
                                {1,1,0,1},
                                {1,1,0,0},
                                {0,1,1,1}
                                };
    int n = maze.size();
    cout << "\n\n";
    print(maze);

    vector<string> v = searchMaze(maze, n);
    print(v);


    return 0;
}