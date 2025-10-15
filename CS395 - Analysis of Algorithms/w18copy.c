/*********************************************
 *
 * Compile: gcc -Wall
 * Run: ./a.out n
 *
 * A program that implements an exhaustive search
 * to uncover shared vertices between graphs.
 *
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//
// Function to convert upper triangular matrix to full adjacency matrix
//
void constructAdjMatrix(int n, int *upperTriangle, int adjMatrix[n][n]) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > i) {
                adjMatrix[i][j] = upperTriangle[k++];
            } else if (j < i) {
                adjMatrix[i][j] = adjMatrix[j][i]; // Symmetric property
            } else {
                adjMatrix[i][j] = 0; // No self-loops
            }
        }
    }
}

//
// Function to check if a subset forms a clique
//
int isClique(int n, int subset, int adjMatrix[n][n]) {
    for (int i = 0; i < n; i++) {
        if (!(subset & (1 << i))) continue;
        for (int j = i + 1; j < n; j++) {
            if ((subset & (1 << j)) && adjMatrix[i][j] == 0) {
                return 0; // Not a clique
            }
        }
    }
    return 1; // Is a clique
}

//
// Function to find the size of the largest clique
//
int findLargestClique(int n, int adjMatrix[n][n]) {
    int largestClique = 0;
    int totalSubsets = (1 << n); // Total number of subsets (2^n)

    for (int subset = 1; subset < totalSubsets; subset++) {
        if (isClique(n, subset, adjMatrix)) {
            int cliqueSize = __builtin_popcount(subset); // Count bits set to 1
            if (cliqueSize > largestClique) {
                largestClique = cliqueSize;
            }
        }
    }

    return largestClique;
}

//
// Main function
//
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s number_of_vertices upper_triangle\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int upperTriangleSize = (n * (n - 1)) / 2;
    if (argc - 2 != upperTriangleSize) {
        printf("Error: Expected %d values for the upper triangle of the adjacency matrix.\n", upperTriangleSize);
        return 1;
    }

    // Parse the upper triangular matrix
    int upperTriangle[upperTriangleSize];
    for (int i = 0; i < upperTriangleSize; i++) {
        upperTriangle[i] = atoi(argv[i + 2]);
    }

    // Construct the full adjacency matrix
    int adjMatrix[n][n];
    constructAdjMatrix(n, upperTriangle, adjMatrix);

    // Find the size of the largest clique
    int largestClique = findLargestClique(n, adjMatrix);
    printf("Size of the largest clique: %d\n", largestClique);

    return 0;
}
