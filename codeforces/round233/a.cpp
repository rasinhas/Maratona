#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main() 
{
    int n, p, k;
    cin >> n >> p >> k;
    int f = max(p-k,1), l=min(p+k,n);
    if(f != 1) cout << "<< ";
    for(int i=f;i<=l;i++) {
        if(i != f) cout << " ";
        if(i == p) cout << "(" << i << ")";
        else cout << i;
    }
    if(l != n) cout << " >>";
    cout << endl;
    return 0;
}
