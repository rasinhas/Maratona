#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int coins[1111111];

int main()
{
    int T;
    cin >> T;
    for(int t=1;t<=T;t++)
    {
        int n, k, c, md;
        cin >> n >> k >> c;
        // solução ótima -> coloca k/n moedas em cada pote (k%n == 0) -> pega k/n moedas de cada pote -> c rodadas
        // # de potes com menos moedas = (n-k%n)%n
        int d = (n-k%n);
        // procura o maior divisor de k menor que n e joga moeda só neles
        // n-md potes vazios + md potes com a mesma quantidade = (n-md)+c rodadas
        for(md=n;md>0;md--) if(k%md == 0) break;
        int mdsol = (n-md)+c;
        // na pior das hipóteses -> pega sempre um pote com menos e tem que saber que acabou o pote -> pega k/n + 1 rodadas por pote e k/n pra cada pote maior
        for(int i=0;i<d;i++) coins[i] = k/n;
        for(int i=d;i<n;i++) coins[i] = k/n+1;
        int osol=0;
        int m = coins[n-1];
        for(int i=0;i<n;i++)
        {
            if(coins[i] >= c) 
            {
                osol += c;
                break;
            } else {
                if(coins[i] < m) osol++;
                osol += coins[i];
                c -= coins[i];
            }
        }
        printf("Case #%d: %d\n", t, min(mdsol,osol));
    }
    return 0;
}
