#include <iostream> 
#include <vector> 

using namespace std;

bool isValid(vector<vector<int>>& sudoku, int &row, int &col, int &val)
{
    for(int i=0; i<9; i++)
    {
        //checks for duplicate in same column
        if(sudoku[i][col] == val)
            return false;
        //checks for duplicate in same row
        if(sudoku[row][i] == val)
            return false;

        //checks for duplicate in same square
        if(sudoku[3*(row/3) + i/3][3*(col/3) + i%3] == val)
            return false;
    }

    return true;
}

bool solver(vector<vector<int>>& sudoku, int row)
{
    //outer 2 loops for searching first blank space
    for(int i=row; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            //if blank space found
            if(!sudoku[i][j])
            {
                //search for possible values
                for(int k=1; k<=9; k++)
                {
                    //check if values are valid for that blank
                    if(isValid(sudoku,i,j, k))
                    {
                        sudoku[i][j] = k;
                        
                        //check if for that value, rest of the sudoku is solvable or not
                        if(solver(sudoku, i))
                            return true;  

                        //backtracking  
                        sudoku[i][j] = 0;
                    }
                }
                //if no possible value is found
                return false;
            }
        }
    }
    //sudoku solved successfully
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	solver(sudoku, 0);
}

void print(vector<vector<int>> &board)
{
    for(auto t : board)
    {
        for(auto &x : t)
            cout << x << " ";
        cout << endl;
    }

    cout << "\n\n";
}

int main()
{
    vector<vector<int>> board = {
                                {0, 0, 4, 0, 0, 7, 8, 3, 0},
                                {0, 1, 0, 9, 3, 0, 7, 0, 5},
                                {3, 5, 7, 0, 0, 4, 1, 0, 0},
                                {0, 3, 0, 0, 0, 2, 9, 8, 4},
                                {0, 0, 0, 0, 8, 1, 0, 0, 0},
                                {0, 2, 0, 0, 0, 0, 6, 0, 0},
                                {4, 7, 3, 2, 0, 8, 0, 0, 1},
                                {2, 6, 0, 1, 0, 0, 0, 7, 8},
                                {5, 0, 1, 6, 0, 0, 4, 0, 0}
                            };

    print(board);
    solveSudoku(board);
    print(board);
    return 0;
}