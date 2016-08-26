#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

set <int> row, col;
set <pair<int,int> > cel;
int rowc, colc, celc;
double p;

double go(int r, int c, int cc, int t) {
}

int main() 
{
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        row.insert(r);
        col.insert(c);
        cells.insert(make_pair(r,c));
    }
    p = 1/(n*n);
    rowc = row.size();
    colc = col.size();
    celc = cel.size();
    return 0;
}
