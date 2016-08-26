#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

// y, x
typedef pair<int,int> pt;

pair<pt,pt> s[111111];

bool cmp(pt a,pt b)
{
    if(a.second < b.second) return 1;
    else if(a.second > b.second) return 0;
    else return a < b;
}

int main()
{
    cin >> n >> q;
    for(int i=0;i<n;i++)
    {
        cin >> s[i].first.first >> s[i].first.second >> s[i].second.first >> s[i].second.second;
        if(s[i].second.second > s[i].first.second) swap(s[i].second,s[i].first);
    }
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++)
    {
    }
    return 0;
}
