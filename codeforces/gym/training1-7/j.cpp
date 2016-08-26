#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int n, isl=1, t;
    string s;
    cin >> n;
    cin >> s;
    t = n;
    for(int i=0;i<n;i++)
    {
        if(s[i] == 'L')
        {
            if(isl == 0) t--;
            isl  = 0;
            i++;
        }
    }
    cout << t << endl;
    return 0;
}
