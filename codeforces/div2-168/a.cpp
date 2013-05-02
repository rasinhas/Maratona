#include <stdio.h>
#include <iostream>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int mat[3][3], a[3][3];;

int in(int u, int v) { return (u>=0 && v >=0 && u<3 && v<3); }

int main()
{
    int v;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) a[i][j] = 1;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++)
    {
        scanf("%d", &mat[i][j]);
        a[i][j] += mat[i][j];
        for(int k=0;k<4;k++)
        {
            if(in(i+dx[k], j+dy[k])) a[i+dx[k]][j+dy[k]] += mat[i][j];
        }
    }
    for(int i=0;i<3;i++) 
    {
        for(int j=0;j<3;j++) printf("%d", (a[i][j])%2);
        printf("\n");
    }
    return 0;
}
