#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    long long r, g, b, ret, m=2;
    int rm, bm, gm;
    cin >> r >> g >> b;
    rm = r%3;
    gm = g%3;
    bm = b%3;
    ret = 0; 
    if(r < 3) m = min(m,r);
    if(b < 3) m = min(m,b);
    if(g < 3) m = min(m,g);
    for(int i=0;i<=m;i++) ret = max(ret, ((r+g+b)-(((rm-i+3)%3)+((bm-i+3)%3)+((gm-i+3)%3)))/3);
    cout << ret <<endl;
    return 0;
}
