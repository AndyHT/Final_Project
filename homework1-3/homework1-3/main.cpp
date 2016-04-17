//
//  main.cpp
//  homework1-3
//
//  Created by Teng on 4/7/16.
//  Copyright © 2016 huoteng. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    char chars[n];
    cin >> chars;
    
    int sum = 0;
    int newNotDown = 0;
    int actionLocation = 0;
    char actionBefore = '\t';
    
    for (int i = 0; i < n; ++i) {
        if (actionBefore == '\t' && chars[i] == 'R') {
            sum += newNotDown;
            newNotDown = 0;
            actionBefore = chars[i];
            actionLocation = i;
        } else if (actionBefore == '\t' && chars[i] == 'L') {
            newNotDown = 0;
            actionBefore = chars[i];
            actionLocation = i;
        } else {
            switch (chars[i]) {
                case '.':
                    newNotDown++;
                    break;
                case 'L':
                    if ((i - actionLocation)%2 == 0) {
                        sum++;
                    }
                    newNotDown = 0;
                    actionLocation = i;
                    actionBefore = 'L';
                    
                    break;
                case 'R':
                    sum += newNotDown;
                    newNotDown = 0;
                    actionLocation = i;
                    actionBefore = 'R';
                    break;
                default:
                    break;
            }
        }
    }
    if (actionBefore != 'R') {
        sum += newNotDown;
    }
    if (actionBefore == '\t') {
        cout << n <<endl;
    } else {
        cout << sum <<endl;
    }
    
    return 0;
}
