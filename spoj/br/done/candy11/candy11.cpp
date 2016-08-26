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
#define INF 1000000000

using namespace std;

//IDEIA//
// descreve c[i] = K(UF+S) com c[i] sendo a quantidade de balas do tipo i,
// K é o número de balas de cada tipo no pacote sortido, S é a quantidade
// de pacotes sortidos, U é a quantidade de pacotes "únicos" de cada tipo
// e F a quantidade de tipos de balas.
// partindo disso testa-se os valores para todos os K divisores do menor c[i]
// (o menor c[i] é o gargalo para a criação dos pacotes) e verifica-se a quantidade
// de valores de S que deixam a equação correta usando o fato de que F divide 
// (c[i]/K - S) chegando ao valor para cada K (o resultado final é a soma destes)

int main()
{
    int f, c[100001];
    int i, j, low, flag, ret;
    vector <int> div;
    while(scanf("%d", &f) && f)
    {
        div.clear();
        low = INF;
        ret = 0;
        //recebe as quantidades de cada tipo de bala e guarda o menor
        for(i=0;i<f;i++)
        {
            scanf("%d", &c[i]);
            low = min(low,c[i]);
        }

        //calcula os divisores do menor c[i]
        for(i=1;i*i<=low;i++)
        {
            if(low%i == 0) 
            {
                div.push_back(i);
                if(low/i != i) div.push_back(low/i);
            }
        }
        
        //itero sobre os divisores de low
        for(i=0;i<div.size();i++)
        {
            flag = 0;
            // verifico se div[i] divide todo c[j]
            for(j=0;j<f;j++)
            {
                if(c[j]%div[i] != 0) 
                {
                    flag = 1;
                    break;
                }
            }

            if(flag) continue;
            
            for(j=1;j<f;j++)
            {
                if((c[j]/div[i])%f != (c[j-1]/div[i])%f)
                {
                    flag = 1;
                    break;
                }
            }
            if(!flag) ret += (low/div[i] - 1)/f;
        }
        printf("%d\n", ret);
    }
	return 0;
}
