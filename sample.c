#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    int i, j;
    int **matrix;
    FILE *file;

    file = fopen("file.txt", "r");

    fscanf(file, "%d %d", &n, &k);

    // Allocate memory for the 2D array
    matrix = (int**) malloc(n * sizeof(int*));

    for (i = 0; i < n; i++) 
    {
        matrix[i] = (int*) malloc(n * sizeof(int));
    }

    // Read in the remaining values
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }

    printf("n = %d %d\n", n, k);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}