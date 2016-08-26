#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    string n, e="";
    int k;
    cin >> n >> k;
    for(int i=0;i<n.size();i++) {
        char m = n[i];
        int p = i;
        for(int j=i+1;j<min((int)n.size(),i+k+1);j++) {
            if(n[j] > m) {
                m = n[j];
                p = j;
            }
        }
        for(int j=p;j>i;j--) swap(n[j],n[j-1]);
        k -= (p-i);
    }
    cout << n << endl;
    return 0;
}

