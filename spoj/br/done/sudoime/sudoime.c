#include <stdio.h>

int main(){
	int i, j, k, l, n, inst = 1;
	int sud[9][9];

	scanf( "%d", &n );

	while( inst <= n ){
		int erro = 0;
		for( i = 0; i < 9; i++ ){
			for( j = 0; j < 9; j++ ){
				scanf( "%i", &sud[i][j] );
			}
		}

		for( k = 0; k < 9; k++ ){
			for( i = 0; i < 9; i++ ){
				for( j = k+1; j < 9; j++ ){

					if( sud[i][k] == sud[i][j] ){
						erro = 1;
						i=j=k=9;
					}
					else if( sud[k][i] == sud[j][i] ){
						erro = 1;
						i=j=k=9;
					}
				}
			}
		}

		if( !erro ){
			for( i = 0; i < 9; i+=3 ){
				for( j = 0; j < 9; j+= 3 ){
					for( k = 0; k < 9; k++ ){
						for( l = k+1; l < 9; l++ ){
							if( sud[i + (k/3)][j + (k%3)] == sud[i+(l/3)][j + (l%3)] ){
								i = j = k = l = 9;
								erro = 1;
							}
						}
					}
				}
			}
		}

		printf( "Instancia %i\n%s", inst++, (erro) ? "NAO" : "SIM" );
		printf( "\n\n");
	}
	return 0;
}

