#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, xi, xf, yi, yf, i;
    string wind;
    cin >> n;
    cin >> xi >> yi >> xf >> yf;
    cin >> wind;
    for(i=0;i<n;i++)
    {
        if(wind[i] == 'S' && yi > yf) yi--;
        if(wind[i] == 'N' && yi < yf) yi++;
        if(wind[i] == 'E' && xi < xf) xi++;
        if(wind[i] == 'W' && xi > xf) xi--;
        if(xi == xf && yi == yf) break;
    }
    if(xi != xf || yi != yf) cout << -1 << endl;
    else cout << i+1 << endl;
    return 0;
}
