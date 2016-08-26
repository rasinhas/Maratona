#include <bits/stdc++.h>

using namespace std;

map <string,int> w;

int main() {
    int n;
    string win, lose;
    cin >> n;
    int k = 0;
    for(int i=0;i<n-1;i++) {
        cin >> win >> lose;
        w[win]++;
    }
    int m = 0;
    for(map<string,int>::iterator it=w.begin();it!=w.end();it++) if(it->second > m) {
		m = it->second;
		win = it->first;
    }
    cout << win << endl;
    return 0;
}
