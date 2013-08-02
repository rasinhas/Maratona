#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int p[1111];

int main()
{
    int d, n, a, f;
    while((cin >> n >> d) && n)
    {
        f = 0;
        memset(p,0,sizeof(p));
        for(int i=0;i<d;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> a;
                p[j]+=a;
            }
        }
        for(int j=0;j<n;j++) if(p[j] == d) f = 1;
        if(f) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
