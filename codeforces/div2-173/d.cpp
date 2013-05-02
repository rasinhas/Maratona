#include <stdio.h>
#include <iostream>

using namespace std;

int t[310][310][310], q[3];

int main()
{
    int n;
    scanf("%d", &n);
    //posiçao final 000
    for(int i=0;i<301;i++) t[i][0][0] = i;
    for(int i=0;i<n;i++)
    {
        scanf("%d", &q[i]);
    }
    if() printf("BitAryo\n");
    else printf("BitLGM\n");
    return 0;
}
