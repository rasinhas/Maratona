#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int n, k, p;
    char s[1100000];
    scanf("%d%d", &n, &k);
    p = k-1;
    if(n == 1 && k == 1) printf("a");
    else if(k > n || (k == 1 && n > 1)) printf("-1\n");
    else
    {
        for(int i=n-1;i>n-k+1;i--)
        {
            s[i] = 'a'+p;
            p--;
        }
        for(int i=0;i<=n-k+1;i++)
        {
            s[i] = 'a' + i%2;
        }
        printf("%s\n", s);
    }
    return 0;
}
