#include <iostream>
#include <cstdio>

using namespace std;

int mod(int a) { return a > 0 ? a : -a; }

int c[1111], r[1111];
int p[1111];

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> p[i];
    for(int i=1;i<n;i++)
    {
        c[i] = p[i]+p[i-1];
        r[i] = mod(p[i]-p[i-1]);
    }
    int f=0;
    for(int i=1;i<n;i++) for(int j=i+1;j<n;j++) 
    {
        if((r[i]+r[j] > mod(c[i]-c[j])) && (max(r[i],r[j]) < mod(c[i]-c[j])+min(r[j],r[i]))) f = 1;
    }
    cout << (f ? "yes" : "no") << endl;
    return 0;
}
