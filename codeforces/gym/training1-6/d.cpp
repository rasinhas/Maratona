#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define ff first
#define ss second

using namespace std;

struct tile {
    int x1, x2, y1, y2;
};

struct rect {
    tile s;
    vector <tile> t;
};

vector <rect> v;

vector<pair<int,int> > ijoin(vector <pair<int,int> > v)
{
    vector <pair<int,int> > r;
    sort(v.begin(),v.end());
    r.push_back(v[0]);
    for(int i=1;i<v.size();i++)
    {
        int j = r.size()-1;
        if(v[i].ff <= r[j].ss) r[j].ss = max(r[j].ss,v[i].ss);
        else r.push_back(v[i]);
    }
    return r;
}

int split(int idx)
{
    vector <tile> t = v[idx].t;
    rect p1, p2, p3;
    if(t.size() == 1) return 0;
    int xc = -1, yc = -1;
    for(int i=0;i<t.size();i++)
    {
        int y0=1e9, yf=0;
        int x0=1e9, xf=0;
        if(t[i].x1 > v[idx].s.x1)
        {
            vector <pair<int,int> > inter;
            for(int j=0;j<t.size();j++)
            {
                if(t[j].x1 != t[i].x1) continue;
                inter.push_back(make_pair(t[j].y1,t[j].y2));
            }
            inter = ijoin(inter);
            if(inter.size() == 1 && inter[0].ff == v[idx].s.y1 && inter[0].ss == v[idx].s.y2) 
            {
                xc = t[i].x1;
                break;
            }
        }
        if(t[i].y1 > v[idx].s.y1)
        {
            vector <pair<int,int> > inter;
            for(int j=0;j<t.size();j++)
            {
                if(t[j].y1 != t[i].y1) continue;
                inter.push_back(make_pair(t[j].x1,t[j].x2));
            }
            inter = ijoin(inter);
            if(inter.size() == 1 && inter[0].ff == v[idx].s.x1 && inter[0].ss == v[idx].s.x2) 
            {
                yc = t[i].y1;
                break;
            }
        }
    }
    if(xc == -1 && yc == -1) return 0;
    if(yc != -1)
    {
        p1.s = v[idx].s;
        p1.s.y1 = yc;
        p2.s = v[idx].s;
        p2.s.y2 = yc;
    }
    else
    {
        p1.s = v[idx].s;
        p1.s.x1 = xc;
        p2.s = v[idx].s;
        p2.s.x2 = xc;
    }
    for(int i=0;i<t.size();i++)
    {
        if(yc != -1)
        {
            if(t[i].y1 >= yc) p1.t.push_back(t[i]);
            else if(t[i].y2 <= yc) p2.t.push_back(t[i]);
        }
        else
        {
            if(t[i].x1 >= xc) p1.t.push_back(t[i]);
            else if(t[i].x2 <= xc) p2.t.push_back(t[i]);
        }
    }
    v[idx] = p1;
    v.push_back(p2);
    return 1;
}

int area(int idx) { return (v[idx].s.x2-v[idx].s.x1)*(v[idx].s.y2-v[idx].s.y1); }

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int l, w, n;
        vector <tile> r;
        rect a;
        tile k;
        v.clear();
        cin >> l >> w >> n;
        for(int i=0;i<n;i++)
        {
            cin >> k.x1 >> k.y1 >> k.x2 >> k.y2;
            r.push_back(k); 
        }
        a.s.x1 = a.s.y1 = 0;
        a.s.x2 = l;
        a.s.y2 = w;
        a.t = r;
        v.push_back(a);
        int i = 0, m = 0;
        while(i < v.size()) if(!split(i)) i++;
        for(int i=0;i<v.size();i++) m = max(m,area(i));
        cout << m << endl;
    }
    return 0;
}
