//
//  main.cpp
//  homework8-1
//
//  Created by Teng on 6/2/16.
//  Copyright © 2016 huoteng. All rights reserved.
//

#include <iostream>
using namespace std;

template <class numtype>
class Example {
public:
    Example(numtype min, numtype max);
    Example(const numtype* array, int size);
    numtype& operator[](int index);
    bool operator==(const Example&) const;
    bool insert(const numtype*, int);
    bool insert(numtype);
    numtype min() const;
    numtype max() const;
    void min(numtype);
    void max(numtype);
    int count (numtype value) const;
private:
    int m_iSize;
    numtype* m_pdArray;
    numtype m_dMin;
    numtype m_dMax;
};