#include <iostream>
#include <cstdio>

using namespace std;

int n;
int a[22];

int go(int s, int u, int r)
{
    int ret;
    if(r == n+1) return 1;
    for(int i=0;i<n;i++)
    {
        int v = (1<<((a[i]+r)%n));
        if(u&(1<<i)) continue;
        if(v & s) continue;
        ret = go(v|s,u|(1<<i),r+1);
        if(ret) return ret;
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int s = 0;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            s += a[i];
        }
        cout << (!(s%n) ? "Sepehr" : "Sohrab") << endl;
        //cout << (go(0,0,1) ? "Sepehr" : "Sohrab") << endl;
    }
    return 0;
}
