//
//  main.cpp
//  homework3-2
//
//  Created by Teng on 4/12/16.
//  Copyright © 2016 huoteng. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
T max(vector<T> vec) {
    T maxValue;
    
    if (vec.size() > 0) {
        maxValue  = vec[0];
    } else {
        return NULL;
    }
    
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] > maxValue) {
            maxValue = vec[i];
        }
    }
    
    return maxValue;
}

template<typename T>
T max(T array[], int size) {
    T maxValue;
    
    if (size > 0) {
        maxValue = array[0];
    } else {
        return NULL;
    }
    
    for (int i = 0; i < size; ++i) {
        if (array[i] > maxValue) {
            maxValue = array[i];
        }
    }
    
    return maxValue;
}

int main(int argc, const char * argv[]) {
    string testStrArray[] = {"a", "aaa", "aksdfja", "cksd", "aksdfjk", "qwekr", "qwer"};
    int size = 7;
    
    string result = max(testStrArray, size);
    cout << "max string result:" << result <<endl;
    
    vector<string> testStrVec(testStrArray, testStrArray+5);
    
    result = max(testStrVec);
    cout << "max string result:" << result <<endl;
    
    
    return 0;
}