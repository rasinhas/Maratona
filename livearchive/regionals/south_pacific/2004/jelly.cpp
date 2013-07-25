#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string s[111];
int v[111];

int main()
{
    int n;
    int h, w, l;
    while((cin >> n) && n)
    {
        for(int i=0;i<n;i++) 
        {
            cin >> s[i] >> h >> w >> l;
            v[i] = h*l*w;
        }
        int mi = 0;
        int ma = 0;
        for(int i=0;i<n;i++)
        {
            if(v[i] < v[mi]) mi = i;
            if(v[i] > v[ma]) ma = i;
        }
        if(mi == ma) cout << "No child has lost jelly." << endl; 
        else cout << s[mi] << " has lost jelly to " << s[ma] << "." << endl;
    }
}
