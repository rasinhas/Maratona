#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> n;

int main()
{
    string s;
    int a=0;
    cin >> s;
    s += '+';
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == '+')
        {
            n.push_back(a);
            a = 0;
        }
        else a = (a*10)+(s[i]-'0');
    }
    sort(n.begin(),n.end());
    cout << n[0];
    for(int i=1;i<n.size();i++) cout << "+" << n[i];
    cout << endl;
    return 0;
}
