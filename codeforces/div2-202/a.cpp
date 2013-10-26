#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

typedef long long ll;

using namespace std;

int change[2];

int main()
{
    int f=0, n, a;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        if(f) continue;
        if(a == 25) change[0]++;
        else if(a == 50) 
        {
            if(change[0] == 0) f = 1;
            change[1]++;
            change[0]--;
        }
        else
        {
            if(change[1] > 0 && change[0] > 0)
            {
                change[1]--;
                change[0]--;
            }
            else if(change[1] == 0 && change[0] > 2) change[0]-=3;
            else f = 1;
        }
    }
    if(f) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}
