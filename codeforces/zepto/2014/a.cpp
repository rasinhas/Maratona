#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

struct candy {
    int t;
    int h;
    int m;
};

int n, x;
candy c[2222];
vector <candy> car;
vector <candy> fru;

bool cmp1(candy a, candy b) {
    return a.h < b.h;
}

bool cmp2(candy a, candy b) {
    return a.m > b.m;
}

int solve(vector<candy> f, vector<candy> s, int h) {
    int r = 0;
    vector <candy> vf, vs;
    int pf=0, ps=0, fc=0, sc=0;
    for(int t=0;t<n;t++) {
        if(t%2 == 0) {
            for(;pf<f.size() && f[pf].h <= h;pf++) if(f[pf].h <= h) vf.push_back(f[pf]);
            sort(vf.begin()+fc,vf.end(),cmp2);
            if(fc >= vf.size()) break;
            h += vf[fc++].m;
            r++;
        } else {
            for(;ps<s.size() && s[ps].h <= h;ps++) if(s[ps].h <= h) vs.push_back(s[ps]);
            sort(vs.begin()+sc,vs.end(),cmp2);
            if(sc >= vs.size()) break;
            h += vs[sc++].m;
            r++;
        }
    }
    return r;
}

int main() {
    cin >> n >> x;
    for(int i=0;i<n;i++) {
        cin >> c[i].t >> c[i].h >> c[i].m;
        if(c[i].t == 0) car.push_back(c[i]);
        else fru.push_back(c[i]);
    }
    sort(car.begin(),car.end(),cmp1);
    sort(fru.begin(),fru.end(),cmp1);
    cout << max(solve(car,fru,x), solve(fru,car,x)) << endl;
    return 0;
}

