//
//  main.cpp
//  homework8-2
//
//  Created by Teng on 6/2/16.
//  Copyright © 2016 huoteng. All rights reserved.
//

#include <iostream>
using namespace std;

template <class numtype>
class Matrix {
public:
    
    // 用x初始化m行n列的矩阵
    Matrix(int m, int n, numtype x) {
        rowNum = m;
        columnNum = n;
        
        p = NULL;
        for (int i = 0; i < rowNum; i++) {
            p[i] = new numtype[columnNum];
        }
        
        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < columnNum; j++) {
                p[i][j] = x;
            }
        }
    }
    
    Matrix(numtype* a, int row, int col) {
        rowNum = row;
        columnNum = col;
        
        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < columnNum; j++) {
                p[i][j] = a[i*j + j];
            }
        }
    }
    
    void multiply(const Matrix& anotherMatrix) {
        Matrix resultMatrix = *new Matrix(rowNum, anotherMatrix->columnNum, 0);
        
        if (rowNum != anotherMatrix->columnNum || columnNum != anotherMatrix->rowNum) {
            cout << "" <<endl;
            return;
        }
        
        for (int i = 0; i < rowNum; ++i) {
            for (int j = 0; j < anotherMatrix->columnNum; ++j) {
                int index = 0;
                while (index < columnNum) {
                    resultMatrix.p[i][j] += p[i][index] * anotherMatrix.p[index][j];
                    index++;
                }
            }
        }
        for (int i = 0; i < rowNum; ++i) {
            for (int j = 0; j < anotherMatrix->columnNum; ++j) {
                p[i][j] = resultMatrix.p[i][j];
            }
        }
        
    }
    
    void add(const Matrix& anotherMatrix) {
        if (rowNum != anotherMatrix.rowNum || columnNum != anotherMatrix->columnNum) {
            cout << "" <<endl;
            return;
        }
        
        for (int i = 0; i < rowNum; ++i) {
            for (int j = 0; j < columnNum; ++j) {
                p[i][j] += anotherMatrix.p[i][j];
            }
        }
    }
    
    void print() {
        for (int i = 0; i < rowNum; ++i) {
            for (int j = 0; j < columnNum; ++j) {
                cout << p[i][j] << '\t';
            }
            cout <<endl;
        }
    }
    
    Matrix& operator+=(const Matrix& anotherMatrix) {
        add(anotherMatrix);
        
        return *this;
    }
    
    float& operator() (int row, int col) {
        return p[row][col];
    }
    
    float operator() (int row, int col) const {
        return p[row][col];
    }
    
    ~Matrix() {
        delete[] p;
    }
private:
    int rowNum;
    int columnNum;
    numtype **p;
};