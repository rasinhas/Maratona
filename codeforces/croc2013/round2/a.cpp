#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    int n, sc, tc, in, tt, st;
    string t, s;
    cin >> n;
    cin >> s;
    cin >> t;
    in = tc = sc = 0;
    for(int i=0;i<2*n;i++)
    {
        if(s[i] == '1' && t[i] == '1') in++;
        else
        {
            if(s[i] == '1') sc++;
            if(t[i] == '1') tc++;
        }
    }
    st = (in+1)/2;
    tt = in/2;
    int j = 0;
    if(in%2 == 1) j = 1;//proximo eh o 2//
    while(sc > 0 || tc > 0)
    {
        if(j%2 == 1)//joga 2
        {
            if(tc > 0) tc--, tt++;
            else sc--;
        }
        else
        {
            if(sc > 0) sc--, st++;
            else tc--;
        }
        j = (j+1)%2;
    }
    if(st > tt) cout << "First" << endl;
    else if(st == tt) cout << "Draw" << endl;
    else cout << "Second" << endl;
    return 0;
}
