#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

void add_matrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void multiply_matrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0; // Initialize to 0
            for (int x = 0; x < SIZE; x++) {
                result[i][j] += m1[i][x] * m2[x][j];
            }
        }
    }
}

void transpose_matrix(int m[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = m[i][j];
        }
    }
}

void print_matrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void get_matrix_input(int matrix[SIZE][SIZE], int matrix_number) {
    printf("Enter the elements of matrix %d (starting with the first row, seperating each element by a comma):\n", matrix_number);
    for (int i = 0; i < SIZE; i++) {
        while (1) {
            printf("Row %d: ", i + 1);
            char input[100];
            fgets(input, sizeof(input), stdin);
            char *token = strtok(input, ",");
            int count = 0;
            while (token != NULL && count < SIZE) {
                matrix[i][count++] = atoi(token);
                token = strtok(NULL, ",");
            }
            if (count == SIZE) {
                break; // Exit the loop if the row is valid
            } else {
                printf("Each row must have exactly %d elements. Please enter the row again with the specified number of elements.\n", SIZE);
            }
        }
    }
}

int main() {
    printf("Matrix size is defined as %dx%d.\n", SIZE, SIZE);

    int m1[SIZE][SIZE], m2[SIZE][SIZE];
    int sum_matrix[SIZE][SIZE], product_matrix[SIZE][SIZE];
    int transpose_m1[SIZE][SIZE], transpose_m2[SIZE][SIZE];

    get_matrix_input(m1, 1);
    get_matrix_input(m2, 2);

    printf("Matrix 1:\n");
    print_matrix(m1);

    printf("Matrix 2:\n");
    print_matrix(m2);

    printf("Sum:\n");
    add_matrices(m1, m2, sum_matrix);
    print_matrix(sum_matrix);

    printf("Product:\n");
    multiply_matrices(m1, m2, product_matrix);
    print_matrix(product_matrix);

    printf("Transpose of Matrix 1:\n");
    transpose_matrix(m1, transpose_m1);
    print_matrix(transpose_m1);

    printf("Transpose of Matrix 2:\n");
    transpose_matrix(m2, transpose_m2);
    print_matrix(transpose_m2);

    return 0;
}