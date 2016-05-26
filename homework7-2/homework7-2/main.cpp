//
//  main.cpp
//  homework7-2
//
//  Created by Teng on 5/22/16.
//  Copyright © 2016 huoteng. All rights reserved.
//

#include <iostream>
#include <ctime>

using namespace std;

class BaseClass {
public:
    virtual void test1() {
        
    }
    
    void test2() {
        
    }
};

class NewClass: public BaseClass {
    
};


int main() {

    BaseClass *pin;
    
    pin = new NewClass();
    
    clock_t t;
    
    t = clock();
    
    for (int i = 0; i < 1000000000; ++i) {
        pin->test1();
    }
    t = clock() - t;
    cout << "virtual function take time:" << ((float)t)/CLOCKS_PER_SEC << endl;
    
    t = clock();
    for (int i = 0; i < 1000000000; ++i) {
        pin->test2();
    }
    t = clock() - t;
    cout << "non-virtual function take time:" << ((float)t)/CLOCKS_PER_SEC << endl;

    return 0;
}