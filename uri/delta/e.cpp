#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sz size()

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const ll inf = (int)1e9;

pii arriv[11111], depart[11111];
stack <int> park;

int main() 
{
    int n, k;
    while(scanf("%d%d", &n, &k) && n) {
        for(int i=0;i<n;i++) {
            int a, d;
            cin >> a >> d;
            arriv[i] = mp(a,i);
            depart[i] = mp(d,i);
        }
        arriv[n] = mp(inf,inf);
        depart[n] = mp(inf,inf);
        sort(arriv,arriv+n);
        sort(depart,depart+n);
        int pa=0, pd=0;
        int ok = 1;
        while(1) {
            if(pd == n && pa == n) break;
            if(park.size() > k) ok = 0;
            if(depart[pd].ff <= arriv[pa].ff) {
                if(park.top() == depart[pd].ss) park.pop();
                else ok = 0;
                pd++;
            } else {
                park.push(arriv[pa].ss);
                pa++;
            }
            if(!ok) break;
        }
        while(!park.empty()) park.pop();
        cout << (ok ? "Sim" : "Nao") << endl;
    }
    return 0;
}
