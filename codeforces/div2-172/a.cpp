#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
#define pb push_back
#define mp make_pair
#define inf 0x3f3f3f3f

using namespace std;

int main()
{
    char str[10000];
    scanf("%s", str);
    if(str[0] > 'Z') str[0] = str[0] - 32;
    printf("%s\n", str);
    return 0;
}
