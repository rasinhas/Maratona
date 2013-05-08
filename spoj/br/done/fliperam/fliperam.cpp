#include <stdio.h> 
#include <vector>                                                                   
#include <algorithm>                                                                
using namespace std;                                                                
int main(void)
{
	int N, M, i, ponto;                                                             
	vector<int> pontos;                                                             
	scanf("%d %d", &N, &M);                                                         
	for(i=0;i<N;i++)                                                                
	{
		scanf("%d", &ponto);                                                        
		pontos.push_back(int(ponto));                                               
	}   
	sort(pontos.begin(),pontos.end());
	for(i=1;i<=M;i++)                                                               
	{
		printf("%d\n",pontos[N-i]);
	}                                                                               
	return(0);                                                                      
}

