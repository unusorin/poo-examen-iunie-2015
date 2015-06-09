#include "Matrix.h"

int tests() {
    {
        //assignment
        Matrix<double> matrix(5, 5, 1);
        Matrix<double> copyMatrix = matrix;
        if (matrix != copyMatrix) {
            return 101;
        }
    }
    {
        //test simple matrix accessor
        Matrix<double> matrix(5, 5, 1);
        if (matrix[1][1] != 1) {
            return 102;
        }

        if (matrix(1, 1) != 1) {
            return 103;
        }
    }
    {
        //test matrix addition
        Matrix<double> matrix1(3, 3, 1);
        Matrix<double> matrix2(3, 3, 3);
        Matrix<double> result(3, 3, 4);
        Matrix<double> matrix3 = matrix1 + matrix2;
        if (matrix3 != result) {
            return 104;
        }
    }
    {
        //test cumulative matrix addition
        Matrix<double> matrix1(3, 3, 1);
        Matrix<double> matrix2(3, 3, 3);
        Matrix<double> result(3, 3, 4);
        matrix1 += matrix2;
        if (matrix1 != result) {
            return 105;
        }
    }
    {
        //test matrix subtraction
        Matrix<double> matrix1(5, 5, 20);
        Matrix<double> matrix2(5, 5, 50);
        Matrix<double> result(5, 5, -30);

        Matrix<double> matrix3 = matrix1 - matrix2;

        if (matrix3 != result) {
            return 106;
        }
    }
    {
        //test cumulative matrix subtraction
        Matrix<double> matrix1(5, 5, 20);
        Matrix<double> matrix2(5, 5, 50);
        Matrix<double> result(5, 5, -30);
        matrix1 -= matrix2;
        if (matrix1 != result) {
            return 107;
        }
    }
    {
        //test matrix multiplication
        Matrix<double> matrix1(5, 3, 1);
        Matrix<double> matrix2(5, 5, 2);

        Matrix<double> matrix3 = matrix1 * matrix2;

        Matrix<double> result(5, 3, 15);
        if (result != matrix3) {
            return 108;
        }
    }
    {
        //test cumulative multiplication
        Matrix<double> matrix1(5, 3, 1);
        Matrix<double> matrix2(5, 5, 2);

        matrix1 *= matrix2;

        Matrix<double> result(5, 3, 15);

        if (result != matrix1) {
            return 109;
        }
    }
    {
        Matrix<string> matrix("sorin");

        Matrix<string> result(1, 1, "sorin");

        if (result != matrix) {
            return 110;
        }
    }

    return 0;
}