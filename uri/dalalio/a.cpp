#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

set <string> us;
int f[26][1111];
string s;

void go(string n, int i) {
    if(us.count(n)) return;
    else {
        us.insert(n);
        if(i >= s.size()) return;
        for(int j=0;j<26;j++) {
            string k = n;
            if(f[j][i] >= s.size()) continue;
            k += s[f[j][i]];
            go(k,f[j][i]+1);
        }
    }
}

int main() {
    while(cin >> s && !cin.eof()) {
        us.clear();
        for(int i=0;i<26;i++) {
            for(int j=s.size()-1;j>=0;j--) {
                f[i][j] = (int)s.size();
                if(j < s.size()-1) f[i][j] = f[i][j+1];
                if(s[j] == 'a'+i) f[i][j] = j;
            }
        }
        go("",0);
        set<string>::iterator it = us.begin();
        it++;
        for(;it!=us.end();it++) {
            for(int j=0;j<(*it).size();j++) printf("%c", (*it)[j]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}

