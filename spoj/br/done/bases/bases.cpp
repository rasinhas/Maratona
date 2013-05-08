#include <stdio.h>
#include <string.h>
#include <stack>
#include <vector>

using namespace std;

struct polinomio
{
    int coef[50];
    int grau;
};

stack <polinomio> pilha;
polinomio resp;
char expr[50];
int i, maxnum, maxalg;

vector <int> divisores(int n)
{
    vector<int> div;
    for(i=1;i*i<=n+1;++i) 
    {
        if(n%i == 0)
        {
            div.push_back(i);
            if(i*i!=n) div.push_back(n/i);
        }
    }
    return div;
}

void push_next_poli(int sinal)
{
    int numsize=0, num=0, aux=1, alg=0;
    polinomio ret;
    memset(ret.coef,0,sizeof(ret.coef));
    ret.grau=0;
    i--;
    while(1)
    {
        if(i < 0 || expr[i] == '+' || expr[i] == '*' || expr[i] == '=') break;
        else
        {
            alg = ((int)(expr[i]-'0'));
            num = num + sinal*alg*aux;
            maxalg = max(maxalg,alg); 
            aux *= 10;
            ret.coef[numsize++] = sinal*((int)(expr[i]-'0'));
            ret.grau = max(numsize - 1,ret.grau);
            i--;
        }
    }
    if(num>maxnum) maxnum = num;
    pilha.push(ret);
}

void sum_poli()
{
    int tam;
    polinomio p1, p2;
    p1 = pilha.top();
    pilha.pop();
    p2 = pilha.top();
    pilha.pop();
    tam = max(p1.grau, p2.grau);
    for(i=0;i<=tam;i++)
    {
        p1.coef[i] = p1.coef[i] +  p2.coef[i];
        if(p1.coef[i]) p1.grau = i;
    }
    p1.grau = tam;
    pilha.push(p1);
}

void multiply_poli(int sinal)
{
    int t1, t2, j, k;
    polinomio p1, p2, ret;
    p1 = pilha.top();
    pilha.pop();
    p2 = pilha.top();
    pilha.pop();
    memset(ret.coef,0,sizeof(ret.coef));
    for(k=0;k<=p1.grau;k++)
    {
        for(j=0;j<=p2.grau;j++)
        {
            ret.coef[k+j] += sinal*p1.coef[k]*p2.coef[j];
            if(ret.coef[k+j]) ret.grau = k+j;
        }
    }
    pilha.push(ret);
}

bool check(int x)
{
    int acc, j;
    acc = 0;
    for(j=0;j<=resp.grau;j++)
    {
        acc /= x;
        acc += resp.coef[j];
        if(acc % x != 0) return false;
    }
    return (acc == 0);
}

int main()
{
    int sinal, len;
    vector <int> div;
    long long val;
    int f, j, k, raizes;
    while(scanf(" %s ", expr) && expr[0] != '=')
    {
        maxnum = 0;
        maxalg = 0;
        raizes = 0;
        f = 0;
        len = strlen(expr);
        expr[len] = '+';
        expr[len+1] = '\0';
        sinal = 1;
        while(!pilha.empty()) pilha.pop();
        for(i=len;i>=0;)
        {
            if(expr[i] == '=') 
            {
                sinal = -1;
                push_next_poli(sinal);
            }
            else if(expr[i]=='*')
            {
                push_next_poli(sinal);
                multiply_poli(sinal);
            }
            else push_next_poli(sinal);
        }
        while(pilha.size()>1)
        {
            sum_poli();
        }
        resp = pilha.top();
        pilha.pop();
        raizes = 0;
        for(j=0;j<=resp.grau;j++)
        {
            if(resp.coef[j] != 0) 
            {
                f = 1;
                break;
            }
        }
        if(!f)
        {
            if(maxalg==0) printf("2+");
            else printf("%d+",maxalg+1);
        }
        else
        {
            while(resp.coef[0] == 0)
            {
                for(j=0;j<=resp.grau;j++)
                {
                    resp.coef[j] = resp.coef[j+1];
                }
                resp.grau--;
            }
            if(resp.coef[0] < 0)
            {
                for(j=0;j<=resp.grau;j++)
                {
                    resp.coef[j] = (-1)*resp.coef[j];
                }
            }
            div = divisores(resp.coef[0]);
            len = div.size();
            for(j=0;j<len;j++)
            {
                if(div[j] <= maxalg) continue;
                if(check(div[j]))
                {
                    printf("%d ", div[j]);
                    raizes++;
                }
            }
            if(raizes == 0) printf("*");
        }
        printf("\n");
    }
    return 0;
}
