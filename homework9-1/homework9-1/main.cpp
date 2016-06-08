//
//  main.cpp
//  homework9-1
//
//  Created by Teng on 6/2/16.
//  Copyright © 2016 huoteng. All rights reserved.
//

#include <iostream>
using namespace std;

struct Getting_From_EmptyException : public exception {
    const char * what () const throw () {
        return "Trying to get elements from an empty stack.";
    }
};

struct Filling_To_FullException : public exception {
    const char * what () const throw () {
        return "Trying to fill elements to a full stack.";
    }
};

template <class T>
class Stack {
public:
    Stack();
    void push(const T& element);
    T pop();
    int size();
    bool empty();
    bool full();
    T peek();   // 查看栈顶对象
    void print();

    
private:
    const T** arr;
    int n; // count
    int capacity = 20;
};

template <class T>
void Stack<T>::push(const T& element) {
    // 判断剩余空间
    if (this->size() == this->capacity) {
        throw Filling_To_FullException();
    }
    
    //push
    arr[n++] = new T(element);
}

template <class T>
T Stack<T>::pop() {
    
    if (size() == 0) {
        throw Getting_From_EmptyException();
    }

    T tmp(*arr[--n]);
    delete arr[n];

    return tmp;
}

template <class T>
inline bool Stack<T>::empty() {
    return n == 0;
}

template <class T>
inline int Stack<T>::size() {
    return n;
}

template <class T>
inline bool Stack<T>::full() {
    return n == size();
}

template <class T>
inline T Stack<T>::peek() {
    if (size() == 0) {
        throw Getting_From_EmptyException();
    }
    
    T tmp(*arr[n-1]);
    
    return tmp;
}

template <class T>
inline void Stack<T>::print() {
    for (int i = 0; i < size(); ++i) {
        cout << "第" << (size() - i) << "个元素：" << *arr[i] << '\n' <<endl;
    }
}
