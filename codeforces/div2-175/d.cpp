#include <iostream>
#include <stdio.h>
#define M 1000000007

using namespace std;

int val[20][20];

int main()
{
    int n;   
    long long r;
    scanf("%d", &n);
    r = 1;
    if(!(n%2)) r = 0;
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(i%2) r = (r*i)%M;
            r = (r*i)%M;
        }
    }
    cout << r << endl;
    /*
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
    {
        val[i][j] = ((i+j-2)%n)+1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%3d", val[i][j]);
        }
        printf("\n");
    }
    */
    return 0;
}
