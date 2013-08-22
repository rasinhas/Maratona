#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int a[111111];
int ac[111111];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i=0;i<n;i++) cin >> a[i];
        sort(a,a+n);
        ac[0] = a[0];
        for(int i=1;i<n;i++) ac[i] = ac[i-1]+a[i];
        int pt = n-1;
        int i;
        for(i=0;i<n;i++)
        {
            while(a[pt] < i+1) pt--;
            int s = ac[n-1]-ac[max(pt-1,i-1)] + (max(pt,i+1)-i-1)*(i+1);
            if(ac[i] > ((i+1)*i) + s) break;
        }
        if(i == n && !(ac[n-1]%2)) cout << "possivel" << endl;
        else cout << "impossivel" << endl;
    }
    return 0;
}
