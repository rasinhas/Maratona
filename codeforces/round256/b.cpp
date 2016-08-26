#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int cs[33], ct[33];

int main() {
    string s, t;
    cin >> s;
    cin >> t;
    for(int i=0;i<s.size();i++) cs[s[i]-'a']++;
    int na=0, nb=0, nt=0;
    for(int i=0;i<t.size();i++) {
        cs[t[i]-'a']--;
        if(cs[t[i]-'a'] < 0) nt = 1;
    }
    if(s.size() > t.size()) nb = 1;
    int c = 0;
    for(int i=0;i<s.size();i++) {
        if(s[i] == t[c]) c++;
        if(c == t.size()) break;
    }
    if(c != t.size()) na = 1;
    if(nt) cout << "need tree" << endl;
    else {
        if(na&nb) cout << "both" << endl;
        else if(na) cout << "array" << endl;
        else if(nb) cout << "automaton" << endl;
    }
    return 0;
}

