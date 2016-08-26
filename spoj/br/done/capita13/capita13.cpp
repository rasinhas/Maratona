#include <bits/stdc++.h>

using namespace std;

int a[4];

int main() {
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a,a+4);
    if(a[0]*a[3] == a[1]*a[2]) cout << "S" << endl;
    else cout << "N" << endl;
    return 0;
}
