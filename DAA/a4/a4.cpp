/*Design n-Queens matrix having first Queen placed. Use backtracking to place
remainingQueens to generate the final n-queen*/


#include<bits/stdc++.h>
using namespace std;

void displayBoard(vector<vector<char>> &board)
{
    for(auto i : board)
        {for(auto ele : i)
          {  cout<<ele<<" ";}
        cout<<endl;}
}

bool isSafe(int r , int c , int n, vector<vector<char>>&board)
{
    for(int i =0;i<n;i++){
        if(board[r][i] =='Q' && i!=c)return false;
    }

    for(int i =0;i<n;i++){
        if(board[i][c] =='Q' && i!=r)return false;
    }
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    return true;
}

void solveNQueens(int idx , vector<vector<char>>&board , int n)
{
    if(idx == n)displayBoard(board);return;
    for(int j=0;j<n;j++)
    {
       
        if(isSafe(idx , j ,n, board))
        { board[idx][j] = 'Q';
        solveNQueens(idx + 1 , board , n);
        board[idx][j] = '.';}
        solveNQueens(idx + 1 , board , n);

    }


}


int main()
{
    int n;
    cout<<"Enter the size of chess board(n) : ";
    cin>>n;
    cout<<"Enter column where the queen is placed in the first row : ";
    int col;
    cin>>col;

    vector<vector<char>>chessBoard(n , vector<char>(n , '.'));
    chessBoard[0][col-1] = 'Q';
    displayBoard(chessBoard);


    solveNQueens(0 , chessBoard,n);

    displayBoard(chessBoard);



    
}