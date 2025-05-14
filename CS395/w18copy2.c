#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Function to check if a subset of vertices forms a clique
bool is_clique(int* subset, int size, int** adj_matrix) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (adj_matrix[subset[i]][subset[j]] == 0) {
                return false;
            }
        }
    }
    return true;
}

// Function to find the largest clique size
int find_largest_clique(int n, int** adj_matrix) {
    int max_clique_size = 0;

    // Total subsets: 2^n
    int total_subsets = 1 << n;

    for (int subset_mask = 0; subset_mask < total_subsets; subset_mask++) {
        int subset[n];
        int subset_size = 0;

        // Extract vertices in the subset based on the mask
        for (int i = 0; i < n; i++) {
            if (subset_mask & (1 << i)) {
                subset[subset_size++] = i;
            }
        }

        // Check if this subset is a clique
        if (is_clique(subset, subset_size, adj_matrix)) {
            if (subset_size > max_clique_size) {
                max_clique_size = subset_size;
            }
        }
    }

    return max_clique_size;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s number_of_vertices upper_triangle_adjacency_matrix\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int** adj_matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adj_matrix[i] = (int*)calloc(n, sizeof(int));
    }

    // Fill the adjacency matrix from the upper triangle input
    int index = 2; // Start after the first two arguments
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                adj_matrix[i][j] = 1; // Diagonal elements are always 1
            } else {
                adj_matrix[i][j] = adj_matrix[j][i] = atoi(argv[index++]);
            }
        }
    }

    // Find the largest clique size
    int max_clique_size = find_largest_clique(n, adj_matrix);

    printf("Largest clique size: %d\n", max_clique_size);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(adj_matrix[i]);
    }
    free(adj_matrix);

    return 0;
}
