//
//  main.cpp
//  homework2-2
//
//  Created by Teng on 4/5/16.
//  Copyright © 2016 huoteng. All rights reserved.
//

#include <iostream>
#include <random>
#include <float.h>
#include <vector>

using namespace std;

int read(){
    char c;
    while( c= getchar(), !isdigit(c) );
    int r= c-'0';
    while( c= getchar(), isdigit(c) ) r= r*10 + c-'0';
    return r; 
}

int main(int argc, const char * argv[]) {
    vector<float> rawVector(25);
    default_random_engine e(time(0));
    cout << "请输入25个数的最小值:" <<endl;
    float min,max;
    cin >> min;
    if (!cin) {
        cout << "输入错误" <<endl;
        return -1;
    }
    cout << "请输入25个数的最大值" <<endl;
    cin >> max;
    if (!cin) {
        cout << "输入错误" <<endl;
        return -1;
    }
    
    cout << "原vector为:" <<endl;
    for (int i = 0; i < 25; ++i) {
        uniform_real_distribution<double> generator(min, max);
        rawVector[i] = generator(e);
        cout << rawVector[i] <<"\n";
    }
    cout <<endl;
    cout << "计算结果为:" <<endl;
    for (int i = 0; i < 25; ++i) {
        float tmp = powf(rawVector[i],2.0);
        if (tmp == INFINITY) {
            cout << "平方后溢出" <<endl;
            rawVector[i] = INFINITY;
        } else {
            cout << tmp << endl;
            rawVector[i] = tmp;
        }
    }
    
    return 0;
}
