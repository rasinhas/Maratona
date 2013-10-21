#include <iostream>
#include <cstdio>

using namespace std;

int p2[20], p[22];

int main()
{
    int m;
    p2[0] = 1;
    for(int i=1;i<20;i++) p2[i] = p2[i-1]*2;
    while(scanf("%d" , &m) != EOF)
    {
        int k=1e9, n;
        for(int i=0;i<20;i++) if(p2[i] >= m)
        {
            k = p2[i]-m;
            n = i;
            break;
        }
        for(int i=0;i<k;i++)
        {
            int a = i;
            for(int j=0;j<n-1;j++) 
            {
                p[j] = a%2;
                a /= 2;
            }
            for(int j=n-2;j>=0;j--) printf("%d", p[j]);
            printf("\n");
        }
        for(int i=k;i<p2[n-1];i++)
        {
            int a = i;
            for(int j=0;j<n-1;j++) 
            {
                p[j] = a%2;
                a /= 2;
            }
            for(int j=n-2;j>=0;j--) printf("%d", p[j]);
            printf("0\n");
            for(int j=n-2;j>=0;j--) printf("%d", p[j]);
            printf("1\n");
        }
    }
    return 0;
}
