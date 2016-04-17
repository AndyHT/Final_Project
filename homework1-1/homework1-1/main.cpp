//
//  main.cpp
//  homework1-1
//
//  Created by Teng on 4/7/16.
//  Copyright © 2016 huoteng. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string inputStr;
    
    cin >> inputStr;
    if (inputStr.length() < 6) {
        cout << "NO" <<endl;
        return 0;
    } else {
        for (int i = 0 ; i < inputStr.length(); ++i) {
            if (inputStr.at(i) != '0' && inputStr.at(i) != '1') {
                cout << "NO" <<endl;
                return 0;
            }
        }
    }
    
    char charBefore = inputStr.at(0);
    int times = 1;
    
    for (int i = 1; i < inputStr.length(); ++i) {
        if (times <= 6) {
            switch (inputStr.at(i)) {
                case '0':
                    if (charBefore == '0') {
                        ++times;
                    } else {
                        times = 1;
                        charBefore = '0';
                    }
                    break;
                case '1':
                    if (charBefore == '1') {
                        ++times;
                    } else {
                        times = 1;
                        charBefore = '1';
                    }
                    break;
                default:
                    break;
            }
        } else {
            break;
        }
    }

    if (times > 6) {
        cout << "YES" <<endl;;
    } else {
        cout << "NO" <<endl;;
    }

    return 0;
}