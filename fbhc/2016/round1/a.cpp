#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int T, n;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> n;
        int cur=0, last=0, cnt=0, ret=0;
        for(int i=0;i<n;i++) {
            cin >> cur;
            if(cnt) {
                int needs = ((cur-last+9)/10)-1;
                if(needs < 0 || needs > 3-cnt) {
                    ret += 4-cnt;
                    cnt = 0;
                } else {
                    ret += needs;
                    cnt += needs;
                }
                cnt++;
            } else cnt++;
            last = cur;
        }
        ret += (4-cnt);
        printf("Case #%d: %d\n", t, ret);
    }
    return 0;
}

