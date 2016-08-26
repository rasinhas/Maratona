#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[444444], l[444444];
int a[111111];

int main()
{
    int i=0;
    while(scanf("%[^\n]", s) != EOF)
    {
        getchar();
        int ac=0, m=0;
        char *pch;
        pch = strtok(s," ");
        while(pch != NULL)
        {
            sscanf(pch,"%d",&a[i]);
            pch = strtok(NULL," ");
            ac += a[i];
            m = max(m,ac);
            if(ac < 0) ac = 0;
            i++; 
        }
        cout << m << endl;
        i = 0;
    }
    return 0;
}
