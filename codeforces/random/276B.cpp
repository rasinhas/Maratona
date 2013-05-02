#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int main()
{
    string str;
    int ci=0, cp=0;
    int let[26];
    cin >> str;
    memset(let,0,sizeof(let));
    for(int i=0;i<str.size();i++) let[str[i]-'a']++;
    for(int i=0;i<26;i++) 
    {
        if(let[i]%2) ci++;
        else cp++;
    }
    if(ci < 2) printf("First\n");
    else
    {
        if(ci%2) printf("First\n");
        else printf("Second\n");
    }
    return 0;
}
