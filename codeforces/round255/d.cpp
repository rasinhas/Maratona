#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int a[1111][1111];
ll r[1111], c[1111];

int main() {
    int n, m, k, p;
    scanf("%d %d %d %d", &n, &m, &k, &p);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        scanf("%d", &a[i][j]);
        r[i] += a[i][j];
        c[j] += a[i][j];
    }
    // se eu pegar uma linha -> todas as colunas perdem p
    // se eu pegar uma coluna -> todas as linhas perdem p
    ll cc=0, rc=0;
    priority_queue <ll> rq, cq;
    for(int i=0;i<n;i++) rq.push(r[i]);
    for(int i=0;i<m;i++) cq.push(c[i]);
    ll s = 0;
    for(int i=0;i<k;i++) {
        ll ru = rq.top();
        ll cu = cq.top();
        if(ru - p*cc > cu - p*rc) {
            rq.pop();
            s += (ru - p*cc);
            rc++;
            rq.push(ru - m*p);
        } else {
            cq.pop();
            s += (cu - p*rc);
            cc++;
            cq.push(cu - n*p);
        }
    }
    cout << s << endl;
    return 0;
}
