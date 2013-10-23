#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int n, ans=0, f;
    string ini, tar;
    cin >> n;
    cin >> ini >> tar;
    f = 0;
    for(int i=0;i<n;i++)
    {
        if(ini[i] == tar[i])
        {
            if(f) ans++;
            f = 0;
        }
        else f = 1;
    }
    if(f) ans++;
    cout << ans << endl;
    return 0;
}
