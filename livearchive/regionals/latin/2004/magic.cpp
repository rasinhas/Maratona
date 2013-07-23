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

char num[13] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
char sui[4] = {'H', 'C', 'D', 'S'};

int suit(char a)
{
    if(a == 'H') return 0;
    else if(a == 'C') return 1;
    else if(a == 'D') return 2;
    else if(a == 'S') return 3;
}

int number(char a)
{
    if(a == '1') return 0;
    else if(a == '2') return 1;
    else if(a == '3') return 2;
    else if(a == '4') return 3;
    else if(a == '5') return 4;
    else if(a == '6') return 5;
    else if(a == '7') return 6;
    else if(a == '8') return 7;
    else if(a == '9') return 8;
    else if(a == 'T') return 9;
    else if(a == 'J') return 10;
    else if(a == 'Q') return 11;
    else if(a == 'K') return 12;
}

int main()
{
    int i, j, k;
    char c[3];
    pair <int,int> cards[5], ordered[5], sol;
    scanf("%d", &k);
    for(i=0;i<k;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%s", c);
            if(j == 0) sol = make_pair(suit(c[1]),number(c[0]));
            else 
            {
                cards[j-1] = make_pair(suit(c[1]),number(c[0]));
                ordered[j-1] = make_pair(suit(c[1]),number(c[0]));
            }
        }
        sort(ordered, ordered+3);
        if(ordered[0] == cards[0] && ordered[1] == cards[1] && ordered[2] == cards[2]) sol.second += 1;
        else if(ordered[0] == cards[0] && ordered[1] == cards[2] && ordered[2] == cards[1]) sol.second += 2;
        else if(ordered[0] == cards[1] && ordered[1] == cards[0] && ordered[2] == cards[2]) sol.second += 3;
        else if(ordered[0] == cards[2] && ordered[1] == cards[0] && ordered[2] == cards[1]) sol.second += 4;
        else if(ordered[0] == cards[1] && ordered[1] == cards[2] && ordered[2] == cards[0]) sol.second += 5;
        else if(ordered[0] == cards[2] && ordered[1] == cards[1] && ordered[2] == cards[0]) sol.second += 6;
        printf("%c%c\n", num[sol.second%13], sui[sol.first]);
    }
	return 0;
}
