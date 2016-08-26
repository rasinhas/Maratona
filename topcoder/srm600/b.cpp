#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

class PalindromeMatrix{
    public:
    int minChange(int vector<string> v, int rc, int cc)
    {
        int n=v.size(), m=v[0].size();
        int rp[22];
        int cp[22];
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) 
        {
            rp[i] = 1;
            if(v[i][j] != v[i][m-j-1])
            {
                rp[i] = 0;
                break;
            }
        }
        for(int i=0;i<m;i++) for(int j=0;j<n;j++)
        {
            cp[i] = 1;
            if(v[j][i] != v[n-j-1][i])
            {
                cp[i] = 0;
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
            }
        }
        return m;
    }
};

int main()
{
    PalindromeMatrix p;
    string s[] = ;
    vector <string> k;
    cout << p.minChange(k,,) << endl;
    return 0;
}
