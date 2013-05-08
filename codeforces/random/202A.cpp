#include <stdio.h>
#include <iostream>
#include <string.h>
#include <utility>

using namespace std;

int main()
{
    char str[100];
    int m=0, len;
    scanf("%s", str);
    len = strlen(str);
    for(int i=0;i<len;i++) m = max(m,(int)str[i]);
    for(int i=0;i<len;i++) if((int)str[i] == m) printf("%c", str[i]);
    return 0;
}
