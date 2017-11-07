//
//  main.cpp
//  DualQueue
//
//  Created by Brian Morales on 10/30/17.
//  Copyright © 2017 Brian. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include "DualQueue.hpp"
using namespace std;

int main() {
    MyIntDeque deque(5);
    
    deque.push_front(10);
    deque.push_front(14);
    deque.push_back(4);
    deque.push_front(6);
    deque.push_back(3);
}
