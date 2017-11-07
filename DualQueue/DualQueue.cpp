//
//  DualQueue.cpp
//  DualQueue
//
//  Created by Brian Morales on 10/26/17.
//  Copyright © 2017 Brian. All rights reserved.
//

#include <iostream>
#include <deque>
#include "DualQueue.hpp"
using namespace std;

MyIntDeque::MyIntDeque(int size){
    list = new int[size];           // setting the size of the list
    cap = size;
    for (int i = 0; i < cap; i++)   // initializing the list with -1
        list[i] = -1;
    
    length = 0;     // length, front, and back are all set to zero
    first = 0;      // to siginify the beginning of the deque.
    last = 0;
}
MyIntDeque:: ~MyIntDeque(){
    delete [] list; // deallocate memory
}

void MyIntDeque::push_back(int data){
    if (isFull())
        cout << "Deque is full.\n"; // check to see of deque is full
    else{
        if(isEmpty()){              // if empty then initialize first element
            list[last] = data;      // to data. Then increase the length.
            length++;
        }
        else {
            last = last + 1;        // else increase last by one.
            list[last] = data;      // set the next last element to data.
            length++;               // increase the length by one.
        }
    }
}

void MyIntDeque::push_front(int data){
    if (isFull())
        cout << "Deque is full.\n"; // Flag if deque is full.
    else {
        if (isEmpty()){             // Flag if deque is empty.
            list[first] = data;     // if empty initialize firs element
            length++;               // to data. Then increase length by one.
        }
        else {
            last = first;           // set last element to first element. Since deque will be shifting to the right.
            int temporaryData1 = list[last];    // Set temporaryData1 to first value in deque.
            int temporaryData2 = 0;             // Create a temp2 and set to zero.
            while(last != length){              // While last does not equel length keep iterating.
                last++;                         // Increase last by one.
                temporaryData2 = list[last];    // Set temp2 to the second value and so on.
                list[last] = temporaryData1;    // Set second element to the previous value and so on.
                temporaryData1 = temporaryData2;// Replace the first value with the second value and so on.
            }
            list[first] = data;     // Once done, all values have been shifted to the right and set first element to data.
            length++;               // Notice how didn't mess with 'first' variable. Increase length.
        }                           // Also last is set back to the last value.
    }
}

void MyIntDeque::pop_back(){
    if (isEmpty())
        cout << "Deque is empty.\n";// Flag if empty.
    else{
        list[last] = -1;            // Set last element to -1.
        last--;                     // Decrease last becuase we popped a value out.
        length--;                   // Decrease length.
    }
}

void MyIntDeque::pop_front(){
    if (isEmpty())
        cout << "Deque is empty.\n";// Flag if empty.
    else {
        int first = last;           // Set first to last.
        int temp1 = list[last];     // Set temp1 to last value.
        int temp2 = 0;              // Create a temp2 and set to zero.
        list[last] = -1;            // Set last element to -1 since the deque will be shifting to the left.
        while (first != 0){         // While first does not equel zero.
            first--;                // Decrease first.
            temp2 = list[first];    // Set temp2 second to last element.
            list[first] = temp1;    // Set second to last element to the temp1 value and so on.
            temp1 = temp2;          // Set temp1 to temp2.
        }
        last--;                     // Oonce done, all elements have been shifted to the left
        length--;                   // so we decrase last value. Decrease length.
    }                               // First is set back to the first value. 
}

int MyIntDeque::size(){
    return length;                  // Returns current size of the deque.
}

int MyIntDeque::front(){
    return list[first];             // Returns the first value in the deque.
}

int MyIntDeque::back(){
    return list[last];              // Returns the last value in the deque.
}

bool MyIntDeque::isFull(){
    return length == cap;           // Flags if the size of the deque has reached its limit.
}

bool MyIntDeque::isEmpty(){
    return list[first] == -1;       // Flags if it is empyt.
}

void MyIntDeque::clear(){
    for (int i = 0; i < cap; i++){  // Clears, does not delete, the whole deque
        list[i] = -1;               // and sets it to -1.
        length = 0;                 // Reset size to zero.
    }
}

void MyIntDeque::printFunc(){
    for (int i = 0; i < length; i++)
        cout << list[i] <<"-> "; 
}
