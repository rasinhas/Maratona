#include <stdio.h>
#include <iostream>

using namespace std;

int l, mat[8][500][500], s[500][500];

void rot(int k)
{
    int i, j, row, col=l-1;
    for(i=0; i<l; i++)
    {
        row=0;
        for(j=0; j<l; j++)
        {
            mat[k+1][row][col]=mat[k][i][j];
            row++;
        }
        col--;
    }
}

void turn(int k)
{
    int i, j, row, col=l-1;
    for(i=0;i<l;i++)
    {
        for(j=0;j<l;j++)
        {
            mat[k+1][i][j] = mat[k][i][l-j-1];
        }
    }
}

int mod(int a) { return ((a>=0) ? a : -a); }

int main()
{
    int i, j, k, cont;
    double maximo, L;
    while(scanf("%d", &l) && l)
    {
        for(i=0; i<l; i++) for(j=0; j<l; j++) scanf("%d", &s[i][j]);
        for(i=0; i<l; i++) for(j=0; j<l; j++) scanf("%d", &mat[0][i][j]);
        rot(0);
        rot(1);
        rot(2);
        turn(3);
        rot(4);
        rot(5);
        rot(6);
        /*
        for(k=0; k<8; k++)
        {
            for(i=0; i<l; i++)
            {
                for(j=0; j<l; j++) printf("%d ", mat[k][i][j]);
                printf("\n");
            }
            printf("\n");
        }
        */
        maximo=0.0;
        L=(double)l;
        for(k=0; k<8; k++)
        {
            cont=0;
            for(i=0; i<l; i++) for(j=0; j<l; j++) if(mod(s[i][j]-mat[k][i][j])<=100) cont++;
            if((double)cont>maximo) maximo=((double)cont);
        }
        printf("%.2lf\n", maximo*100.0/(L*L));
    }
    return 0;
}
