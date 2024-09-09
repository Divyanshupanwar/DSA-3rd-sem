#include <stdio.h>

int findRowWithMaxOnes(int m, int n, int matrix[m][n]) {
    int maxRow = -1; // To store the row with maximum number of 1s
    int j = n - 1;   // Start from the top-right corner
    int row = 0;     // Start at the first row

    while (row < m && j >= 0) {
        if (matrix[row][j] == 1) {
            // Move left if we find a 1
            maxRow = row;
            j--;
        } else {
            // Move down if we find a 0
            row++;
        }
    }
    
    return maxRow;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    // Input the matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int result = findRowWithMaxOnes(m, n, matrix);

    if (result != -1) {
        printf("%d\n", result);
    } else {
        printf("Not Present\n");
    }

    return 0;
}
