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
    
    /*
    给定一个由0-9组成的字符串，1可以转化成A，2可以转化成B。依此类推。。
    25可以转化成Y，26可以转化成z，给一个字符串，返回能转化的字母串的有几种？
    */
    int FibsDigToAZ(int n, string gStr);
    int FibsDigToAZ2(int n, string gStr, int known[]);
    
    /*
    给一个由数字组成的矩阵，初始在左上角，要求每次只能向下或向右移动，
    路径和就是经过的数字全部加起来，求可能的最小路径和
    MinDirNum(i,j) = min(MinDirNum(i, j-1), MinDirNum(i-1, j)) +v[i][j]
    */
    int GetMinDir();
    int MinDirNum(int m, int n);
    
private:
    std::map<int, char> m_Map_DigToAZ;
    string result;
    
    int M;
    int N;
    int rectangle[10][10];
    int record[10][10];

};

#endif