#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> ret;
int s[111111];

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=30;i>=0;i--)
    {
        int k = (1<<i);
        int v = (1<<31)-1;
        for(int j=0;j<n;j++) if(s[j]&k)
        {
            ret.push_back(s[j]);
            v &= s[j];
        }
        if(v%k == 0)
        {
            cout << ret.size() << endl;
            for(int j=0;j<ret.size();j++) cout << ret[j] << " ";
            cout << endl;
            break;
        }
        ret.clear();
    }
    return 0;
}
