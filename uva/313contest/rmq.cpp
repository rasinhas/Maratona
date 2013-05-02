#include <stdio.h>
#define MOD 1000000007

using namespace std;

int main()
{
    int n, l, r, ans, k;
    char str[11000];
    while(scanf("%d", &n) != EOF)
    {
        scanf("%s", str);
        ans = 0;
        for(int i=0;i<n;i++)
        {
            l = r = 0;
            while(i-l > 0 && str[i-l-1] > str[i]) l++;
            while(i+r < n-1 && str[i+r+1] >= str[i]) r++;
            k = ((l+1)*(r+1))%MOD;
            ans = (ans + (str[i]-'0')*k)%MOD;
        }
        printf("%d\n", ans);
    }
}
