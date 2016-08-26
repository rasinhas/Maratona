#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

double inversions(vector <int> vec) {
    int r = 0;
    for(int i=0;i<vec.size();i++) for(int j=i+1;j<vec.size();j++) if(vec[j] < vec[i]) r++;
    return 1.0*r;
}

vector <int> invert(vector <int> vec, int l, int r) {
    while(l < r) swap(vec[l++],vec[r--]);
    return vec;
}

double go(vector <int> p, int k, double prob) {
    int n = p.size();
    if(k == 0) return prob*inversions(p);
    double ret = 0.0;
    int intervals = (n*(n+1))/2;
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            ret += go(invert(p,i,j),k-1,(prob/(1.0*intervals)));
        }
    }
    return ret;
}

int main() {
    int n, k;
    vector <int> p;
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        int pa;
        cin >> pa;
        p.push_back(pa);
    }
    printf("%.12lf\n", go(p,k,1.0));
    return 0;
}

