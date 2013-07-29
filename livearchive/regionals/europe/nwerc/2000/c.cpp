#include <iostream>

using namespace std;

int s[555];

int mod(int a) { return a > 0 ? a : -a; }

int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        int ret=1e9;;
        cin >> n;
        for(int i=0;i<n;i++) cin >> s[i];
        for(int i=0;i<n;i++)
        {
            int diff=0;
            for(int j=0;j<n;j++) diff += mod(s[i]-s[j]);
            ret = min(ret,diff);
        }
        cout << ret << endl;
    }
    return 0;
}
