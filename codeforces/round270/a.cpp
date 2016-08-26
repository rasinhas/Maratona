#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int n;
    cin >> n;
    if(n%2) {
        printf("%d %d\n", n-9,9);
    } else {
        printf("%d %d\n", n-4,4);
    }
    return 0;
}

