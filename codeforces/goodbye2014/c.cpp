#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int w[555], b[1111], top[1111];

int main() {
    int n, m;
    stack <int> qa, qb;
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> w[i];
    for(int i=0;i<m;i++) {
        cin >> b[i];
        b[i]--;
    }
    int r = 0;
    for(int i=0;i<m;i++) {
        int p = 0;
        while(!qa.empty()) {
            if(qa.top() == b[i]) {
                qa.pop();
                break;
            }
            qb.push(qa.top());
            p += w[qa.top()];
            qa.pop();
        }
        r += p;
        while(!qb.empty()) {
            qa.push(qb.top());
            qb.pop();
        }
        qa.push(b[i]);
    }
    cout << r << endl;
    return 0;
}

