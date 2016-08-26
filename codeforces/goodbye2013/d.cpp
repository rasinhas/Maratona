#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int f[55];

int main()
{
    int k, x, n, m;
    cin >> k >> x >> n >> m;
    f[0] = 1;
    f[1] = 1;
    for(int i=2;i<55;i++) f[i] = f[i-1]+f[i-2];
    int a = f[k-3], b = f[k-2], na, nb;
    int ok = 0;
    for(int i=0;i<=n/2;i++)
    {
        if((x - a*i)%b == 0 && (x - a*i)/b <= m/2)
        {
            ok = 1;
            na = i;
            nb = (x-a*i)/b;
            break;
        }
        if(i < n/2 && ((x-(k-1)/2) - a*i)%b == 0 && ((x-(k-1)/2) - a*i)/b < m/2)
        {
            ok = 2;
            na = i;
            nb = ((x-(k-1)/2)-a*i)/b;
            break;
        }
    }
    if(!ok) cout << "Happy new year!" << endl;
    else if(ok == 1)
    {
        for(int i=0;i<na;i++) cout << "AC";
        for(int i=na*2;i<n;i++) cout << "B";
        cout << endl;
        for(int i=0;i<nb;i++) cout << "AC";
        for(int i=nb*2;i<m;i++) cout << "B";
        cout << endl;
    }
    else if(ok == 2)
    {
        cout << "C";
        for(int i=0;i<na;i++) cout << "AC";
        for(int i=na*2;i<n-1;i++) cout << "B";
        cout << endl;
        for(int i=0;i<nb;i++) cout << "AC";
        for(int i=nb*2;i<m-1;i++) cout << "B";
        cout << "A" <<  endl;
    }
    return 0;
}
