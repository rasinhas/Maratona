#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int main()
{
    int pos = 0, len;
    char s[100], cmd[100];
    scanf("%s", s);
    scanf("%s", cmd);
    len = strlen(cmd);
    for(int i=0;i<len;i++) if(cmd[i] == s[pos]) pos++;
    printf("%d\n", pos+1);
    return 0;
}
