#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int p[] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int main() {
    int next = p[15], i = 15;
    int d = 0;
    string s;
    for(int j=0;j<20;j++) {
        cout << next << endl;
        fflush(stdout);
        fflush(stdout);
        cin >> s;
        fflush(stdout);
        fflush(stdout);
        if(s == "yes") {
            d++;
            if(next*next <= 100) next *= next;
            else next = p[--i];
        } else next = p[--i];
        if(i == 0) break;
        if(d > 1) break;
    }
    cout << (d > 1 ? "composite" : "prime") << endl;
    return 0;
}

