//
//  insertion_Sort.h
//  Sorting
//
//  Created by Sean Russell on 3/17/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TemplateLibrary_insertion_Sort_h
#define TemplateLibrary_insertion_Sort_h
#include "StackModel.h"
using namespace std;

// sorts a stack using insertion sort
void insertion_Sort(stack<int>& data)
{
    for (int start = 1; start < data.size(); ++start){
        
        int insert = data.at(start);
        int here = start;
        
        while ((here > 0) && (data.at(here - 1) > insert))
        {
            data.swap(here, here - 1);
            --here;            
        }
        data.put(insert, here);
    }
}

#endif
