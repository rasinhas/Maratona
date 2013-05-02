#include <iostream>
#include <stdio.h>

using namespace std;

int dx[4]={0,0,1,1};
int dy[4]={0,1,0,1};

int main()
{
    int a, f, b;
    char s[5][5];
    for(int i=0;i<4;i++) scanf("%s", s[i]);
    f = 0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            a = 0;
            b = 0;
            for(int k=0;k<4;k++)
            {
                if(s[i+dx[k]][j+dy[k]] == '#') a++;
                if(s[i+dx[k]][j+dy[k]] == '.') b++;
            }
            if(a >= 3) f = 1;
            if(b >= 3) f = 1;
        }
    }
    if(f) printf("YES\n");
    else printf("NO\n");
    return 0;
}
