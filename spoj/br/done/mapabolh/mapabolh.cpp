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

char str[5001], adj[4][5001];

void up(int a)
{
    if(str[a] == 's') adj[0][a] = 'p';
    else if(str[a] == 'r') adj[0][a] = 'q';
    else if(str[a] == 'p') { adj[0][a] = 's'; return up(a-1);}
    else if(str[a] == 'q') { adj[0][a] = 'r'; return up(a-1);}
    else if(str[a] == 'm') { strcpy(adj[0], "<none>"); return;}
}

void down(int a)
{
    if(str[a] == 'p') adj[1][a] = 's';
    else if(str[a] == 'q') adj[1][a] = 'r';
    else if(str[a] == 's') { adj[1][a] = 'p'; return down(a-1);}
    else if(str[a] == 'r') { adj[1][a] = 'q'; return down(a-1);}
    else if(str[a] == 'm') { strcpy(adj[1], "<none>"); return;}
}

void left(int a)
{
    if(str[a] == 'r') adj[2][a] = 's';
    else if(str[a] == 'q') adj[2][a] = 'p';
    else if(str[a] == 's') { adj[2][a] = 'r'; return left(a-1);}
    else if(str[a] == 'p') { adj[2][a] = 'q'; return left(a-1);}
    else if(str[a] == 'm') { strcpy(adj[2], "<none>"); return;}
}

void right(int a)
{
    if(str[a] == 's') adj[3][a] = 'r';
    else if(str[a] == 'p') adj[3][a] = 'q';
    else if(str[a] == 'r') { adj[3][a] = 's'; return right(a-1);}
    else if(str[a] == 'q') { adj[3][a] = 'p'; return right(a-1);}
    else if(str[a] == 'm') { strcpy(adj[3], "<none>"); return;}
}

int main()
{
    int n, len;
    scanf("%d", &n);
    while(n--)
    {
        scanf(" %s", str);
        len = strlen(str)-1;
        for(int i=0;i<4;i++) strcpy(adj[i], str);
        up(len);
        down(len);
        left(len);
        right(len);
        for(int i=0;i<4;i++) printf("%s ", adj[i]);
        printf("\n");
    }
	return 0;
}
