#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, a, b;
    int al=0, ni=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a >> b;
        if(a > al)
        {
            al = max(al,a);
            ni = max(ni,b);
        }
    }
    cout << ni << endl;
    return 0;
}
