#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int c[10][26], z[26];

int l(char c) { return c-'A';}

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        string r = "", s;
        printf("Case #%d: ", t);
        cin >> s;
        for(int i=0;i<s.size();i++) z[s[i]-'A']++;
        while(z[l('Z')]) {
            z[l('Z')]--;
            z[l('E')]--;
            z[l('R')]--;
            z[l('O')]--;
            r += '0';
        }
        while(z[l('W')]) {
            z[l('T')]--;
            z[l('W')]--;
            z[l('O')]--;
            r += '2';
        }
        while(z[l('U')]) {
            z[l('F')]--;
            z[l('O')]--;
            z[l('U')]--;
            z[l('R')]--;
            r += '4';
        }
        while(z[l('X')]) {
            z[l('S')]--;
            z[l('I')]--;
            z[l('X')]--;
            r += '6';
        }
        while(z[l('G')]) {
            z[l('E')]--;
            z[l('I')]--;
            z[l('G')]--;
            z[l('H')]--;
            z[l('T')]--;
            r += '8';
        }
        while(z[l('H')]) {
            z[l('T')]--;
            z[l('H')]--;
            z[l('R')]--;
            z[l('E')]--;
            z[l('E')]--;
            r += '3';
        }
        while(z[l('O')]) {
            z[l('O')]--;
            z[l('N')]--;
            z[l('E')]--;
            r += '1';
        }
        while(z[l('S')]) {
            z[l('S')]--;
            z[l('E')]--;
            z[l('V')]--;
            z[l('E')]--;
            z[l('N')]--;
            r += '7';
        }
        while(z[l('V')]) {
            z[l('F')]--;
            z[l('I')]--;
            z[l('V')]--;
            z[l('E')]--;
            r += '5';
        }
        while(z[l('N')]) {
            z[l('N')]--;
            z[l('I')]--;
            z[l('N')]--;
            z[l('E')]--;
            r += '9';
        }
        sort(r.begin(),r.end());
        cout << r << endl;
    }
    return 0;
}

