#include <iostream>
#include <cstdio>
#include <algorithm>
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

vector <pii> edges;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(m%2) cout << "No solution" << endl;
    else {
    }
    return 0;
}
