#include <iostream>
#include <cstdio>

using namespace std;

int s[3];

int main()
{
    int n, l, d, t;
    cin >> n >> l;
    for(int i=0;i<n;i++)
    {
        cin >> t >> d;
        if(d == -1) s[t] += 1;
        else if(d > l) s[t] += 3;
        else s[t] += 2;
    }
    printf("%d:%d\n", s[1], s[2]);
    return 0;
}
