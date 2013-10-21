#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t, a, b, c;
    while(scanf("%d", &t) != EOF)
    {
        while(t--)
        {
            cin >> a >> b >> c;
            int p = 0, k;
            printf("0");
            if(c%3 == 0)
            {
                k = c/3;
                for(int i=1;i<=k;i++) printf(" %d", 3*i);
                for(int i=k;i>=0;i--) printf(" %d", 3*i+1);
                for(int i=0;i<=k;i++) printf(" %d", 3*i+2);
                c = 0;
                a -= 2;
                p = 3*k+2;
            }
            else if(c%3 == 1)
            {
                k = c/3+1;
                for(int i=1;i<=k;i++) printf(" %d", 3*i);
                for(int i=k;i>=1;i--) printf(" %d", 3*i-2);
                for(int i=1;i<=k;i++) printf(" %d", 3*i-1);
                printf(" %d", 3*k+1);
                c = 0;
                a -= 1;
                b -= 2;
                p = 3*k+1;
            }
            else 
            {
                k = c/3+1;
                for(int i=1;i<=k;i++) printf(" %d", 3*i);
                for(int i=k;i>=1;i--) printf(" %d", 3*i-1);
                for(int i=1;i<=k+1;i++) printf(" %d", 3*i-2);
                c = 0;
                a -= 2;
                p = 3*k+1;
            }
            for(;a > 1;a--) printf(" %d", ++p);
            if(b%2 == 0)
            {
                k = b/2;
                for(int i=1;i<=k;i++) printf(" %d", p+2*i);
                for(int i=k;i>=0;i--) printf(" %d", p+2*i+1);
                b = 0;
                a--;
            }
            else
            {
                k = b/2+1;
                for(int i=1;i<=k;i++) printf(" %d", p+2*i);
                for(int i=k;i>=1;i--) printf(" %d", p+2*i-1);
                b = 0;
                a--;
            }
            printf("\n");
        }
    }
    return 0;
}
