#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctype.h>
#define INF 0x3f3f3f3f

using namespace std;

int f[13] = {-1, 306, 337, 0, 31, 61, 92, 122, 153, 184, 214, 245, 275};

int main()
{
    int n, i, dia, mes, ano, a, b, c, d, cnt;
    map <int, string> nome;
    vector < pair< int,int> > v;
    string str;
    scanf("%d", &n);
    nome.clear();
    cnt = 0;
    for(i=0;i<n;i++)
    {
        cin >> str;
        nome[cnt] = str;
        scanf("%d%d%d", &dia, &mes, &ano);
        if(mes <= 2) --ano;
        a = ano/4;
        b = ano/100;
        c = ano/400;
        d = dia + f[mes] + ano*365 + a - b + c;
        v.push_back(make_pair(d,cnt++));
    }
    sort(v.begin(),v.end());
    cout << nome[v[n-1].second] << endl << nome[v[0].second] << endl;
	return 0;
}
