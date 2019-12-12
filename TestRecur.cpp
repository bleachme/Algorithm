
#include "TestRecur.h"
#include "common.h"

TestRecur::TestRecur()
{
    
}

TestRecur::~TestRecur()
{
    
}

//递归
int TestRecur::Fibs(int n)
{
    if ( n <= 0 ) return 0;
    if ( 1 == n ) return 1;
    
    return Fibs(n-1) + Fibs(n-2);
}

//自底向上动态规划
int TestRecur::Fibs2(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    
    int v[n] = {0};
    v[0] = v[1] = 1;
    
    for (int i=2; i<n; ++i)
    {
        v[i] = v[i-1] + v[i-2];
    }
    
    return v[n-1];
}

//自底向上动态规划 优化
int TestRecur::Fibs3(int n)
{
    int a=1,b=1;
    int tmp = 0;
    
    for (int i=2; i<n; ++i)
    {
        tmp = b;
        b = a+b;
        a = tmp;
    }
    
    return b;
}

//自顶向下的动态规划
int TestRecur::FibsUpToDown(int n, int known[])
{
    
    if (known[n] >= 0)
        return known[n];
    
    int tmp = 0;
    if (n <= 0) tmp = 0;
    else if (1 == n) tmp = 1;
    else if (n > 1) tmp = FibsUpToDown(n-1, known) + FibsUpToDown(n-2, known);
    
    known[n] = tmp;
    return tmp;
}

