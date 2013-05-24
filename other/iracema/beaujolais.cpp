#include <iostream>
#include <cstdio>
#include <cstring>
#define t(x) (10+(x))

using namespace std;

int main()
{
    int a, b, n;
    int mval, cur, ret, tmax, tmin;
    int temp[50];
    while(cin >> n && n)
    {
        tmin = 50;
        memset(temp,0,sizeof(temp));
        for(int i=0;i<n;i++)
        {
            cin >> a >> b;
            if(a < tmin)
            {
                tmin = a;
                tmax = b;
            }
            temp[t(a)]++;
            temp[t(b+1)]--;
        }
        cur = 0;
        mval = 0;
        for(int i=0;i<=30;i++)
        {
            cur += temp[i];
            if(cur >= mval)
            {
                mval = cur;
                ret = i-10;
            }
        }
        if(mval == 1) ret = tmax;
        cout << ret << endl;
    }
    return 0;
}
