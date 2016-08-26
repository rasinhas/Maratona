#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

char c[333333];
int lps[333333];

int main()
{
    int n, m=0, nn;
    scanf("%d ", &n);
    // construction
    c[0] = '^';
    c[1] = '#';
    for(int i=0;i<n;i++) 
    {
        c[2*(i+1)+1] = '#';
        scanf("%c", &c[2*(i+1)]);
    }
    c[2*n+2] = '$';
    //
    nn = 2*n+2;
    int k=0,r=0;
    for(int i=1;i<nn;i++)
    {
        int o = 2*k-i;
        lps[i] = (r>i) ? min(r-i,lps[o]) : 0;
        while(c[i+1+lps[i]] == c[i-1-lps[i]]) lps[i]++;
        m = max(m,lps[i]);
        if(i+lps[i] > r) 
        {
            k = i;
            r = i + lps[i];
        }
    }
    /*
    for(int i=0;i<=2*n+2;i++) printf("%3c", c[i]);
    cout << endl;
    for(int i=0;i<=2*n+2;i++) printf("%3d", lps[i]);
    cout << endl;
    */
    cout << m << endl;
    return 0;
}
