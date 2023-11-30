#include <stdio.h>
#include "../matriks.h"

int main()
{
    int type;
    

    scanf("%d", &type);

    Matrix m1, m2, m3;
    readMatrix(&m1, 5, 5);
    readMatrix(&m2, 5, 5);
    readMatrix(&m3, 5, 5);

    switch (type)
    {
    case 1:
        // Create Matrix
        int nRows, nCols;
        printf("Enter number of rows: ");
        scanf("%d", &nRows);
        printf("Enter number of columns: ");
        scanf("%d", &nCols);
        createMatrix(nRows, nCols, &m1);
        printf("Matrix created.\n");
        break;

    case 2:
        // Read Matrix
        printf("Enter values for m1:\n");
        readMatrix(&m1, ROW_EFF_Matriks(m1), COL_EFF_Matriks(m1));
        printf("Matrix m1 after reading values:\n");
        displayMatrix(m1);
        break;

    case 3:
        // Display Matrix
        printf("Matrix m1:\n");
        displayMatrix(m1);
        break;

    case 4:
        // Check if Square Matrix
        if (isSquareMatrix(m1)) {
            printf("m1 is a square matrix.\n");
        } else {
            printf("m1 is not a square matrix.\n");
        }
        break;

    case 5:
        // Check if Symmetric Matrix
        if (isSymmetricMatrix(m1)) {
            printf("m1 is a symmetric matrix.\n");
        } else {
            printf("m1 is not a symmetric matrix.\n");
        }
        break;

    case 6:
        // Transpose Matrix
        printf("Transpose of m1:\n");
        m2 = transposeMatrix(m1);
        displayMatrix(m2);
        break;

    case 7:
        // In-Place Transpose Matrix
        pTransposeMatrix(&m1);
        printf("m1 after in-place transpose:\n");
        displayMatrix(m1);
        break;

    case 8:
        // Add Matrices
        createMatrix(ROW_EFF_Matriks(m1), COL_EFF_Matriks(m1), &m2);
        printf("Enter values for m2:\n");
        readMatrix(&m2, ROW_EFF_Matriks(m2), COL_EFF_Matriks(m2));
        printf("Matrix m2:\n");
        displayMatrix(m2);
        m3 = addMatrix(m1, m2);
        printf("m1 + m2:\n");
        displayMatrix(m3);
        break;

    case 9:
        // Subtract Matrices
        createMatrix(ROW_EFF_Matriks(m1), COL_EFF_Matriks(m1), &m2);
        printf("Enter values for m2:\n");
        readMatrix(&m2, ROW_EFF_Matriks(m2), COL_EFF_Matriks(m2));
        printf("Matrix m2:\n");
        displayMatrix(m2);
        m3 = subtractMatrix(m1, m2);
        printf("m1 - m2:\n");
        displayMatrix(m3);
        break;

    case 10:
        // Multiply Matrices
        createMatrix(ROW_EFF_Matriks(m1), COL_EFF_Matriks(m1), &m2);
        printf("Enter values for m2:\n");
        readMatrix(&m2, ROW_EFF_Matriks(m2), COL_EFF_Matriks(m2));
        printf("Matrix m2:\n");
        displayMatrix(m2);
        m3 = multiplyMatrix(m1, m2);
        printf("m1 * m2:\n");
        displayMatrix(m3);
        break;

    case 11:
        // Multiply Matrix by Constant
        int constant;
        printf("Enter a constant: ");
        scanf("%d", &constant);
        m3 = multiplyMatrixByConst(m1, constant);
        printf("%d * m1:\n", constant);
        displayMatrix(m3);
        break;

    case 12:
        // In-Place Multiply Matrix by Constant
        int constant2;
        printf("Enter a constant: ");
        scanf("%d", &constant2);
        pMultiplyMatrixbyConst(&m1, constant2);
        printf("m1 after in-place multiplication by %d:\n", constant2);
        displayMatrix(m1);
        break;

    case 13:
        // Calculate Determinant
        if (!isSquareMatrix(m1)) {
            printf("Cannot calculate determinant for non-square matrix.\n");
        } else {
            float det = determinantMatrix(m1);
            printf("Determinant of m1: %.2f\n", det);
        }
        break;

    case 14:
        // Check if Sparse Matrix
        if (isSparseMatrix(m1)) {
            printf("m1 is a sparse matrix.\n");
        } else {
            printf("m1 is not a sparse matrix.\n");
        }
        break;

    case 15:
        // Check if Identity Matrix
        if (isIdentityMatrix(m1)) {
            printf("m1 is an identity matrix.\n");
        } else {
            printf("m1 is not an identity matrix.\n");
        }
        break;

    

    }
    return 0;
}