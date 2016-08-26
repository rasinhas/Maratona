#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int t=1;t<=T;t++)
    {
        int n, a[4];
        char c;
        cin >> n;
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {
            cin >> c;
            if(c == 'B') a[0]++;
            if(c == 'W') a[1]++;
            if(c == 'T') a[2]++;
            if(c == 'A') a[3]++;
        }
        printf("Case %d: ", t);
        if(a[0] == n-a[3] && a[0] > 0) cout << "BANGLAWASH";
        else if(a[1] == n-a[3] && a[1] > 0) cout << "WHITEWASH";
        else if(a[3] == n) cout << "ABANDONED";
        else if(a[0] == a[1]) cout << "DRAW " << a[0] << " " << a[2];
        else if(a[0] > a[1]) cout << "BANGLADESH " << a[0] << " - " << a[1];
        else if(a[0] < a[1]) cout << "WWW " << a[1] << " - " << a[0];
        cout << endl;
    }
    return 0;
}
