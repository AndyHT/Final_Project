//
//  main.cpp
//  homework2-4
//
//  Created by Teng on 4/6/16.
//  Copyright © 2016 huoteng. All rights reserved.
//

#include <iostream>
using namespace std;

struct Student
{
    string name;
    string sex;
    int age;
    
    friend ostream &operator<<( ostream &output, const Student &stu ){
        output << "Name:" << stu.name << ",Sex:" << stu.sex << ",Age:" << stu.age;
        return output;
    }
};

int main(int argc, const char * argv[]) {
    
    Student stu1 = Student();
    stu1.name = "Liming";
    stu1.sex = "male";
    stu1.age = 20;
    cout << "stu1 message:\n" << stu1 <<endl;
    
    Student stu2 = Student();
    stu2.name = "Xiaohong";
    stu2.sex = "female";
    stu2.age = 19;
    cout << "stu2 message:\n" << stu2 <<endl;
    
    Student* stu1p = &stu1;
    Student* stu2p = &stu2;
    
    stu1p->name = "Lihua";
    stu1p->sex = "female";
    stu1p->age = 13;
    cout << "stu1 message after modify:\n" << *stu1p <<endl;
    
    stu2p->name = "Guihua";
    stu2p->sex = "male";
    stu2p->age = 20;
    cout << "stu2 message after modify:\n" << *stu2p <<endl;
    
    
    return 0;
}
