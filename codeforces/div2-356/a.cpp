#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int a[5];

int main() {
    for(int i=0;i<5;i++) cin >> a[i];
    sort(a,a+5);
    int s = 0;
    int b = 0;
    for(int i=0;i<5;i++) s += a[i];
    for(int i=5;i>0;i--) {
        if(a[i] == a[i-1]) b = max(b,2*a[i]);
        if(i > 1 && a[i] == a[i-1] && a[i] == a[i-2]) b = max(b,3*a[i]);
    }
    cout << s-b << endl;
    return 0;
}

