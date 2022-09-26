#include <iostream>
#include<cstdlib>
#include <cmath>


bool isOk(int queen[], int col) {
    for (int i = 0; i < col; i++) {
        if ((queen[i] == queen[col]) || (abs(queen[col] - queen[i]) == (col - i))) {
            return false;
        }
    }
    return true;
}

void backTrack(int& col) {
    col--;
    if (col == -1) exit(1);
}

void printBoard(int queen[]) {
    int board[4][4] = { 0 };

    for (int i = 0; i < 4; i++) {
        board[queen[i]][i] = 1;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int hetman[4]{}, column = 1;

    bool fromBackTrack = false;

    while (column < 4) {
        if (!fromBackTrack) {
            hetman[column] = -1;
        }

        fromBackTrack = false;

        while (hetman[column] < 4) {
            hetman[column]++;

            while (hetman[column] == 4) {
                backTrack(column);
                hetman[column]++;
            }

            if (isOk(hetman, column))
                break;
        }
        column++;
    }
    printBoard(hetman);

    return 0;
}