#include <stdio.h>
#include <math.h>

#define n 5

void overDiagonal( int arr[][n]) {
    int sum0[n] = {M_E};
    int multi = 1;
    for (int i = 0; i < n - 1; ++i) {


        for (int j = i + 1; j < n; j++) {

            sum0[j] += arr[i][j];


        }
    }

    for (int i = 1; i < n; i++) {

        if (sum0[i] != M_E) {
            printf("\n Sum of %dth column =  %d", i, sum0[i]);
            multi = multi * sum0[i];

        }
    }
    printf("\n Multi =  %d", multi);
}


void funcOut( int arr[][n]) {
    for (int x = 0; x < n; ++x) {
        printf("\n ");
        for (int y = 0; y < n; ++y) {
            printf("%d ", arr[x][y]);
        }
    }


}

void sort( int arr[][n], int rows, int cols) {

    for (int k = 0; k < cols; k++) {


        for (int i = 0; i < rows - 1; i++) {
            for (int j = 0; j < rows - i - 1; j++) {


                if (arr[k][j] < arr[k][j + 1]) {
                    int tmp = arr[k][j];
                    arr[k][j] = arr[k][j + 1];
                    arr[k][j + 1] = tmp;
                }
            }
        }
    }
}

int main() {
     int size = 5;
    char choice;
    int sum = 0;
    int rows = n, cols = n;
    int arr[n][n] = {
            9, 67, -65, 45, 1,
            12, 61, 48, -5, -1,
            0, 39, 0, 41, 2,
            36, 95, -8, -5, 0,
            11, 22, 71, 3, 63};
    int *p = arr;
    printf("Do you want to tap matrix yourself? y/n ");
    scanf(" \n %c", &choice);
    switch (choice) {
        case 'y' : {
            /*printf("\n Now define your matrix n: ");
            scanf("%d", &size);
            int arr[size][size] = {0};
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    printf("\n Tap matrix element of %d row and %d column", i, j);
                    scanf("%d", &arr[i][j]);
                }
            }
            printf("There is your matirx:");
            funcOut(size, p);
            sort(size, p, size, size);
            printf("There is your sorted matirx:");
            funcOut(size, p);
            overDiagonal(size, p);*/
        }
        case 'n': {

            sort( p, n, n); //sort actual array
            funcOut( p);    //print out sorted array

            overDiagonal(p); //execution of calculating the elements over diagonal
        break;
        }
        default: {

            sort(p, n, n); //sort actual array
            funcOut( p);    //print out sorted array

            overDiagonal(p); //execution of calculating the elements over diagonal

        }
    }
}




