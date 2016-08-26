#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct v{
    int i;
    int f;
    int sz;
    string s;
    v(int i=0,int f=0,int sz=0,string s=""):i(i), f(f), sz(sz), s(s) {}
}v;

int m;
string s;
string pal;

v bfs(v init)
{
    queue<v> q;
    q.push(init);
    while(!q.empty())
    {
        v u = q.front();
        q.pop();
        if(u.i > u.f) return u;
        if(s[u.i] == s[u.f])
        {
            int k=2;
            if(u.i == u.f) k--;
            return v(u.i+1,u.f-1,u.sz+k,u.s+s[u.i]);
        }
        q.push(v(u.i+1,u.f,u.sz,u.s));
        q.push(v(u.i,u.f-1,u.sz,u.s));
    }
}

int main()
{
    cin >> s;
    v u = v(0,s.size()-1,0,"");
    while(u.i <= u.f)
    {
        u = bfs(u);
        if(u.sz == 100) break;
    }
    cout << u.s;
    if(u.sz%2) u.s.erase(u.s.end()-1);
    reverse(u.s.begin(),u.s.end());
    cout << u.s << endl;
    return 0;
}
