#include <iostream>
#define N 4

using namespace std;

bool isSafe(int board[N][N], int row, int col)
{
    //check if queen can be placed on the same col
    for (int i = row; i>=0; --i)
        if (board[i][col])
            return false;
    //check if queen is laready present on top left diagonal
    for (int i = row, j = col; i>=0 && j>=0; --i, --j)
        if (board[i][col])
            return false;
    //check if queen is already present on top right diagonal
    for (int i=row, j=col; i>=0 && j<N; --i, ++j)
        if (board[i][j])
            return false;
    return true;
}

bool solveNQP(int board[N][N], int row)
{
    //Already placed all the queens
    if (row >= N)
        return true;
    
    //iterate over all the col
    for (int col = 0; col<N; ++col)
    {
        //check if queen can be placed (row, col)
        if isSafe(board, row, col)
        {
            board[row][col] = 1;
            
            //check if placing queen at (row, col) makes up for solution
            if ( solveNQP(board, row + 1)
                return true;
            
            //placing queen at(row, col) does not yield solution
            board[row][col] = 0;
        }
    }
    return false;
}

void printSolution(int board[N][N])
{
    cout<<"Co-ordinates of queen on board" <<endl)
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
        {
            if (board[i][j])
                cout<<"("<<i<<","<<j<<") ";
        }
    }
}            

int main()
{
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 }
                      };
    if (solveNQP(board, 0) == true)
        printSolution(board);
    else
        cout<<"No solution exists" <<endl;
    return 0;
}