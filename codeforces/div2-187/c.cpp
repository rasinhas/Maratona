#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#define pb push_back
#define sz size()

using namespace std;

long long a[500001];
long long d[500001];
vector <int> fail;

int main()
{
    int n, k;
    long long v, c=0, t;
    long long dj = 0;
    cin >> n >> k;
    t = n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++)
    {
        v = dj - c*(t-c-1)*a[i]; 
        if(v < k)
        {
            fail.pb(i+1);
            t--;
        }
        else
        {
            dj += a[i]*c;
            c++;
        }
    }
    for(int i=0;i<fail.sz;i++) cout << fail[i] << endl;
    return 0;
}
