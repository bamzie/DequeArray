//
//  DualQueue.hpp
//  DualQueue
//
//  Created by Brian Morales on 10/26/17.
//  Copyright © 2017 Brian. All rights reserved.
//

#ifndef DualQueue_hpp
#define DualQueue_hpp
#include <stdio.h>

class MyIntDeque{
private:
    int* list;
    int cap;
    int length;
    int first;
    int last;
public:
    MyIntDeque(int size);
    ~MyIntDeque();
    void push_back(int);
    void push_front(int);
    void pop_back();
    void pop_front();
    int size();
    int front();
    int back();
    bool isFull();
    bool isEmpty();
    void clear();
    void printFunc(); 
};

#endif /* DualQueue_hpp */
