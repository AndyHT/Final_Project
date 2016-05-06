//
//  main.cpp
//  homework6-2
//
//  Created by Teng on 5/5/16.
//  Copyright © 2016 huoteng. All rights reserved.
//

#include <iostream>

using namespace std;

class Matrix {
public:
    Matrix() {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin >> matrix[i][j];
            }
        }
    }
    
    Matrix(float a[16]) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                matrix[i][j] = a[4*i + j];
            }
        }
    }
    
    void multiply(const Matrix& anotherMatrix) {
        float resultArray[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        Matrix resultMatrix = *new Matrix(resultArray);
        
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                int index = 0;
                while (index < 4) {
                    resultMatrix.matrix[i][j] += matrix[i][index] * anotherMatrix.matrix[index][j];
                    index++;
                }
            }
        }
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                matrix[i][j] = resultMatrix.matrix[i][j];
            }
        }
        
    }
    
    void add(const Matrix& anotherMatrix) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                matrix[i][j] += anotherMatrix.matrix[i][j];
            }
        }
    }
    
    void print() {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cout << matrix[i][j] << '\t';
            }
            cout <<endl;
        }
    }
    
    Matrix& operator+=(const Matrix& anotherMatrix) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                matrix[i][j] += anotherMatrix.matrix[i][j];
            }
        }
        
        return *this;
    }
    
    float& operator() (int row, int column) {
        return matrix[row][column];
    }
    
    float operator()(int row, int column) const {
        return matrix[row][column];
    }
private:
    float matrix[4][4];
};

Matrix operator += (Matrix a, Matrix b) {
    a.add(b);
    return a;
}

//int main(int argc, const char * argv[]) {
//    
//    Matrix b = *new Matrix();
//    b.print();
//
//    float a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//    Matrix m1(a);
//    Matrix m2(a);
//    m1.multiply(m2);
//    m1.print();
//    /*
//     90 100 110 120
//     202 228 254 280
//     314 356 398 440
//     426 484 542 600
//     */
//    
//    return 0;
//}
