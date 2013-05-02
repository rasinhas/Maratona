#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main(void)
{
	int N, K, i;
	vector<string> chamada;
	char nome[21];
	scanf("%d %d",&N,&K);
	for(i=0;i<N;i++)
	{
		scanf("%s",nome);
		chamada.push_back(string(nome));
	}
	sort(chamada.begin(),chamada.end());
	printf("%s\n",chamada[K-1].c_str());

	return(0);
}


