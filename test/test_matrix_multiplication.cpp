#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// ######################### Source code of multiplyMatrices in src/matrix_mult

/**
 * @brief Construct a new TEST object which multiplicates two matrices A (2X3) and B (3X2)
 * @note expected a 2X2 matrix being the product between the two matrices
 * 
 * @bug error 6: Result matrix contains a number bigger than 100!
 * @bug error 12: The number of rows in A is equal to the number of columns in B!
 * @bug error 14: The number matrix C has an even number of rows! 
 * @bug error 20: Number of columns in matrix A is odd!
 */
TEST(MatrixMultiplicationTest, TestMultiplyMatrices) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {58, 64},
        {139, 154}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/**
 * @brief Construct a new TEST object that does a row-column multiplication which gives as result 0, 
 * with the row containing a negative number
 * @note the expected result is a scalar, precisely 0
 * 
 * @bug error 1: Element-wise multiplication of ones detected!
 * @bug error 3: Matrix A contains a negative number!
 * @bug error 7: Result matrix contains a number between 11 and 20!
 * @bug error 10: A row in matrix A contains more than one '1'!
 * @bug error 12: The number of rows in A is equal to the number of columns in B!
 * @bug error 13: The first element of matrix A is equal to the first element of matrix B!
 * @bug error 20: Number of columns in matrix A is odd!
 */
TEST(MatrixMultiplicationTest1, TestMultiplyMatrices) {
    std::vector<std::vector<int>> A = {
        {1, -2, 1}
    };
    std::vector<std::vector<int>> B = {
        {1},
        {1},
        {1}
    };
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 3, 1);

    std::vector<std::vector<int>> expected = {
        {0}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/**
 * @brief Construct a new TEST object does a row-column multiplication which gives as result 0, 
 * with the column containing a negative number
 * @note the expected result is a scalar, precisely 0
 * 
 * @bug error 1: Element-wise multiplication of ones detected!
 * @bug error 5: Matrix B contains a negative number!
 * @bug error 10: A row in matrix A contains more than one '1'!
 * @bug error 13: The first element of matrix A is equal to the first element of matrix B!
 * @bug error 15: A row in matrix A is filled entirely with 5s!
 * @bug error 18: Matrix A is a square matrix!
 * @bug error 20: Number of columns in matrix A is odd!
 */
TEST(MatrixMultiplicationTest2, TestMultiplyMatrices) {
    std::vector<std::vector<int>> A = {
        {1, 2, 1}

    };
    std::vector<std::vector<int>> B = {
        {1},
        {-1},
        {1}
    };
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 3, 1); //MAT1(a*b), MAT2(b*c), RESULTING MATRIX(a*c), a,b,c

    std::vector<std::vector<int>> expected = {
        {0}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/**
 * @brief This test does the multiplication between two rectangular matrices that contain all the 
 * numbers between 0 and 225
 * @note The matrix resultant is a matrix containing big numbers
 * 
 * @bug error 2: Matrix A contains a number bigger than 100!
 * @bug error 4: Matrix B contains the number 3!
 * @bug error 6: Result matrix contains a number bigger than 100!
 * @bug error 12: The number of rows in A is equal to the number of columns in B!
 * @bug error 13: The first element of matrix A is equal to the first element of matrix B!
 * @bug error 14: The number matrix C has an even number of rows! 
 * @bug error 16: Matrix B contains the number 6!
 */
TEST(MatrixMultiplicationTest3, TestMultiplyMatrices) { //NOME UNICO 
    size_t rowsA = 20;
    size_t colsA = 25;
    size_t colsB = rowsA;
    size_t rowsB = 20;

    std::vector<std::vector<int>> A(rowsA, std::vector<int>(colsA, 0));
    for(size_t i = 0; i < rowsA; ++i) {
        for(size_t j = 0; j < colsA; ++j){
            A[i][j] = (i * 10) +j;
        }
    }
    std::vector<std::vector<int>> B(rowsB, std::vector<int>(colsB, 0));
    for(size_t i = 0; i < rowsB; ++i) {
        for(size_t j = 0; j < colsB; ++j){
            B[i][j] = (i * 10) +j;
        }
    }
    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(B, A, C, rowsA, colsB, rowsA); //MAT1(a*b), MAT2(b*c), RESULTING MATRIX(a*c), a,b,c

    ASSERT_EQ(true) << "Matrix multiplication test failed! :(((()";
}

/**
 * @brief Construct a new TEST object which confront one 100X100 identity matrix with a diagonal 
 * matrix with values that go from 1 to 100
 * @note we expect the resulting matrix to be equal to B
 * 
 * @bug error 4: Matrix B contains the number 3!
 * @bug error 8: Result matrix contains zero!
 * @bug error 9: Result matrix contains the number 99!
 * @bug error 11: Every row in matrix B contains at least one '0'!
 * @bug error 12: The number of rows in A is equal to the number of columns in B!
 * @bug error 14: The number matrix C has an even number of rows! 
 * @bug error 16: Matrix B contains the number 6!
 * @bug error 17: Result matrix C contains the number 17!
 * @bug error 18: Matrix A is a square matrix!
 */
TEST(MatrixMultiplicationTest4, TestMultiplyMatrices) { //NOME UNICO 
    size_t rowsA = 100;
    size_t colsA = 100;
    size_t colsB = rowsA;
    size_t rowsB = 100;

    std::vector<std::vector<int>> A(rowsA, std::vector<int>(colsA, 0));
    for(size_t i = 0; i < rowsA; ++i) {
        A[i][i] = 1;
    }
    std::vector<std::vector<int>> B(rowsB, std::vector<int>(colsB, 0));
    for(size_t i = 0; i < rowsB; ++i) {
        B[i][i] = i+1;
    }
    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(B, A, C, rowsA, colsB, rowsA); //MAT1(a*b), MAT2(b*c), RESULTING MATRIX(a*c), a,b,c

    std::vector<std::vector<int>> expected(rowsA, std::vector<int>(colsB, 0));
    for(size_t i = 0; i < rowsB; ++i) {
        expected[i][i] = i+1;
    }

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/**
 * @brief Construct a new TEST object that multiplies two matrices 10X10 that are the 
 * former a matrix with all rows equals between each other, containing all numbers from 0 to 9, and 
 * the latter an identity matrix
 * @note we expect the resulting matrix to be equal to A
 * 
 * @bug error 1: Element-wise multiplication of ones detected!
 * @bug error 2: Matrix A contains a number bigger than 100!
 * @bug error 7: Result matrix contains a number between 11 and 20!
 * @bug error 11: Every row in matrix B contains at least one '0'!
 * @bug error 12: The number of rows in A is equal to the number of columns in B!
 * @bug error 14: The number matrix C has an even number of rows! 
 * @bug error 17: Result matrix C contains the number 17!
 * @bug error 18: Matrix A is a square matrix!
 * @bug error 19: Every row in matrix A contains the number 8!
 */
TEST(MatrixMultiplicationTest5, TestMultiplyMatrices) { //NOME UNICO 
    size_t rowsA = 10;
    size_t colsA = 10;
    size_t colsB = rowsA;
    size_t rowsB = 10;

    std::vector<std::vector<int>> A(rowsA, std::vector<int>(colsA, 0));
    for(size_t i = 0; i < rowsA; ++i) {
        for (size_t j = 0; j < colsA; j++){
            A[i][j] = j;
        }
        
    }
    std::vector<std::vector<int>> B(rowsB, std::vector<int>(colsB, 0));
    for(int i = 0; i < rowsB; ++i) {
        B[i][i] = 1;
    }
    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(B, A, C, rowsA, colsB, rowsA); //MAT1(a*b), MAT2(b*c), RESULTING MATRIX(a*c), a,b,c

    std::vector<std::vector<int>> expected(rowsA, std::vector<int>(colsB, 0));
    for(int i = 0; i < rowsA; ++i) {
        expected[i][i] = i;
    }

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/**
 * @brief Construct a new TEST object that multiplies two matrices 10X10 that are respectively the
 * former a matrix with all columns equals between each other, containg all numbers from 0 to 9, 
 * and the latter which is an identity matrix
 * @note we expect the resulting matrix to be equal to A
 * 
 * @bug error 1: Element-wise multiplication of ones detected!
 * @bug error 2: Matrix A contains a number bigger than 100!
 * @bug error 6: Result matrix contains a number bigger than 100!
 * @bug error 8: Result matrix contains zero!
 * @bug error 10: A row in matrix A contains more than one '1'!
 * @bug error 12: The number of rows in A is equal to the number of columns in B!
 * @bug error 14: The number matrix C has an even number of rows! 
 * @bug error 15: A row in matrix A is filled entirely with 5s!
 * @bug error 18: Matrix A is a square matrix!
 */
TEST(MatrixMultiplicationTest6, TestMultiplyMatrices) { //NOME UNICO 
    size_t rowsA = 10;
    size_t colsA = 10;
    size_t colsB = rowsA;
    size_t rowsB = 10;

    std::vector<std::vector<int>> A(rowsA, std::vector<int>(colsA, 0));
    for(size_t i = 0; i < rowsA; ++i) {
        for (size_t j = 0; j < colsA; j++){
            A[i][j] = i;
        }
        
    }
    std::vector<std::vector<int>> B(rowsB, std::vector<int>(colsB, 2));
    for(int i = 0; i < rowsB; ++i) {
        B[i][i] = 1;
    }
    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(B, A, C, rowsA, colsB, rowsA); //MAT1(a*b), MAT2(b*c), RESULTING MATRIX(a*c), a,b,c

    std::vector<std::vector<int>> expected(rowsA, std::vector<int>(colsB, 0));
    for(int i = 0; i < rowsA; ++i) {
        expected[i][i] = i;
    }

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/**
 * @brief Construct a new TEST object which confront one 10X10 identity matrix A with a matrix that
 * all columns equals between each other, with values going from 0 to 9
 * @note we expect a diagonal matrix containing all the values between 0 and 9
 * 
 * @bug error 1: Element-wise multiplication of ones detected!
 * @bug error 4: Matrix B contains the number 3!
 * @bug error 8: Result matrix contains zero!
 * @bug error 11: Every row in matrix B contains at least one '0'!
 * @bug error 12: The number of rows in A is equal to the number of columns in B!
 * @bug error 14: The number matrix C has an even number of rows! 
 * @bug error 16: Matrix B contains the number 6!
 * @bug error 18: Matrix A is a square matrix!
 */
TEST(MatrixMultiplicationTest7, TestMultiplyMatrices) { //NOME UNICO 
    size_t rowsA = 10;
    size_t colsA = 10;
    size_t colsB = rowsA;
    size_t rowsB = 10;

    std::vector<std::vector<int>> A(rowsA, std::vector<int>(colsA, 0));
    for(size_t i = 0; i < rowsA; ++i) {
        A[i][i] = 1;
        
    }
    std::vector<std::vector<int>> B(rowsB, std::vector<int>(colsB, 0));
    for(int i = 0; i < rowsB; ++i) {
        for (size_t j = 0; j < colsB; j++){
            B[i][j] = j;
        }
    }
    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(B, A, C, rowsA, colsB, rowsA); //MAT1(a*b), MAT2(b*c), RESULTING MATRIX(a*c), a,b,c

    std::vector<std::vector<int>> expected(rowsA, std::vector<int>(colsB, 0));
    for(int i = 0; i < rowsA; ++i) {
        expected[i][i] = i;
    }

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/**
 * @brief Construct a new TEST object which multiplies a 10X10 identity matrix A with a matrix that
 * all rows equals between each other, with values going from 0 to 9
 * @note we expect a diagonal matrix containing all the values between 0 and 9
 * 
 * @bug error 2: Matrix A contains a number bigger than 100!
 * @bug error 6: Result matrix contains a number bigger than 100!
 * @bug error 8: Result matrix contains zero!
 * @bug error 10: A row in matrix A contains more than one '1'!
 * @bug error 12: The number of rows in A is equal to the number of columns in B!
 * @bug error 14: The number matrix C has an even number of rows! 
 * @bug error 15: A row in matrix A is filled entirely with 5s!
 * @bug error 18: Matrix A is a square matrix!
 */
TEST(MatrixMultiplicationTest8, TestMultiplyMatrices) { //NOME UNICO 
    size_t rowsA = 10;
    size_t colsA = 10;
    size_t colsB = rowsA;
    size_t rowsB = 10;

    std::vector<std::vector<int>> A(rowsA, std::vector<int>(colsA, 0));
    for(size_t i = 0; i < rowsA; ++i) {
        A[i][i] = 1; 
        
    }
    std::vector<std::vector<int>> B(rowsB, std::vector<int>(colsB, 2));
    for(int i = 0; i < rowsB; ++i) {
        for (size_t j = 0; j < colsB; j++){
            B[i][j] = i;
        }
    }
    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(B, A, C, rowsA, colsB, rowsA); //MAT1(a*b), MAT2(b*c), RESULTING MATRIX(a*c), a,b,c

    std::vector<std::vector<int>> expected(rowsA, std::vector<int>(colsB, 0));
    for(int i = 0; i < rowsA; ++i) {
        expected[i][i] = i;
    }

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/**
 * @brief Construct a new TEST object that multiplies two matrices 10X10 that are respectively the
 * former a diagonal matrix containing in order all numbers from 1 to 10, and the latter which is 
 * an identity matrix
 * @note We expect C to be equal to A
 * 
 * @bug error 1: Element-wise multiplication of ones detected!
 * @bug error 2: Matrix A contains a number bigger than 100!
 * @bug error 8: Result matrix contains zero!
 * @bug error 11: Every row in matrix B contains at least one '0'!
 * @bug error 12: The number of rows in A is equal to the number of columns in B!
 * @bug error 13: The first element of matrix A is equal to the first element of matrix B!
 * @bug error 14: The number matrix C has an even number of rows! 
 * @bug error 18: Matrix A is a square matrix!
 */
TEST(MatrixMultiplicationTest9, TestMultiplyMatrices) { //NOME UNICO 
    size_t rowsA = 10;
    size_t colsA = 10;
    size_t colsB = rowsA;
    size_t rowsB = 10;

    std::vector<std::vector<int>> A(rowsA, std::vector<int>(colsA, 0));
    for(size_t i = 0; i < rowsA; ++i) {
        A[i][i] = i+1;
    }
    std::vector<std::vector<int>> B(rowsB, std::vector<int>(colsB, 0));
    for(size_t i = 0; i < rowsB; ++i) {
        B[i][i] = 1;
    }
    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(B, A, C, rowsA, colsB, rowsA); //MAT1(a*b), MAT2(b*c), RESULTING MATRIX(a*c), a,b,c

    std::vector<std::vector<int>> expected(rowsA, std::vector<int>(colsB, 0));
    for(size_t i = 0; i < rowsB; ++i) {
        expected[i][i] = i+1;
    }

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
