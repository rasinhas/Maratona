#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int n, q, v, x, y;
    unsigned long long r=0;
    long long a[201000], seq[201000], freq[201000];
    scanf("%d%d", &n, &q);
    memset(seq,0,(n+2)*sizeof(int));
    memset(freq,0,(n+2)*sizeof(int));
    for(int i=0;i<n;i++) cin >> a[i]; 
    sort(a,a+n);
    for(int i=0;i<q;i++)
    {
        scanf("%d%d", &x, &y);
        seq[x-1]++;
        seq[y]--;
    }
    v = 0;
    for(int i=0;i<n;i++)
    {
        v += seq[i];
        freq[i] = v;
    }
    sort(freq,freq+n);
    for(int i=0;i<n;i++) r += freq[i]*a[i];
    cout << r << endl;
    return 0;
}
