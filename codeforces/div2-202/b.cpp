#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

typedef long long ll;

using namespace std;

int a[11];
string s;

int main()
{
    int v, k=0, m=1e9;
    s = "";
    cin >> v;
    for(int i=0;i<9;i++) 
    {
        cin >> a[i];
        if(a[i] < m)
        {
            k = v/a[i];
            m = a[i];
        }
    }
    for(int i=1;i<=k;i++) 
    {
        for(int j=8;j>=0;j--)
        {
            if((v-a[j]) >= m*(k-i))
            {
                s += '0'+j+1;
                v -= a[j];
                break;
            }
        }
    }
    if(s == "") s = "-1";
    cout << s << endl;
    return 0;
}
