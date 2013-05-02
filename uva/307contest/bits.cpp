#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int main()
{
    int n, m, m2;
    int bin1, bin0, ans1, ans0, bini;
    int corr[1000];
    string bin, ans;
    int i, j;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        cin >> bin;
        cin >> ans;
        m = 0;
        m2 = 0;
        bin1 = 0;
        bin0 = 0;
        ans1 = 0;
        ans0 = 0;
        memset(corr,0,sizeof(corr));
        for(j=0;j<bin.size();j++)
        {
            if(bin[j] == '1') bin1++;
            else if(bin[j] == '0') bin0++;
            if(ans[j] == '1') ans1++;
            else ans0++;
            if(bin[j] == ans[j]) corr[j] = 1;
        }
        if(bin1 > ans1) m = -1;
        else
        {
            for(j=0;j<bin.size();j++)
            {
                if(bin[j] == '?')
                {
                    if(bin1 == ans1)
                    {
                        if(ans[j] == '0') corr[j] = 1;
                        bin0++;
                        bin[j] = '0';
                    }
                    else
                    {
                        if(ans[j] == '1') bin1++;
                        else bin0++;
                        bin[j] = ans[j];
                        corr[j] = 1;
                    }
                    m++;
                }
            }
            if(bin1 < ans1)
            {
                m2 -= ans1-bin1;
                m += ans1-bin1;
            }
            for(j=0;j<bin.size();j++)
            {
                if(!corr[j])
                    m2++;
            }
        }
        printf("Case %d: %d\n", i+1, m+m2/2);
    }
    return 0;
}
