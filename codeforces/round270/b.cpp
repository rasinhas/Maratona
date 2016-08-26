#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int n, k, a;
    cin >> n >> k;
    priority_queue<int> q;
    for(int i=0;i<n;i++) {
        cin >> a;
        a--;
        q.push(a);
    }
    int r = 0;
    while(!q.empty()) {
        int m = q.top();
        for(int i=0;i<k;i++) {
            if(q.empty()) break;
            q.pop();
        }
        r += 2*m;
    }
    cout << r << endl;
    return 0;
}

