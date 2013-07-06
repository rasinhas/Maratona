#include <iostream>
#include <cstdio>
#include <string>
#include<cstring>
#define pb push_back
#define sz size()
#define mp make_pair

using namespace std;

int a[200];
int b[200];

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    b[-1] = 0;
    b[0] = a[0];
    for(int i=1;i<n;i++) b[i] = a[i]+b[i-1];
    int c = 0;
    int ret = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int l, r, in;
            l = b[i-1];
            r = b[n-1] - b[j];
            in = j-i+1 - b[j] + b[i-1];
            ret = max(ret,l+r+in);
        }
    }
    cout << ret << endl;
    return 0;
}
