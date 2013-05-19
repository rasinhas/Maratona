#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

priority_queue <int, vector<int>, greater<int> > q;
vector <int> r;

int main()
{
    int n, a;
    int v, ret, cur;
    cin >> n;
    for(int i=0;i<n;i++) 
    {
        cin >> a;
        q.push(a);
    }
    while(!q.empty())
    {
        v = q.top();
        q.pop();
        if(!q.empty() && v == q.top())
        {
            q.pop();
            q.push(v+1);
        }
        else 
        {
            r.push_back(v);
        }
    }
    ret = 0;
    cur = -1;
    for(int i=0;i<r.size();i++)
    {
        ret += r[i]-cur-1;
        cur = r[i];
    }
    cout << ret << endl;
    return 0;
}
