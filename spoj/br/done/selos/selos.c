#include <stdio.h>

int main()
{
    long long int n, i;
    scanf("%lld", &n);
    if(n==0 || n==1){
        printf("N\n");
        return 0;
    }
    if(n == 2){
        printf("N\n");
        return 0;
    }
    if(n%2 == 0){   
        printf("S\n");
        return 0;
    }
    for(i=3;i<n;i+=2){  
        if(n%i == 0){   
            printf("S\n");
            return 0;
        }
        if(i*i > n) {   
            break;
        }
    }
    printf("N\n");
    return 0;
}
