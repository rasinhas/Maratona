#include <stdio.h>

int main()
{
	long long int n, i;
	scanf("%lld", &n);
	if(n<0)
		n=-n;
	if(n==0 || n==1){
		printf("nao");
		return 0;
	}
	if(n == 2){
		printf("sim");
		return 0;
	}
	if(n%2 == 0){   
		printf("nao");
		return 0;
	}
	for(i=3;i<n;i+=2){  
		if(n%i == 0){   
			printf("nao");
			return 0;
		}
		if(i*i > n) {   
			break;
		}
	}
	printf("sim");
	return 0;
}

