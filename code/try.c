#include <stdio.h>
#include <stdlib.h>

void luDecomposition(int** mat, int n) {
    int** lower = (int**)malloc(n * sizeof(int*));
    int** upper = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++) {
        lower[i] = (int*)malloc(n * sizeof(int));
        upper[i] = (int*)malloc(n * sizeof(int));
    }

     int i = 0, j = 0, k = 0;
    double det = 1.0;

    // Decomposing matrix into Upper and Lower triangular matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j < i)
                lower[j][i] = 0;
            else {
                lower[j][i] = mat[j][i];
                for (k = 0; k < i; k++) {
                    lower[j][i] = lower[j][i] - lower[j][k] * upper[k][i];
                }
            }
        }

        for (j = 0; j < n; j++) {
            if (j < i)
                upper[i][j] = 0;
            else if (j == i)
                upper[i][j] = 1;
            else {
                upper[i][j] = mat[i][j] / lower[i][i];
                for (k = 0; k < i; k++) {
                    upper[i][j] = upper[i][j] - ((lower[i][k] * upper[k][j]) / lower[i][i]);
                }
            }
        }
    }

    // Calculating determinant as product of diagonals of upper triangular matrix
    for (i = 0; i < n; i++) {
        det *= lower[i][i];
    }

    printf("Determinant of the matrix is : %lf", abs(det));

    for(int i = 0; i < n; i++) {
        free(lower[i]);
        free(upper[i]);
    }
    free(lower);
    free(upper);



    for(int i = 0; i < n; i++) {
        free(lower[i]);
        free(upper[i]);
    }
    free(lower);
    free(upper);
}

int main() {
    int n;
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    int** mat = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++) {
        mat[i] = (int*)malloc(n * sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    luDecomposition(mat, n);

    for(int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
