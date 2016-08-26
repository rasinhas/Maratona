#include <iostream>
#include <cstdio>
#include <string>
#include <set>

using namespace std;

string s[1111];
set <int> d;

int main() 
{
    int n, m;
    bool ok = true;
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=0;i<n;i++) {
        int k = -1;
        for(int j=0;j<m;j++) {
            if(s[i][j] == 'G') k = 0;
            if(k == -1){
                if(s[i][j] == 'S') ok = false;
                else k++;
            } else {
                if(s[i][j] == 'S') d.insert(k);
                else k++;
            }
        }
    }
    if(ok) cout << d.size() << endl;
    else cout << -1 << endl;
    return 0;
}
