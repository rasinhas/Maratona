#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#define inf 0x3f3f3f3f;
#define pb push_back
#define sz size()
#define mp make_pair

typedef long long ll;

using namespace std;

int tab[200][200];
int res[200][200];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int in(int i, int j) { return (i >= 0 && i < 200 && j >= 0 && j < 200); }

int main()
{
    int n, t, r, f, x, y;
    cin >> n >> t;
    r = 0;
    tab[70][70] = n;
    do {
        f = 0;
        for(int i=0;i<=140;i++)
        {
            for(int j=0;j<=140;j++)
            {
                tab[i][j] += res[i][j];
                res[i][j] = 0;
                if(tab[i][j] > 3)
                {
                    for(int k=0;k<4;k++) if(in(i+dx[k], j+dy[k])) res[i+dx[k]][j+dy[k]] += tab[i][j]/4;
                    f = 1;
                }
                tab[i][j] = tab[i][j]%4;
            }
        }
    } while(f == 1);
    for(int i=0;i<t;i++)
    {
        cin >> x >> y;
        x += 70;
        y += 70;
        if(in(x,y)) cout << 0 << endl;
        else cout << tab[x][y] << endl;
    }
    return 0;
}
