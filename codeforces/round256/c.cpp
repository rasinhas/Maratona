#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int h[5555];
int n, cur;

int solve(int a, int b, int c) {
    if(a == b) return 1;
    int m = 1e9+1;
    for(int i=a;i<=b;i++) m = min(m,h[i]);
    int s = (m-c);
    int ini = a, fin = b;
    int i = a;
    while(1) {
        while(h[i] == m) {
            i++;
            if(i > b) break;
        }
        if(i > b) break;
        ini = i;
        while(h[i] != m) {
            i++;
            if(i > b) break;
        }
        fin = i-1;
        s += solve(ini,fin,m);
    }
    cur += min(s,b-a+1);
    return min(s,(b-a+1));
}

int main() {
    cin >> n;
    cur = 0;
    for(int i=0;i<n;i++) cin >> h[i];
    cout << min(solve(0,n-1,0),n) << endl;
    return 0;
}

