#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

int main()
{
    stack <char> symb;
    char expr[100100];
    int i, j, n, ret, len;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        ret=1;
        scanf("%s",expr);
        len=strlen(expr);
        for(j=0;j<len;j++) 
        {
            if(expr[j]==')' || expr[j]==']' || expr[j]=='}')
            {
                if(symb.empty())
                {
                    ret=0;
                    break;
                }
                else if(expr[j]-symb.top()==1 || expr[j]-symb.top()==2)
                {
                    symb.pop();
                }
                else 
                {
                    ret=0;
                    break;
                }
            }
            else symb.push(expr[j]);
        }
        if(ret && symb.empty()) printf("S\n");
        else printf("N\n");
        while(!symb.empty()) symb.pop();
    }
}
