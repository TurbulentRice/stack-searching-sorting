//
//  StackModel.h
//  TemplateLibrary
//
//  Created by Sean Russell on 4/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TemplateLibrary_StackModel_h
#define TemplateLibrary_StackModel_h
using namespace std;

// vector stack

template <typename Type>
class stack
{
    Type* container;    // array of Type
    int top;            // index of next open space
    int top_item;       // index of top item
    
public:
    // constructors
    stack();
    // check methods
    bool isempty();
    // get methods
    int size();             // returns # of elements (top)
    Type at(int);           // returns element at given index
    Type last();            // returns last element
    Type first();           // returns first element
    Type middle();          // returns middle element
    Type* copy();           // returns a pointer array of Type
    // add methods
    void push(Type);        // adds to back
    void putin(Type);       // adds to front
    void insert(Type, int); // inserts this(Type) here(int)
    void put(Type, int);    // puts this(Type) here(int)
    // remove methods
    bool pop();
    bool remove(int);
    void clear();
    // mutation methods
    void swap(int, int);
    void sort();
    void scramble();
};

// constructor creates empty stack object
template <typename Type>
stack<Type>::stack()
{
    container = new Type[0];
    top = 0;
    top_item = -1;
}

// isempty() returns bool indicating whether stack is empty
template <typename Type>
bool stack<Type>::isempty()
{
    if (top == 0) return true;
    else if (top > 0) return false;
}

// size() returns number of items stored in container (top)
template <typename Type>
int stack<Type>::size()
{
    return top;
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

// get() returns pointer array of Type
template <typename Type>
Type* stack<Type>::copy()
{
    return container;
}

// push() copies container, increases size
template <typename Type>
void stack<Type>::push(Type item)
{
    // create new array of size top + 1
    Type* new_container = new Type[top + 1];
    
    // copy elements of old array into new one
    for (int i = 0; i < top; ++i)
    {
        new_container[i] = container[i];
    }
    
    // clear old container
    delete [] container;
    
    // add new item and copy into container
    new_container[top] = item;
    top++;
    top_item++;
    container = new Type[top];
    for (int i = 0; i < top; ++i)
    {
        container[i] = new_container[i];
    }
    
    delete [] new_container;
}

// putin() creates new array, pushes everything back and adds item at beginning
template <typename Type>
void stack<Type>::putin(Type item)
{
    // create new array of size top + 1
    Type* new_container = new Type[top + 1];
    
    // copy elements of old array into new one
    for (int i = 0; i < top; ++i)
    {
        new_container[i + 1] = container[i];
    }
    
    // clear old container
    delete [] container;
    
    // add new item and copy into container
    new_container[0] = item;
    top++;
    top_item++;
    container = new Type[top];
    for (int i = 0; i < top; ++i)
    {
        container[i] = new_container[i];
    }
    
    delete [] new_container;
}

// insert() creates new array, pulls everything after loc back and adds item at loc
template <typename Type>
void stack<Type>::insert(Type item, int loc)
{
    // create new array of size top + 1
    Type* new_container = new Type[top + 1];
    
    // copy elements of old array into new one
    for (int i = 0; i < top; ++i)
    {
        new_container[i] = container[i];
    }
    
    for (int i = top + 1; i > loc; --i)
    {
        new_container[i] = new_container[i - 1];
    }
    
    // clear old container
    delete [] container;
    
    // add new item and copy into container
    new_container[loc] = item;
    top++;
    top_item++;
    container = new Type[top];
    for (int i = 0; i < top; ++i)
    {
        container[i] = new_container[i];
    }
    
    delete [] new_container;
}

// put() changes an item at a specified index
template <typename Type>
void stack<Type>::put(Type item, int loc)
{
    container[loc] = item; 
}

// pop() if not empty, remove() top element
template <typename Type>
bool stack<Type>::pop()
{
    if (!isempty())
    {
        remove(top_item);
        return true;
    }
    else return false;
}

// remove() if not empty, pulls everything after loc down one and deletes element
template <typename Type>
bool stack<Type>::remove(int loc)
{
    if (!isempty())
    {
        // create new array of size top - 1
        Type* new_container = new Type[top - 1];
        
        // pulls everything after loc in container down one
        for (int i = loc; i < top; ++i)
        {
            container[i] = container[i + 1];
            i++;
        }
        
        // copy elements of old array into new one
        for (int i = 0; i < top - 1; ++i)
        {
            new_container[i] = container[i];
        }
        
        // clear old container
        delete [] container;
        
        // change size and copy into container
        top--;
        top_item--;
        container = new Type[top];
        for (int i = 0; i < top; ++i)
        {
            container[i] = new_container[i];
        }
        
        delete [] new_container;
        
        return true;
    }
    else return false;
}

// clear() deletes allocated memory
template <typename Type>
void stack<Type>::clear()
{
    delete [] container;
    
    cout << "Stack cleared!" << endl;
    
    top = 0;
    top_item = -1;
    return;
}

// swap() switches the condents of two indeces
template <typename Type>
void stack<Type>::swap(int a, int b)
{
    int t = container[a];
    container[a] = container[b];
    container[b] = container[t];
    return;
}

// scramble() randomizes order of items
template <typename Type>
void stack<Type>::scramble()
{
    return;
}

// sorts() sorts container in ascending order
template <typename Type>
void stack<Type>::sort()
{
    for (int start = 1; start < top; ++start)
    {
        
        Type insert = at(start);
        int here = start;
        
        while ((here > 0) && (at(here - 1) > insert))
        {
            swap(here, here - 1);
            --here;    
        }
        put(insert, here);
    }
}

#endif
