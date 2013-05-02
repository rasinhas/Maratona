#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    string str;
    int n;
    char p;
    cin >> str;
    scanf("%d", &n);
    for(int i=0;i<str.size();i++)
    {
        if(str[i] < 97) str[i] = str[i] + 32;
    }
    for(int i=0;i<str.size();i++)
    {
        p = str[i];
        if((int)p < 97 + n)
        {
            str[i] = str[i] - 32;
        }
    }
    cout << str;
    return 0;
}
