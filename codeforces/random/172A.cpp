#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n, m=30, lcp;
    string a, b;
    scanf("%d", &n);
    cin >> a;
    for(int i=1;i<n;i++)
    {
        cin >> b;
        lcp = 0;
        for(int j=0;j<b.size();j++)
        {
            if(b[j] != a[j]) break;
            lcp++;
        }
        if(lcp < m) m = lcp;
    }
    printf("%d\n", m);
    return 0;
}
