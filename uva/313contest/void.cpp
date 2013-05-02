#include <stdio.h>
#define MOD 1000000007


using namespace std;

int main()
{
    int t, n;
    long long ret, mi;
    int w[7000];
    scanf("%d", &t);
    for(int i=0;i<t;i++)
    {
        scanf("%d", &n);
        ret = 1;
        mi = 0;
        for(int j=0;j<n;j++)
        {
            scanf("%d", &w[j]);
            ret = (ret * (w[j]+1))%MOD;
            mi = (mi + w[j])%MOD;
        }
        mi++;
        ret = (ret + (MOD - mi))%MOD;
        printf("%lld\n", ret);
    }
    return 0;
}
