#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

struct rena {
    string nome;
    int idade, peso;
    double altura;
};

rena renas[111111];

bool ord(rena a, rena b) {
    if(a.peso == b.peso) {
        if(a.idade == b.idade) {
            if(a.altura == b.altura) return a.nome < b.nome;
            return a.altura < b.altura;
        }
        return a.idade < b.idade;
    }
    return a.peso > b.peso;
}

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        printf("CENARIO {%d}\n", t);
        int n, m;
        cin >> n >> m;
        for(int i=0;i<n;i++) cin >> renas[i].nome >> renas[i].peso >> renas[i].idade >> renas[i].altura;
        sort(renas,renas+n,ord);
        for(int i=1;i<=m;i++) {
            printf("%d - ",i);
            cout << renas[i-1].nome << endl;
        }
    }
    return 0;
}

