//Placing n queens on a n*n chess board such that no two queens attack each other.

/*
  0 1 2 3
0 0 0 0 0
1 0 0 0 0
2 0 0 1 0 
3 0 0 0 0

4*4 board

*/

/*
To solve this problem, we will keep queens one by one in each column from 0 to n-1 by checking for conditions that no queen is already present such that it is attacking new queen. For this, no queen should be present in (same row) or (same column) or (same diagonal moving towards top-left & bottom-right) or (same diagonal moving towards bottom-left & top-right). We need not check for same column because in our solution, we are keeping queens col by col, so two queen could not be placed in same column. So we will check for other 3 conditions.
*/


#include <iostream> 
#include <vector> 

using namespace std;

void solve(vector<vector<int>> &ans, vector<vector<int>> &chess, int n, vector<int> &r, vector<int> &d1, vector<int> &d2, int col)
{
    //if current column index is n, it means we have placed n queens on n columns, so push current board to ans & return 
	if(col == n)
	{
		vector<int> temp;
		for(auto &m : chess)
			for(auto &x : m)
				temp.push_back(x);
		
		ans.push_back(temp);
		return;
	}

    //For the current column, we will search for row index such that putting a queen does not violate the condition i.e two queens attacking each other. For this, at every row index from 0 to n, we will check following conditions : 1) Same row should not already contain a queen  2)Both diagnonals should not contain already present queen
	for(int j = 0; j<n; j++)
	{
        //r[j] = 0 ensures no queen present on j'th row
        //d1[j+col] = 0 ensures no queen present on diagonal moving towards bottom-left & top-left as on this diagonal, sum of each element's row index & col index is same
        //d2[j-col] = 0 ensures no queen present on diagonal moving towards top-left & bottom-right as on this diagonal, difference b/w each element's row index & col index is same. n-1 is added to ensure difference remains absolute.
		if(!r[j] && !d1[j+col] && !d2[j-col + n-1])
		{
            //updating r, d1, d2 vectors & board to mark the queen which we are currently placing in current col.
			r[j] = 1;
			d1[j+col] = 1;
			d2[j-col+n-1] = 1;
			chess[j][col] = 1;

            //solve for the next column by recursion
			solve(ans, chess, n, r, d1, d2, col+1);

            //backtracking so that other possible combinations could be solved too.
			r[j] = 0;
			d1[j+col] = 0;
			d2[j-col+n-1] = 0;
			chess[j][col] = 0;
		}
	}

}

vector<vector<int>> nQueens(int n)
{
    //ans contains each of the possible combinations 
	vector<vector<int>> ans;

    //chess represents chess board at any given instant
	vector<vector<int>> chess(n, vector<int>(n));
 
    //row contains the index of rows which already contain a queen...it is used so that queen is not added to such rows
	vector<int> row(n, 0);

    //d1 is used to check for queens on diagonal from bottom-left to top-right. It could be observed that on this diagonal, sum (row index)+(col index) is same for each element. We will use this property to store the queen's (already present on the board) location.
	vector<int> d1(2*n, 0);

    //d2 is used to check for queens on diagonal from top-left to bottom-right. It could be observed that on this diagonal, diff (row index)-(col index) is same for each element. We will use this property to store the queen's (already present on the board) location.
	vector<int> d2(2*n, 0);

    //col represent current column which we are dealing with. Intially starting from 0th column
    int col = 0;

	solve(ans, chess, n, row, d1, d2, col);

	return ans;
	
}

void print(vector<vector<int>> &board, int n)
{
    for(auto &v : board)
    {
        for(int i=0; i<n*n; i++)
        {
            cout << v[i] << " ";
            if((i+1)%n == 0)
                cout << endl;
        }
        cout << endl << endl;
    }
}

int main()
{
    int n = 4;
    vector<vector<int>> board = nQueens(n);
    print(board, n);

    return 0;
}