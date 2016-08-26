#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int branch[2222222], d[2222222];
int m[3];

int main()
{
    int q, n=4, k;
    cin >> q;
    d[] = {0,1,1,1};
    branch[] = {-1,0,1,2};
    m[] = {1,1,1};
    for(int i=0;i<q;i++)
    {
        cin >> k;
        n++;
        d[n] = d[k]+1;
        b[n++] = b[k];
        d[n] = d[k]+1;
        b[n] = b[k];
        m[b[k]] = max(m[b[k]], d[n]);
        cout << max()
    }
    return 0;
}
