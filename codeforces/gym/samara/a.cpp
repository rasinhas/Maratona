#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector <pair<int,int> > p;
vector <int> ans;
int vis[222222];
int ok[222222];

int main()
{
    int n, a, b, c, ans=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a >> b >> c;
        p.push_back(make_pair(a,i));
        p.push_back(make_pair(b,i));
        p.push_back(make_pair(c,i));
    }
    sort(p.begin(),p.end());
    int v2=0, v3=0;
    for(int i=p.size()-1;i>=0;i--)
    {
        vis[p[i].second]++;
        if(vis[p[i].second] == 2) v2 = 1;
        if(vis[p[i].second] == 3) v3 = 1;
        if(v2 == 0 && vis[p[i].second] == 1) ok[p[i].second] |= 1;
        if(v3 == 0 && vis[p[i].second] == 2) ok[p[i].second] |= 2;
        if(ok[p[i].second] == 3 && vis[p[i].second] == 3) ans++;
    }
    cout << ans << endl;
    for(int i=0;i<n;i++) if(ok[i] == 3) cout << i+1 << " ";
    cout << endl;
    return 0;
}
