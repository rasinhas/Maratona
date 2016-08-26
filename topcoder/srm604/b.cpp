#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int pw3[22];

int dfs(int a, int msk, int s)
{
    int k = 0;
    if(a == 0) return msk;
    if((msk&(1<<s)) == 0) k = dfs(a-pw3[s],(msk|(1<<s)),s+1);
    if(k) return k;
    k = dfs(a,msk,s+1);
    if(k) return k;
    if(pw3[(1<<s)] > 3*a || s > 20) return -1;
    return -1;
}

int solve(int a, int msk)
{
    int ret = dfs(a,msk,0);
    return ret;
}

class PowerOfThree{
    public:
    string ableToGet(int x, int y)
    {
        pw3[0] = 1;
        for(int i=0;i<21;i++) pw3[i] = pw3[i-1]*3;
        int msk = solve(x,0);
        if(msk == -1) return "Impossible";
        msk = solve(y,msk);
        if(msk == -1) return "Impossible";
        int ok = 1;
        int z=0;
        for(int i=0;i<=20;i++)
        {
            if((msk&(1<<i)) == 0) z = 1;
            if(z && ((msk&(1<<i)) == 1)) ok = 0;
        }
        return ok ? "Possible" : "Impossible";
    }
};

int main()
{
    PowerOfThree a;
    cout << a.ableToGet(1,3) << endl;
    cout << a.ableToGet(-6890,18252) << endl;
    cout << a.ableToGet(0,2) << endl;
    cout << a.ableToGet(0,0) << endl;
    cout << a.ableToGet(1,9) << endl;
    cout << a.ableToGet(3,0) << endl;
    cout << a.ableToGet(1,1) << endl;
    cout << a.ableToGet(-1000000000,1000000000) << endl;
    return 0;
}
