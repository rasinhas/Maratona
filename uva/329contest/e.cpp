#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define sz size()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string s[111], w[55];
int dic[111][33], d[33];
char p[2222], *pt;

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        int n, m;
        printf("Case #%d:\n", t);
        cin >> n >> m;
        memset(dic,0,sizeof(dic));
        for(int i=0;i<n;i++) cin >> s[i];
        for(int i=0;i<n;i++) {
            for(int j=0;j<s[i].sz;j++) {
                dic[i][s[i][j]-'a']++;
            }
        }
        for(int i=0;i<m;i++) {
            getchar();
            scanf("%[^\n]", p);
            int k = 0;
            pt = strtok(p," ");
            while(pt != NULL)
            {
                w[k] = pt;
                pt = strtok(NULL," ");
                k++;
            }
            for(int j=0;j<k;j++) {
                memset(d,0,sizeof(d));
                for(int l=0;l<w[j].sz;l++) {
                    d[w[j][l]-'a']++;
                }
                for(int l=0;l<n;l++) {
                    int f = 1;
                    for(int o=0;o<26;o++) {
                        if(d[o] != dic[l][o]) f = 0;
                    }
                    if(f) {
                        if(j) cout << " ";
                        cout << s[l];
                        break;
                    }
                }
            }
            cout << endl;
        }
    }
    return 0;
}
