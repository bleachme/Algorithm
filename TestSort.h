#ifndef TEST_SORT_H
#define TEST_SORT_H

#include "common.h"

template <typename T>

class TestSort
{
public:
    TestSort();
    ~TestSort();
    
    //int prin(int vec[], int n);
    
    //冒泡
    int BubbleSort(T vec[], int n);
    int BubbleSort2(T vec[], int n);
    
    
//private:
  
};

//typedef TestSort<int> TestSortInt;

template <typename T>
int prinMe(T vec[], int n)
{
    for (int i=0; i<n; ++i)
    {
        cout<<vec[i]<<", ";
    }
    cout<<endl;
    
    return 0;
}








#endif