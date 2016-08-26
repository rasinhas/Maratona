#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int a[333333];

map <int,int> t, nex;
map <int,int>::iterator it;

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        t[a[i]]++;
    }
    int l = 0, lc = 0;
    for(it=t.begin();it!=t.end();it++)
    {
        int cur = it->first;
        int curc = it->second;
        if(nex[l] + lc > cur) nex[cur] = nex[l]+lc;
        else nex[cur] = cur;
        l = cur;
        lc = curc;
    }
    for(int i=0;i<n;i++)
    {
        cout << nex[a[i]] << " ";
        nex[a[i]]++;
    }
    cout << endl;
    return 0;
}
