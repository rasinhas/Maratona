#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string ee[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0;i<8;i++) {
        int j;
        if(n != ee[i].size()) continue;
        for(j=0;j<s.size();j++) {
            if(s[j] == '.') continue;
            else {
                if(s[j] != ee[i][j]) break;
            }
        }
        if(j == n && j == s.size()) {
            cout << ee[i] << endl;
            break;
        }
    }
    return 0;
}

