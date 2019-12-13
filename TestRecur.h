#ifndef TEST_RECUR_H
#define TEST_RECUR_H

#include "common.h"

class TestRecur
{
public:
    TestRecur();
    ~TestRecur();
    
    int Fibs(int n);
    int Fibs2(int n);
    int Fibs3(int n);
    
    int FibsUpToDown(int n, int known[]);
    
    
    int FibsDigToAZ(int n, string gStr);
    int FibsDigToAZ2(int n, string gStr, int known[]);
    
private:
    std::map<int, char> m_Map_DigToAZ;
    string result;

};

#endif