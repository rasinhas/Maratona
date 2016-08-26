#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int lps[9999999];
char s[9999999], c[3333333];

void build()
{
    int i=0;
    s[0] = '^';
    s[1] = '#';
    while(c[i] != '\0')
    {
        s[2*(i+1)+1] = '#';
        s[2*(i+1)] = c[i++];
    }
    s[2*i+2] = '$';
}

int manacher()
{
    int k=0, r=0, m=0;
    int l = strlen(s);
    for(int i=1;i<l;i+=2)
    {
        int o = 2*k-i;
        lps[i] = (r>i) ? min(r-i,lps[o]) : 0;
        if(i-lps[i] <= k)
        {
            int d = k - (i - lps[i]);
            m = max(m,2*(lps[i]-d));
        }
        while(s[i+1+lps[i]] == s[i-1-lps[i]]) lps[i]++;
        if(lps[i-lps[i]/2] >= lps[i]/2) m = max(m,lps[i]);
        if(i+lps[i] > r) 
        {
            k = i;
            r = i + lps[i];
        }
    }
    return m;
}

int main()
{
    int n, M=0;
    cin >> n;
    for(int i=0;i<n;i++) 
    {
        getchar();
        memset(lps,0,sizeof(lps));
        memset(s,0,sizeof(s));
        scanf("%[^\n]", c);
        build();
        int m = manacher();
        int l = strlen(s);
        cout << m << endl;
        /*
        for(int i=0;i<l;i++) printf("%3d",i);
        cout << endl;
        for(int i=0;i<l;i++) printf("%3c",s[i]);
        cout << endl;
        for(int i=0;i<l;i++) printf("%3d",lps[i]);
        cout << endl;
        */
    }
    return 0;
}

