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
    int x, y, ret=0;
    scanf("%d%d", &y, &x);
    if(y < 0 && x >= y && x < -y) ret = 4*(-y)-1;
    if(y > 0 && x > -y+1 && x <= y) ret = 4*y-3;
    if(x > 0 && y >= -x && y < x) ret = 4*x-2;
    if(x < 0 && y > x && y <= -x+1) ret = 4*(-x);
    printf("%d\n", ret);
    return 0;
}
