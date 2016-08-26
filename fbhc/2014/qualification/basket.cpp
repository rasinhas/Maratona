#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <vector>
#include <functional>
#define ff first
#define ss second

using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,string> ppl;

int n, p;
ppl play[33];
map <string,int> seed;
map <int,string> seeder;
vector <string> ret;
pii game[33];

void sub(int t)
{
    int in=0, out=0, intime=1000, outtime=0, c=0;
    for(int j=t;j<n;j+=2)
    {
        c++;
        if(game[j].ss)
        {
            game[j].ff++;
            if(game[j].ff >= outtime)
            {
                outtime = game[j].ff;
                out = j;
            }
        }
        else
        {
            if(game[j].ff < intime)
            {
                intime = game[j].ff;
                in = j;
            }
        }
    }
    if(c == p) return;
    game[out].ss = 0;
    game[in].ss = 1;
}

int main()
{
    int T, m;
    cin >> T;
    for(int t=1;t<=T;t++)
    {
        cin >> n >> m >> p;
        ret.clear();
        seeder.clear();
        for(int i=0;i<n;i++) game[i].ff = game[i].ss = 0;
        for(int i=0;i<n;i++) cin >> play[i].ss >> play[i].ff.ff >> play[i].ff.ss;
        sort(play,play+n,greater<ppl>());
        for(int i=0;i<n;i++) seeder[i] = play[i].ss;
        for(int i=0;i<2*p;i++) game[i].ss = 1;
        for(int i=0;i<m;i++)
        {
            sub(0);
            sub(1);
        }
        for(int i=0;i<n;i++) if(game[i].ss) ret.push_back(seeder[i]);
        sort(ret.begin(),ret.end());
        printf("Case #%d:", t);
        for(int i=0;i<ret.size();i++) cout << " " << ret[i];
        cout << endl;
    }
    return 0;
}
