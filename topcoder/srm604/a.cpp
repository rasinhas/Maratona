#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int mod(int x) { return x > 0 ? x : -x; }

class PowerOfThree{
    public:
    string ableToGet(int x, int y)
    {
        x = mod(x);
        y = mod(y);
        int tx[22], ty[22], cx[22], cy[22], u[22];
        int ok = 1;
        memset(u,0,sizeof(u));
        memset(cx,0,sizeof(cx));
        memset(cy,0,sizeof(cy));
        int kx=0, ky=0;
        while(x)
        {
            tx[kx++] = x%3;
            x /= 3;
        }
        while(y)
        {
            ty[ky++] = y%3;
            y /= 3;
        }
        for(int i=0;i<kx;i++)
        {
            int ni = i;
            cout << tx[ni];
            if(tx[i] == 1)
            {
                u[ni]++;
                cx[ni] = 1;
            }
            else if(tx[i] == 2) 
            {
                u[ni]++;
                u[ni+1]++;
                cx[ni] = 2;
            }
        }
        cout << endl;
        for(int i=0;i<kx;i++) cout << tx[i];
        cout << endl;
        for(int i=0;i<=kx;i++) cout << u[i];
        cout << endl;
        for(int i=0;i<max(kx,ky);i++) if(u[i] != 1) ok = 0;
        if(u[max(kx,ky)] > 1) ok = 0;
        return (ok ? "Possible" : "Impossible");
    }
};

int main()
{
    PowerOfThree a;
    cout << a.ableToGet(-6890,18252) << endl;
    /*
    cout << a.ableToGet(1,3) << endl;
    cout << a.ableToGet(0,2) << endl;
    cout << a.ableToGet(0,0) << endl;
    cout << a.ableToGet(1,9) << endl;
    cout << a.ableToGet(3,0) << endl;
    cout << a.ableToGet(1,1) << endl;
    cout << a.ableToGet(-1000000000,1000000000) << endl;
    */
    return 0;
}
