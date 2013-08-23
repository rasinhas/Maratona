#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int a[111111];
long long ac[111111];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i=0;i<n;i++) cin >> a[i];
        sort(a,a+n,greater<int>());
        ac[0] = a[0];
        for(int i=1;i<n;i++) ac[i] = ac[i-1]+a[i];
        long long pt = n-1;
        long long i;
        for(i=0;i<n;i++)
        {
            while(a[pt] < i+1) pt--;
            long long s = ac[n-1]-ac[max(pt,i-1)] + (max(pt,i+1)-i)*(i+1);
            if(ac[i] > ((i+1)*i) + s) break;
        }
        if(i == n && !(ac[n-1]%2)) cout << "possivel" << endl;
        else cout << "impossivel" << endl;
    }
    return 0;
}
