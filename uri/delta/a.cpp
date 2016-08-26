#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sz size()

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const ll inf = (int)1e18;

char s[11111];
string str[11111];
map <string,int> m;
map <string,int>::iterator it;
map <string,string> dic;
pair <string, int> best[30];

int main() 
{
    while(scanf("%[^\n]", s) && s[0] != '.') {
        getchar();
        m.clear();
        for(int i=0;i<30;i++) best[i] = mp("",0);
        char *p;
        p = strtok(s, " ");
        string st;
        int k=0;
        while(p != NULL) {
            st = p;
            str[k++] = p;
            dic[st] = st;
            m[st]++;
            p = strtok(NULL," ");
        }
        for(it=m.begin();it!=m.end();it++) {
            string f = it->first;
            int sc = (it->second)*(f.size()-2);
            if(sc > best[f[0]-'a'].ss) {
                dic[best[f[0]-'a'].ff] = best[f[0]-'a'].ff;
                best[f[0]-'a'] = mp(f, sc);
                dic[f] = f[0];
                dic[f] += ".";
            }
        }
        int ab = 0;
        for(int i=0;i<26;i++) if(best[i].ss > 0) ab++;
        cout << dic[str[0]];
        for(int i=1;i<k;i++) {
            cout << " " << dic[str[i]];
        }
        cout << endl;
        cout << ab << endl;
        for(int i=0;i<26;i++) if(best[i].ss > 0) cout << dic[best[i].ff] << " = " << best[i].ff << endl;
    }
    return 0;
}
