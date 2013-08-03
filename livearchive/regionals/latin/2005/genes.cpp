#include <iostream>
#include <cstdio>

using namespace std;

int g[555555];

int main()
{
    int n, r, a, b, q, v, t=1;
    while((cin>>n) && n)
    {
        for(int i=1;i<=n;i++) g[i] = i;
        cin >> r;
        for(int i=0;i<r;i++) 
        {
            cin >> a >> b;
            for(int j=0;a+j<b-j;j++) swap(g[a+j],g[b-j]);
        }
        cin >> q;
        cout <<  "Genome " << t++ << endl;
        for(int i=0;i<q;i++)
        {
            cin >> v;
            for(int j=1;j<=n;j++) if(g[j] == v) 
            {
                cout << j << endl;
                break;
            }
        }
    }
    return 0;
}
