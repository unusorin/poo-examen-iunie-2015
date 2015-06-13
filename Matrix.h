//
// Created by sorin_badea on 6/8/15.
//

#ifndef POO_PROIECT_MATRIX_H
#define POO_PROIECT_MATRIX_H

#include "vector"

using  namespace std;

/**
 * Matrix class that simplifies the work with 2 dimensional arrays
 */
template<typename T>
class Matrix {

private:
    /**
     * Matrix width and height
     */
    unsigned width, height;
private:
    /**
     * Reset vector with new dimensions and new initial value
     */
    void reset(unsigned width, unsigned height, const T &initialValue);

public:
    /**
     * Elements vector
     */
    vector<T> elements;

    /**
     * Constructor
     */
    Matrix(unsigned width, unsigned height, const T &initialValue);

    /**
     * Constructor for converting a undefined type to Matrix
     */
    Matrix(const T &initialValue);

    /**
     * Constructor
     */
    Matrix();

    /**
     * Copy constructor
     */
    Matrix(const Matrix &matrix);

    /**
     * Destructor
     */
    virtual ~Matrix();

    /**
     * MatrixProxy handle double array subscript operator overload
     */
    class MatrixProxy {
        /**
         * Matrix object copy
         */
        Matrix<T> *matrix;
        /**
         * First dimension that was send to the first array subscript operator ( matrix[currentHeight] )
         */
        unsigned currentHeight;
    public:
        typename Matrix<T>::MatrixProxy;

        /**
         * Constructor
         */
        MatrixProxy(Matrix<T> *matrix, unsigned currentHeight) : matrix(matrix), currentHeight(currentHeight) { }

        /**
         * Overload array subscript operator
         */
        T &operator[](unsigned index);

        /**
         * Overload array subscript operator (const version)
         */
        const T &operator[](unsigned index) const;
    };

    /**
     * Overload array subscript operator
     */
    MatrixProxy operator[](unsigned index);

    /**
     * Overload assignment operator
     */
    Matrix<T> &operator=(const Matrix<T> &matrix);

    /**
     * Overload addition operator
     */
    Matrix<T> operator+(const Matrix<T> &matrix);

    /**
     * Overload cumulative addition operator
     */
    Matrix<T> &operator+=(const Matrix<T> &matrix);

    /**
     * Overload subtraction operator
     */
    Matrix<T> operator-(const Matrix<T> &matrix);

    /**
     * Overload cumulative subtraction operator
     */
    Matrix<T> &operator-=(const Matrix<T> &matrix);

    /**
     * Overload multiplier operator
     */
    Matrix<T> operator*(const Matrix<T> &matrix);

    /**
     * Overload cumulative multiplier operator
     */
    Matrix<T> &operator*=(const Matrix<T> &matrix1);

    /**
     * Get individual element
     */
    T &operator()(const unsigned &height, const unsigned &column);

    const T &operator()(const unsigned &height, const unsigned &column) const;

    /**
     * Overload equality operator
     */
    bool operator==(const Matrix<T> &matrix);

    /**
     * Overload non-equality operator
     */
    bool operator!=(const Matrix<T> &matrix);

    /**
     * Width getter
     */
    unsigned getWidth() const;

    /**
     * Height getter
     */
    unsigned getHeight() const;

    /**
     * Print matrix
     */
    void print();

};

#include "Matrix.cpp"

#endif //POO_PROIECT_MATRIX_H
