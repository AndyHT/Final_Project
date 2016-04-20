//
//  main.cpp
//  homework4-2
//
//  Created by Teng on 4/17/16.
//  Copyright © 2016 huoteng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool compareLen(const string &x, const string &y) {
    return x.length() < y.length();
}

int main(int argc, const char * argv[]) {
    string path;
    cin>>path;
//    path = "/Users/huoteng/Desktop/test.txt";//for test
    ifstream inputFile(path);
    if (!inputFile) {
        cout << "不可以打开文件" << endl;
        exit(1);
    }
    
    string dataStr;
    vector<string> wordsVec;
    while (inputFile>>dataStr) {
        transform(dataStr.begin(), dataStr.end(), dataStr.begin(), ::tolower);
        
        bool isExist = false;
        for (int i = 0; i < wordsVec.size(); ++i) {
            if (dataStr.compare(wordsVec[i]) == 0) {
                isExist = true;
                break;
            }
        }
        if (!isExist) {
            wordsVec.insert(wordsVec.end(), dataStr);
        }
    }
    inputFile.close();
    
    ofstream output1("3_2out.txt");
    sort(wordsVec.begin(), wordsVec.end(), compareLen);
    for (int i = 0; i < wordsVec.size(); ++i) {
        output1 << wordsVec[i] <<endl;
    }
    output1.close();
}
