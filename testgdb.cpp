/*gdbStep.c*/
#include "TestRecur.h"
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
    TestRecur testRec;
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
    
    
    
    
    //count(c);

    //while(1);
    return 0;
}