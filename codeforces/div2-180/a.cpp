#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, s, l, lr;
    string c;
    cin >> n;
    cin >> c;
    s = 0;
    l = 0;
    for(int i=0;i<n;i++)
    {
        if(c[i] == 'R' && s == 0) s = i+1;
        if(c[i] != 'R' && c[i-1] == 'R' && l == 0) lr = i+1;
        if(c[i] == 'L' && l == 0) l = i;
    }
    if(s == 0) s = l+1;
    if(l == 0) l = lr;
    cout << s << " " << l << endl;
    return 0;
}
