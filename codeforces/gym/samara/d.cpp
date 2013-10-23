#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    int n;
    string a, b, c;
    cin >> n;
    cin >> a >> b >> c;
    for(int i=0;i<n;i++)
    {
        if(b[i] == c[i]) cout << b[i];
        else cout << a[i];
    }
    cout << endl;
    return 0;
}
