
#include "TestRecur.h"


TestRecur::TestRecur()
{
    for (int i=0; i<26; ++i)
    {
        m_Map_DigToAZ.insert( pair<int, char>(1+i, 'A'+i) );
        //cout<<"m_Map_DigToAZ."<<i+1<<":"<<m_Map_DigToAZ[i+1]<<endl;
    }
    
    memset(rectangle, 0, 10*10);
    M=N=0;
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

/*
例4：给定一个由0-9组成的字符串，1可以转化成A，2可以转化成B。依此类推。。
25可以转化成Y，26可以转化成z，给一个字符串，返回能转化的字母串的有几种？

f(n):
if next2>26 or next2 ==0:
    return  f(i-1) 
if 1<=next2<=26:
    return f(i-1) + f(i-2)
*/
int TestRecur::FibsDigToAZ(int n, string gStr) //递归
{
    
    cout<<endl<<"begin"<<gStr.substr(0, n)<<endl;
    string getStr = gStr.substr(0, n);
    int temp = 0;
    
    if (getStr.length() < 1)
    {
        return 0;
    }
    else if (getStr.length() == 1)
    {
        int tmp = atoi(getStr.substr(0, n).c_str());
        if (tmp >=1 && tmp <=26)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (getStr.length() == 2)
    {
        int tmp = atoi(getStr.substr(0, n).c_str());
        if (tmp>=1 && tmp <=26)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
    
    const char* pStr = getStr.substr(n-2, 2).c_str();
    cout<<pStr<<endl;
    
    int next2 = atoi(pStr);
    if (next2>=1 && next2 <=26)
    {
        return FibsDigToAZ(n-1, gStr) + FibsDigToAZ(n-2, gStr);
    }
    else
    {
        return FibsDigToAZ(n-1, gStr);
    }
    
}

//自顶向下动态规划
int TestRecur::FibsDigToAZ2(int n, string gStr, int known[])
{
    if (known[n]>=0)
    {
        return known[n];
    }
    
    cout<<endl<<"begin"<<gStr.substr(0, n)<<endl;
    string getStr = gStr.substr(0, n);
    int temp = 0;
    
    if (getStr.length() < 1)
    {
        temp = 0;
    }
    else if (getStr.length() == 1)
    {
        int tmp = atoi(getStr.substr(0, n).c_str());
        if (tmp >=1 && tmp <=26)
        {
            temp = 1;
        }
        else
        {
            temp = 0;
        }
    }
    else if (getStr.length() == 2)
    {
        int tmp = atoi(getStr.substr(0, n).c_str());
        if (tmp>=1 && tmp <=26)
        {
            temp = 2;
        }
        else
        {
            temp = 1;
        }
    }
    else
    {
    
        const char* pStr = getStr.substr(n-2, 2).c_str();
        cout<<pStr<<endl;
        
        int next2 = atoi(pStr);
        if (next2>=1 && next2 <=26)
        {
            temp = FibsDigToAZ2(n-1, gStr, known) + FibsDigToAZ2(n-2, gStr, known);
        }
        else
        {
            temp = FibsDigToAZ2(n-1, gStr, known);
        }
    }
    
    
    cout<<"known["<<n<<"]="<<known[n]<<endl;
    known[n] = temp;
    cout<<"known["<<n<<"]="<<known[n]<<endl;
    return temp;
}


/*
    给一个由数字组成的矩阵，初始在左上角，要求每次只能向下或向右移动，
    路径和就是经过的数字全部加起来，求可能的最小路径和
    MinDirNum(i,j) = min(MinDirNum(i, j-1), MinDirNum(i-1, j)) +v[i][j]
*/
int TestRecur::GetMinDir()
{
    FILE *fp = freopen("ini.txt", "r", stdin);
    
    string info;
    
    while(cin>>info)
    {
        memset(rectangle, 0, 10*10); //record
        memset(record, 0, 10*10);
        M=N=0;
    
        cout<<"info:"<<info<<endl;
        if (info.find("*"))
        {
            //get M N
            const char* pInfo = info.c_str();
            M = atoi(&pInfo[0]);
            N = atoi(&pInfo[2]);
        }
        cout<<"M="<<M<<", N="<<N<<endl;
        
        //int rec[M][N] = {0};
        for(int i=0; i<M; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                cin>>rectangle[i][j];
                cout<<rectangle[i][j];
            }
            cout<<endl;
        }
        
        //calculate
        int ret = 0;
        ret = MinDirNum(M-1, N-1);
        cout<<"ret = "<<ret<<endl;
        
        cout<<"record:"<<endl;
        for(int i=0; i<M; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                 
                cout<<record[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    fclose(fp);
}
    
    
int TestRecur::MinDirNum(int m, int n)
{
    /*
    cout<<"***********"<<endl;
    
    for(int i=0; i<m; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            
            cout<<rectangle[i][j];
        }
        cout<<endl;
    }
    */
    
    //MinDirNum(i,j) = min(MinDirNum(i, j-1), MinDirNum(i-1, j)) +v[i][j]
    if(record[m][n]>0)
    {
        return record[m][n];
    }
    
    int tmp = 0;
    if (m == 0 && n == 0)
    {
        tmp = rectangle[m][n];
    }
    else if (m == 0 && n != 0)
    {
        tmp = MinDirNum(m, n-1) + rectangle[m][n];
    }
    else if (m != 0 && n == 0)
    {
        tmp = MinDirNum(m-1, n) + rectangle[m][n];
    }
    else
    {
        int up = MinDirNum(m-1, n);
        int left = MinDirNum(m, n-1);
        int mini = left <= up ? left : up;
        cout<<"up="<<up<<", left="<<left<<", mini = "<<mini<<endl;
        tmp = mini + rectangle[m][n];
    }
    
    record[m][n] = tmp;
    return tmp;
}



