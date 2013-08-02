#include <iostream>
#include <cstdio>

using namespace std;

int x[5555];

int main()
{
    int n, f;
    while((cin>>n) && n)
    {
        f = -1;
        for(int i=0;i<n;i++) 
        {
            cin >> x[i];
            if(f == -1 && x[i] == 1) f = i;
        }
        int s=0, ret=0;
        if(f==-1) ret = (n+1)/2;
        else
        {
            for(int i=f;i<=n+f;i++)
            {
                if(x[i%n] == 1)
                {
                    ret += s/2;
                    s = 0;
                }
                else s++;
            }
        }
        cout << ret << endl;
    }
    return 0;
}
