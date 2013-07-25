#include <iostream>
#include <cstdio>

using namespace std;

int round(int a)
{
    if(a%5>2) a += (5-a%5); 
    else a -= a%5;
    return a;
}

int n[11];
int v[11]={2000,1000,500,200,100,50,20,10,5};

int cnt(int c, int v, int i)
{
    n[i] = c/v;
    return c-n[i]*v;
}

int main()
{
    int a, b, c, d, e;
    int k=0;
    while(scanf("%d.%d %d.%d", &a, &b, &d, &e) && (a || b || d || e))
    {
        int c = round(d*100+e)-round(a*100+b);
        if(c < 0) cout << "Not enough money offered.";
        else if(c == 0) cout << "Exact amount.";
        else
        {
            k=0;
            for(int i=0;i<9;i++) c = cnt(c,v[i],i);
            for(int i=0;i<9;i++) if(n[i])
            {
                if(k == 0)
                {
                    if(i > 4) printf("%dc*%d", v[i],n[i]), k++;
                    else printf("$%d*%d",v[i]/100,n[i]), k++;
                }
                else
                {
                    if(i > 4) printf(" %dc*%d", v[i],n[i]), k++;
                    else printf(" $%d*%d",v[i]/100,n[i]), k++;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
