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

int main()
{
    int n, p, f;
    int i, j, k, prim, cmp;
    string pal, phr;
    char str[1000];
    char *pch;
    char a;
    vector <string> esp;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        esp.clear();
        scanf("%d%d", &p, &f);
        for(j=0;j<p;j++)
        {
            cin >> pal;
            for(k=0;k<pal.size();k++) pal[k] = tolower(pal[k]);
            //cout << pal << endl;
            esp.push_back(pal);
        }
        getc(stdin);
        for(j=0;j<f;j++)
        {
            prim = 1;
            scanf("%[^\n]", str);
            for(k=0;k<strlen(str);k++) str[k] = tolower(str[k]);
            pch = strtok(str," -:");
            while(pch != NULL)
            {
                cmp = 0;
                for(k=0;k<p;k++)
                {
                    if(!esp[k].compare(pch))
                    {
                        cmp = 1;
                        if(prim) break;
                        else printf("%c",pch[0]);
                    }
                }
                if(!cmp) printf("%c", toupper(pch[0]));
                prim = 0;
                pch = strtok(NULL," -:");
            }
            getc(stdin);
            printf("\n");
        }
        printf("\n");
    }
	return 0;
}
