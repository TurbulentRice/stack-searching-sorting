//
//  StackModel.cpp
//  TemplateLibrary
//
//  Created by Sean Russell on 4/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <string>
#include "StackModel.h"

// constructor creates new stack object of size max
template <typename Type>
stack<Type>::stack()
{
    top = 0;
    top_item = -1;
    size = max;
}

// isempty() checks if stack is empty
template <typename Type>
bool stack<Type>::isempty()
{
    return (top == 0);
}

// isfull() checks if stack is full
template <typename Type>
bool stack<Type>::isfull()
{
    return (top == size);
}

// length() returns number of items stored in container (top)
template <typename Type>
int stack<Type>::length()
{
    return top;
}

// capacity() returns size capacity of container (size)
template <typename Type>
int stack<Type>::capacity()
{
    return size;
}

// at() returns item at loc
template <typename Type>
Type stack<Type>::at(int loc)
{
    return container[loc];
}

// last() returns last item in container
template <typename Type>
Type stack<Type>::last()
{
    return container[top_item];
}

// first() returns first item in container
template <typename Type>
Type stack<Type>::first()
{
    return container[0];
}

// middle() returns item in middle of container
template <typename Type>
Type stack<Type>::middle()
{
    return container[(top_item / 2)];
}

// puton() if there is room, adds item to back of container
template <typename Type>
bool stack<Type>::puton(Type item)
{
    if (top < size)
    {
        // adds item to current empty space
        // moves top to next empty space
        container[top++] = item;
        top_item++;
        return true;
    }
    else return false;
}

// putin() if not full, pushes everything back and adds item at beginning
template <typename Type>
bool stack<Type>::putin(Type item)
{
    if (!isfull())
    {
        
    }
    else return false;
}

// insert() if not full, pushes everything after loc back and adds item at loc
template <typename Type>
bool stack<Type>::insert(Type item, int loc)
{
    if (!isfull())
    {
        
    }
    else return false;
}

// pop() if not empty, moves top down one
template <typename Type>
bool stack<Type>::pop()
{
    if (!isempty())
    {
        --top;
        --top_item;
        return true;
    }
    else return false;
}

// remove() if not empty, pulls everything after loc down one
template <typename Type>
bool stack<Type>::remove(int loc)
{
    if (!isempty())
    {
        
    }
    else return false;
}

