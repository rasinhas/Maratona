#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>
#define pb push_back
#define mp make_pair
#define sz size()

using namespace std;

int main()
{
    int n, a=0;
    int len, m;
    char c[10];
    cin >> n;
    while(n > 0)
    {
        sprintf(c,"%d",n);
        len = strlen(c);
        m = 0;
        for(int i=0;i<len;i++) m = max(m,c[i]-'0');
        n -= m;
        a++;
    }
    cout << a << endl;
    return 0;
}
