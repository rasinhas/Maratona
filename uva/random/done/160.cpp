#include <stdio.h>

using namespace std;

int p[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int f[101][25];

int main()
{
    int i, j, k, n;
    for(i=2;i<101;i++)
    {
        k = i;
        for(j=0;j<25;j++)
        {
            f[i][j] = f[i-1][j];
            while(k != 1 && k%p[j] == 0)
            {
                f[i][j]++;
                k /= p[j];
            }
        }
    }
    while(scanf("%d", &n) && n)
    {
        printf("%3d! =", n);
        k = 0;
        for(i=0;i<25;i++) if(f[n][i]) k = i;
        for(i=0;i<=k;i++) 
        {
            if(i == 15) printf("\n      ");
            printf("%3d", f[n][i]);
        }
        printf("\n");
    }
    return 0;
}
