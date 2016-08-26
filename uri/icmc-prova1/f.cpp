#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string divide(string s) {
    string ret = "";
    if(s == "1") return "0";
    int c = (s[0] == '1' ? 1 : 0);
    for(int i=c;i<s.size();i++) {
        int v = c*10 + (s[i]-'0');
        c = v%2;
        ret += (v/2)+'0';
    }
    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        string s;
        int c = 0;
        cin >> s;
        while(1) {
            if(s == "0") break;
            if((s[s.size()-1]-'0')%2) c++;
            s = divide(s);
        }
        cout << c << endl;
    }
    return 0;
}

