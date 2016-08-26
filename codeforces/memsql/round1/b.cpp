#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int n, m;
    cin >> n >> m;
    if(n == 1 && m == 1) {
        printf("0 0\n");
        printf("1 1\n");
        printf("0 1\n");
        printf("1 0\n");
    }
    else if(n == 0) {
        printf("0 %d\n", m-1);
        printf("0 0\n");
        printf("0 %d\n", m);
        printf("0 1\n");
    }
    else if(m == 0) {
        printf("%d 0\n", n-1);
        printf("0 0\n");
        printf("%d 0\n", n);
        printf("0 0\n");
    }
    else {
        printf("%d %d\n", n-1, m);
        printf("0 0\n");
        printf("%d %d\n", n, m);
        printf("1 0\n");
    }
    return 0;
}

