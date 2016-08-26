#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

map <string, double> p;
char c[1111];

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, q;
        double a, cap;
        string s;
        cin >> n;
        getchar();
        for(int i=0;i<n;i++) {
            getline(cin,s);
            scanf(" %lf ", &a);
            p[s] = a;
        }
        scanf(" %lf ", &cap);
        double pt = 0;
        while(getline(cin,s)) {
            scanf(" %d ", &q);
            if(q == 0) break;
            if(!p.count(s)) {
                cout << "NAO LISTADO: " << s << endl;
                continue;
            }
            pt += (p[s]*q);
        }
        int qt = ceil(pt/cap);
        printf("Peso total: %.2lf kg\n", pt);
        cout << "Numero de trenos: " << qt << endl;
        cout << endl;
    }
    return 0;
}

