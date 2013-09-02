#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

typedef long long ll;

ll ab(ll a) { return a>0 ? a : -a; }
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }

ll mul(ll a,ll b,ll m)
{
    if(b == 0) return 0;
    else if(b%2) return (a+mul(a,b-1,m))%m;
    return mul((a+a)%m,b/2,m);
}

ll pow(ll a,ll b,ll m)
{
    if(b == 0) return 1;
    else if(b%2) return (mul(a,pow(a,b-1,m),m));
    return pow(mul(a,a,m),b/2,m);
}

bool miller_rabin(ll a , ll n)
{
    if(a>=n) return true;
    ll r=0,s=n-1,j;
    while(!(s & 1)) s>>=1,r++;
    ll x=pow(a,s,n);
    if(x==1) return true;
    for(j=0;j<r;j++,x=mul(x,x,n)) if (x==n-1) return true ;
    return false ; 
}

bool isprime (ll n)
{
    int base[]={2,3,5,7,11,13,17,19,23,29};
    for(int i=0;i<10;i++) if(!miller_rabin(base[i],n)) return false;
    return true ;
}

ll pollard_rho(ll n)
{
    ll x,y,d,c=-1;
    if(!(n%2)) return 2;
    while(1)
    {
        y=x=2;
        while(1)
        {
            x=mul(x,x,n); x=(x-c)%n;
            y=mul(y,y,n); y=(y-c)%n;
            y=mul(y,y,n); y=(y-c)%n; 
            d=gcd(ab(n+y-x),n);
            if(d==n) break ; 
            else if(d>1) return d; 
        }
        c --; 
    }
}

map <ll,ll> exp;
map <ll,ll>::iterator it;
int t;
void factor(ll n)
{
    if(isprime(n)) exp[n]++;
    else 
    {
        ll buf=pollard_rho(n);
        factor(buf);
        factor(n/buf); 
    }
}


int main()
{
    ll q, r;
    while(scanf("%lld", &q) && q)
    {
        t = 0;
        exp.clear();
        factor(q);
        ll r = 2;
        for(it=exp.begin();it!=exp.end();it++) if(it->first > 2) r *= ((2*(it->second))+1);
        cout << r << endl;
    }
    return 0;
}
