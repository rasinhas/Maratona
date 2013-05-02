#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
    int ret=0, a, b;
    scanf("%d %d", &a, &b);
    for(int i=0;i<15;i++) if(a == primes[i] && b == primes[i+1]) ret = 1;
    if(ret) printf("YES\n");
    else printf("NO\n");
    return 0;
}
