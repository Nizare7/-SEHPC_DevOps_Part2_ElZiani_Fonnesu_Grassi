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
 * @brief This test does the multiplication between two rectangular matrices, one 20X15 that contains all numbers from 0 to 204
 * and the other 25X20 that contains all numbers from 0 to 259
 * @note The matrix resultant is a matrix containing big numbers
 * 
 * @bug error 2: Matrix A contains a number bigger than 100!
 * @bug error 4: Matrix B contains the number 3!
 * @bug error 6: Result matrix contains a number bigger than 100!
 * @bug error 12: The number of rows in A is equal to the number of columns in B!
 * @bug error 13: The first element of matrix A is equal to the first element of matrix B!
 * @bug error 14: The number matrix C has an even number of rows! 
 * @bug error 16: Matrix B contains the number 6!
 * @bug error 20: Number of columns in matrix A is odd!
 */
TEST(MatrixMultiplicationTest3, TestMultiplyMatrices) { //NOME UNICO 
    size_t rowsA = 20;
    size_t colsA = 15;
    size_t colsB = rowsA;
    size_t rowsB = 25;

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

    multiplyMatrices(A, B, C, rowsA, colsA, colsB); 

    std::vector<std::vector<int>> expected = {
        {10150, 10255, 10360, 10465, 10570, 10675, 10780, 10885, 10990, 11095, 11200, 11305, 11410, 11515, 11620, 11725, 11830, 11935, 12040, 12145},
        {20650, 20905, 21160, 21415, 21670, 21925, 22180, 22435, 22690, 22945, 23200, 23455, 23710, 23965, 24220, 24475, 24730, 24985, 25240, 25495},
        {31150, 31555, 31960, 32365, 32770, 33175, 33580, 33985, 34390, 34795, 35200, 35605, 36010, 36415, 36820, 37225, 37630, 38035, 38440, 38845},
        {41650, 42205, 42760, 43315, 43870, 44425, 44980, 45535, 46090, 46645, 47200, 47755, 48310, 48865, 49420, 49975, 50530, 51085, 51640, 52195},
        {52150, 52855, 53560, 54265, 54970, 55675, 56380, 57085, 57790, 58495, 59200, 59905, 60610, 61315, 62020, 62725, 63430, 64135, 64840, 65545},
        {62650, 63505, 64360, 65215, 66070, 66925, 67780, 68635, 69490, 70345, 71200, 72055, 72910, 73765, 74620, 75475, 76330, 77185, 78040, 78895},
        {73150, 74155, 75160, 76165, 77170, 78175, 79180, 80185, 81190, 82195, 83200, 84205, 85210, 86215, 87220, 88225, 89230, 90235, 91240, 92245},
        {83650, 84805, 85960, 87115, 88270, 89425, 90580, 91735, 92890, 94045, 95200, 96355, 97510, 98665, 99820, 100975, 102130, 103285, 104440, 105595},
        {94150, 95455, 96760, 98065, 99370, 100675, 101980, 103285, 104590, 105895, 107200, 108505, 109810, 111115, 112420, 113725, 115030, 116335, 117640, 118945},
        {104650, 106105, 107560, 109015, 110470, 111925, 113380, 114835, 116290, 117745, 119200, 120655, 122110, 123565, 125020, 126475, 127930, 129385, 130840, 132295},
        {115150, 116755, 118360, 119965, 121570, 123175, 124780, 126385, 127990, 129595, 131200, 132805, 134410, 136015, 137620, 139225, 140830, 142435, 144040, 145645},
        {125650, 127405, 129160, 130915, 132670, 134425, 136180, 137935, 139690, 141445, 143200, 144955, 146710, 148465, 150220, 151975, 153730, 155485, 157240, 158995},
        {136150, 138055, 139960, 141865, 143770, 145675, 147580, 149485, 151390, 153295, 155200, 157105, 159010, 160915, 162820, 164725, 166630, 168535, 170440, 172345},
        {146650, 148705, 150760, 152815, 154870, 156925, 158980, 161035, 163090, 165145, 167200, 169255, 171310, 173365, 175420, 177475, 179530, 181585, 183640, 185695},
        {157150, 159355, 161560, 163765, 165970, 168175, 170380, 172585, 174790, 176995, 179200, 181405, 183610, 185815, 188020, 190225, 192430, 194635, 196840, 199045},
        {167650, 170005, 172360, 174715, 177070, 179425, 181780, 184135, 186490, 188845, 191200, 193555, 195910, 198265, 200620, 202975, 205330, 207685, 210040, 212395},
        {178150, 180655, 183160, 185665, 188170, 190675, 193180, 195685, 198190, 200695, 203200, 205705, 208210, 210715, 213220, 215725, 218230, 220735, 223240, 225745},
        {188650, 191305, 193960, 196615, 199270, 201925, 204580, 207235, 209890, 212545, 215200, 217855, 220510, 223165, 225820, 228475, 231130, 233785, 236440, 239095},
        {199150, 201955, 204760, 207565, 210370, 213175, 215980, 218785, 221590, 224395, 227200, 230005, 232810, 235615, 238420, 241225, 244030, 246835, 249640, 252445},
        {209650, 212605, 215560, 218515, 221470, 224425, 227380, 230335, 233290, 236245, 239200, 242155, 245110, 248065, 251020, 253975, 256930, 259885, 262840, 265795}
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
    size_t colsB = rowsA;
    size_t rowsB = 10;

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
    size_t colsB = rowsA;
    size_t rowsB = 10;

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
    size_t colsB = rowsA;
    size_t rowsB = 10;

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
    size_t colsB = rowsA;
    size_t rowsB = 10;

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
    size_t colsB = rowsA;
    size_t rowsB = 10;

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
