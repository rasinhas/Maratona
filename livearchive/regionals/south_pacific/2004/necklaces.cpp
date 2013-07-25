#include <iostream>
#include <string>
#define sz size()
#define inf 1e9

using namespace std;

typedef long long ll;

int mi, ma;
string s;

void process(char c)
{
    ll p=0ll, q=0ll;
    for(int i=0;i<s.sz;i++)
    {
        if(s[i] == c)
        {
            p += (1ll<<(s.sz-i-1));
            p += (1ll<<(2*s.sz-i-1));
            q += (1ll<<i);
            q += (1ll<<(s.sz+i));
        }
    }
    int k = s.sz;
    while(k)
    {
        int v = (p%(1<<s.sz));
        int w = (q%(1<<s.sz));
        ma = max(ma,v);
        mi = min(mi,v);
        p = (p>>1);
        ma = max(ma,w);
        mi = min(mi,w);
        q = (q>>1);
        k--;
    }
}

int main()
{
    while(1)
    {
        cin >> s;
        if(s == "END") break;
        mi = inf;
        ma = -inf;
        process('W');
        process('B');
        cout << mi << " " << ma << endl;
    }
    return 0;
}
