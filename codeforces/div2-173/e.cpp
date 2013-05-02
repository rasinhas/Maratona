#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    unsigned long long s[101000], pre[101000], post[101000];
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%llu", &s[i]);
        if(i == 0) pre[i] = s[i];
        else pre[i] = (pre[i-1]^s[i]);
    }
    for(int i=n-1;i>=0;i--)
    {
        if(i == n-1) post[i] = s[i];
        else post[i] = (post[i+1]^s[i]);
    }
    for(int i=0;i<n;i++) printf("%llu ", pre[i]);
    printf("\n");
    for(int i=0;i<n;i++) printf("%llu ", post[i]);
    printf("\n");
    return 0;
}
