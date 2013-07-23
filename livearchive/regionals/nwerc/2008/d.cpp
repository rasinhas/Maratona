#include <iostream>
#include <cstdio>

using namespace std;

int x[222];

int main()
{
    int a, b, t;
    cin >> t;
    for(int i=0;i<t;i++) cin >> x[2*i];
    for(a=0;a<10001;a++)
    {
        int ok;
        for(b=0;b<10001;b++)
        {
            ok = 1;
            for(int i=0;i<t-1;i++)
            {
                if((a*((a*x[2*i] + b)%10001)+b)%10001 != x[2*(i+1)]) ok = 0;
                if(!ok) break;
            }
            if(ok) break;
        }
        if(ok) break;
    }
    for(int i=0;i<t;i++)
    {
        cout << ((a*x[2*i]+b)%10001) << endl;
    }
    return 0;
}
