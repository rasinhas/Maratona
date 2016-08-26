#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define sz size()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const ll mod = (int)1e9+7;

int main() {
    int T;
    string s;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> s;
        int m1 = (s.sz-1)/2;
        int m2 = m1 + 1;
        int k1 = m2;
        int k2 = s.sz-m1-1;
        ll v = 0;
        while(1) {
            if(!(k1 | k2)) break;
            v *= 2;
            if(k1 > k2) {
                v += (s[m1--]-'0');
                k1--;
            } else if(k1 < k2) {
                v += (s[m2++]-'0');
                k2--;
            } else {
                if(s[m1] > s[m2]) {
                    v += (s[m1--]-'0');
                    k1--;
                } else {
                    v += (s[m2++]-'0');
                    k2--;
                }
            }
            v %= mod;
        }
        printf("Case #%d: %lld\n", t, v);
    }
    return 0;
}
