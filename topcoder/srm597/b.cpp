#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

class LittleElephantAndString
{
    public:
    int getNumber(string a, string b)
    {
        int c[33];
        memset(c,0,sizeof(c));
        if(a.size()!=b.size()) return -1;
        for(int i=0;i<a.size();i++) 
        {
            c[a[i]-'A']++;
            c[b[i]-'A']--;
        }
        for(int i=0;i<26;i++) if(c[i] != 0) return -1;
        int s = a.size()-1;
        for(int i=a.size()-1;i>=0;i--)
        {
            if(a[i] == b[s]) s--;
        }
        return s+1;
    }
};

int main()
{
    return 0;
}
