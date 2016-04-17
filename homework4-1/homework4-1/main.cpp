//
//  main.cpp
//  homework4-1
//
//  Created by Teng on 4/17/16.
//  Copyright © 2016 huoteng. All rights reserved.
//  /Users/huoteng/Desktop/test.txt

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
#include <set>

using namespace std;

struct Word {
    int appearNum;
    string word;
};

bool compareLex(const Word &x, const Word &y) {
    return x.word < y.word;
}

bool compareFre(const Word &x, const Word &y) {
    if (x.appearNum > y.appearNum) {
        return true;
    } else if(x.appearNum == y.appearNum) {
        return x.word < y.word;
    } else {
        return false;
    }
}

int main(int argc, const char * argv[]) {
    string path;
//    cin>>path;
    path = "/Users/huoteng/Desktop/test.txt";//for test
    ifstream inputFile(path);
    if (!inputFile) {
        cout << "不可以打开文件" << endl;
        exit(1);
    }
    
    string dataStr;
    vector<Word> wordsVec;
    set<string> wordsSet;
    while (inputFile>>dataStr) {
        transform(dataStr.begin(), dataStr.end(), dataStr.begin(), ::tolower);
        
        if (wordsSet.find(dataStr) != wordsSet.end()) {
            //word 在set中存在，vector中计数
            for (int i = 0; i < wordsVec.size(); ++i) {
                if (dataStr.compare(wordsVec[i].word) == 0) {
                    wordsVec[i].appearNum++;
                    break;
                }
            }
        } else {
            Word newWord;
            newWord.word = dataStr;
            newWord.appearNum = 1;
            wordsSet.insert(dataStr);
            wordsVec.insert(wordsVec.end(), newWord);
        }
    }
    inputFile.close();
    
    ofstream output1("3_1_lout.txt");
    
    sort(wordsVec.begin(), wordsVec.end(), compareLex);
    for (int i = 0; i < wordsVec.size(); ++i) {
        output1 << wordsVec[i].word << ": " << wordsVec[i].appearNum <<endl;
    }
    output1.close();
    
    ofstream output2("3_1_2lout.txt");
    sort(wordsVec.begin(), wordsVec.end(), compareFre);
    for (int i = 0; i < wordsVec.size(); ++i) {
        output2 << wordsVec[i].word << ": " << wordsVec[i].appearNum <<endl;
    }
    output2.close();
    
}
