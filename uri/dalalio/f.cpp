#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int hh[11], mm[11], ph[11] = {8,18,28,38}, pm[11] = {8,14,20,26,32,38};
string cloc[33] =  {" ____________________________________________",
"|                                            |",
"|    ____________________________________    |_",
"|   |                                    |   |_)",
"|   |   8         4         2         1  |   |",
"|   |                                    |   |",
"|   |                                    |   |",
"|   |                                    |   |",
"|   |                                    |   |",
"|   |                                    |   |",
"|   |                                    |   |",
"|   |   32    16    8     4     2     1  |   |_",
"|   |____________________________________|   |_)",
"|                                            |",
"|____________________________________________|"};

int main() {
    int h, m;
    while(scanf("%d:%d", &h, &m) != EOF) {
        for(int i=0;i<4;i++) {
            if(h&(1<<(3-i))) cloc[6][ph[i]] = 'o';
            else cloc[6][ph[i]] = ' ';
        }
        for(int i=0;i<6;i++) {
            if(m&(1<<(5-i))) cloc[9][pm[i]] = 'o';
            else cloc[9][pm[i]] = ' ';
        }
        for(int i=0;i<15;i++) cout << cloc[i] << endl;
        cout << endl;
    }
    return 0;
}

