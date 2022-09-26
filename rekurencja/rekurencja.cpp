#include <iostream>
#include<cstdlib>
#include <cmath>

bool wygranko(int q[], int col) {
    for (int i = 0; i < col; i++) {
        if ((q[i] == q[col]) || (abs(q[col] - q[i]) == (col - i))) {
            return false;
        }
    }
    return true;
}

void outOfChessBoard(int& col) {
    col--;
    if (col == -1) exit(1);
}

void printBoard(int q[]) {
    int board[4][4] = { 0 };

    for (int i = 0; i < 4; i++)
    {
        board[q[i]][i] = 1;
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            std::cout << board[i][j] << " ";
        std::cout << std::endl;
    }
}

int main()
{
    int hetman[4];
    hetman[0] = 0;
    int column = 1;

    bool outOfRange = false;

    while (column < 4) {
        if (!outOfRange)
            hetman[column] = -1;
        outOfRange = false;
        while (hetman[column] < 4) {
            hetman[column]++;

            while (hetman[column] == 4) {
                outOfChessBoard(column);
                hetman[column]++;
            }
            if (wygranko(hetman, column))
                break;

        }
        column++;
    }
    printBoard(hetman);
    outOfChessBoard(column);
    outOfRange = true;
}