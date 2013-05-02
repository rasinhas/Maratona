#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    if(n == 0 && m > 0) printf("Impossible\n");
    else printf("%d %d\n", max(n,m), n+max(0,m-1));
    return 0;
}
