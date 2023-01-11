#include <bits/stdc++.h>
using namespace std;

int grid[9][9];

void printSolvedGrid(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout<<grid[i][j]<<" ";
        }

        cout<<endl;
    }

    return;
}

bool isValid(int row, int col, int value)
{
    for (int i = 0; i < 9; i++)
    {
        if (grid[row][i] == value)
        {
            return false;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (grid[i][col] == value)
        {
            return false;
        }
    }

    int row_start = row - row % 3;
    int row_end = row + (3 - row % 3);

    int col_start = col - col % 3;
    int col_end = col + (3 - col % 3);

    for (int i = row_start; i < row_end; i++)
    {
        for (int j = col_start; j < col_end; j++)
        {
            if (grid[i][j] == value)
            {
                return false;
            }
        }
    }

    return true;
}

bool findEmpty(int &row, int &col)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (grid[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool ifSolvable()
{
    int row, col;
    if (!findEmpty(row, col))
    {
        cout<<endl;
        printSolvedGrid();
        return true;
    }
    else
    {
        for (int i = 1; i < 10; i++)
        {
            if (isValid(row, col, i))
            {
                grid[row][col] = i;
                if (ifSolvable())
                {
                    return true;
                }
                grid[row][col] = 0;
            }
        }
    }

    return false;
}

int main()
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> grid[i][j];
        }
    }

    bool ans = ifSolvable();
    if (ans)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    // write your code here
    return 0;
}
