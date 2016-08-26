#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, a, b;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &a, &b);
        if(a < 0 && b > 0) a++;
        cout << b-a << endl;
    }
    return 0;
}
