#include <stdio.h>

void print_matrix(int n, int arr[n][n+1]) {
    for (int i = 0; i < n; i++) {             // Loop over rows
        for (int j = 0; j < n+1; j++) {       // Loop over columns
            printf("%d ", arr[i][j]);         // Print the element
        }
        printf("\n");                         // Move to the next line after each row
    }
}

int main() {
    int n = 3;
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    print_matrix(n, arr);                     // Call the function to print the matrix
    
    return 0;
}
