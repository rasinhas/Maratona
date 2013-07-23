#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char u[55], d[55];
char s[111];

int to_dec(char *p)
{
    int ret=0;
    int p2=16;
    for(int i=0;i<5;i++)
    {
        if(p[i] == '1') ret += p2;
        p2 /= 2;
    }
    return ret;
}

int main()
{
    scanf("%[^\n]", d);
    getchar();
    scanf("%[^\n]", u);
    getchar();
    while(scanf("%s", s) != EOF)
    {
        int ss=0;
        int len=strlen(s);
        for(int i=0;i<len;i+=5)
        {
            int k = to_dec(s+i);
            if(k == 31) ss = 1;
            else if(k == 27) ss = 0;
            else if(ss == 0) cout << d[k];
            else cout << u[k];
        }
        cout << endl;
    }
    return 0;
}
