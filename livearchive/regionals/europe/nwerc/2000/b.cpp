#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

// a[2*symb*maxn]
int a[100];
string seq;
int n, k, symb=2;

// limites aceitaveis de tempo
// symb = 2 -> n ~= 24
// symb = 3 -> n ~= 15
// symb = 4 -> n ~= 12
// symb = 5 -> n ~= 10
// symb = 6 -> n ~= 9
// symb = 7 -> n ~= 8
// symb = 8 -> n ~= 8
// symb = 9 -> n ~= 7

int de_bruijn(int t, int p)
{
    if(t > n) 
    {
        if(!(n%p)) for(int i=1;i<=p;i++) seq += ('0'+a[i]);
    }
    else 
    {
        a[t] = a[t-p];
        de_bruijn(t+1,p);
        for(int i=a[t-p]+1;i<symb;i++)
        {
            a[t] = i;
            de_bruijn(t+1,t);
        }
    }
}

int bin2dec(int k)
{
    int r = 0;
    for(int i=0;i<n;i++) r += ((seq[k+n-i-1]-'0')<<i);
    return r;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        memset(a,0,sizeof(a));
        seq = "";
        de_bruijn(1,1);
        seq += seq;
        cout << bin2dec(k) << endl;
    }
    return 0;
}
