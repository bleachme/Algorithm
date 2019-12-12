#ifndef TEST_RECUR_H
#define TEST_RECUR_H

class TestRecur
{
public:
    TestRecur();
    ~TestRecur();
    
    int Fibs(int n);
    int Fibs2(int n);
    int Fibs3(int n);
    
    int FibsUpToDown(int n, int known[]);
};

#endif