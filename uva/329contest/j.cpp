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

int main() {
    int T, n, m;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> n >> m;
        int k = (m/2) * (n/2);
        int a = (k+1)/2;
        a *= 4;
        int b = m*n-a;
        printf("Case #%d: ", t);
        if(a == b) cout << "Draw\n";
        else if(a > b) cout << "Ana\n";
        else cout << "Bob\n";
    }
    return 0;
}
