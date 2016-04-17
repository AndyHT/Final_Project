//
//  main.cpp
//  homework2-3
//
//  Created by Teng on 4/6/16.
//  Copyright © 2016 huoteng. All rights reserved.
//

#include <iostream>

using namespace::std;


void fun1(string* str1) {
    *str1 = "test func1";
}

void fun2(string& str2) {
    str2 = "test func2";
}

int main(int argc, const char * argv[]) {
    string strRaw = "HelloWorld";
    
    cout << "strRaw is \"" << strRaw << "\" before fun1" << endl;
    fun1(&strRaw);
    cout << "strRaw is \"" << strRaw << "\" after fun1" << endl;
    
    strRaw = "HelloWorld";
    cout << "strRaw is \"" << strRaw << "\" before fun2" << endl;
    fun2(strRaw);
    cout << "strRaw is \"" << strRaw << "\" after fun2" << endl;
    
    
}



