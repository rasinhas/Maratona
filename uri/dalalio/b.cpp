#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll m[111][111];

int main() {
    int n;
    while(cin >> n && n) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                m[i][j] = (1<<(i+j));
            }
        }
        for(int i=0;i<n;i++) {
            if(n < 3) {
                printf("%1lld", m[i][0]);
                for(int j=1;j<n;j++) printf(" %1lld", m[i][j]); 
            } else if(n < 5) {
                printf("%2lld", m[i][0]);
                for(int j=1;j<n;j++) printf(" %2lld", m[i][j]); 
            } else if(n < 6) {
                printf("%3lld", m[i][0]);
                for(int j=1;j<n;j++) printf(" %3lld", m[i][j]); 
            } else if(n < 8) {
                printf("%4lld", m[i][0]);
                for(int j=1;j<n;j++) printf(" %4lld", m[i][j]); 
            } else if(n < 10) {
                printf("%5lld", m[i][0]);
                for(int j=1;j<n;j++) printf(" %5lld", m[i][j]); 
            } else if(n < 11) {
                printf("%6lld", m[i][0]);
                for(int j=1;j<n;j++) printf(" %6lld", m[i][j]); 
            } else if(n < 13) {
                printf("%7lld", m[i][0]);
                for(int j=1;j<n;j++) printf(" %7lld", m[i][j]); 
            } else if(n < 15) {
                printf("%8lld", m[i][0]);
                for(int j=1;j<n;j++) printf(" %8lld", m[i][j]); 
            } else if(n < 16) {
                printf("%9lld", m[i][0]);
                for(int j=1;j<n;j++) printf(" %9lld", m[i][j]); 
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

