#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    ifstream in("ghanophobia.in");
    int n, a, b;
    char c;
    in >> n;
    for(int i=0;i<n;i++)
    {
        in >> a >> c >> b;
        printf("Case %d: ", i+1);
        if(a-b > 5) cout << "YES" << endl;
        else if(a-b < 5) cout << "NO" << endl;
        else
        {
            if(a == 5) cout << "YES" << endl;
            else if(a == 6) cout << "PENALTIES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}
