#ifndef POO_PROIECT_MATRIX_CPP
#define POO_PROIECT_MATRIX_CPP

#include <stddef.h>
#include <stdexcept>
#include <iostream>
#include "Matrix.h"

template<typename T>
Matrix<T>::Matrix(unsigned width, unsigned height, const T &initialValue) {
    this->width = width;
    this->height = height;
    //resize the vector that will contain the matrix
    reset(width, height, initialValue);
}

template<typename T>
Matrix<T>::Matrix(const T &initialValue) {
    this->width = 1;
    this->height = 1;
    reset(1, 1, initialValue);
}

template<typename T>
void Matrix<T>::reset(unsigned width, unsigned height, const T &initialValue) {
    this->elements.resize(height * width, initialValue);
}

template<typename T>
T &Matrix<T>::MatrixProxy::operator[](unsigned index) {
    return (*matrix)(currentHeight, index);
}

template<typename T>
const T &Matrix<T>::MatrixProxy::operator[](unsigned index) const {
    return (*matrix)(currentHeight, index);
}

template<typename T>
typename Matrix<T>::MatrixProxy Matrix<T>::operator[](unsigned index) {
    return Matrix<T>::MatrixProxy(this, index);
}

template<typename T>
unsigned Matrix<T>::getWidth() const {
    return width;
}

template<typename T>
unsigned Matrix<T>::getHeight() const {
    return height;
}

template<typename T>
void Matrix<T>::print() {
    for (unsigned heightCount = 0; heightCount < this->getHeight(); heightCount++) {
        for (unsigned widthCount = 0; widthCount < this->width; widthCount++) {
            std::cout << (*this)[heightCount][widthCount] << " ";
        }
        std::cout << endl;
    }
}

template<typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &matrix) {
    if (&matrix == this) {
        return *this;
    }
    this->height = matrix.getHeight();
    this->width = matrix.getWidth();

    reset(this->getWidth(), this->getHeight(), 0);

    for (unsigned heightCount = 0; heightCount < this->getHeight(); heightCount++) {
        for (unsigned widthCount = 0; widthCount < this->getWidth(); widthCount++) {
            (*this)[heightCount][widthCount] = matrix[heightCount][widthCount];
        }
    }
    return (*this);
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &matrix) {

    if (this->getWidth() != matrix.getWidth() || this->getHeight() != matrix.getHeight()) {
        throw std::invalid_argument("Cannot sum two matrixes of different type");
    }

    Matrix<T> newMatrix = (*this);

    for (unsigned heightCounter = 0; heightCounter < this->getHeight(); heightCounter++) {
        for (unsigned widthCounter = 0; widthCounter < this->getWidth(); widthCounter++) {
            newMatrix[heightCounter][widthCounter] =
                    (*this)[heightCounter][widthCounter] + matrix[heightCounter][widthCounter];
        }
    }
    return newMatrix;
}

template<typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &matrix) {
    if (this->getWidth() != matrix.getWidth() || this->getHeight() != matrix.getHeight()) {
        throw std::invalid_argument("Cannot sum two matrixes of different type");
    }

    for (unsigned heightCounter = 0; heightCounter < this->getHeight(); heightCounter++) {
        for (unsigned widthCounter = 0; widthCounter < this->getWidth(); widthCounter++) {
            (*this)[heightCounter][widthCounter] += matrix[heightCounter][widthCounter];
        }
    }

    return (*this);
}

template<typename T>


Matrix<T> Matrix<T>::operator-(const Matrix<T> &matrix) {
    if (this->getWidth() != matrix.getWidth() || this->getHeight() != matrix.getHeight()) {
        throw std::invalid_argument("Cannot diff two matrixes of different type");
    }

    Matrix<T> newMatrix = (*this);

    for (unsigned heightCounter = 0; heightCounter < this->getHeight(); heightCounter++) {
        for (unsigned widthCounter = 0; widthCounter < this->getWidth(); widthCounter++) {
            newMatrix[heightCounter][widthCounter] =
                    (*this)[heightCounter][widthCounter] - matrix[heightCounter][widthCounter];
        }
    }

    return newMatrix;
}

template<typename T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &matrix) {
    if (this->getWidth() != matrix.getWidth() || this->getHeight() != matrix.getHeight()) {
        throw std::invalid_argument("Cannot diff two matrixes of different type");
    }

    for (unsigned heightCounter = 0; heightCounter < this->getHeight(); heightCounter++) {
        for (unsigned widthCounter = 0; widthCounter < this->getWidth(); widthCounter++) {
            (*this)[heightCounter][widthCounter] -= matrix[heightCounter][widthCounter];
        }
    }

    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &matrix) {

    if (this->getWidth() != matrix.getHeight()) {
        throw std::invalid_argument("Cannot multiple since a.width != b.height");
    }
    Matrix<T> newMatrix = Matrix(matrix.getWidth(), this->getHeight(), 0);

    for (unsigned heightCounter = 0; heightCounter < newMatrix.getHeight(); heightCounter++) {
        for (unsigned widthCounter = 0; widthCounter < newMatrix.getWidth(); widthCounter++) {
            for (unsigned counter = 0; counter < this->getWidth(); counter++) {
                newMatrix[heightCounter][widthCounter] +=
                        (*this)[heightCounter][counter] + matrix[counter][widthCounter];
            }
        }
    }

    return newMatrix;
}

template<typename T>
Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &matrix1) {
    Matrix<T> result = (*this) * matrix1;
    (*this) = result;
    return (*this);
}

template<typename T>
bool Matrix<T>::operator==(const Matrix<T> &matrix) {
    if (this->getWidth() != matrix.getWidth()) {
        return false;
    }
    if (this->getHeight() != matrix.getHeight()) {
        return false;
    }

    for (unsigned heightCounter = 0; heightCounter < this->getHeight(); heightCounter++) {
        for (unsigned widthCounter = 0; widthCounter < this->getWidth(); widthCounter++) {
            if ((*this)[heightCounter][widthCounter] != matrix[heightCounter][widthCounter]) {
                return false;
            }
        }
    }

    return true;
}

template<typename T>
bool Matrix<T>::operator!=(const Matrix<T> &matrix) {
    return !(matrix == *this);
}

template<typename T>
T &Matrix<T>::operator()(const unsigned &height, const unsigned &column) {
    return this->elements[height * this->width + column];
}

template<typename T>
const T &Matrix<T>::operator()(const unsigned &height, const unsigned &column) const {
    return this->elements[height * this->width + column];
}

#endif //POO_PROIECT_MATRIX_CPP
