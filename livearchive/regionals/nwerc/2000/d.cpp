#include <cstdio>
#include <iostream>

using namespace std;

int a[444444];
int prime[111111];
int np=1;

void sieve(int n) {
    for(int i=4;i<n;i+=2) a[i]=1;
    prime[0]=2;
    for(int i=3;i<n;i+=2) {
        if(a[i]) continue;
        prime[np++]=i;
        for(int j=2*i;j<n;j+=i) a[j]=1;
    }
}

int algsum(int n)
{
    int s=0;
    while(n>0)
    {
        s += n%10;
        n /= 10;
    }
    return s;
}

int check(int n)
{
    int ns = algsum(n);
    int fs = 0;
    if(n < 100000)
    {
        if(!a[n]) return 0;
    }
    else
    {
        for(int i=0;i<np;i++)
        {
            if(n%prime[i] == 0) break;
            if(i == np-1) return 0;
        }
    }
    for(int i=0;i<np;i++)
    {
        while(n%prime[i] == 0)
        {
            fs += algsum(prime[i]);
            n /= prime[i];
        }
    }
    if(n != 1) fs += algsum(n);
    if(ns == fs) return 1;
    else return 0;
}

int main()
{
    int n, t;
    sieve(100000);
    cin >> t;
    while(t--)
    {
        cin >> n;
        n++;
        while(!check(n)) n++;
        cout << n << endl;
    }
    return 0;
}
