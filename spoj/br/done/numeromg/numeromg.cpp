#include <bits/stdc++.h>

using namespace std;

//char a[11], b[11];

int index_of(char c) {
    if(c >= '0' && c <= '9') return c-'0';
    else return (c-'A')+10;
}

int char_of(int i) {
    if(i < 10) return '0'+i;
    else return 'A'+i-10;
}

int to_int(string s) {
    int sz = s.size();
    int mul = 1;
    int ret = 0;
    for(int i=sz-1;i>=0;i--) {
        ret += (index_of(s[i])*mul);
        mul *= 36;
    }
    return ret;
}

string to_string(int x) {
    string s;
    while(x) {
        s += char_of(x%36);
        x /= 36;
    }
    reverse(s.begin(),s.end());
    return s;
}

int main() {
    string a, b;
    while(1) {
        cin >> a >> b;
        if(a == "0" && b == "0") break;
        int ai = to_int(a), bi = to_int(b);
        cout << to_string(ai+bi) << endl;
    }
    return 0;
}
