#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, x;
    string s;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        cin >> s;
        if(s[0] == '+') x++;
        else if(s[0] == '-') x--;
        else if(s[2] == '+') x++;
        else if(s[2] == '-') x--;
    }
    printf("%d\n", x);
    return 0;
}
