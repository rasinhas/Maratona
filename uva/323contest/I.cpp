#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int v[55];

int main()
{
    int n;
    while(cin >> n && !cin.eof())
    {
        priority_queue <pair<int,long long> > q;
        for(int i=0;i<n;i++) 
        {
            cin >> v[i];
            q.push(make_pair(v[i],0));
        }
        long long m = -1;
        while(q.size() > 1)
        {
            pair<int,long long> a, b, c;
            a = q.top(); q.pop();
            b = q.top(); q.pop();
            c.first = a.first-1;
            if(a.second == 0) a.second = m;
            if(b.second == 0) b.second = m;
            m = min(m,min(a.second,b.second));
            c.second = a.second + b.second;
            q.push(c);
        }
        cout << -q.top().second << endl;
    }
    return 0;
}
