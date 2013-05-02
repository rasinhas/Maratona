#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t, n, m;
    int c[40];
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> n;
        m = 0;
        for(int j=0;j<n;j++)
        {
            cin >> c[j];
            m = max(m,c[j]);
        }
        cout << "Case " << i+1 << ": " << m << endl;
    }
    return 0;
}
