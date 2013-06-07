#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#define sz size()

using namespace std;

int acc[100000];

int main()
{
    int q, l, r;
    string s;
    cin >> s;
    cin >> q;
    if(s[0] == s[1]) acc[0] = 1;
    for(int i=0;i<s.sz;i++) 
    {
        acc[i+1] = acc[i];
        if(s[i] == s[i+1]) acc[i+1]++;
    }
    for(int i=0;i<q;i++)
    {
        cin >> l >> r;
        cout << acc[r-1]-acc[l-1] << endl;
    }
    return 0;
}
