#include <bits/stdc++.h>

using namespace std;

string s[2222];
int a[2222222];
int z;

void update(int x, int delta)
{
    for(; x <= z; x += x&-x)
          a[x] += delta;
}

int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
         sum += a[x];
     return sum;
}

int main() {
    int n, m, q, c=0;
    cin >> n >> m >> q;
    z = n*m;
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(s[i][j] == '*') {
        update(i+j*n + 1,1);
        c++;
    }
    int a, b;
    for(int i=0;i<q;i++) {
        scanf("%d%d", &a, &b);
        a--; b--;
        int idx = a + b*n + 1;
        if(query(idx) == query(idx-1)) {
            update(idx,1);
            c++;
        }
        else {
            update(idx,-1);
            c--;
        }
        cout << c - query(c) << endl;
    }
    return 0;
}
