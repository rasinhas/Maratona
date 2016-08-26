#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int a[555555];
ll v[555555];
vector <int> v1, v2;

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        scanf("%d", &a[i]);
        v[i] = a[i];
        if(i) v[i] += v[i-1];
    }
    ll s = v[n-1];
    if(s%3 != 0) cout << 0 << endl;
    else if(n < 3) cout << 0 << endl;
    else {
        for(int i=0;i<n-1;i++) {
            if(v[i] == s/3) v1.push_back(i);
            if(v[i] == 2*s/3) v2.push_back(i);
        }
        ll r = 0;
        int j = 0;
        for(int i=0;i<v1.size();i++) {
            if(j >= v2.size()) break;
            while(j < v2.size() && v2[j] <= v1[i]) j++;
            r += (v2.size()-j);
        }
        cout << r << endl;
    }
    return 0;
}
