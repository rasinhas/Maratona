#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string s[7] = {"+------------------------+",
               "|#.#.#.#.#.#.#.#.#.#.#.|D|)",
               "|#.#.#.#.#.#.#.#.#.#.#.|.|",
               "|#.......................|",
               "|#.#.#.#.#.#.#.#.#.#.#.|.|)",
               "+------------------------+"};

int main() {
    int n;
    cin >> n;
    for(int i=0;i<s[0].size();i++) {
        for(int j=1;j<5;j++) {
            if(n == 0) break;
            if(s[j][i] == '#') {
                s[j][i] = 'O';
                n--;
            }
        }
    }
    for(int i=0;i<6;i++) cout << s[i] << endl;
    return 0;
}

