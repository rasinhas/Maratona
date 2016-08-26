#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    queue <char> q1, q2;
    for(int i=0;i<s1.size();i++) q1.push(s1[i]);
    for(int i=0;i<s2.size();i++) q2.push(s2[i]);
    q1.push('0');
    q2.push('0');
    int t = 0;
    while(1) {
        char c1 = q1.front(), c2 = q2.front();
        if(c1 == '0' && c2 == '0') break;
        if(c1 == 'F') q1.pop();
        if(c1 == 'R') q1.pop();
        if(c1 == 'L' && (c2 == 'L' || c2 == '0')) q1.pop(); 
        if(c2 == 'F') q2.pop();
        if(c2 == 'R') q2.pop();
        if(c2 == 'L' && (c1 == 'L' || c1 == '0')) q2.pop(); 
        t++;
    }
    cout << t << endl;
    return 0;
}

