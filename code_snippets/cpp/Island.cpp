// Program to count islands in boolean 2D matrix
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

bool isValid( int M[][COL], int row, int col, bool V[][COL])
{
    return( row >= 0 && row < ROW && col >= 0 && col < COL && M[row][col] && !V[row][col] );
}

void DFS( int M[][COL], int row, int col, bool V[][COL])
{
    static int adjRow[8] = { -1, 0, 1, -1,  1, -1, 0, 1};
    static int adjCol[8] = { -1, -1, -1, 0,  0, 1, 1, 1};
    V[row][col] = true;
    for( int k = 0; k < 8; k++)
    {
        if(isValid(M, row+adjRow[k], col+adjCol[k], V))
        {
            DFS( M, row+adjRow[k], col+adjCol[k], V );
        }
    }
}

int countIslands( int M[][COL] )
{
    //visited matrix
    bool V[ROW][COL];
    memset(V, 0 , sizeof(bool)*ROW*COL));
    int count = 0;
    for( int i = 0; i < ROW; ++i)
    {
        for( int j = 0; j < COL; j++)
        {
            if(M[i][j] && !V[i][j])
            {
                DFS(M, i, j, V);
                count++;
            }
        }
    }
    return count;
}

// Driver program to test above function
int main()
{
	int M[][COL]= { {1, 1, 0, 0, 0},
		            {0, 1, 0, 0, 1},
		            {1, 0, 0, 1, 1},
		            {0, 1, 0, 1, 0},
		            {1, 0, 1, 0, 1}
		          };

	printf("Number of islands is: %d\n", countIslands(M));

	return 0;
}
