#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a, b, n;
    int p[2];
    while(cin>>n && n)
    {
        p[0] = p[1] = 0;
        for(int i=0;i<n;i++)
        {
            cin >> a >> b;
            if(a>b) p[0]++;
            if(a<b) p[1]++;
        }
        cout << p[0] << " " << p[1] << endl;
    }
    return 0;
}
