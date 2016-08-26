#include <iostream>
#include <cstdio>

using namespace std;

int vis[666];

int main() {
    int a, b, c, r=0;
    cin >> a >> b >> c;
    for(int i=0;i<200;i++) vis[a+i] = vis[b+i] = vis[c+i] = 1;
    for(int i=0;i<600;i++) if(!vis[i]) r++;
    cout << r*100 << endl;
    return 0;
}
