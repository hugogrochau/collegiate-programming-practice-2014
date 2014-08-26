#include <stdio.h>
#define EMPTY -1

int c[1100];
int N;
int carro, pos;
int livres;
bool erro;

void resetArray(int n)
{
	for(int i=0;i<n;i++)
	{
		c[i] = EMPTY;
	}
	return;
}

void printArray(int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",c[i]);
	}
	printf("\n");
	return;
}

bool isOutOfBounds(int x)
{
	return x>= N || x<0;
}

int main(void)
{
	while(1)
	{
		scanf(" %d ",&N);
		if(N==0) break;
		
		resetArray(N);
		livres = 0;
		erro = false;
		
		for(int i=0;i<N;i++)
		{
			scanf(" %d %d ",&carro,&pos);
			if(!erro)
			{
				if(isOutOfBounds(i+pos))
				{
					erro = true;
					continue;
				}
				else if(c[i+pos]!=EMPTY)
				{
					erro = true;
					continue;
				}
				else
				{
					c[i+pos] = carro;
				}
			
				if(c[i] == EMPTY) livres++;
				if(pos<0) livres--;
			}
		}
		
		if(livres)
		{
			erro = true;
		}
		if(livres < 0) printf("ERRO INESPERADO - OLHAR CODIGO\n");
		
		if(erro)
		{
			printf("-1\n");
		}
		else
		{
			printArray(N);
		}
	}

	return 0;
}
