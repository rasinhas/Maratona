#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class WinterAndPresents{
    public:
    long long getNumber(vector<int> a, vector<int> o)
    {
        int size[55];
        memset(size,0,sizeof(size));
        int m = 1000000000;
        long long ret = 0;
        for(int i=0;i<a.size();i++) 
        {
            size[i] = a[i]+o[i];
            m = min(m,size[i]);
        }
        for(int i=1;i<=m;i++)
        {
            long long ko=0, ka=0;
            for(int j=0;j<a.size();j++)
            {
                if(a[j] < i) ka += i-a[j];
                if(o[j] < i) ko += i-o[j];
            }
            ret += (long long)i*a.size() + (1-ka) + (1-ko) - 1;
        }
        return ret;
    }
};

int main()
{
    int a[] = {1000000};
    int o[] = {1000000};
    vector <int> x(a,a+sizeof(a)/sizeof(int)), y(o,o+sizeof(o)/sizeof(int));
    WinterAndPresents k;
    cout << k.getNumber(x,y) << endl;
    return 0;
}
