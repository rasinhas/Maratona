#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int x[111111], y[111111];

int d2ij(int i, int j) { return (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);}

int main() {
    int n, d;
    cin >> n >> d;
    int d2 = d*d;
    for(int i=0;i<n;i++) scanf("%d%d", &x[i], &y[i]);
    int best = 1;
    int tip = 1;
    int pts[3] = {0,-1,-1};
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int c = 0;
            if(d2ij(i,j) <= d2) {
                best = 2;
                tip = 2;
                pts[0] = i;
                pts[1] = j;
                break;
            }
        }
        if(tip == 2) break;
    }
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) for(int k=j+1;k<n;k++){
        int c = 0;
        if(d2ij(i,j) > d2 || d2ij(i,k) > d2 || d2ij(j,k) > d2) continue;
        for(int l=0;l<n;l++) if(d2ij(i,l) <= d2 && d2ij(j,l) <= d2 && d2ij(k,l) <= d2) c++;
        if(c > best) {
            best = max(c,best);
            tip = 3;
            pts[0] = i;
            pts[1] = j;
            pts[2] = k;
        }
    }
    cout << best << endl;
    if(tip < 3) for(int i=0;i<tip;i++) cout << pts[i]+1 << " ";
    else for(int i=0;i<n;i++) {
        int ok = 1;
        for(int j=0;j<tip;j++) if(d2ij(i,pts[j]) > d2) ok = 0;
        if(ok) cout << i+1 << " ";
    }
    cout << endl;
    return 0;
}

