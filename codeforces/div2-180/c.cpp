#include <stdio.h>
#include <iostream>
#include <string>
#define sz size()

using namespace std;

int main()
{
    int c1a, c1b;
    string a, b;
    cin >> a;
    cin >> b;
    c1a = c1b = 0;
    for(int i=0;i<a.sz;i++) if(a[i] == '1') c1a++;
    for(int i=0;i<b.sz;i++) if(b[i] == '1') c1b++;
    if(c1a%2 == 1) c1a++;
    if(c1a < c1b) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}
