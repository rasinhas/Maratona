#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int n, a=0, f=0, in=0, ret;
    string s;
    scanf("%d", &n);
    cin >> s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == 'A') a++;
        else if(s[i] == 'I') in++;
        else f++;
    }
    if(in == 0) ret = a;
    else if(in == 1) ret = 1;
    else ret = 0;
    printf("%d\n", ret);
    return 0;
}
