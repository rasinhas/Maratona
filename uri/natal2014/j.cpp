#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        for(int i=1;i<=n;i+=2) {
            int s = (n-i)/2;
            for(int j=0;j<s;j++) printf(" ");
            for(int j=0;j<i;j++) printf("*");
            printf("\n");
        }
        for(int i=1;i<=3;i+=2) {
            int s = (n-i)/2;
            for(int j=0;j<s;j++) printf(" ");
            for(int j=0;j<i;j++) printf("*");
            printf("\n");
        }
        cout << endl;
    }
    return 0;
}

