/*gdbStep.c*/
#include "TestRecur.h"
#include "TestSort.h"
#include "common.h"
/*计算简单乘法,这里没有考虑溢出*/


struct testStr
{
    string name;
};

struct testStr1
{
    string name1;
    string name2;
};

int add(int a, int b)
{
    int c = a + b;
    cout<<"add c="<<c<<endl;
    return c;
}
/*打印从0到num-1的数*/
int count(int num)
{
    int i = 0;
    if(0 > num)
        return 0;
    while(i < num)
    {
        printf("%d\n",i);
        i++;
    }
    return i;
}



int main(void)
{
/*    
    printf("size of testStr = %d\n", sizeof(testStr) );
    printf("size of testStr1 = %d\n", sizeof(testStr1) );//testStr1
    
    int a = 3;
    int b = 7;
    printf("it will calc a + b\n");
    int c = add(a,b);
    printf("%d + %d = %d\n",a,b,c);
 */   
    
    //递归 动态规划 斐波那契
    TestRecur testRec;
/*    
    for (int j=1; j<10; ++j)
    {
        cout<<"Fibs("<<j<<") = "<<testRec.Fibs(j)<<endl;
        cout<<"Fibs2("<<j<<") = "<<testRec.Fibs2(j)<<endl;
        cout<<"Fibs3("<<j<<") = "<<testRec.Fibs3(j)<<endl;
        //int FibsUpToDown(int n, int* known);
        int vec[j+1];
        fill(vec, vec+j+1, -1);
        cout<<"FibsUpToDown("<<j<<") = "<<testRec.FibsUpToDown(j, vec)<<endl<<endl;
    }
*/    
    
    
#if 0    
    /*
例4：给定一个由0-9组成的字符串，1可以转化成A，2可以转化成B。依此类推。。
25可以转化成Y，26可以转化成z，给一个字符串，返回能转化的字母串的有几种？

    */
    string getStr;
    cin>>getStr;
    
    int tmp[getStr.length()+1];
    fill(tmp, tmp+getStr.length()+1, -1);
    
    int num = testRec.FibsDigToAZ(getStr.length(), getStr);
    cout<<"num1="<<num<<endl;
    
    cout<<"/**************************/"<<endl;
    num = testRec.FibsDigToAZ2(getStr.length(), getStr, tmp);
    cout<<"num2="<<num<<endl;
    //count(c);
#endif  

    //testRec.GetMinDir();  
     

    TestSort<int> sortTest;
    int sortVec[10] = {2,1,5,3,0,7,6,5,5,6};
    sortTest.BubbleSort(sortVec, 10);
    prinMe(sortVec, 10);
    //sortTest.prin(sortVec, 10);
    
    int sortVec2[10] = {9,8,7,6,0,5,4,2,3,1};
    sortTest.BubbleSort2(sortVec2, 10);
    //prinMe<int>(sortVec2, 10);
    prinMe (sortVec2, 10);

    //while(1);
    return 0;
}


