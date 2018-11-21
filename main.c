#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SAMPLE_MATRIX_SIZE 5

int **allocateMemoryForMatrix(unsigned int size) {
    int **matrix = (int **) malloc(size * sizeof(int *));

    for (int row = 0; row < size; ++row) {
        matrix[row] = (int *) malloc(size * sizeof(int));
    }

    return matrix;
}

void freeMemoryOfMatrix(int **matrix, unsigned int size) {
    for (int row = 0; row < size; ++row) {
        free(matrix[row]);
    }
    free(matrix);
}


int sumOverDiagonal(int **matrix, int matrixSize, int columnId) {
    int sum = 0;

    for (int rowId = 0; rowId < matrixSize; ++rowId) {
        if (rowId == columnId) {
            break;
        } else {
            sum += matrix[rowId][columnId];
        }
    }

    return sum;
}

int productOfSumOverDiagonal(int **matrix, int matrixSize) {
    int product = 1;

    for (int colId = 1; colId < matrixSize; ++colId) {
        product *= sumOverDiagonal(matrix, matrixSize, colId);
    }

    return product;

}

void printMatrix(int **matrix, int matrixSize) {
    printf("\n\n");

    for (int row = 0; row < matrixSize; ++row) {
        printf("\n");
        for (int col = 0; col < matrixSize; ++col) {
            printf("%d ", matrix[row][col]);
        }
    }

    printf("\n\n");
}

void bubbleSortArray(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if (arr[j] > arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sortMatrixRows(int **matrix, int matrixSize) {
    for (int row = 0; row < matrixSize; ++row) {
        bubbleSortArray(matrix[row], matrixSize);
    }
}

int main() {
    int sampleMatrix[SAMPLE_MATRIX_SIZE][SAMPLE_MATRIX_SIZE] = {
            9, 67, -65, 45, 1,
            12, 61, 48, -5, -1,
            0, 39, 0, 41, 2,
            36, 95, -8, -5, 0,
            11, 22, 71, 3, 63
    };

    unsigned int size = 5;
    int **matrix;
    char choice;
    printf("Do you want to tap matrix yourself? y/n");
    scanf("%c", &choice);
    switch (choice) {
        case 'y': {
            printf("Tap a size of cube matrix: ");
            scanf("%d", &size);
            matrix = allocateMemoryForMatrix(size);
            for (int row = 0; row < size; ++row) {
                for (int col = 0; col < size; ++col) {
                    printf("Tap element of %dth row and %dth col: ", row, col);
                    scanf("%d", &matrix[row][col]);

                }
            }
            break;
        }
        case 'n': {
            matrix = allocateMemoryForMatrix(size);
            for (int row = 0; row < SAMPLE_MATRIX_SIZE; ++row) {
                for (int col = 0; col < SAMPLE_MATRIX_SIZE; ++col) {
                    matrix[row][col] = sampleMatrix[row][col];
                }
            }
        }

        default: {

            matrix = allocateMemoryForMatrix(size);
            for (int row = 0; row < SAMPLE_MATRIX_SIZE; ++row) {
                for (int col = 0; col < SAMPLE_MATRIX_SIZE; ++col) {
                    matrix[row][col] = sampleMatrix[row][col];
                }
            }
        }
    }


    printf("Initial matrix");
    printMatrix(matrix, size);

    sortMatrixRows(matrix, size);

    printf("Sorted matrix");
    printMatrix(matrix, size);

    for (int colId = 1; colId < size; ++colId) {
        printf("Sum of colId %d: %d\n", colId, sumOverDiagonal(matrix, size, colId));
    }

    int prod = productOfSumOverDiagonal(matrix, size);
    printf("Product = %d", prod);
    freeMemoryOfMatrix(matrix, size);

    return 0;
}


