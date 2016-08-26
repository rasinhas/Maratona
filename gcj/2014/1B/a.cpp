#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e2+10;

int pt[N], npt[N];
string s[N];
int n;

int mod(int a) { return a > 0 ? a : -a; }

int solve() {
	int pa=0, ret=0;
	while(1) {
		int ca = s[0][pa];
		int sz[N];
		for(int i=0;i<n;i++) {
			if(s[i][pt[i]] != ca) return -1;
			if(pt[i] == s[i].size()) return -1;
			while(s[i][npt[i]] == ca) {
				npt[i]++;
			}
			sz[i] = npt[i]-pt[i]+1;
		}
		sort(sz,sz+n);
		int c=0;
		for(int i=0;i<n;i++) {
			ret += mod(sz[i] - sz[n/2]);
		 	pt[i] = npt[i];
			if(pt[i] == s[i].size()) c++;
		}
		pa = npt[0];
		if(c == n) return ret;
		else if(c == 0) continue;
		else return -1;
	}
}

int main() {
	int T;
	cin >> T;
	for(int t=1;t<=T;t++) {
		int ok = 1;
		cin >> n;
		for(int i=0;i<n;i++) cin >> s[i];
		memset(pt,0,sizeof(pt));
		memset(npt,0,sizeof(npt));
		int r = solve();
		printf("Case #%d: ", t);
		if(r == -1) printf("Fegla Won\n");
		else printf("%d\n", r);
	}
	return 0;
}
