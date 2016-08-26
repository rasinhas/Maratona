#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#define ff first
#define ss second

using namespace std;

pair<int,int> c[11111];
priority_queue<int> q;

int main()
{
    int n;
    ifstream in("msched.in");
    ofstream out("msched.out");
    in >> n;
    for(int i=0;i<n;i++) in >> c[i].ss >> c[i].ff;
    sort(c,c+n,greater<pair<int,int> >());
    int j=0, r=0;
    for(int i=c[0].ff;i>0;i--)
    {
        while(c[j].ff == i)
        {
            q.push(c[j].ss);
            j++;
        }
        if(!q.empty())
        {
            r += q.top();
            q.pop();
        }
    }
    out << r << endl;
    return 0;
}
