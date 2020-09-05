#include "TestSort.h"





template <typename T>
TestSort<T>::TestSort()
{
    
}

template <typename T>
TestSort<T>::~TestSort()
{
    
}

/*
template <typename T>
int TestSort<T>::prin(int vec[], int n)
{
    for (int i=0; i<n; ++i)
    {
        cout<<vec[i]<<", ";
    }
    cout<<endl;
    
    return 0;
}
*/

template <typename T>
int TestSort<T>::BubbleSort(T vec[], int n)
{
    for(int i=1; i<n; ++i)
    {
        for(int j=0; j<n-i; ++j)
        {
            if ( vec[j]>vec[j+1] )
            {
                swap(vec[j], vec[j+1]);
            }
        }
    }
    
    return 0;
}

template <typename T>
int TestSort<T>::BubbleSort2(T vec[], int n)
{
    for (int i=n-1; i>0; --i)
    {
        for(int j=0; j<i; ++j)
        {
            if ( vec[j]>vec[j+1] )
            {
                swap(vec[j], vec[j+1]);
            }
        }
    }
    
    return 0;
}



//模板类实例  如果实现放在头文件中，不需要再实例化
template class TestSort<int>;

