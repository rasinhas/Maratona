#include <cstdio>
#include <iostream>

using namespace std;

int sum[1001];

int main()
{
    int t, n;
    cin >> t;
    sum[0] = 0;
    for(int i=1;i<=1000;i++) sum[i] = sum[i-1]+i;
    for(int i=1;i<=1000;i++) sum[i] += sum[i-1];
    for(int i=1;i<=t;i++)
    {
        cout << i << ": ";
        cin >> n;
        cout << n << " " << sum[n] << endl;
    }
    return 0;
}
