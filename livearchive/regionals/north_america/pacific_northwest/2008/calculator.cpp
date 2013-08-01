#include <iostream>
#include <cstdio>

using namespace std;

// 0->998 = neg / 1000->1999 = pos / 999 = 0
int ma[2222];
int c[10] = {30,10,25,25,20,25,30,15,35,30};

void precalc()
{
    for(int i=0;i<1000;i++)
    {
        int k=i, v=5;
        do
        {
            v += c[k%10];
            k /= 10;
        } while(k > 0);
        ma[999-i] = v;
        ma[i+999] = v-5;
    }
}

int in(int a) { return (a > -1000 && a < 1000); }

int main()
{
    precalc();
    int x, y, z, t=1;
    while(scanf("%d", &x) && x)
    {
        scanf("%d %d", &y, &z);
        int ret = 0;
        for(int i=0;i<2000;i++)
        {
            int vi = i-999;
            if(ma[i] == x)
            {
                for(int j=0;j<2000;j++)
                {
                    int vj = j-999;
                    if(ma[j] == y)
                    {
                        if(in(vi+vj) && ma[999+vi+vj] == z) ret++;
                        if(in(vi-vj) && ma[999+vi-vj] == z) ret++;
                        if(in(vi*vj) && ma[999+(vi*vj)] == z) ret++;
                        if(vj != 0 && in(vi/vj) && ma[999+(vi/vj)] == z) ret++;
                    }
                }
            }
        }
        printf("Case %d: ", t++);
        if(ret == 0) cout << "No solutions." << endl;
        else if(ret == 1) printf("%d solution.\n", ret);
        else printf("%d solutions.\n", ret);
    }
    return 0;
}
