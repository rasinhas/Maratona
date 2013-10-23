#include <iostream>
#include <cstdio>
#include <cassert>
#define xx first
#define yy second

using namespace std;

typedef pair<int,int> pt;
typedef pair<pt,pt> rect;

int mod(int a) { return a > 0 ? a : -a; }

bool overlap(rect a, rect b)
{
    if(b.yy.xx <= a.xx.xx) return 0;
    if(b.yy.yy <= a.xx.yy) return 0;
    if(b.xx.xx >= a.yy.xx) return 0;
    if(b.xx.yy >= a.yy.yy) return 0;
    return 1;
}

rect r[111];
int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        int s = 0, l, w;
        int f = 0;
        cin >> l >> w;
        cin >> n;
        for(int i=0;i<n;i++) 
        {
            cin >> r[i].xx.xx >> r[i].xx.yy >> r[i].yy.xx >> r[i].yy.yy;
            s += mod((r[i].xx.xx-r[i].yy.xx)*(r[i].xx.yy-r[i].yy.yy));
            if(r[i].xx.xx < 0 || r[i].xx.yy < 0 || r[i].yy.xx < 0 || r[i].yy.yy < 0) f = 2;
            if(r[i].xx.xx > l || r[i].xx.yy > w || r[i].yy.xx > l || r[i].yy.yy > w) f = 2;
        }
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(i != j && overlap(r[i],r[j])) f = 1;
        if(f == 1) cout << "NONDISJOINT" << endl;
        else if(f == 2) cout << "NONCONTAINED" << endl;
        else if(f == 0)
        {
            if(s == l*w) cout << "OK" << endl;
            else cout << "NONCOVERING" << endl;
        }
    }
    return 0;
}
