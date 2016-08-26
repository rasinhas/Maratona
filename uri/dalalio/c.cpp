#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

vector <int> sq;
set <int> s;

int main() {
    int n;
    for(int i=0;i*i<=1e5;i++) sq.push_back(i*i);
    for(int i=0;i<sq.size();i++) {
        for(int j=i;j<sq.size();j++) s.insert(sq[i]+sq[j]);
    }
    while(scanf("%d", &n) != EOF) {
        cout << (s.count(n) ? "YES" : "NO") << endl;
    }
    return 0;
}

