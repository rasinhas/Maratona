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
        printf("Case #%d: ", t);
        cin >> n;
        if(n == 0) cout << "INSOMNIA" << endl;
        else {
            int m = 0, k, i = 0;
            while(m != (1<<10)-1) {
                i++;
                k = i*n;
                while(k) {
                    m |= (1<<(k%10));
                    k /= 10;
                }
            }
            cout << i*n << endl;
        }
    }
    return 0;
}

