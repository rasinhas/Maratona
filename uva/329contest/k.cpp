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
    int T, n, k;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> n >> k;
        double p = 1;
        for(int i=0;i<n/k;i++) p /= n;
        cout << p << endl;
        for(int i=n/k;i>0;i--) {
        }
    }
    return 0;
}
