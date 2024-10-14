#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5 //define size of matrices 
//function to sum two matrices together 
void add_matrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    //loop through elements and add corresponding elements of m1 and m2
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = m1[i][j] + m2[i][j]; //store result 
        }
    }
}

//function to get the product of two matrices 
void multiply_matrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    //loop through each row of m1 and each column of m2 in order to multiply the matrices 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0; //initialize result matrix element to 0
            for (int x = 0; x < SIZE; x++) {
                result[i][j] += m1[i][x] * m2[x][j];
            }
        }
    }
}
//function to transpose a matrix 
void transpose_matrix(int m[SIZE][SIZE], int result[SIZE][SIZE]) {
    //loop through and swap rows and columns of the matrix 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = m[i][j]; //assign the transpose position to each element in the original matrix  
        }
    }
}
//function to print a matrix 
void print_matrix(int matrix[SIZE][SIZE]) {
    //loop through and print each row of matrix 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%5d ", matrix[i][j]); //print each element 
        }
        printf("\n"); //create new line after each row
    }
    printf("\n"); //new line after matrix is printed 
}
//function to obtain input for matrices from user 
void get_matrix_input(int matrix[SIZE][SIZE], int matrix_number) {
    //prompt user to enter elements row by row to create a matrix 
    printf("Enter the elements of matrix %d (starting with the first row, seperating each element by a comma):\n", matrix_number);
    for (int i = 0; i < SIZE; i++) {
        while (1) {
            printf("Row %d: ", i + 1);
            char input[100]; //buffer to hold user input
            fgets(input, sizeof(input), stdin); //get user input as string
            char *token = strtok(input, ","); //tokenize input by comma 
            int count = 0;
            while (token != NULL && count < SIZE) { //parse each element and convert to integer
                matrix[i][count++] = atoi(token); //store in matrix 
                token = strtok(NULL, ","); //get next token
            }
            if (count == SIZE) {
                break; // Exit the loop if the row is valid
            } else { //print error message if nuber of elements is not correct
                printf("Each row must have exactly %d elements. Please enter the row again with the specified number of elements.\n", SIZE);
            }
        }
    }
}

int main() {
    printf("Matrix size is defined as %dx%d.\n", SIZE, SIZE);
    //declare matrices for input, sum, product, and transposed matrices 
    int m1[SIZE][SIZE], m2[SIZE][SIZE];
    int sum_matrix[SIZE][SIZE], product_matrix[SIZE][SIZE];
    int transpose_m1[SIZE][SIZE], transpose_m2[SIZE][SIZE];
    //get input for both matrices
    get_matrix_input(m1, 1);
    get_matrix_input(m2, 2);
    //print first matrix user entered
    printf("Matrix 1:\n");
    print_matrix(m1);
    //print second matrix user entered 
    printf("Matrix 2:\n");
    print_matrix(m2);
    //perform and print sum of matrices
    printf("Sum:\n");
    add_matrices(m1, m2, sum_matrix);
    print_matrix(sum_matrix);
    //perform and print product of matrices
    printf("Product:\n");
    multiply_matrices(m1, m2, product_matrix);
    print_matrix(product_matrix);
    //perform and print the transpose of first matrix user enters 
    printf("Transpose of Matrix 1:\n");
    transpose_matrix(m1, transpose_m1);
    print_matrix(transpose_m1);
    //perform and print transpose of second matrix user enters 
    printf("Transpose of Matrix 2:\n");
    transpose_matrix(m2, transpose_m2);
    print_matrix(transpose_m2);

    return 0; //program ended and was executed successfully
}