#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int p[1111], f[1111];
map <string,int> id;
map <int,string> name;

void print(int i) {
    cout << name[i] << endl;
    if(f[i] != -1) print(f[i]);
}

int main() {
    int n, c = 0;
    cin >> n;
    memset(p,-1,sizeof(p));
    memset(f,-1,sizeof(f));
    for(int i=0;i<n;i++) {
        string a, b;
        cin >> a >> b;
        if(!id.count(a)) {
            id[a] = c;
            name[c++] = a;
        }
        if(!id.count(b)) {
            id[b] = c;
            name[c++] = b;
        }
        p[id[a]] = id[b];
        f[id[b]] = id[a];
    }
    for(int i=0;i<n+1;i++) {
        if(p[i] == -1) print(i);
    }
    return 0;
}

