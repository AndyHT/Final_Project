//
//  main.cpp
//  homework5-1
//
//  Created by Teng on 4/22/16.
//  Copyright © 2016 huoteng. All rights reserved.
//

#include <iostream>

using namespace std;

bool isSuccess(const char a, const char b, const char c, const char d) {

    int numA = (int)a;
    int numB = (int)b;
    int numC = (int)c;
    int numD = (int)d;
    
    int sum = numA + numB + numC + numD;
    
    if (sum != 162) {
        return true;
    }
    
    return false;
}

// #: 35, .:46

int main() {
    
    char input[4];
    char squre[4][4];
    for (int i = 0; i < 4; ++i) {
        cin >> input;
        for (int j = 0; j < 4; ++j) {
            squre[i][j] = input[j];
        }
    }
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (isSuccess(squre[i][j], squre[i+1][j], squre[i][j+1], squre[i+1][j+1])) {
                cout << "YES" <<endl;
                return 0;
            }
        }
    }
    
    cout << "NO"<<endl;
    
    return 0;
}
