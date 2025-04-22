
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_safe(int board[], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void print_board(int board[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void solve_n_queens(int board[], int row, int n) {
    if (row == n) {
        print_board(board, n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (is_safe(board, row, col)) {
            board[row] = col;
            solve_n_queens(board, row + 1, n);
        }
    }
}

int main() {
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("N must be greater than 0.\n");
        return 1;
    }

    int *board = (int *)malloc(n * sizeof(int));
    if (board == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    solve_n_queens(board, 0, n);

    free(board);
    return 0;
}
