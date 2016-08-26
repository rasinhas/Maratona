#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class LittleElephantAndDouble
{
    public:
    string getAnswer(vector<int> v)
    {
        int f = 0;
        sort(v.begin(),v.end());
        int d = v[0];
        for(int i=0;i<v.size();i++)
        {
            if(v[i]%d != 0) f = 1;
            else 
            {
                int k = v[i]/d;
                if(k != 1 && __bulitin_popcount(k) != 1) f = 1;
            }
        }
        return (f ? "NO" : "YES");
    }
};

int main()
{
    return 0;
}
