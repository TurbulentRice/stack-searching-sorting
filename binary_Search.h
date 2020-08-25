//
//  binary_Search.h
//  Sorting
//
//  Created by Sean Russell on 3/16/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Sorting_binary_Search_h
#define Sorting_binary_Search_h
using namespace std;

// gets sorted vector, search key, lower bound, and upper bound
int binary_Search(vector<int> array, int element, int low, int high)
{
    // continues while search still valid
    if (low <= high){
        
        // element is mid
        int mid = (low + high) / 2;
        if (element == array[mid]){
            return (mid);
        }
        
        // element is larger than mid
        else if (element > array[mid]){
            return binary_Search(array, element, (mid + 1), high);
        }
        
        // element is smaller than mid
        else if (element < array[mid]){
            high = mid;
            return binary_Search(array, element, low, (mid - 1));
        } 
    }
    
    return (-1); // search failed if upper sub is smaller than lower sub
}

#endif
