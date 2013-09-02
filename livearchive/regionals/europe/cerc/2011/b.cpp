#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int n;
    string k, m;
    while((cin >> k) && k != "0")
    {
        n = 0;
        cin >> m;
        for(int i=0;i<m.size();i++)
        {
            printf("%c", 'A' + (k[n++]-'A' + m[i]-'A' + 1)%26);
            n%=k.size();
        }
        cout << endl;
    }
    return 0;
}
