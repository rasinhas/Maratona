#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>

using namespace std;

long long ac[4444];
map <int,int> m;

int main()
{
    int a;
    long long r = 0;
    string s;
    cin >> a;
    cin >> s;
    ac[0] = s[0]-'0';
    for(int i=1;i<s.size();i++) ac[i] = ac[i-1]+(s[i]-'0');
    for(int i=0;i<s.size();i++) 
    {
        m[ac[i]]++;
        for(int j=i+1;j<s.size();j++) m[ac[j]-ac[i]]++;
    }
    map <int,int>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        cout << it->first << " " << it->second << endl;
        if(a%(it->first) == 0) r += m[a/(it->first)]*it->second;
    }
    cout << r << endl;
    return 0;
}
