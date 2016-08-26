#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int a[1111];
int t, b;
int s[2];

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin>> a[i];
    t = n-1;
    b = 0;
    int i=0;
    while(t >= b)
    {
        if(a[t] > a[b]) s[i%2] += a[t--];
        else s[i%2] += a[b++];
        i++;
    }
    cout << s[0] << " " << s[1] << endl;
    return 0;
}
