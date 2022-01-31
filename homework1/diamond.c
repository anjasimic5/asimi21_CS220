#include <stdio.h>
void diamond()
{
	int n;
	printf("Enter a non-negative odd digit: ");
	scanf("%d", &n);
	
	while(n != -1)
	{
		int j = 1, been = 0, x;
		while(j!= -1 || been != 1) 
		{
			if(j == n)
			{
				x = j;
				been = 1;
				while(x > 0)
				{
					printf("*");
					x = x - 1;
				}
				printf("\n");
			}
			else
			{
				x = (n - j)/2;
				for(int i = 1; i <= x; i++)
				{
					printf(" ");
				}
				
				for(int i = 1; i <= j; i ++)
				{
					printf("*");
				}
				
				printf("\n");
			}
			if(been == 1)
				{
					j = j - 2;
				}
			else
				{
					j = j + 2;
				}
		}
		printf("Enter a non-negative odd digit: ");
		scanf("%d", &n);
	}
	
	printf("Bye!\n");
}
