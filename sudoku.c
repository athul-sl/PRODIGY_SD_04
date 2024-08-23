#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

void print(int sud[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", sud[i][j]);
        }
        printf("\n");
    }
}

bool valid(int sud[SIZE][SIZE], int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        if (sud[row][x] == num) {
            return false;
        }
    }

    for (int x = 0; x < SIZE; x++) {
        if (sud[x][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (sud[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solve(int sud[SIZE][SIZE]) {
    int row, col;

    if (!empty(sud, &row, &col)) {
        return true;
    }

    for (int num = 1; num <= SIZE; num++) {
        if (valid(sud, row, col, num)) {
            sud[row][col] = num;

            if (solve(sud)) {
                return true;
            }

            sud[row][col] = 0;
        }
    }

    return false;
}

bool empty(int sud[SIZE][SIZE], int *row, int *col) {
    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (sud[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int sud[SIZE][SIZE];
    
    printf("Enter the Sudoku puzzle (0 for empty cells):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &sud[i][j]);
        }
    }

    if (solve(sud)) {
        printf("\nSolved Sudoku puzzle:\n");
        print(sud);
    } else {
        printf("\nNo solution exists.\n");
    }

    return 0;
}
