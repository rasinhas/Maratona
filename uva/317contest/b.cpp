#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t;
    int h, len, l, r;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> r;
        len = r*5;
        h = r*3/2;
        l = len*45/100;
        r = len*55/100;
        cout << "Case " << i+1 << ":" << endl;
        cout << -l << " " << h << endl; 
        cout << r << " " << h << endl; 
        cout << r << " " << -h << endl; 
        cout << -l << " " << -h << endl; 
    }
    return 0;
}
