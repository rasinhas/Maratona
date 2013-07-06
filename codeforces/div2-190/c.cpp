#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#define sz size()

using namespace std;

int mod(int a) { return a > 0 ? a : -a; }

int main()
{
    int a, b, c;
    int dx=0, dy=0, tx, ty;
    string s;
    cin >> a >> b;
    cin >> s;
    for(int i=0;i<s.sz;i++)
    {
        if(s[i] == 'R') dx++; 
        if(s[i] == 'L') dx--;
        if(s[i] == 'U') dy++; 
        if(s[i] == 'D') dy--;
    }
    tx = dx;
    ty = dy;
    dx = 0;
    dy = 0;
    bool ok=false;
    for(int i=0;i<=s.sz;i++)
    {
        int px=a-dx;
        int py=b-dy;
        if(px == 0 && py == 0) ok = true;
        if(ty == 0 && tx == 0) {}
        else if(ty==0) 
        {
            if(py == 0 && px%tx == 0 && (1ll*px*tx) > 0) ok = true;
        }
        else if(tx==0)
        {
            if(px == 0 && py%ty == 0 && (1ll*py*ty) > 0) ok = true;
        }
        else 
        {
            if(mod(px)%mod(tx) == 0 && (1ll*px*ty) == (1ll*py*tx) && (1ll*py*ty) > 0) ok = true;
        }
        if(ok)
        {
            cout << "Yes" << endl;
            return 0;
        }
        if(i < s.sz)
        {
            if(s[i] == 'R') dx++; 
            if(s[i] == 'L') dx--;
            if(s[i] == 'U') dy++; 
            if(s[i] == 'D') dy--;
        }
    }
    cout << "No" << endl;
    return 0;
}
