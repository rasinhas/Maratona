#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int pos[11];
int stop[11];
int t[11111];

int main()
{
    int p, s, k, win;
    while(scanf("%d %d", &p, &s) && p)
    {
        memset(pos,0,sizeof(pos));
        memset(stop,0,sizeof(stop));
        memset(t,0,sizeof(t));
        win = 0;
        for(int i=0;i<3;i++)
        {
            cin >> k;
            t[k] = 1;
        }
        int n, a, b;
        cin >> n;
        k = 0;
        for(int j=0;k<n;j++)
        {
            if(!stop[j%p])
            {
                cin >> a >> b;
                pos[j%p] += (a+b);
                if(!win && pos[j%p] > s) win = (j%p)+1;
                if(t[pos[j%p]] == 1) stop[j%p] = 1;
                k++;
            }
            else stop[j%p] = 0;
        }
        cout << win << endl;
    }
    return 0;
}
