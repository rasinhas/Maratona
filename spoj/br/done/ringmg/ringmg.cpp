#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int a[1111], c[1111];
int n;

int go(int v, int cc,int dir, int o) {
    if(v == o) return 1;
    cc += a[v]; 
    if(dir == 1) {
        if(cc < c[v]) return 0;
        else return go((v+1)%n,cc-c[v],dir,o);
    } 
    if(dir == 2) {
        if(cc < c[(v-1+n)%n]) return 0;
        else return go((v-1+n)%n,cc-c[(v-1+n)%n],dir,o);
    }
}

int main() {
    while(scanf("%d", &n) && n) {
        for(int i=0;i<n;i++) scanf("%d", &a[i]);
        for(int i=0;i<n;i++) scanf("%d", &c[i]);
        int r1=-1, r2=-1;
        for(int i=0;i<n;i++) {
            if(go(i,0,1,(i-1+n)%n)) r1 = i+1;
            if(r1 != -1) break;
        }
        for(int i=0;i<n;i++) {
            if(go(i,0,2,(i+1)%n)) r2 = i+1;
            if(r2 != -1) break;
        }
        printf("%d %d\n", r1, r2);
    }
    return 0;
}
