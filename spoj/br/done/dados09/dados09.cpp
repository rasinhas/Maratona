#include <stdio.h>
#define max(a,b) (a) > (b) ? a : b

//inversos d[0]/d[5], d[1]/d[3], d[2],d[4]

using namespace std;

int main()
{
    int n, i, j, val;
    int inv[6] = {5,3,4,1,2,0};
    int d[10], pos[10];
    int pd[10100][10];
    scanf("%d", &n);
    for(j=0;j<6;j++) 
    {
        scanf("%d", &d[j]);
        pos[d[j]] = j;
    }
    pd[0][1] = d[inv[pos[1]]] != 6 ? 6 : 5;
    pd[0][2] = d[inv[pos[2]]] != 6 ? 6 : 5;
    pd[0][3] = d[inv[pos[3]]] != 6 ? 6 : 5;
    pd[0][4] = d[inv[pos[4]]] != 6 ? 6 : 5;
    pd[0][5] = d[inv[pos[5]]] != 6 ? 6 : 4;
    pd[0][6] = d[inv[pos[6]]] != 5 ? 5 : 4;
    for(i=1;i<n;i++)
    {
        for(j=0;j<6;j++) 
        {
            scanf("%d", &d[j]);
            pos[d[j]] = j;
        }
        pd[i][1] = pd[i-1][d[inv[pos[1]]]] + (d[inv[pos[1]]] != 6 ? 6 : 5);
        pd[i][2] = pd[i-1][d[inv[pos[2]]]] + (d[inv[pos[2]]] != 6 ? 6 : 5);
        pd[i][3] = pd[i-1][d[inv[pos[3]]]] + (d[inv[pos[3]]] != 6 ? 6 : 5);
        pd[i][4] = pd[i-1][d[inv[pos[4]]]] + (d[inv[pos[4]]] != 6 ? 6 : 5);
        pd[i][5] = pd[i-1][d[inv[pos[5]]]] + (d[inv[pos[5]]] != 6 ? 6 : 4);
        pd[i][6] = pd[i-1][d[inv[pos[6]]]] + (d[inv[pos[6]]] != 5 ? 5 : 4);
    }
    val = 0;
    for(i=1;i<7;i++) val = max(val,pd[n-1][i]);
    printf("%d\n",val);
    return 0;
}
