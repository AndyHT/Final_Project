//
//  main.cpp
//  homework1-2
//
//  Created by Teng on 4/7/16.
//  Copyright © 2016 huoteng. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    int table[n][n];
    
    int tmp1 = 1;
    int tmp2 = 1;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j < k - 1) {
                table[i][j] = tmp1++;
            } else {
                table[i][j] = n * (k - 1) + tmp2++;
                if (j == k - 1) {
                    sum += table[i][j];
                }
            }
        }
    }
    
    cout << sum <<endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << table[i][j] << "\t";
        }
        cout <<endl;
    }
    
    return 0;
}
