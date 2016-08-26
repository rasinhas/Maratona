#include <iostream>
#include <cstdio>
#include <algorithm>
#define ff first
#define ss second

using namespace std;

typedef long long ll;

int n;
int a[1111][1111];

int calc() {
    int r = 0;
    for(int i=0;i<n;i++) {
        int v=0;
        for(int j=0;j<n;j++) {
            v += a[i][j]*a[j][i];
        }
        r += v;
    }
    return r%2;
}

int main() {
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) scanf("%d", &a[i][j]);
    }
    int v = calc();
    int q, t, k;
    scanf("%d", &q);
    for(int i=0;i<q;i++) {
        scanf("%d", &t);
        if(t == 3) printf("%d",v);
        else if(t == 2) {
            scanf("%d", &k);
            v = 1-v;
        }
        else if(t == 1) {
            scanf("%d", &k);
            v = 1-v;
        }
    }
    cout << endl;
    return 0;
}
