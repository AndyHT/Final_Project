//
//  main.cpp
//  homework3-1
//
//  Created by Teng on 4/12/16.
//  Copyright © 2016 huoteng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int max(vector<int> vec) {
    int maxInt;
    
    if (vec.size() > 0) {
        maxInt = vec[0];
    } else {
        return NULL;
    }
    
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] > maxInt) {
            maxInt = vec[i];
        }
    }
    
    return maxInt;
}

float max(vector<float> vec) {
    float maxFloat;
    
    if (vec.size() > 0) {
        maxFloat = vec[0];
    } else {
        return NULL;
    }
    
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] > maxFloat) {
            maxFloat = vec[i];
        }
    }
    
    return maxFloat;
}

string max(vector<string> vec) {
    string maxString;
    
    if (vec.size() > 0) {
        maxString = vec[0];
    } else {
        return NULL;
    }
    
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] > maxString) {
            maxString = vec[i];
        }
    }
    
    return maxString;
}

int max(int array[], int size) {
    
    int maxInt;
    
    if (size > 0) {
        maxInt = array[0];
    } else {
        return NULL;
    }
    
    for (int i = 0; i < size; ++i) {
        if (array[i] > maxInt) {
            maxInt = array[i];
        }
    }
    
    return maxInt;
}

float max(float array[], int size) {
    float maxFloat;
    
    if (size > 0) {
        maxFloat = array[0];
    } else {
        return NULL;
    }
    
    for (int i = 0; i < size; ++i) {
        if (array[i] > maxFloat) {
            maxFloat = array[i];
        }
    }
    
    return maxFloat;
}

string max(string array[], int size) {
    string maxString;
    
    if (size > 0) {
        maxString = array[0];
    } else {
        return NULL;
    }
    
    for (int i = 0; i < size; ++i) {
        if (array[i] > maxString) {
            maxString = array[i];
        }
    }
    
    return maxString;
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
