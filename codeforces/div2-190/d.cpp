#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#define sz size()
#define pb push_back

using namespace std;

vector <int> ci, jid, jia;
int used[200];

int main()
{
    int n, m;
    int p;
    int usedd=0, useda=0;
    string s;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> s;
        cin >> p;
        if(s[0] == 'A') jia.pb(p);
        else jid.pb(p);
    }
    for(int i=0;i<m;i++)
    {
        cin >> p;
        ci.pb(p);
    }
    sort(jid.begin(),jid.end(),greater<int>());
    sort(jia.begin(),jia.end(),greater<int>());
    sort(ci.begin(),ci.end(),greater<int>());
    int c=0;
    int ret1=0;
    for(int i=(int)jia.sz-1;i>=0;i--)
    {
        if(ci[c] > jia[i]) ret1 += (ci[c++]-jia[i]);
        if(c == ci.sz) break;
    }
    int d=(int)jid.sz-1;
    for(int i=(int)ci.sz-1;i>=0;i--)
    {
        if(d < 0) break;
        if(ci[i] > jid[d])
        {
            used[i] = 1; 
            d--;
            usedd++;
        }
    }
    int ret2 = 0;
    d = (int)jia.sz-1;
    for(int i=(int)ci.sz-1;i>=0;i--)
    {
        if(d < 0) break;
        if(used[i]) continue;
        if(ci[i] >= jia[d])
        {
            used[i] = 1;
            ret2 += (ci[i]-jia[d--]);
            useda++;
        }
    }
    if(useda == jia.sz && usedd == jid.sz) for(int i=0;i<ci.sz;i++) if(!used[i]) ret2 += ci[i];
    cout << max(ret2,ret1) << endl;
    return 0;
}
