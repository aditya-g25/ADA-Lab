#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int N;

void printSolution(int board[][MAX]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int board[][MAX], int row, int col) {
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQ(int board[][MAX], int col) {

    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {

        if (isSafe(board, i, col)) {

            board[i][col] = 1;

            if (solveNQ(board, col + 1))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

int main() {

    printf("Enter number of queens: ");
    scanf("%d", &N);

    int board[MAX][MAX] = {0};

    if (solveNQ(board, 0))
        printSolution(board);
    else
        printf("Solution does not exist\n");

    return 0;
}