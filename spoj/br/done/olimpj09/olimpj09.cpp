#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
#define rep(i,n) for(i=0;i<(n);i++)

using namespace std;

struct pais
{
    int m;
    int id;
};

bool compara(pais a, pais b)
{
    if(a.m>b.m) return true;
    else if(a.m<b.m) return false;
    else
    {
        if(a.id<b.id) return true;
        else return false;
    }
}

int main()
{
    vector <pais> quadro;
    pais aux;
    int i, n, m, o, p, b;
    scanf("%d%d", &n, &m);
    for(i=0;i<n;i++) 
    {
        aux.id=i;
        aux.m=0;
        quadro.push_back(aux);
    }
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d", &o, &p, &b);
        quadro[o-1].m++;
        quadro[p-1].m++;
        quadro[b-1].m++;
    }
    sort(quadro.begin(),quadro.end(),compara);
    for(i=0;i<n;i++) printf("%d ",quadro[i].id+1);
    printf("\n");
	return 0;
}

