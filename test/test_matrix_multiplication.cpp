#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

#include <math.h>

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
 * @brief This test does the multiplication between two rectangular matrices with various numbers
 * @note The matrix resultant is a rectangular matrix
 * 
 * @bug error 3: Matrix A contains a negative number!
 * @bug error 5: Matrix B contains a negative number!
 * @bug error 6: Result matrix contains a number bigger than 100!
 * @bug error 10: A row in Matrix A contains more than one '1'!
 */
TEST(MatrixMultiplicationTest3, TestMultiplyMatrices) { //NOME UNICO 
    size_t rowsA = 3;
    size_t colsA = 4;
    size_t rowsB = colsA;
    size_t colsB = 2;

    std::vector<std::vector<int>> A = {
        {1, 2, 1, -1},
        {0, -5, 6, 1},
        {-2, 3, 4, 2}

    };
    std::vector<std::vector<int>> B = {
        {0, 0},
        {4, -2},
        {50, 7},
        {-3, 11}

    };
    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(A, B, C, rowsA, colsA, colsB); 

    std::vector<std::vector<int>> expected = {
        {61, -8},
        {277, 63},
        {206, 44}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
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
 * @bug error 13: The first element of matrix A is equal to the first element of matrix B!
 * @bug error 14: The number matrix C has an even number of rows! 
 * @bug error 16: Matrix B contains the number 6!
 * @bug error 18: Matrix A is a square matrix!
 */
TEST(MatrixMultiplicationTest4, TestMultiplyMatrices) { //NOME UNICO 
    size_t rowsA = 100;
    size_t colsA = 100;
    size_t colsB = 100;
    size_t rowsB = colsA;

    std::vector<std::vector<int>> A(rowsA, std::vector<int>(colsA, 0));
    for(size_t i = 0; i < rowsA; ++i) {
        A[i][i] = 1;
    }
    std::vector<std::vector<int>> B(rowsB, std::vector<int>(colsB, 0));
    for(size_t i = 0; i < rowsB; ++i) {
        B[i][i] = i+1;
    }
    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(A, B, C, rowsA, colsA, colsB); 

    std::vector<std::vector<int>> expected(rowsA, std::vector<int>(colsB, 0));
    for(size_t i = 0; i < rowsA; ++i) {
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
    size_t colsB = 10;
    size_t rowsB = colsA;

    std::vector<std::vector<int>> A(rowsA, std::vector<int>(colsA, 0));
    for(size_t i = 0; i < rowsA; ++i) {
        for(size_t j = 0; j < colsA; j++){
            A[i][j] = j;
        }
        
    }
    std::vector<std::vector<int>> B(rowsB, std::vector<int>(colsB, 0));
    for(size_t i = 0; i < rowsB; ++i) {
        B[i][i] = 1;
    }
    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(A, B, C, rowsA, colsA, colsB);

    std::vector<std::vector<int>> expected(rowsA, std::vector<int>(colsB, 0));
    for(size_t i = 0; i < rowsA; ++i) {
        for(size_t j = 0; j < colsB; j++){
            expected[i][j] = j;
        }
    }

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/**
 * @brief Construct a new TEST object that multiplies two matrices 10X10 that are respectively the
 * former a matrix with all columns equals between each other, containg all numbers from 0 to 9, 
 * and matrix with 1s in the diagonal and 2s in the other elements
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
    size_t colsB = 10;
    size_t rowsB = colsA;

    std::vector<std::vector<int>> A(rowsA, std::vector<int>(colsA, 0));
    for(size_t i = 0; i < rowsA; ++i) {
        for(size_t j = 0; j < colsA; j++){
            A[i][j] = i;
        }
    }
    std::vector<std::vector<int>> B(rowsB, std::vector<int>(colsB, 2));
    for(size_t i = 0; i < rowsB; ++i) {
        B[i][i] = 1;
    }
    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(A, B, C, rowsA, colsA, colsB); 

    std::vector<std::vector<int>> expected = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {19, 19, 19, 19, 19, 19, 19, 19, 19, 19},
        {38, 38, 38, 38, 38, 38, 38, 38, 38, 38},
        {57, 57, 57, 57, 57, 57, 57, 57, 57, 57},
        {76, 76, 76, 76, 76, 76, 76, 76, 76, 76},
        {95, 95, 95, 95, 95, 95, 95, 95, 95, 95},
        {114, 114, 114, 114, 114, 114, 114, 114, 114, 114},
        {133, 133, 133, 133, 133, 133, 133, 133, 133, 133},
        {152, 152, 152, 152, 152, 152, 152, 152, 152, 152},
        {171, 171, 171, 171, 171, 171, 171, 171, 171, 171}
    };


    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/** 
 * @brief Construct a new TEST object which confront one 10X10 identity matrix A with a matrix that
 * all rows equals between each other, with values going from 0 to 9
 * @note we expect C to be equal to B
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
    size_t colsB = 10;
    size_t rowsB = colsA;

    std::vector<std::vector<int>> A(rowsA, std::vector<int>(colsA, 0));
    for(size_t i = 0; i < rowsA; ++i) {
        A[i][i] = 1;
        
    }
    std::vector<std::vector<int>> B(rowsB, std::vector<int>(colsB, 0));
    for(size_t i = 0; i < rowsB; ++i) {
        for(size_t j = 0; j < colsB; j++){
            B[i][j] = j;
        }
    }
    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(A, B, C, rowsA, colsA, colsB);

    std::vector<std::vector<int>> expected(rowsA, std::vector<int>(colsB, 0));
    for(size_t i = 0; i < rowsA; ++i) {
        for(size_t j = 0; j < colsB; j++){
            expected[i][j] = j;
        }
    }

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
} 

/**
 * @brief Construct a new TEST object which multiplies a 10X10 identity matrix A with a matrix that
 * all columns equals between each other, with values going from 0 to 9
 * @note we expect C to be equal to B
 * 
 * @bug error 1: Element-wise multiplication of ones detected!
 * @bug error 4: Matrix B contains the number 3!
 * @bug error 7: Result matrix contains a number between 11 and 20!
 * @bug error 12: The number of rows in A is equal to the number of columns in B!
 * @bug error 14: The number matrix C has an even number of rows! 
 * @bug error 16: Matrix B contains the number 6!
 * @bug error 17: Result matrix C contains the number 17!
 * @bug error 18: Matrix A is a square matrix!
 */
TEST(MatrixMultiplicationTest8, TestMultiplyMatrices) { //NOME UNICO 
    size_t rowsA = 10;
    size_t colsA = 10;
    size_t colsB = 10;
    size_t rowsB = colsA;

    std::vector<std::vector<int>> A(rowsA, std::vector<int>(colsA, 0));
    for(size_t i = 0; i < rowsA; ++i) {
        A[i][i] = 1; 
        
    }
    std::vector<std::vector<int>> B(rowsB, std::vector<int>(colsB, 2));
    for(size_t i = 0; i < rowsB; ++i) {
        for(size_t j = 0; j < colsB; j++){
            B[i][j] = i;
        }
    }
    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(A, B, C, rowsA, colsA, colsB);

    std::vector<std::vector<int>> expected(rowsA, std::vector<int>(colsB, 0));
    for(size_t i = 0; i < rowsA; ++i) {
        for(size_t j = 0; j < colsB; j++){
            expected[i][j] = i;
        }
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
 * @bug error 7: Result matrix contains a number between 11 and 20!
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
    size_t colsB = 10;
    size_t rowsB = colsA;

    std::vector<std::vector<int>> A(rowsA, std::vector<int>(colsA, 0));
    for(size_t i = 0; i < rowsA; ++i) {
        A[i][i] = i+1;
    }
    std::vector<std::vector<int>> B(rowsB, std::vector<int>(colsB, 0));
    for(size_t i = 0; i < rowsB; ++i) {
        B[i][i] = 1;
    }
    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(A, B, C, rowsA, colsA, colsB);

    std::vector<std::vector<int>> expected(rowsA, std::vector<int>(colsB, 0));
    for(size_t i = 0; i < rowsA; ++i) {
        expected[i][i] = i+1;
    }

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/**
 * @brief Construct a new TEST object that multiplies two matrices 10x10 where the first matrix is a diagonal matrix 
 * containing alternating 1 and -1, and the second matrix is a diagonal matrix with alternating powers of -2 and 2.
 * @note We expect C to be a diagonal matrix where each element on the diagonal is the product of the corresponding 
 * elements from A and B.
 * 
 * @bug error 1: Element-wise multiplication of ones detected!
 * @bug error 3: Matrix A contains a negative number!
 * @bug error 4: Matrix B contains the number 3!
 * @bug error 5: Matrix B contains a negative number!
 * @bug error 6: Result matrix contains a number bigger than 100!
 * @bug error 7: Result matrix contains a number between 11 and 20!
 * @bug error 8: Result matrix contains zero!
 * @bug error 11: Every row in matrix B contains at least one '0'!
 * @bug error 12: The number of rows in A is equal to the number of columns in B!
 * @bug error 14: The number matrix C has an even number of rows!
 * @bug error 16: Matrix B contains the number 6!
 * @bug error 17: Result matrix C contains the number 17!
 * @bug error 18: Matrix A is a square matrix!
 */
TEST(MatrixMultiplicationTest10, TestMultiplyMatrices) { //NOME UNICO 
    size_t rowsA = 10;
    size_t colsA = 10;
    size_t colsB = 10;
    size_t rowsB = colsA;

    std::vector<std::vector<int>> A(rowsA, std::vector<int>(colsA, 0));
    for(size_t i = 0; i < rowsA; ++i) {
        A[i][i] = std::pow(-1, i);
    }
    std::vector<std::vector<int>> B(rowsB, std::vector<int>(colsB, 0));
    for(size_t i = 0; i < rowsB; ++i) {
        B[i][i] = std::pow(-2, i) * std::pow(-1, i+1);
    }
    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(A, B, C, rowsA, colsA, colsB);

    std::vector<std::vector<int>> expected(rowsA, std::vector<int>(colsB, 0));
    for(size_t i = 0; i < rowsA; ++i) {
        expected[i][i] = -1 * std::pow(-2, i);
    }

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
