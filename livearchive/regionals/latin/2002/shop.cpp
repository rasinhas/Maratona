#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int vis[1111][1111];
int c[2222], n;
vector <int> mi;

int go(int m, int l, int bx)
{
    if(vis[m][l]) return 0;
    if(bx == n) return 1;
    vis[m][l] = 1;
    if(l >= c[bx] && go(m,l-c[bx],bx+1)) return 1;
    if(m >= c[bx] && go(m-c[bx],l,bx+1))
    {
        mi.push_back(bx);
        return 1;
    }
    return 0;
}

int main()
{
    int m, l;
    while((cin>>m>>l) && (m+l))
    {
        cin >> n;
        mi.clear();
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++) cin >> c[i];
        if(!go(m,l,0)) cout << "Impossible to distribute" << endl;
        else 
        {
            cout << mi.size();
            for(int i=((int)mi.size()-1);i>=0;i--) printf(" %d", mi[i]+1);
            cout << endl;
        }
    }
    return 0;
}
