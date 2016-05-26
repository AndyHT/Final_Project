//
//  main.cpp
//  homework7-1
//
//  Created by Teng on 5/22/16.
//  Copyright © 2016 huoteng. All rights reserved.
//

#include <iostream>
using namespace std;

class Traveler {
    string name;
    
public:
    Traveler(string str) {
        name = str;
    }
    
    Traveler(const Traveler& t) {
        name = t.name;
    }
    
    void operator = (const Traveler& t) {
        name = t.name;
    }
};

class Pager {
    string belong;
   
public:
    Pager(string str) {
        belong = str;
    }
    
    Pager(const Pager& p) {
        belong = p.belong;
    }
    
    void operator = (const Pager& p) {
        belong = p.belong;
    }
};

class BusinessTraveler: public Traveler {
    Pager pager;
    
public:
    BusinessTraveler() : Traveler("default traveler"), pager("default pager") {}
    
    BusinessTraveler(string str) : Traveler("default traveler"), pager("default pager")  {
        pager = *new Pager(str);
    }
    
    BusinessTraveler(const BusinessTraveler& b) : Traveler("default traveler"), pager("default pager")  {
        pager = b.pager;
    }
    
    void operator = (const BusinessTraveler& b) {
        pager = b.pager;
    }
};

//int main(int argc, const char * argv[]) {
//    
//    
//    
//    return 0;
//}
