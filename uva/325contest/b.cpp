#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char c[11111];
    while(scanf("%s", c) != EOF)
    {
        getchar();
        int r = 0;
        int l = strlen(c);
        int nz = 0;
        for(int i=0;i<l;i++)
        {
            if(c[i] == '1')
            {
                if(nz == 0) nz += 2;
                else nz++;
            }
            else 
            {
                nz = max(0,nz-1);
                if(nz == 0) r++;
            }
        }
        if(nz == 0) cout << r << endl;
        else cout << 0 << endl;
    }
    return 0;
}
