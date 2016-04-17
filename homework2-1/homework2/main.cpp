//
//  main.cpp
//  homework2
//
//  Created by Teng on 4/5/16.
//  Copyright © 2016 huoteng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "请输入文件绝对路径及文件名\n";
    string filePath = "";
    cin>>filePath;
    cout << "输入的路径:" << filePath <<endl;
    ifstream readFile(filePath.c_str());
    if (!readFile) {
        cout<<"文件打开失败:"<< filePath <<endl;
        return -1;
    } else {
        cout << "Read from path...." <<endl;
        
        string charData;
        int charSum = 0;
        while (readFile >> charData) {
            //判断that
            if (charData == "that") {
                charSum++;
            }
        }
        cout << "that出现的次数为:" << charSum <<endl;
        return 0;
    }
}
