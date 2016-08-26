#include <iostream>
#include <cstdio>
#include <fstream>
#include <set>

using namespace std;

int n;
int c[2][3], p[3];
set <int> vis;

void go(int v, int val, int idx) 
{
    if(idx == 3) 
    {
        vis.insert(val);
        return;
    }
    for(int i=-2;i<3;i++)
    {
        int u = (c[v][idx] + i + n)%n;
        go(v,val+u*p[idx],idx+1);
    }
}

int main()
{
    ifstream in("combo.in");
    ofstream out("combo.out");
    in >> n;
    p[0] = 1;
    for(int i=1;i<3;i++) p[i] = n*p[i-1];
    for(int i=0;i<3;i++) in >> c[0][i];
    for(int i=0;i<3;i++) in >> c[1][i];
    go(0,0,0);
    go(1,0,0);
    out << vis.size() << endl;
    return 0;
}
