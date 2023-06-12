/*
37. Sudoku Solver
Hard

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
*/
class Solution {
public:

    bool isSafe(int row, int col,vector<vector<char>>& board,int val){
       //Row check
       for(int i=0;i<9;i++){
           if(board[i][col]==val)
           return false;
       } 
       //Column check
       for(int i=0;i<9;i++){
           if(board[row][i]==val)
           return false;
       }
       // 3*3 grid
       for(int i=0;i<9;i++){
           if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==val)
           return false;
       }
       return true;
    }
    bool solve(vector<vector<char>>& board){
        int n = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //Check for empty cell
                if(board[i][j]=='.'){
                    //try to fill with values from 1 to 9
                    for(char val = '1';val<='9';val++){
                        //Check for safety
                        if(isSafe(i,j,board,val)){
                            //insert
                            board[i][j] = val;
                            //recursion
                            bool aageKaSolution = solve(board);
                            if(aageKaSolution==true){
                                return true;
                            }
                            else{
                                //backtrack
                                board[i][j]='.';
                            }
                        }
                    }
                    //If no value from 1 to 9 is the solution
                    return false;
                }
            }
        }
        //All cells filled
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};