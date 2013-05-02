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

stack <int> s1, s2, stk;
vector <int> cards;
vector <string> sol;

int main()
{
    int i, n, t, test=1;
    int next, fail, at;
    while(scanf("%d", &n) && n)
    {
        while(!s1.empty()) s1.pop();
        while(!s2.empty()) s2.pop();
        while(!stk.empty()) stk.pop();
        sol.clear();
        cards.clear();
        for(i=0;i<n;i++)
        {
            scanf("%d", &t);
            stk.push(t);
            cards.push_back(t);
        }
        sort(cards.begin(), cards.end());
        sol.push_back("push 1");
        s1.push(stk.top());
        stk.pop();
        next = 0;
        fail = 0;
        while(1)
        {
            while(1)
            {
                if((s1.empty() || s1.top() != cards[next]) && (s2.empty() || s2.top() != cards[next])) break;
                else if(!s1.empty() && s1.top() == cards[next])
                {
                    next++;
                    s1.pop();
                    sol.push_back("pop 1");
                }
                else if(!s2.empty() && s2.top() == cards[next])
                {
                    next++;
                    s2.pop();
                    sol.push_back("pop 2");
                }
            }
            if(stk.empty()) break;
            at = stk.top();
            stk.pop();
            if(s1.empty() || (!s1.empty() && !s2.empty() &&s1.top() < s2.top()))
            {
                if(s1.empty() || at <= s1.top())
                {
                    s1.push(at);
                    sol.push_back("push 1");
                }
                else if(s2.empty() || at <= s2.top())
                {
                    s2.push(at);
                    sol.push_back("push 2");
                }
                else
                {
                    fail = 1;
                    break;
                }
            }
            else if(s2.empty() || (!s1.empty() && !s2.empty() &&s1.top() > s2.top()))
            {
                if(s2.empty() || at <= s2.top())
                {
                    s2.push(at);
                    sol.push_back("push 2");
                }
                else if(s1.empty() || at <= s1.top())
                {
                    s1.push(at);
                    sol.push_back("push 1");
                }
                else
                {
                    fail = 1;
                    break;
                }
            }
        }
        printf("#%d\n",test++);
        if(fail) printf("impossible\n");
        else for(i=0;i<sol.size();i++) cout << sol[i] << endl;
    }
	return 0;
}
