#include <iostream>
#include<vector>

using namespace std;

// Place N Queens in a N size chessboard

/*
Input chessnoard size = 4

Output1:
_, _, Q, _,
Q, _, _, _,
_, _, _, Q,
_, Q, _, _,

Output2:
_, Q, _, _,
_, _, _, Q,
Q, _, _, _,
_, _, Q, _,

*/

//TC: O(N * N!)
//SC: O(N^2)

bool isSafeToPlaceQueen(int row, int column, vector<string>& board, int n)
{
    int tmpRow = row;
    int tmpColumn = column;

    //left up diagonal case
    while(tmpRow >= 0 && tmpColumn >= 0)
    {
        if(board[tmpRow][tmpColumn] == 'Q')
            return false;

        tmpRow--;
        tmpColumn--;
    }

    //left row case
    tmpRow = row;
    tmpColumn = column;
    while(tmpColumn >= 0)
    {
        if(board[tmpRow][tmpColumn] == 'Q')
            return false;

        tmpColumn--;
    }

    //left down diagonal case
    tmpRow = row;
    tmpColumn = column;
    while(tmpRow < n && tmpColumn >= 0)
    {
        if(board[tmpRow][tmpColumn] == 'Q')
            return false;

        tmpRow++;
        tmpColumn--;
    }

    return true;
}

void solve(int column, vector<vector<string>>& ans, vector<string>& board, int n)
{
    if(column == n)
    {
        ans.push_back(board);
        return;
    }

    for(int row = 0; row < n; row++)
    {
        if(isSafeToPlaceQueen(row, column, board, n))
        {
            board[row][column] = 'Q';
            solve(column+1, ans, board, n);
            board[row][column] = '_';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '_');

    for(int i = 0; i < n; i++)
        board[i] = s;

    solve(0, ans, board, n);

    return ans;
}

//Optimized solution using hashing
//TC: O(N * N!)
//SC: O(N)
void solution(int column, vector<string>& board, vector<vector<string>>& ans,
              vector<int>& leftRow, vector<int>& upDiagonal, vector<int>& downDiagonal, int n)
{
    if(column == n)
    {
        ans.push_back(board);
        return;
    }

    for(int row = 0; row < n; row++)
    {
        if((leftRow[row] == 0) &&
           (downDiagonal[row+column] == 0) &&
           (upDiagonal[n-1 + column - row] == 0))
        {
            board[row][column] = 'Q';
            leftRow[row] = 1;
            downDiagonal[row+column] = 1;
            upDiagonal[n-1 + column - row] = 1;

            solution(column+1, board, ans, leftRow,upDiagonal,downDiagonal, n);

            board[row][column] = '_';
            leftRow[row] = 0;
            downDiagonal[row+column] = 0;
            upDiagonal[n-1 + column - row] = 0;

        }
    }

}

vector<vector<string>> solveNQueensOptimized(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '_');

    for(int i = 0; i < n; i++)
        board[i] = s;

    vector<int> leftRow(n, 0);
    vector<int> upDiagonal(2*n-1, 0);
    vector<int> downDiagonal(2*n-1, 0);

    solution(0, board, ans, leftRow, upDiagonal, downDiagonal, n);

    return ans;
}

int main()
{
    int n = 4;

    vector<vector<string>> result = solveNQueensOptimized(n);

    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
        {
            string str = result[i][j];
            for(auto ch : str)
                cout<<ch<<", ";

            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
