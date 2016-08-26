#include <bits/stdc++.h>

using namespace std;

int n;
int a[100000];
map <pair<pair<int,int>, int>, int> memo;

int solve(int x, int y, int msk) {
    if(memo.count(make_pair(make_pair(x,y),msk))) return memo[make_pair(make_pair(x,y),msk)];
    int sz = __builtin_popcount(msk);
    if(sz == 1) return memo[make_pair(make_pair(x,y),msk)] = 1;
    for(int i=1;i<(1<<sz)-1;i++) {
        int sum = 0, pos = 0;
        int msk1 = 0, msk2 = 0, aux=msk;
        while(aux) {
            int j = aux & -aux;
            aux -= j;
            if((1<<pos)&i) {
                sum += a[j];
                msk1 |= j;
            } else msk2 |= j;
            pos++;
        }
        if((sum%x == 0) && solve(x,(sum/x),msk1) && solve(x,y-(sum/x),msk2)) return memo[make_pair(make_pair(x,y),msk)] = 1;
        if((sum%y == 0) && solve((sum/y),y,msk1) && solve(x-(sum/y),y,msk2)) return memo[make_pair(make_pair(x,y),msk)] = 1;
    }
    return memo[make_pair(make_pair(x,y),msk)] = 0;
}

int main() {
    int x, y, t=1;
    while(cin >> n && n) {
        cin >> x >> y;
        int s = 0;
        for(int i=0;i<n;i++) {
            int k;
            cin >> k;
            a[1<<i] = k;
            s += k;
        }
        memo.clear();
        printf("Case %d: %s\n", t++, (s == x*y && solve(x,y,(1<<n)-1) ? "Yes" : "No"));
    }
    return 0;
}
