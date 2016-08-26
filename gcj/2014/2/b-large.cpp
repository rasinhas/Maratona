#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int a[1111];
vector<int> b;

int mod(int a) { return a > 0 ? a : -a; }

int bubble1(int ini, int fim, vector <int> v) {
    if(ini >= fim) return 0;
    int r = 0;
    for(int i=ini;i<fim;i++) {
        int s = 0;
        for(int j=ini;j<fim;j++) {
            if(v[j] > v[j+1]) {
                swap(v[j],v[j+1]);
                r++;
                s++;
            }
        }
        if(s == 0) break;
    }
    return r;
}

int bubble2(int ini, int fim, vector <int> v) {
    if(ini >= fim) return 0;
    int r = 0;
    cout << "#";
    for(int i=ini;i<=fim;i++) cout << v[i] << " ";
    cout << endl;
    for(int i=ini;i<=fim;i++) {
        int s = 0;
        for(int j=ini;j<fim;j++) {
            if(v[j] < v[j+1]) {
                swap(v[j],v[j+1]);
                r++;
                s++;
            }
        }
        if(s == 0) break;
    }
    return r;
}

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        int n;
        cin >> n;
        for(int i=0;i<n;i++) cin >> a[i];
        int m = *max_element(a,a+n);
        int mp = 0;
        b.clear();
        for(int i=0;i<n;i++) {
            if(a[i] != m) b.push_back(a[i]);
            else mp = i;
        }
        int ret = 1e9;
        for(int i=2;i<3;i++) {
            int r = mod(mp-i);
            cout << r << endl;
            r += bubble1(0,i-1,b);
            cout << bubble1(0,i-1,b) << endl;
            r += bubble2(i,n-2,b);
            cout << bubble2(i,n-2,b) << endl;
            ret = min(ret,r);
        }
        printf("Case #%d: %d\n", t, ret);
    }
    return 0;
}

