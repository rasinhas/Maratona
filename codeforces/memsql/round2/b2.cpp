#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#define K 300

using namespace std;

string s;
string srev;
string ret;
int lcs[300][50100];

void rebuild(int i, int f, string str)
{
    if(str.size() == 100 || lcs[i%K][f] == 0) 
    {
        ret = str;
        return ;
    }
    if(s[i-1] == srev[f-1]) rebuild(i-1,f-1,str+s[i-1]);    
    else if(lcs[i%K][f] == lcs[(i+K-1)%K][f]) rebuild(i-1,f,str);
    else rebuild(i,f-1,str);
}

int main()
{
    int f=0;
    cin >> s;
    srev = s;
    reverse(srev.begin(),srev.end());
    for(int i=1;i<=s.size();i++)
    {
        for(int j=1;j<=s.size();j++)
        {
            if(s[i-1] == srev[j-1]) lcs[i%K][j] = 1+lcs[(i+K-1)%K][j-1];
            else lcs[i%K][j] = max(lcs[(i+K-1)%K][j], lcs[i%K][j-1]);
        }
    }
    rebuild(s.size(),s.size(),"");
    int o=0;
    if(ret.size()%2) o=1;
    string p = ret.substr(0,(ret.size()+1)/2);
    cout << p;
    p = ret.substr(0,ret.size()/2);
    reverse(p.begin(),p.end());
    cout << p << endl;
    return 0;
}
