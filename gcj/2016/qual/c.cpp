#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string value(int n, int k) {
    string s = "1";
    while(k) {
        if(k%2) s += "11";
        else s += "00";
        k /= 2;
    }
    while(s.size() < n) s += '0';
    reverse(s.begin(),s.end());
    s[0] = '1';
    return s;
}

int main() {
    int t, n, j;
    cin >> t;
    cin >> n >> j;
    printf("Case #1: \n");
    std::string s;
    for(int i=0;i<n;i++) s += '0';
    s[0] = s[n-1] = '1';
    int k = 0;
    while(j--) {
        cout << value(n,k);
        for(int i=2;i<=10;i++) cout << " " << (i%2 ? 2 : i+1);
        cout << endl;
        k++;
    }
    return 0;
}

