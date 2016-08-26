#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    srand(time(NULL));
    int n = 15;
    printf("%d\n", n);
    for(int i=0;i<n;i++) {
        printf("%.6lf\n", (rand()%100000)/100000.0);
    }
    return 0;
}

