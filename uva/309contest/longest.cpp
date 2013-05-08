#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctype.h>
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
    int i, len;
    char str[200], longest[200];
    char *pch;
    strcpy(longest,"");
    while(scanf("%s", str))
    {
        if(!strcmp(str,"E-N-D")) break;
        pch = strtok(str," ,.()[]{}!?:;1234567890/\\@#$%&*_=+\"'");
        while(pch != NULL)
        {
            if(strlen(pch) > strlen(longest)) strcpy(longest,pch);
            pch = strtok(NULL," ,.()[]{}!?:;1234567890/\\@#$%&*_=+\"'");
        }
    }
    len = strlen(longest);
    for(i=0;i<len;i++)
    {
        longest[i] = tolower(longest[i]);
    }
    printf("%s\n", longest);
	return 0;
}
