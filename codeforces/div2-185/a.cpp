#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#define sz size()

using namespace std;

int main()
{
    int n, r, f;
    string s;
    char c[1000], p[1000],  fs[100]="lala.", rs[100]="miao.";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        getchar();
        r = f = 0;
        scanf("%[^\n]", c);
        int len = strlen(c);
        if(c[0] == 'm' && c[1] == 'i' && c[2] == 'a' && c[3] == 'o' && c[4] == '.') r = 1;
        if(c[len-1] == '.' && c[len-2] == 'a' && c[len-3] == 'l' && c[len-4] == 'a' && c[len-5] == 'l') f = 1;
        if(r == 1 && f == 0) printf("Rainbow's\n");
        else if(r == 0 && f == 1) printf("Freda's\n");
        else printf("OMG>.< I don't know!\n");
    }
    return 0;
}
