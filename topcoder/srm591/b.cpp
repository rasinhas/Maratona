#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

class ConvertibleStrings {
    public:
    int leastRemovals(string a, string b)
    {
        int ret=55;
        string s="ABCDEFGHI";
        do {
            for(int i=0;i<a.size();i++) if(b[i] != s[a[i]-'A']) m++;
            ret = min(ret,m);
        } while(next_permutation(s.begin(),s.end()));
        return ret;
    }
};
