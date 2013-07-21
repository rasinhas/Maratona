#include <iostream>
#include <cstdio>
#include <utility>
#define mp make_pair
#define inf 1000000000

using namespace std;

int main()
{
    int n;
    long long ta=0;
    int mx=inf, my=inf, Mx=-inf, My=-inf;
    int x1, y1, x2, y2;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        mx = min(x1,mx);
        Mx = max(x2,Mx);
        my = min(y1,my);
        My = max(y2,My);
        ta += (x2-x1)*(y2-y1);
    }
    if(ta == (Mx-mx)*(My-my) && (Mx-mx) == (My-my)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
