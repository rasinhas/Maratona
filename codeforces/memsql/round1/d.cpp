#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int k, n1, n2, n3, t1, t2, t3;

int main() {
    cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
    priority_queue <int> q1, q2, q3;
    int t = 0, ini = k;
    for(t=0;;t++) {
        while(1) {
            if(q3.empty()) break;
            if(-q3.top() <= t) {
                q3.pop();
                k--;
            } else break;
        }
        if(q3.size() < n3) {
            while(1) {
                if(q2.empty() || q3.size() == n3) break;
                if(-q2.top() <= t) {
                    q2.pop();
                    q3.push(-(t+t3));
                } else break;
            }
        }
        if(q2.size() < n2) {
            while(1) {
                if(q1.empty() || q2.size() == n2) break;
                if(-q1.top() <= t) {
                    q1.pop();
                    q2.push(-(t+t2));
                } else break;
            }
        }
        if(ini > 0) {
            while(ini && q1.size() < n1) {
                q1.push(-(t+t1));
                ini--;
            }
        }
        if(k == 0) break;
    }
    cout << t << endl;
    return 0;
}

