#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;
typedef long long ll;

class ORSolitaire{
    public:
    int getMinimum(vector<int> v, int g)
    {
        vector <int> b[33];
        int mk[55];
        memset(mk,0,sizeof(mk));
        for(int i=0;i<32;i++)
        {
            for(int j=0;j<v.size();j++)
            {
                if((((1<<i)&v[j])>0) && (((1<<i)&g) == 0)) mk[j] = 1;
            }
        }
        for(int i=0;i<32;i++)
        {
            if((((1<<i)&g)))
            {
                for(int j=0;j<v.size();j++)
                {
                    if(mk[j] == 0 && (v[j] <= g) && (v[j]&(1<<i)))
                    {
                        b[i].push_back(v[j]);
                    }
                }
            }
        }
        int m = 1000000;
        for(int i=0;i<32;i++)
        {
            if(((1<<i)&g))
            {
                m = min(m,(int)b[i].size());
            }
        }
        return m;
    }
};

int main()
{
    ORSolitaire a;
    int arr[] = {503, 505, 152, 435, 491, 512, 1023, 355, 510, 500, 502, 255, 63, 508, 509, 511, 60, 250, 254, 346};
    vector <int> k(arr,arr+sizeof(arr)/sizeof(int));
    cout << a.getMinimum(k,510) << endl;
    return 0;
}
