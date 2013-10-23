#include <cstdio>
#include <map>
#include <string>
#include <iostream>

using namespace std;

map<string, int> vote;

char c[22][111], p[22][111], v[1111];
int cont[22];

int main()
{
    int i, n, m;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        getchar();  
        scanf("%[^\n]", c[i]);
        getchar();  
        scanf("%[^\n]", p[i]);
        vote[c[i]]=i;
    }
    scanf("%d", &m);
    for(i=0; i<m; i++)
    {
        getchar();  
        scanf("%[^\n]", v);
        if(vote.count(v)) cont[vote[v]]++;
    }
    int max=0, num=0, id;
    for(i=0; i<n; i++) if(cont[i]>max)
    {
        id=i;
        max=cont[i];
    }
    for(i=0; i<n; i++) if(cont[i]==max) num++;
    if(num>1) printf("tie\n");
    else printf("%s\n", p[id]);
    return 0;   
}
