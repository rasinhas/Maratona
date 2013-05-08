#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int m[500];
    int n, k, p;
    scanf("%d%d", &n, &k);
    for(int i=0;i<2*n+1;i++) scanf("%d", &m[i]);
    p = 1;
    while(k>0)
    {
        if(m[p] > m[p-1]+1 && m[p] > m[p+1]+1)
        {
            m[p]--;
            k--;
        }
        p+=2;
    }
    for(int i=0;i<2*n+1;i++) printf("%d ", m[i]);
    return 0;
}
