#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    srand(time(NULL));
    int c = rand()%1000 + 1;
    for(int i=0;i<c;i++) cout << "rotacione " << rand()%360 << "." << rand()%10 << " ande " << rand()%50 << " repita " << (rand()%100000 + 1) << endl;
    return 0;
}

