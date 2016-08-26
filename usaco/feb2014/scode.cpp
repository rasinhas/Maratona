#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define ff first
#define ss second
#define sz size()

using namespace std;

const int mod = 2014;

map <string, int> sol;

int solve(string s) 
{
    if(sol.count(s)) return sol[s];
    int ret = 1;
    // testing every prefix
    for(int i=(s.sz+1)/2;i<s.sz;i++) {
        string a = s.substr(0,i);
        string b = s.substr(i,s.sz);
        // testing if b is prefix of a
        if(a.sz != b.sz && b == a.substr(0,b.sz)) ret += solve(a);
        // testing if b is suffix of a
        if(a.sz != b.sz && b == a.substr(a.sz-b.sz,a.sz)) ret += solve(a);
    }
    // testing every suffix
    for(int i=(s.sz+1)/2;i<s.sz;i++) {
        string a = s.substr(s.sz-i,s.sz);
        string b = s.substr(0,s.sz-i);
        // testing if b is prefix of a
        if(a.sz != b.sz && b == a.substr(0,b.sz)) ret += solve(a);
        // testing if b is suffix of a
        if(a.sz != b.sz && b == a.substr(a.sz-b.sz,a.sz)) ret += solve(a);
    }
    return sol[s]=ret%mod;
}

int main()
{
    ifstream in("scode.in");
    ofstream out("scode.out");
    string s;
    in >> s;
    out << (solve(s)+mod-1)%mod << endl;
    return 0;
}
